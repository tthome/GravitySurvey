using System;
using System.Globalization;
using System.IO;
using System.Text;
using System.Windows;
using Microsoft.Win32;

namespace UI
{
    public partial class InputReceiversWindow
    {
        public InputReceiversWindow()
        {
            InitializeComponent();
        }

        private void OpenFileButton_OnClick(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog
            {
                FileName = "Receivers",
                DefaultExt = "txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                Simulation.ReceiversPath = fileDialog.FileName;
                OkButton.IsEnabled = true;
            }
        }

        private void GenerateReceivers_OnClick(object sender, RoutedEventArgs e)
        {
            var receiversCount = Convert.ToInt32(ReceiversCountTextBox.Text);

            var beginX = Convert.ToDouble(BeginX.Text);
            var beginY = Convert.ToDouble(BeginY.Text);
            var beginZ = Convert.ToDouble(BeginZ.Text);
            var endX = Convert.ToDouble(EndX.Text);
            var endY = Convert.ToDouble(EndY.Text);
            var endZ = Convert.ToDouble(EndZ.Text);

            var hx = (endX - beginX)/receiversCount;
            var hy = (endY - beginY)/receiversCount;
            var hz = (endZ - beginZ)/receiversCount;

            var fileDialog = new SaveFileDialog
            {
                FileName = "Receivers",
                DefaultExt = "txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                using (var writer = new StreamWriter(fileDialog.OpenFile(), Encoding.Default))
                {
                    writer.WriteLine(receiversCount);
                    for (var i = 0; i < receiversCount; i++)
                    {
                        var x = i*hx + beginX;
                        var y = i*hy + beginY;
                        var z = i*hz + beginZ;
                        writer.WriteLine(x.ToString(CultureInfo.InvariantCulture) + " " +
                                         y.ToString(CultureInfo.InvariantCulture) + " " +
                                         z.ToString(CultureInfo.InvariantCulture));
                    }
                    Simulation.ReceiversPath = fileDialog.FileName;
                    OkButton.IsEnabled = true;
                }
            }
        }

        private void OkButton_OnClick(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}