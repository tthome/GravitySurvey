using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using Microsoft.Win32;
using OxyPlot;
using OxyPlot.Series;

namespace UI
{
    public partial class MainWindow
    {
        public MainWindow()
        {
            InitializeComponent();
            MyModel = new PlotModel {Title = "Example 1"};
            MyModel.Series.Add(new FunctionSeries(Math.Cos, 0, 10, 0.1, "cos(x)"));
        }

        public PlotModel MyModel { get; }

        private void MenuItem_OnClick(object sender, RoutedEventArgs e)
        {
            var openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog(this) == true)
                ShowArea(openFileDialog.FileName);
            //new Area1Window().Show();
        }

        private void InputAreaButton_OnClick(object sender, RoutedEventArgs e)
        {
            new AreaWindow().Show();
        }

        private void InputReceiversButton_OnClick(object sender, RoutedEventArgs e)
        {
            new ReceiversWindow().Show();
        }

        private void SolutionButton_OnClick(object sender, RoutedEventArgs e)
        {
            Simulation.Calculate();
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            PlotView.DataContext = null;
            PlotView.DataContext = this;
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
                    {
                        values[i] = Convert.ToDouble(matches[i].Value, CultureInfo.InvariantCulture);
                    }
                    list.Add(values);
                    line = reader.ReadLine();
                }
            }
            return list;
        }

        private void OpenConfigButton_OnClick(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog
            {
                FileName = "Config",
                DefaultExt = "txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                using (var reader = new StreamReader(fileDialog.OpenFile(), Encoding.Default))
                {
                    var line = reader.ReadLine();
                    if (line != null)
                    {
                        var strings = line.Split(' ', '\t');
                        UseAlphaCheckBox.IsChecked = Convert.ToBoolean(Convert.ToInt32(strings[0]));
                        UseGammaCheckBox.IsChecked = Convert.ToBoolean(Convert.ToInt32(strings[1]));

                        AlphaStartTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                        AlphaStepTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                        AlphaCoeffTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);

                        GammaStartTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                        GammaStepTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                        GammaCoeffTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                        GammaDiffTextBox.Text =
                            Convert.ToDouble(reader.ReadLine(), CultureInfo.InvariantCulture)
                                .ToString("G", CultureInfo.InvariantCulture);
                    }
                }

                Simulation.ConfigPath = fileDialog.FileName;
            }
        }

        private void SaveConfigButton_OnClick(object sender, RoutedEventArgs e)
        {
            var useAlpha = UseAlphaCheckBox.IsChecked == true ? 1 : 0;
            var alphaStart = Convert.ToDouble(AlphaStartTextBox.Text, CultureInfo.InvariantCulture);
            var alphaStep = Convert.ToDouble(AlphaStepTextBox.Text, CultureInfo.InvariantCulture);
            var alphaCoeff = Convert.ToDouble(AlphaCoeffTextBox.Text, CultureInfo.InvariantCulture);

            var useGamma = UseGammaCheckBox.IsChecked == true ? 1 : 0;
            var gammaStart = Convert.ToDouble(GammaStartTextBox.Text, CultureInfo.InvariantCulture);
            var gammaStep = Convert.ToDouble(GammaStepTextBox.Text, CultureInfo.InvariantCulture);
            var gammaCoeff = Convert.ToDouble(GammaCoeffTextBox.Text, CultureInfo.InvariantCulture);
            var gammaDiff = Convert.ToDouble(GammaDiffTextBox.Text, CultureInfo.InvariantCulture);

            var fileDialog = new SaveFileDialog
            {
                FileName = "Config",
                DefaultExt = "txt"
            };

            if (fileDialog.ShowDialog() == true)
            {
                using (var writer = new StreamWriter(fileDialog.OpenFile(), Encoding.Default))
                {
                    writer.WriteLine(useAlpha + " " + useGamma);
                    writer.WriteLine(alphaStart.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(alphaStep.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(alphaCoeff.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(gammaStart.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(gammaStep.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(gammaCoeff.ToString(CultureInfo.InvariantCulture));
                    writer.WriteLine(gammaDiff.ToString(CultureInfo.InvariantCulture));
                }

                Simulation.ConfigPath = fileDialog.FileName;
            }
        }
    }
}