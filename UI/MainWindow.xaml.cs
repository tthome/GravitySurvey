using System.Windows;
using Wrapper;

namespace UI
{
    public partial class MainWindow
    {
        public MainWindow()
        {
            InitializeComponent();
            Manager.Run();
        }

        private void MenuItem_OnClick(object sender, RoutedEventArgs e)
        {
            new AreaWindow().Show();
        }
    }
}