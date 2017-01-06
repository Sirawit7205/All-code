using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TestGraph
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            numericUpDown1.Value = Properties.Settings.Default.highA;
            numericUpDown2.Value = Properties.Settings.Default.medA;
            numericUpDown3.Value = Properties.Settings.Default.chgA;
            numericUpDown4.Value = Properties.Settings.Default.highB;
            numericUpDown5.Value = Properties.Settings.Default.medB;
            numericUpDown6.Value = Properties.Settings.Default.chgB;
            numericUpDown7.Value = Properties.Settings.Default.highC;
            numericUpDown8.Value = Properties.Settings.Default.medC;
            numericUpDown9.Value = Properties.Settings.Default.chgC;
            numericUpDown10.Value = Convert.ToDecimal(Properties.Settings.Default.highD);
            numericUpDown11.Value = Convert.ToDecimal(Properties.Settings.Default.medD);
            numericUpDown12.Value = Convert.ToDecimal(Properties.Settings.Default.chgD);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Properties.Settings.Default.highA = Convert.ToInt32(numericUpDown1.Value);
            Properties.Settings.Default.medA = Convert.ToInt32(numericUpDown2.Value);
            Properties.Settings.Default.chgA = Convert.ToInt32(numericUpDown3.Value);
            Properties.Settings.Default.highB = Convert.ToInt32(numericUpDown4.Value);
            Properties.Settings.Default.medB = Convert.ToInt32(numericUpDown5.Value);
            Properties.Settings.Default.chgB = Convert.ToInt32(numericUpDown6.Value);
            Properties.Settings.Default.highC = Convert.ToInt32(numericUpDown7.Value);
            Properties.Settings.Default.medC = Convert.ToInt32(numericUpDown8.Value);
            Properties.Settings.Default.chgC = Convert.ToInt32(numericUpDown9.Value);
            Properties.Settings.Default.highD = Convert.ToSingle(numericUpDown10.Value);
            Properties.Settings.Default.medD = Convert.ToSingle(numericUpDown11.Value);
            Properties.Settings.Default.chgD = Convert.ToSingle(numericUpDown12.Value);
            Properties.Settings.Default.Save();
            Close();
        }
    }
}
