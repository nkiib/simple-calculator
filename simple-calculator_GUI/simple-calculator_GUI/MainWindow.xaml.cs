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
        public const string CALCPATH = ".\\calc_shiftjis.exe";
        public const string RESULT_PRE = ">> ";
        public List<CALCTYPE> CALCTYPES = new List<CALCTYPE>()
        {
            new CALCTYPE("最小公倍数","-m"),
            new CALCTYPE("最大公約数","-d"),
            new CALCTYPE("素判定","-c"),
            new CALCTYPE("合計","-s"),
            new CALCTYPE("平均","-a"),
            new CALCTYPE("約分","-r"),
            new CALCTYPE("累乗","-p")
        };

        public string output = "";

        public MainWindow()
        {
            InitializeComponent();
            this.collectTypes(ref this.CALCTYPES);
        }

        public void collectTypes(ref List<CALCTYPE> types)
        {
            this.CB_Type.ItemsSource = this.CALCTYPES;
        }

        public string calculate(string args)
        {
            if (this.CB_Type.SelectedItem == null) return "";
            ProcessStartInfo p = new ProcessStartInfo();
            p.FileName = $"{CALCPATH}";
            p.Arguments = $"{(this.CB_Type.SelectedItem as CALCTYPE).ARG} {args}";
            p.UseShellExecute = false;
            p.CreateNoWindow = true;
            p.RedirectStandardOutput = true;

            Process ps = Process.Start(p);
            ps.WaitForExit();
            var res = ps.StandardOutput.ReadToEnd();
            //var bres = Encoding.Default.GetBytes(res);
            //res = Encoding.UTF8.GetString(bres);
            Console.WriteLine(res);
            return res;
        }

        private void on_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key == Key.Enter)
            {
                if (this.TB_Input.Text == "") return;
                var res = this.calculate(this.TB_Input.Text);
                this.output = "";
                this.output += RESULT_PRE;
                this.output += res;
                this.TB_Result.Text = this.output;
            }
        }
    }
}
