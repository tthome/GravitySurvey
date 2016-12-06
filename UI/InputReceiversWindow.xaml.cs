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

            var Beg_x = Convert.ToDouble(BeginX.Text);
            var Beg_y = Convert.ToDouble(BeginY.Text);
            var Beg_z = Convert.ToDouble(BeginZ.Text);
            var End_x = Convert.ToDouble(EndX.Text);
            var End_y = Convert.ToDouble(EndY.Text);
            var End_z = Convert.ToDouble(EndZ.Text);
            
            var hx = (End_x - Beg_x)/receiverCount;
            var hy = (End_y - Beg_y)/receiverCount;
            var hz = (End_z - Beg_z)/receiverCount;


            var fileDialog = new SaveFileDialog();

            if (fileDialog.ShowDialog() == true)
                using (var writer = new StreamWriter(fileDialog.OpenFile(), Encoding.Default))
                {
                    writer.WriteLine(receiverCount);
                    for (var i = 0; i < receiverCount; i++)
                    {
                        var x = i*hx + Beg_x;
                        var y = i*hy + Beg_y;
                        var z = i*hz + Beg_z;
                        writer.WriteLine(x.ToString(CultureInfo.InvariantCulture) + " " +
                                         y.ToString(CultureInfo.InvariantCulture) + " " +
                                         z.ToString(CultureInfo.InvariantCulture));
                    }
                }
        }
    }
}