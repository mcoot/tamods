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
    public partial class SettingsForm : Form
    {
        private LauncherForm parent;
        
        public SettingsForm(LauncherForm parent)
        {
            InitializeComponent();
            this.parent = parent;

            if (!parent.updaterEnabled)
            {
                this.selectUpdateChannel.Enabled = false;
            }
        }

        private void SettingsForm_Load(object sender, EventArgs e)
        {
            fileSelectLauncherDirectory.FilePathChanged += new EventHandler(fileSelectLauncherDirectory_FilePathChanged);
            fileSelectLauncherDirectory.setFilePath(parent.LauncherPath);

            fileSelectDLLDirectory.FilePathChanged += new EventHandler(fileSelectDLLDirectory_FilePathChanged);
            fileSelectDLLDirectory.setFilePath(parent.DLLPath);

            checkAutoInjectSmartMode.Checked = parent.autoInjectTimer.SmartMode;
            numAutoInjectDelay.Value = parent.autoInjectTimer.Delay;

        }

        private void selectUpdateChannel_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (selectUpdateChannel.SelectedItem != null)
            {
                try
                {
                    parent.updater.setUpdateChannel(selectUpdateChannel.SelectedItem.ToString().ToLower());
                }
                catch (XmlException ex)
                {
                    MessageBox.Show("ERROR: The updater could not set the requested update channel.\n Message: " + ex,
                    "Error Setting Update Channel", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void fileSelectLauncherDirectory_FilePathChanged(object sender, EventArgs e)
        {
            parent.LauncherPath = fileSelectLauncherDirectory.FilePath;
        }

        private void fileSelectDLLDirectory_FilePathChanged(object sender, EventArgs e)
        {
            parent.DLLPath = fileSelectDLLDirectory.FilePath;
        }

        private void SettingsForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Hide();
            e.Cancel = true;
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void checkAutoInjectSmartMode_CheckedChanged(object sender, EventArgs e)
        {
            parent.autoInjectTimer.SmartMode = checkAutoInjectSmartMode.Checked;
            numAutoInjectDelay.Enabled = !checkAutoInjectSmartMode.Checked;

            if (checkAutoInjectSmartMode.Checked)
            {
                parent.autoInjectTimer.Delay = 15;
            }
            else
            {
                parent.autoInjectTimer.Delay = Convert.ToInt32(numAutoInjectDelay.Value);
            }
        }

        private void numAutoInjectDelay_ValueChanged(object sender, EventArgs e)
        {
            if (numAutoInjectDelay.Enabled)
            {
                parent.autoInjectTimer.Delay = Convert.ToInt32(numAutoInjectDelay.Value);
            }
        }
    }
}
