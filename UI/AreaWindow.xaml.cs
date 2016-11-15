using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using Microsoft.Win32;

namespace UI
{
    public partial class AreaWindow
    {
        public AreaWindow()
        {
            InitializeComponent();
        }

        private void FileOpen_OnClick(object sender, RoutedEventArgs e)
        {
            var openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog(this) == true)
                ShowArea(openFileDialog.FileName);
        }

        private void ShowArea(string path)
        {
            var values = LoadArea(path);
            var min = values.SelectMany(row => row).Min();
            var max = values.SelectMany(row => row).Max();
            var isColumnsInitialized = false;
            for (var row = 0; row < values.Count; row++)
            {
                AreaGrid.RowDefinitions.Add(new RowDefinition());
                for (var column = 0; column < values[row].Length; column++)
                {
                    if (!isColumnsInitialized) AreaGrid.ColumnDefinitions.Add(new ColumnDefinition());
                    var percent = (max - values[row][column])/(max - min);
                    var textBlock = new TextBlock
                    {
                        Text = values[row][column].ToString("E2"),
                        Background = new SolidColorBrush(
                            Color.FromArgb((byte) (255*percent), 39, 174, 96))
                    };
                    Grid.SetRow(textBlock, row);
                    Grid.SetColumn(textBlock, column);
                    AreaGrid.Children.Add(textBlock);
                }
                isColumnsInitialized = true;
            }
        }

        private List<double[]> LoadArea(string path)
        {
            var list = new List<double[]>();
            using (var reader = new StreamReader(path))
            {
                var regex = new Regex(@"[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?");
                var line = reader.ReadLine();
                while (!string.IsNullOrWhiteSpace(line))
                {
                    var matches = regex.Matches(line);
                    var values = new double[matches.Count];
                    for (var i = 0; i < matches.Count; i++)
                        values[i] = Convert.ToDouble(matches[i].Value, CultureInfo.InvariantCulture);
                    list.Add(values);
                    line = reader.ReadLine();
                }
            }
            return list;
        }
    }
}