using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using Microsoft.Win32;

namespace simple_calculator_GUI
{
    public partial class CALCTYPE
    {
        public string TYPE = "";
        public string ARG = "";
        public CALCTYPE() { }
        public CALCTYPE(string type, string arg)
        {
            this.TYPE = type;
            this.ARG = arg;
        }

        public override string ToString()
        {
            return this.TYPE;
        }
    }
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        public const string CALCPATH = ".\\calc.exe";
        public const string CALC_M = "-m";
        public const string CALC_D = "-d";
        public const string CALC_C = "-c";
        public const string CALC_S = "-s";
        public const string CALC_A = "-a";
        public const string CALC_R = "-r";
        public const string CALC_V = "-v";

        public MainWindow()
        {
            InitializeComponent();
            ProcessStartInfo p = new ProcessStartInfo();
            p.FileName = $"{CALCPATH}";
            p.Arguments = "";
            p.UseShellExecute = false;
            p.RedirectStandardOutput = true;

            Process ps = Process.Start(p);
            
            ps.WaitForExit();
            string result = ps.StandardOutput.ReadToEnd();
            var bres = Encoding.Default.GetBytes(result);
            result = Encoding.UTF8.GetString(bres);
            Console.WriteLine(result);
        }

        public void collectTypes(ref List<CALCTYPE> types)
        {
        }
    }
}
