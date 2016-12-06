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

        private void InputAreaButton_Click(object sender, RoutedEventArgs e)
        {
            new InputAreaWindow().Show();
        }

        private void InputReceiversButton_Click(object sender, RoutedEventArgs e)
        {
            new InputReceiversWindow().Show();
        }
    }
}