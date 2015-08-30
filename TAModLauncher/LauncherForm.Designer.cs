namespace TAModLauncher
{
    partial class LauncherForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btnUpdateLaunch = new System.Windows.Forms.Button();
            this.progressUpdate = new System.Windows.Forms.ProgressBar();
            this.checkAutoUpdate = new System.Windows.Forms.CheckBox();
            this.labelDownload = new System.Windows.Forms.Label();
            this.btnUpdateCheck = new System.Windows.Forms.Button();
            this.btnReinstall = new System.Windows.Forms.Button();
            this.btnSettings = new System.Windows.Forms.Button();
            this.timerCheckTribesRunning = new System.Windows.Forms.Timer(this.components);
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // btnUpdateLaunch
            // 
            this.btnUpdateLaunch.Location = new System.Drawing.Point(549, 132);
            this.btnUpdateLaunch.Name = "btnUpdateLaunch";
            this.btnUpdateLaunch.Size = new System.Drawing.Size(75, 38);
            this.btnUpdateLaunch.TabIndex = 0;
            this.btnUpdateLaunch.Text = "Launch Game";
            this.btnUpdateLaunch.UseVisualStyleBackColor = true;
            this.btnUpdateLaunch.Click += new System.EventHandler(this.btnUpdateLaunch_Click);
            // 
            // progressUpdate
            // 
            this.progressUpdate.Location = new System.Drawing.Point(12, 132);
            this.progressUpdate.Name = "progressUpdate";
            this.progressUpdate.Size = new System.Drawing.Size(531, 38);
            this.progressUpdate.TabIndex = 2;
            // 
            // checkAutoUpdate
            // 
            this.checkAutoUpdate.AutoSize = true;
            this.checkAutoUpdate.Checked = true;
            this.checkAutoUpdate.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkAutoUpdate.Location = new System.Drawing.Point(12, 109);
            this.checkAutoUpdate.Name = "checkAutoUpdate";
            this.checkAutoUpdate.Size = new System.Drawing.Size(183, 17);
            this.checkAutoUpdate.TabIndex = 3;
            this.checkAutoUpdate.Text = "Automatically Check For Updates";
            this.checkAutoUpdate.UseVisualStyleBackColor = true;
            // 
            // labelDownload
            // 
            this.labelDownload.AutoSize = true;
            this.labelDownload.Location = new System.Drawing.Point(12, 173);
            this.labelDownload.Name = "labelDownload";
            this.labelDownload.Size = new System.Drawing.Size(83, 13);
            this.labelDownload.TabIndex = 4;
            this.labelDownload.Text = "Ready To Play! ";
            this.labelDownload.Visible = false;
            // 
            // btnUpdateCheck
            // 
            this.btnUpdateCheck.Location = new System.Drawing.Point(198, 105);
            this.btnUpdateCheck.Name = "btnUpdateCheck";
            this.btnUpdateCheck.Size = new System.Drawing.Size(75, 23);
            this.btnUpdateCheck.TabIndex = 5;
            this.btnUpdateCheck.Text = "Check Now";
            this.btnUpdateCheck.UseVisualStyleBackColor = true;
            this.btnUpdateCheck.Click += new System.EventHandler(this.btnUpdateCheck_Click);
            // 
            // btnReinstall
            // 
            this.btnReinstall.Location = new System.Drawing.Point(279, 105);
            this.btnReinstall.Name = "btnReinstall";
            this.btnReinstall.Size = new System.Drawing.Size(81, 23);
            this.btnReinstall.TabIndex = 6;
            this.btnReinstall.Text = "Reinstall Mod";
            this.btnReinstall.UseVisualStyleBackColor = true;
            this.btnReinstall.Click += new System.EventHandler(this.btnReinstall_Click);
            // 
            // btnSettings
            // 
            this.btnSettings.Location = new System.Drawing.Point(549, 12);
            this.btnSettings.Name = "btnSettings";
            this.btnSettings.Size = new System.Drawing.Size(75, 23);
            this.btnSettings.TabIndex = 9;
            this.btnSettings.Text = "Settings";
            this.btnSettings.UseVisualStyleBackColor = true;
            this.btnSettings.Click += new System.EventHandler(this.btnSettings_Click);
            // 
            // timerCheckTribesRunning
            // 
            this.timerCheckTribesRunning.Enabled = true;
            this.timerCheckTribesRunning.Interval = 1000;
            this.timerCheckTribesRunning.Tick += new System.EventHandler(this.timerCheckTribesRunning_Tick);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(424, 108);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(117, 17);
            this.checkBox1.TabIndex = 10;
            this.checkBox1.Text = "Automatically Inject";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // LauncherForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(630, 191);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.btnSettings);
            this.Controls.Add(this.btnReinstall);
            this.Controls.Add(this.btnUpdateCheck);
            this.Controls.Add(this.labelDownload);
            this.Controls.Add(this.checkAutoUpdate);
            this.Controls.Add(this.progressUpdate);
            this.Controls.Add(this.btnUpdateLaunch);
            this.MaximumSize = new System.Drawing.Size(646, 230);
            this.MinimumSize = new System.Drawing.Size(646, 230);
            this.Name = "LauncherForm";
            this.Text = "TAMods Launcher";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.LauncherForm_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.LauncherForm_FormClosed);
            this.Load += new System.EventHandler(this.LauncherForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnUpdateLaunch;
        private System.Windows.Forms.ProgressBar progressUpdate;
        private System.Windows.Forms.CheckBox checkAutoUpdate;
        private System.Windows.Forms.Label labelDownload;
        private System.Windows.Forms.Button btnUpdateCheck;
        private System.Windows.Forms.Button btnReinstall;
        private System.Windows.Forms.Button btnSettings;
        private System.Windows.Forms.Timer timerCheckTribesRunning;
        private System.Windows.Forms.CheckBox checkBox1;
    }
}

