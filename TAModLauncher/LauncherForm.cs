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

namespace TAModLauncher
{
    public partial class LauncherForm : Form
    {
        private TAModUpdater updater;
        private TAModLauncherConfig config;

        private bool updateRequired;

        public LauncherForm()
        {
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

            if (checkAutoUpdate.Checked)
            {
                checkForUpdates();
            }

        }

        private void LauncherForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            config.setProperty("//LauncherConfig/AutoUpdateCheck", checkAutoUpdate.Checked.ToString().ToLower());
            if (selectUpdateChannel.SelectedItem != null) config.setProperty("//LauncherConfig/UpdateChannel", selectUpdateChannel.SelectedItem.ToString().ToLower());
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
            selectUpdateChannel.Items.Clear();
            foreach (string channel in updater.getAvailableUpdateChannels())
            {
                selectUpdateChannel.Items.Add(channel);
            }

            // Try to get the user's channel from the launcher config
            string userUpdateChannel = config.getProperty("//LauncherConfig/UpdateChannel");

            if (userUpdateChannel != null && selectUpdateChannel.Items.Contains(userUpdateChannel))
            {
                selectUpdateChannel.SelectedItem = userUpdateChannel;
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
                labelDownload.Visible = false;
                btnUpdateLaunch.Text = "Launch Tribes";
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
            labelDownload.Visible = true;
            labelDownload.Text = "Ready to Play!";
            //MessageBox.Show("Download complete!");
        }

        private void btnUpdateLaunch_Click(object sender, EventArgs e)
        {
            labelDownload.Visible = true;
            updater.beginUpdate();
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
        }

        private void selectUpdateChannel_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (selectUpdateChannel.SelectedItem != null)
            {
                try
                {
                    updater.setUpdateChannel(selectUpdateChannel.SelectedItem.ToString().ToLower());
                }
                catch (XmlException ex)
                {
                    MessageBox.Show("ERROR: The updater could not set the requested update channel.\n Message: " + ex,
                    "Error Setting Update Channel", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}
