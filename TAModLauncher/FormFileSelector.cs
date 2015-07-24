using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace TAModLauncher
{
    public partial class FormFileSelector : UserControl
    {
        private string filePath;

        public string FilePath
        {
            get { return filePath; }
            set { filePath = value; }
        }

        public event EventHandler FilePathChanged;
        
        public FormFileSelector(string filePath)
        {
            InitializeComponent();
            this.filePath = filePath;
        }

        public FormFileSelector() : this("") { }

        public void setFileDialogFilter(string filter)
        {
            fileMain.Filter = filter;
        }

        public void setFilePath(string path)
        {
            FilePath = path;
            textFilePath.Text = path;
        }

        private void FormFileSelector_Load(object sender, EventArgs e)
        {
            textFilePath.Text = this.filePath;
        }

        private void btnSelectFile_Click(object sender, EventArgs e)
        {
            if (filePath.Trim() != "" && Directory.Exists(Path.GetDirectoryName(filePath))) fileMain.FileName = filePath;
            fileMain.ShowDialog();
            filePath = fileMain.FileName;
            updateTextBox();
        }

        private void textFilePath_TextChanged(object sender, EventArgs e)
        {
            filePath = textFilePath.Text;
            FilePathChanged(this, EventArgs.Empty);
        }

        private void updateTextBox()
        {
            textFilePath.Text = this.filePath;
            FilePathChanged(this, EventArgs.Empty);
        }
    }
}
