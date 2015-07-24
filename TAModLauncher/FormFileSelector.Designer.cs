namespace TAModLauncher
{
    partial class FormFileSelector
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.fileMain = new System.Windows.Forms.OpenFileDialog();
            this.textFilePath = new System.Windows.Forms.TextBox();
            this.btnSelectFile = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // fileMain
            // 
            this.fileMain.Title = "Select File";
            // 
            // textFilePath
            // 
            this.textFilePath.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textFilePath.Location = new System.Drawing.Point(0, 0);
            this.textFilePath.MinimumSize = new System.Drawing.Size(150, 20);
            this.textFilePath.Name = "textFilePath";
            this.textFilePath.Size = new System.Drawing.Size(345, 20);
            this.textFilePath.TabIndex = 4;
            this.textFilePath.TextChanged += new System.EventHandler(this.textFilePath_TextChanged);
            // 
            // btnSelectFile
            // 
            this.btnSelectFile.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnSelectFile.Location = new System.Drawing.Point(345, 0);
            this.btnSelectFile.Name = "btnSelectFile";
            this.btnSelectFile.Size = new System.Drawing.Size(75, 20);
            this.btnSelectFile.TabIndex = 5;
            this.btnSelectFile.Text = "Select File";
            this.btnSelectFile.UseVisualStyleBackColor = true;
            this.btnSelectFile.Click += new System.EventHandler(this.btnSelectFile_Click);
            // 
            // FormFileSelector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.textFilePath);
            this.Controls.Add(this.btnSelectFile);
            this.MaximumSize = new System.Drawing.Size(0, 20);
            this.MinimumSize = new System.Drawing.Size(420, 20);
            this.Name = "FormFileSelector";
            this.Size = new System.Drawing.Size(420, 20);
            this.Load += new System.EventHandler(this.FormFileSelector_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog fileMain;
        private System.Windows.Forms.TextBox textFilePath;
        private System.Windows.Forms.Button btnSelectFile;
    }
}
