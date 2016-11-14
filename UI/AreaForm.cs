using System;
using System.IO;
using System.Windows.Forms;

namespace UI
{
    public partial class AreaForm : Form
    {
        public AreaForm()
        {
            InitializeComponent();
        }

        private void OpenToolStripMenuItemClick(object sender, EventArgs e)
        {
            var openFileDialog = new OpenFileDialog
            {
                InitialDirectory = Path.GetFullPath(Path.Combine(Application.ExecutablePath, @"..\..\..\..\"))
            };
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                ShowArea(openFileDialog.FileName);    
            }
        }

        private void ShowArea(string path)
        {
            using (var reader = new StreamReader(path))
            {
                var line = reader.ReadLine();
                while (!string.IsNullOrWhiteSpace(line))
                {
                    var strings = line.Split(' ');
                    foreach (var s in strings)
                    {
                        dataGridView1.Ce
                    }
                    line = reader.ReadLine();
                }
            }
        }
    }
}