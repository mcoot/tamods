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

namespace TAModLauncher
{
    public partial class LauncherForm : Form
    {
        private TAModUpdater updater;

        public LauncherForm()
        {
            InitializeComponent();
        }

        private void LauncherForm_Load(object sender, EventArgs e)
        {
            updater = new TAModUpdater();

            // Event handlers
            updater.DownloadProgressChanged += new EventHandler(updateProgressChange);
            updater.DownloadCompleted += new EventHandler(updateFinished);

            // Load manifests
            updater.loadLocalManifest();
            updater.loadServerManifest();


        }

        private void updateProgressChange(object sender, EventArgs e)
        {
            labelCurrentDownload.Text = "Downloading: " + updater.getDownloadListCurrentFile();
            progressUpdate.Value = Math.Max(0, Math.Min(100, updater.getDownloadListProgressPercentage()));
        }

        private void updateFinished(object sender, EventArgs e)
        {
            labelCurrentDownload.Visible = false;
            MessageBox.Show("Update complete!");
        }

        private void btnUpdateInject_Click(object sender, EventArgs e)
        {
            labelCurrentDownload.Visible = true;
            updater.beginUpdate();
        }
    }
}
