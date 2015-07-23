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
            this.btnUpdateLaunch = new System.Windows.Forms.Button();
            this.progressUpdate = new System.Windows.Forms.ProgressBar();
            this.checkAutoUpdate = new System.Windows.Forms.CheckBox();
            this.labelDownload = new System.Windows.Forms.Label();
            this.btnUpdateCheck = new System.Windows.Forms.Button();
            this.btnReinstall = new System.Windows.Forms.Button();
            this.selectUpdateChannel = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnUpdateLaunch
            // 
            this.btnUpdateLaunch.Location = new System.Drawing.Point(611, 132);
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
            this.progressUpdate.Size = new System.Drawing.Size(593, 38);
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
            this.btnReinstall.Size = new System.Drawing.Size(96, 21);
            this.btnReinstall.TabIndex = 6;
            this.btnReinstall.Text = "Reinstall Mod";
            this.btnReinstall.UseVisualStyleBackColor = true;
            this.btnReinstall.Click += new System.EventHandler(this.btnReinstall_Click);
            // 
            // selectUpdateChannel
            // 
            this.selectUpdateChannel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.selectUpdateChannel.FormattingEnabled = true;
            this.selectUpdateChannel.Location = new System.Drawing.Point(143, 38);
            this.selectUpdateChannel.Name = "selectUpdateChannel";
            this.selectUpdateChannel.Size = new System.Drawing.Size(98, 21);
            this.selectUpdateChannel.TabIndex = 7;
            this.selectUpdateChannel.SelectedIndexChanged += new System.EventHandler(this.selectUpdateChannel_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(57, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Update Channel";
            // 
            // LauncherForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(698, 195);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.selectUpdateChannel);
            this.Controls.Add(this.btnReinstall);
            this.Controls.Add(this.btnUpdateCheck);
            this.Controls.Add(this.labelDownload);
            this.Controls.Add(this.checkAutoUpdate);
            this.Controls.Add(this.progressUpdate);
            this.Controls.Add(this.btnUpdateLaunch);
            this.Name = "LauncherForm";
            this.Text = "TAMods Launcher";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.LauncherForm_FormClosing);
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
        private System.Windows.Forms.ComboBox selectUpdateChannel;
        private System.Windows.Forms.Label label1;
    }
}

