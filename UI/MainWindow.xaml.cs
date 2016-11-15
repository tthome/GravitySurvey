using System.Windows;

namespace UI
{
    public partial class MainWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void MenuItem_OnClick(object sender, RoutedEventArgs e)
        {
            new AreaWindow().Show();
        }
    }
}