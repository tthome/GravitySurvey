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

        private void GenerateReceivers_OnClick(object sender, RoutedEventArgs e)
        {
            var receiverCount = Convert.ToInt32(ReceiversCount.Text);

            var beginX = Convert.ToDouble(BeginX.Text);
            var beginY = Convert.ToDouble(BeginY.Text);
            var beginZ = Convert.ToDouble(BeginZ.Text);
            var endX = Convert.ToDouble(EndX.Text);
            var endY = Convert.ToDouble(EndY.Text);
            var endZ = Convert.ToDouble(EndZ.Text);

            var hx = (endX - beginX)/receiverCount;
            var hy = (endY - beginY)/receiverCount;
            var hz = (endZ - beginZ)/receiverCount;

            var fileDialog = new SaveFileDialog();

            if (fileDialog.ShowDialog() == true)
            {
                using (var writer = new StreamWriter(fileDialog.OpenFile(), Encoding.Default))
                {
                    writer.WriteLine(receiverCount);
                    for (var i = 0; i < receiverCount; i++)
                    {
                        var x = i*hx + beginX;
                        var y = i*hy + beginY;
                        var z = i*hz + beginZ;
                        writer.WriteLine(x.ToString(CultureInfo.InvariantCulture) + " " +
                                         y.ToString(CultureInfo.InvariantCulture) + " " +
                                         z.ToString(CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}