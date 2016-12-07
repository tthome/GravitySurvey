using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Windows;
using OxyPlot;
using OxyPlot.Series;
using Microsoft.Win32;

namespace UI
{
    public partial class MainWindow
    {
        List<double> x1 = new List<double>();
        List<double> y1 = new List<double>();

        public MainWindow()
        {
            InitializeComponent();
           
        }

            public string Title { get; private set; }

            public ObservableCollection<DataPoint> Points { get; private set; }
// this.MyModel = new PlotModel { Title = "Example 1" };
// this.MyModel.Series.Add(new FunctionSeries(Math.Cos, 0, 10, 0.1, "cos(x)"));


//public PlotModel MyModel { get; private set; }

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
        void rff(string file, List<double>x, List<double> y)
        {
            int j = 0;
            string line;
            System.IO.StreamReader f1 = new System.IO.StreamReader(file);
            while ((line = f1.ReadLine()) != null)
            {
                string[] words = line.Split(new []{' ', '\t' });

                x.Add(Single.Parse(words[0], CultureInfo.InvariantCulture));
                y.Add(Single.Parse(words[1], CultureInfo.InvariantCulture));
                //  j++;
            }
           
            f1.Close();
        }
        private void SolutionButton_Click(object sender, RoutedEventArgs e)
        {
            string file1="";
            var fileDialog = new OpenFileDialog();
            var result = fileDialog.ShowDialog();
            if (result == true)
            {
                 file1 = fileDialog.FileName;
            }
            rff(file1, x1, y1);
            this.Points = new ObservableCollection<DataPoint>();
            /*
                              {
                                  new DataPoint(0, 4),
                                  new DataPoint(10, 13),
                                  new DataPoint(20, 15),
                                  new DataPoint(30, 16),
                                  new DataPoint(40, 12),
                                  new DataPoint(50, 12)
                              };*/
            for (int i = 0; i < x1.Count; i++)
            {
                Points.Add(new DataPoint(x1[i], y1[i]));
            }
            Plot.DataContext = null;
            Plot.DataContext = this;
        }


        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            Plot.DataContext = null;
            Plot.DataContext = this;
        }
    }
}