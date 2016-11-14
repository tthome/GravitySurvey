using System;
using System.Globalization;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
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
            using (var reader = new StreamReader(path))
            {
                var regex = new Regex(@"[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?");
                var isColumnsInitialized = false;
                var line = reader.ReadLine();
                var row = 0;
                while (!string.IsNullOrWhiteSpace(line))
                {
                    AreaGrid.RowDefinitions.Add(new RowDefinition());
                    var matches = regex.Matches(line);
                    var column = 0;
                    for (var i = 0; i < matches.Count; i++)
                    {
                        if (!isColumnsInitialized) AreaGrid.ColumnDefinitions.Add(new ColumnDefinition());
                        var value = Convert.ToDouble(matches[i].Value, CultureInfo.InvariantCulture);
                        var textBlock = new TextBlock {Text = value.ToString("E2")};
                        Grid.SetRow(textBlock, row);
                        Grid.SetColumn(textBlock, column);
                        AreaGrid.Children.Add(textBlock);
                        column++;
                    }
                    isColumnsInitialized = true;
                    line = reader.ReadLine();
                    row++;
                }
            }
        }
    }
}