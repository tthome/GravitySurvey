using System.Windows.Forms;
using Core;

namespace UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            var manager = new Core.Manager();
            Manager.Run();
        }
    }
}