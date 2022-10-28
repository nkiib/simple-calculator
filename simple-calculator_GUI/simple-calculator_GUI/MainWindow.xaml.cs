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
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        public const string CALCPATH = "";
        public MainWindow()
        {
            InitializeComponent();
            ProcessStartInfo p = new ProcessStartInfo();
            p.FileName = $"{CALCPATH}";
            p.Arguments = "";
            p.UseShellExecute = true;

            Process ps = Process.Start(p);
            ps.WaitForExit();
        }
    }
}
