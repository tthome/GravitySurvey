using System.IO;
using System.Windows;
using Microsoft.Win32;

namespace UI
{
    public partial class AreaWindow
    {
        public AreaWindow()
        {
            InitializeComponent();
        }

        private void OpenFileButton_OnClick(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog
            {
                FileName = "Area",
                DefaultExt = "txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                Simulation.AreaPath = fileDialog.FileName;
                ShowArea(fileDialog.FileName);
                OkButton.IsEnabled = true;
            }
        }

        private void ShowArea(string path)
        {
            using (var reader = new StreamReader(path))
            {
                AreaTextBox.Text = reader.ReadToEnd();
            }
        }

        private void SaveFileButton_OnClick(object sender, RoutedEventArgs e)
        {
            var fileDialog = new SaveFileDialog
            {
                FileName = "Area",
                DefaultExt = ".txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                using (var writer = new StreamWriter(fileDialog.FileName))
                {
                    writer.Write(AreaTextBox.Text);
                }

                Simulation.AreaPath = fileDialog.FileName;
                ShowArea(fileDialog.FileName);
                OkButton.IsEnabled = true;
            }
        }

        private void OkButton_OnClick(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}