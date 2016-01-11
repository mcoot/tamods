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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LauncherForm));
            this.btnUpdateLaunch = new System.Windows.Forms.Button();
            this.progressUpdate = new System.Windows.Forms.ProgressBar();
            this.checkAutoUpdate = new System.Windows.Forms.CheckBox();
            this.labelDownload = new System.Windows.Forms.Label();
            this.btnUpdateCheck = new System.Windows.Forms.Button();
            this.btnReinstall = new System.Windows.Forms.Button();
            this.btnSettings = new System.Windows.Forms.Button();
            this.timerCheckTribesRunning = new System.Windows.Forms.Timer(this.components);
            this.checkAutoInject = new System.Windows.Forms.CheckBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btnAbout = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // btnUpdateLaunch
            // 
            this.btnUpdateLaunch.Location = new System.Drawing.Point(824, 203);
            this.btnUpdateLaunch.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnUpdateLaunch.Name = "btnUpdateLaunch";
            this.btnUpdateLaunch.Size = new System.Drawing.Size(112, 58);
            this.btnUpdateLaunch.TabIndex = 0;
            this.btnUpdateLaunch.Text = "Launch Game";
            this.btnUpdateLaunch.UseVisualStyleBackColor = true;
            this.btnUpdateLaunch.Click += new System.EventHandler(this.btnUpdateLaunch_Click);
            // 
            // progressUpdate
            // 
            this.progressUpdate.Location = new System.Drawing.Point(18, 203);
            this.progressUpdate.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.progressUpdate.Name = "progressUpdate";
            this.progressUpdate.Size = new System.Drawing.Size(796, 58);
            this.progressUpdate.TabIndex = 2;
            // 
            // checkAutoUpdate
            // 
            this.checkAutoUpdate.AutoSize = true;
            this.checkAutoUpdate.Checked = true;
            this.checkAutoUpdate.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkAutoUpdate.Location = new System.Drawing.Point(18, 168);
            this.checkAutoUpdate.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.checkAutoUpdate.Name = "checkAutoUpdate";
            this.checkAutoUpdate.Size = new System.Drawing.Size(271, 24);
            this.checkAutoUpdate.TabIndex = 3;
            this.checkAutoUpdate.Text = "Automatically Check For Updates";
            this.checkAutoUpdate.UseVisualStyleBackColor = true;
            // 
            // labelDownload
            // 
            this.labelDownload.AutoSize = true;
            this.labelDownload.Location = new System.Drawing.Point(18, 266);
            this.labelDownload.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelDownload.Name = "labelDownload";
            this.labelDownload.Size = new System.Drawing.Size(118, 20);
            this.labelDownload.TabIndex = 4;
            this.labelDownload.Text = "Ready To Play! ";
            this.labelDownload.Visible = false;
            // 
            // btnUpdateCheck
            // 
            this.btnUpdateCheck.Location = new System.Drawing.Point(297, 162);
            this.btnUpdateCheck.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnUpdateCheck.Name = "btnUpdateCheck";
            this.btnUpdateCheck.Size = new System.Drawing.Size(112, 35);
            this.btnUpdateCheck.TabIndex = 5;
            this.btnUpdateCheck.Text = "Check Now";
            this.btnUpdateCheck.UseVisualStyleBackColor = true;
            this.btnUpdateCheck.Click += new System.EventHandler(this.btnUpdateCheck_Click);
            // 
            // btnReinstall
            // 
            this.btnReinstall.Location = new System.Drawing.Point(418, 162);
            this.btnReinstall.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnReinstall.Name = "btnReinstall";
            this.btnReinstall.Size = new System.Drawing.Size(122, 35);
            this.btnReinstall.TabIndex = 6;
            this.btnReinstall.Text = "Reinstall Mod";
            this.btnReinstall.UseVisualStyleBackColor = true;
            this.btnReinstall.Click += new System.EventHandler(this.btnReinstall_Click);
            // 
            // btnSettings
            // 
            this.btnSettings.Location = new System.Drawing.Point(824, 18);
            this.btnSettings.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnSettings.Name = "btnSettings";
            this.btnSettings.Size = new System.Drawing.Size(112, 35);
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
            // checkAutoInject
            // 
            this.checkAutoInject.AutoSize = true;
            this.checkAutoInject.Location = new System.Drawing.Point(636, 166);
            this.checkAutoInject.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.checkAutoInject.Name = "checkAutoInject";
            this.checkAutoInject.Size = new System.Drawing.Size(172, 24);
            this.checkAutoInject.TabIndex = 10;
            this.checkAutoInject.Text = "Automatically Inject";
            this.checkAutoInject.UseVisualStyleBackColor = true;
            this.checkAutoInject.CheckedChanged += new System.EventHandler(this.checkAutoInject_CheckedChanged);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::TAModLauncher.Properties.Resources.launcherlogo;
            this.pictureBox1.Location = new System.Drawing.Point(-2, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(411, 148);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 11;
            this.pictureBox1.TabStop = false;
            // 
            // btnAbout
            // 
            this.btnAbout.Location = new System.Drawing.Point(824, 61);
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Size = new System.Drawing.Size(112, 37);
            this.btnAbout.TabIndex = 12;
            this.btnAbout.Text = "About";
            this.btnAbout.UseVisualStyleBackColor = true;
            this.btnAbout.Click += new System.EventHandler(this.btnAbout_Click);
            // 
            // LauncherForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(936, 268);
            this.Controls.Add(this.btnAbout);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.checkAutoInject);
            this.Controls.Add(this.btnSettings);
            this.Controls.Add(this.btnReinstall);
            this.Controls.Add(this.btnUpdateCheck);
            this.Controls.Add(this.labelDownload);
            this.Controls.Add(this.checkAutoUpdate);
            this.Controls.Add(this.progressUpdate);
            this.Controls.Add(this.btnUpdateLaunch);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(958, 324);
            this.MinimumSize = new System.Drawing.Size(958, 324);
            this.Name = "LauncherForm";
            this.Text = "TAMods Launcher";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.LauncherForm_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.LauncherForm_FormClosed);
            this.Load += new System.EventHandler(this.LauncherForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
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
        private System.Windows.Forms.CheckBox checkAutoInject;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btnAbout;
    }
}

