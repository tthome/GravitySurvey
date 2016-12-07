using System;
using System.Collections.Generic;
using System.Windows;
using OxyPlot;
using OxyPlot.Series;


namespace UI
{
    public partial class MainWindow
    {
        public MainWindow()
        {
            InitializeComponent();
            this.MyModel = new PlotModel { Title = "Example 1" };
            this.MyModel.Series.Add(new FunctionSeries(Math.Cos, 0, 10, 0.1, "cos(x)"));

        }
        public PlotModel MyModel { get; private set; }

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

        private void SolutionButton_Click(object sender, RoutedEventArgs e)
        {
            throw new System.NotImplementedException();
        }


        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            PlotView.DataContext = null;
            PlotView.DataContext = this;
        }
    }
}