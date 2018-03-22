using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Xml;
using Microsoft.Win32;
using System.Media;

namespace TAModLauncher
{
    public partial class LauncherForm : Form
    {
        public bool updaterEnabled = true;

        public TAModUpdater updater;
        public TAModLauncherConfig config;
        public DLLInjector injector;
        public SettingsForm settingsform;
        public GameDetector autoInjectTimer;
        public string LauncherPath { get; set; }

        public string DLLPath { get; set; }

        public bool updateRequired;
        public string tribesProcessName = "tribesascend";

        public LauncherForm()
        {
            // Use '.' instead of ',' for floating point numbers
            System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
            customCulture.NumberFormat.NumberDecimalSeparator = ".";
            System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

            InitializeComponent();
        }

        private void LauncherForm_Load(object sender, EventArgs e)
        {
            updater = new TAModUpdater();
            config = new TAModLauncherConfig("launcher.xml");
            
            // Event handlers
            updater.DownloadProgressChanged += new EventHandler(updateProgressChange);
            updater.DownloadCompleted += new EventHandler(updateFinished);

            // Load config data
            checkAutoUpdate.Checked = (config.getProperty("//LauncherConfig/AutoUpdateCheck") == null ?
                    true : Convert.ToBoolean(config.getProperty("//LauncherConfig/AutoUpdateCheck").ToLower()));

            string launcherRegEntry = config.getRegistryEntry(Registry.LocalMachine,
                "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{3C87E0FF-BC0A-4F5E-951B-68DC3F8DF1FC}",
                "InstallLocation");
            LauncherPath = (config.getProperty("//LauncherConfig/TribesLauncherPath") == null ?
                (launcherRegEntry == null ? "C:\\Program Files (x86)\\Hi-Rez Studios\\HiRezLauncherUI.exe" : launcherRegEntry + "\\HiRezLauncherUI.exe")
                : config.getProperty("//LauncherConfig/TribesLauncherPath"));
            DLLPath = (config.getProperty("//LauncherConfig/TAModsDLLPath") == null ?
                 "TAMods.dll" : config.getProperty("//LauncherConfig/TAModsDLLPath"));
            bool autoInjecting = (config.getProperty("//LauncherConfig/AutoInject/Enabled") == null ?
                false : Convert.ToBoolean(config.getProperty("//LauncherConfig/AutoInject/Enabled")));
            int autoInjectDelay = (config.getProperty("//LauncherConfig/AutoInject/Delay") == null ?
                60 : Convert.ToInt32(config.getProperty("//LauncherConfig/AutoInject/Delay")));
            bool autoInjectMode = (config.getProperty("//LauncherConfig/AutoInject/SmartMode") == null ?
                true : Convert.ToBoolean(config.getProperty("//LauncherConfig/AutoInject/SmartMode")));
            
            // Create the injector
            injector = new DLLInjector(tribesProcessName, DLLPath);

            // Create the auto-inject timer
            autoInjectTimer = new GameDetector(autoInjecting, autoInjectDelay, "tribesascend", autoInjectMode);
            checkAutoInject.Checked = autoInjectTimer.Enabled;

            // Initialise settings form
            settingsform = new SettingsForm(this);

            if (updaterEnabled && checkAutoUpdate.Checked)
            {
                checkForUpdates();
            }

            // If updater not enabled, grey out updater gui components
            if (!updaterEnabled)
            {
                progressUpdate.Enabled = false;
                checkAutoUpdate.Enabled = false;
                btnUpdateCheck.Enabled = false;
                btnReinstall.Enabled = false;
            }

            

        }

        private void LauncherForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            config.setProperty("//LauncherConfig/AutoUpdateCheck", checkAutoUpdate.Checked.ToString().ToLower());
            if (settingsform.selectUpdateChannel.SelectedItem != null) config.setProperty("//LauncherConfig/UpdateChannel", settingsform.selectUpdateChannel.SelectedItem.ToString().ToLower());
            if (LauncherPath.Trim() != "") config.setProperty("//LauncherConfig/TribesLauncherPath", LauncherPath);
            if (DLLPath.Trim() != "") config.setProperty("//LauncherConfig/TAModsDLLPath", DLLPath);
            config.setProperty("//LauncherConfig/AutoInject/Enabled", autoInjectTimer.Enabled.ToString());
            config.setProperty("//LauncherConfig/AutoInject/Delay", autoInjectTimer.Delay.ToString());
            config.setProperty("//LauncherConfig/AutoInject/SmartMode", autoInjectTimer.SmartMode.ToString());
            config.saveConfig("launcher.xml");
        }

        private bool checkForUpdates()
        {
            // Returns true on successful check, false on failure
            
            // Load manifests
            try
            {
                updater.loadLocalManifest();
            }
            catch (FileNotFoundException)
            {
                MessageBox.Show("ERROR: The updater could not find the local versioning manifest.",
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (UnauthorizedAccessException e)
            {
                MessageBox.Show("ERROR: The updater does not have permission to access the local versioning manifest, giving error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (IOException e)
            {
                MessageBox.Show("ERROR: The updater failed to load the local versioning manifest, with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (XmlException e)
            {
                MessageBox.Show("ERROR: The local versioning manifest could not be parsed, with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (Exception e)
            {
                MessageBox.Show("ERROR: Local manifest loading failed with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            try
            {
                updater.loadServerManifest();
            }
            catch (FileNotFoundException)
            {
                MessageBox.Show("ERROR: The updater could not find the server versioning manifest.",
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (UnauthorizedAccessException e)
            {
                MessageBox.Show("ERROR: The updater does not have permission to access the server versioning manifest, giving error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (IOException e)
            {
                MessageBox.Show("ERROR: The updater failed to load the server versioning manifest, with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (XmlException e)
            {
                MessageBox.Show("ERROR: The server versioning manifest could not be parsed, with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            catch (Exception e)
            {
                MessageBox.Show("ERROR: Server manifest loading failed with error message:\n" + e.Message,
                    "Error Loading Manifest", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            // Get release channels
            settingsform.selectUpdateChannel.Items.Clear();
            foreach (string channel in updater.getAvailableUpdateChannels())
            {
                settingsform.selectUpdateChannel.Items.Add(channel);
            }

            // Try to get the user's channel from the launcher config
            string userUpdateChannel = config.getProperty("//LauncherConfig/UpdateChannel");

            if (userUpdateChannel != null && settingsform.selectUpdateChannel.Items.Contains(userUpdateChannel))
            {
                settingsform.selectUpdateChannel.SelectedItem = userUpdateChannel;
            }

            // If no update channel is set, choose stable channel if available
            if (userUpdateChannel == null && settingsform.selectUpdateChannel.Items.Contains("stable"))
            {
                settingsform.selectUpdateChannel.SelectedItem = "stable";
            }

            // Determine whether update is required
            updateRequired = (updater.getFilesNeedingUpdate().Count > 0);

            if (updateRequired)
            {
                labelDownload.Visible = true;
                labelDownload.Text = "Update Available!";
                btnUpdateLaunch.Text = "Update";
            }
            else
            {
                labelDownload.Visible = true;
                labelDownload.Text = "Up to date!";
                btnUpdateLaunch.Text = "Launch Tribes";
            }

            return true;


        }

        private bool InjectMods()
        {
            if (!injector.DoesProcessExist(tribesProcessName))
            {
                MessageBox.Show("ERROR: Tribes: Ascend is not running.",
                    "Error Injecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (injector.HasInjected)
            {
                MessageBox.Show("ERROR: Mods have already been injected.",
                    "Error Injecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!File.Exists(DLLPath))
            {
                MessageBox.Show("ERROR: TAMods DLL could not be located.",
                    "Error Injecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (DLLPath.ToLower() == "tamods.dll")
            {
                DLLPath = System.Environment.CurrentDirectory + "\\tamods.dll";
            }
            
            try
            {
                injector.Inject();
            }
            catch (InjectorException ex)
            {
                MessageBox.Show("ERROR: Injection failed.\n\nMessage: " + ex.Message,
                    "Error Injecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            SoundPlayer s = new SoundPlayer(TAModLauncher.Properties.Resources.blueplate);
            s.Play();

            return true;
        }

        private bool EjectMods()
        {
            if (!injector.DoesProcessExist(tribesProcessName))
            {
                MessageBox.Show("ERROR: Tribes: Ascend is not running.",
                    "Error Ejecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!injector.HasInjected)
            {
                MessageBox.Show("ERROR: Mods have not been injected.",
                    "Error Ejecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            try
            {
                injector.Eject();
            }
            catch (InjectorException ex)
            {
                MessageBox.Show("ERROR: Ejection failed.\n\nMessage: " + ex.Message,
                    "Error Ejecting TAMods", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            
            return true;
        }

        private void updateProgressChange(object sender, EventArgs e)
        {
            labelDownload.Text = "Downloading: " + updater.getDownloadListCurrentFile();
            progressUpdate.Value = Math.Max(0, Math.Min(100, updater.getDownloadListProgressPercentage()));
        }

        private void updateFinished(object sender, EventArgs e)
        {
            checkForUpdates();
            updateRequired = false;
            labelDownload.Visible = true;
            labelDownload.Text = "Ready to Play!";
            progressUpdate.Value = 0;
            //MessageBox.Show("Download complete!");
        }

        private void btnUpdateLaunch_Click(object sender, EventArgs e)
        {
            if (updateRequired)
            {
                labelDownload.Visible = true;
                updater.beginUpdate();
            }
            else
            {
                // Check if game is already running
                if (injector.DoesProcessExist(tribesProcessName))
                {
                    InjectMods();
                    labelDownload.Text = "Mods injected!";
                    //if (injector.HasInjected)
                    //{
                    //    EjectMods();
                    //    labelDownload.Text = "Mods ejected!";
                    //}
                    //else
                    //{
                    //    InjectMods();
                    //    labelDownload.Text = "Mods injected!";
                    //}
                }
                else
                {
                    if (File.Exists(LauncherPath))
                    {
                        try
                        {
                            Process.Start(LauncherPath);
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show("ERROR: Tribes: Ascend could not be started.\n Message: " + ex.Message,
                                "Error Starting Tribes Launcher", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                    else
                    {
                        MessageBox.Show("ERROR: The Tribes path is not valid. Please change this in the settings.",
                        "Error Starting Tribes Launcher", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void btnUpdateCheck_Click(object sender, EventArgs e)
        {
            checkForUpdates();
        }

        private void btnReinstall_Click(object sender, EventArgs e)
        {
            labelDownload.Visible = true;
            try
            {
                updater.beginFullDownload();
            }
            catch (XmlException)
            {
                MessageBox.Show("ERROR: The updater could not find files in the server manifest for download.",
                    "Error Retrieving Files", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show("ERROR: Redownload failed with error message:\n" + ex.Message,
                    "Error Redownloading", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void LauncherForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void btnSettings_Click(object sender, EventArgs e)
        {
            settingsform.Show();
        }

        private void timerCheckTribesRunning_Tick(object sender, EventArgs e)
        {
            if (!updateRequired)
            {
                if (injector.DoesProcessExist(tribesProcessName))
                {
                    if (injector.HasInjected)
                    {
                        //btnUpdateLaunch.Text = "Eject TAMods";
                    }
                    else
                    {
                        btnUpdateLaunch.Text = "Inject TAMods";

                        // Handle auto-injection
                        if (autoInjectTimer.Enabled)
                        {
                            if (autoInjectTimer.IsReadyToInject())
                            {
                                InjectMods();
                            }
                        }
                    }
                }
                else
                {
                    btnUpdateLaunch.Text = "Launch Tribes";
                    labelDownload.Text = "Ready to play!";
                    if (injector.HasInjected) injector.HasInjected = false;
                    if (autoInjectTimer.Enabled)
                    {
                        autoInjectTimer.ResetTimer();
                    }
                }
            }
        }

        private void checkAutoInject_CheckedChanged(object sender, EventArgs e)
        {
            autoInjectTimer.Enabled = checkAutoInject.Checked;
        }

        private void btnAbout_Click(object sender, EventArgs e)
        {
            String msg = "TAMods Launcher v0.7\n\nFor help with TAMods or the launcher/config tool, post in /r/tribes, or message the devs - /u/Ensiss, /u/Schreq, /u/Dodgesabre, /u/AvianIsTheTerm.";
            MessageBox.Show(msg, "About");
        }

        private void btnBackup_Click(object sender, EventArgs e)
        {
            updater.backupCurrentLocalFiles();
        }
    }
}
