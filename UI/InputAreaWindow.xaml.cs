using System.IO;
using System.Windows;
using Microsoft.Win32;
using Shell;

namespace UI
{
    public partial class InputAreaWindow
    {
        public InputAreaWindow()
        {
            InitializeComponent();
        }

        private void OpenFileButton_Click(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog();
            var result = fileDialog.ShowDialog();
            if (result == true)
            {
                var file1 = fileDialog.FileName;
                Manager m = new Manager();
                m.InputArea(file1);
                ShowArea(file1);
            }
        }

        private void ShowArea(string path)
        {
            using (var reader = new StreamReader(path))
            {
                AreaTextBox.Text = reader.ReadToEnd();
            }
        }
    }
}