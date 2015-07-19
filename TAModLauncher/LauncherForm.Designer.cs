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
            this.btnUpdateInject = new System.Windows.Forms.Button();
            this.btnLaunchTribes = new System.Windows.Forms.Button();
            this.progressUpdate = new System.Windows.Forms.ProgressBar();
            this.checkAutoUpdate = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // btnUpdateInject
            // 
            this.btnUpdateInject.Location = new System.Drawing.Point(611, 299);
            this.btnUpdateInject.Name = "btnUpdateInject";
            this.btnUpdateInject.Size = new System.Drawing.Size(75, 38);
            this.btnUpdateInject.TabIndex = 0;
            this.btnUpdateInject.Text = "Update / Inject";
            this.btnUpdateInject.UseVisualStyleBackColor = true;
            // 
            // btnLaunchTribes
            // 
            this.btnLaunchTribes.Location = new System.Drawing.Point(611, 255);
            this.btnLaunchTribes.Name = "btnLaunchTribes";
            this.btnLaunchTribes.Size = new System.Drawing.Size(75, 38);
            this.btnLaunchTribes.TabIndex = 1;
            this.btnLaunchTribes.Text = "Launch Game";
            this.btnLaunchTribes.UseVisualStyleBackColor = true;
            // 
            // progressUpdate
            // 
            this.progressUpdate.Location = new System.Drawing.Point(12, 299);
            this.progressUpdate.Name = "progressUpdate";
            this.progressUpdate.Size = new System.Drawing.Size(593, 38);
            this.progressUpdate.TabIndex = 2;
            // 
            // checkAutoUpdate
            // 
            this.checkAutoUpdate.AutoSize = true;
            this.checkAutoUpdate.Checked = true;
            this.checkAutoUpdate.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkAutoUpdate.Location = new System.Drawing.Point(12, 276);
            this.checkAutoUpdate.Name = "checkAutoUpdate";
            this.checkAutoUpdate.Size = new System.Drawing.Size(183, 17);
            this.checkAutoUpdate.TabIndex = 3;
            this.checkAutoUpdate.Text = "Automatically Check For Updates";
            this.checkAutoUpdate.UseVisualStyleBackColor = true;
            // 
            // LauncherForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(698, 349);
            this.Controls.Add(this.checkAutoUpdate);
            this.Controls.Add(this.progressUpdate);
            this.Controls.Add(this.btnLaunchTribes);
            this.Controls.Add(this.btnUpdateInject);
            this.Name = "LauncherForm";
            this.Text = "TAMods Launcher";
            this.Load += new System.EventHandler(this.LauncherForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnUpdateInject;
        private System.Windows.Forms.Button btnLaunchTribes;
        private System.Windows.Forms.ProgressBar progressUpdate;
        private System.Windows.Forms.CheckBox checkAutoUpdate;
    }
}

