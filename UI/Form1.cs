using System.Windows.Forms;
using Wrapper;

namespace UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Manager.Run();
        }
    }
}