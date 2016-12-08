using Shell;

namespace UI
{
    public static class Simulation
    {
        public static string AreaPath { get; set; }

        public static string ReceiversPath { get; set; }

        #region Inverse

        private static InverseM _inverse;

        public static InverseM Inverse
        {
            get { return _inverse ?? (_inverse = new InverseM()); }
            set { _inverse = value; }
        }

        #endregion
    }
}