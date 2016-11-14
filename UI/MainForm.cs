using System;
using System.Windows.Forms;

namespace UI
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void ExitToolStripMenuItemClick(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void NewAreaToolStripMenuItemClick(object sender, EventArgs e)
        {
            new AreaForm().ShowDialog(this);
        }
    }
}