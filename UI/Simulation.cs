using System.Windows;
using Shell;

namespace UI
{
    public static class Simulation
    {
        public static string AreaPath { private get; set; }

        public static string ReceiversPath { private get; set; }

        public static string ConfigPath { private get; set; }

        public static bool Calculate()
        {
            var inverse = new InverseM();

            if (!string.IsNullOrWhiteSpace(AreaPath))
                inverse.InputArea(AreaPath);
            else
            {
                MessageBox.Show("Не выбран файл области!", "Ошибка!");
                return false;
            }
            if (!string.IsNullOrWhiteSpace(ReceiversPath))
                inverse.InputReceivers(ReceiversPath);
            else
            {
                MessageBox.Show("Не выбран файл приемников!", "Ошибка!");
                return false;
            }
            if (!string.IsNullOrWhiteSpace(ConfigPath))
                inverse.InputConfig(ConfigPath);
            else
            {
                MessageBox.Show("Не выбран файл конфигурации!", "Ошибка!");
                return false;
            }

            inverse.Calculate();

            return true;
        }
    }
}