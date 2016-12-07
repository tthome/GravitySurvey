using Microsoft.Win32;
using System.IO;
using System.Windows;

namespace UI
{

    public partial class InputAreaWindow : Window
    {
        public InputAreaWindow()
        {
            InitializeComponent();
        }

        private void OpenFileButton_Click(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog();
            var result = fileDialog.ShowDialog();
            if (result == true) {
                string file1 = fileDialog.FileName;
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
