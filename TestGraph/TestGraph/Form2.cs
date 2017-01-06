using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Serialization;
using System.IO;

namespace TestGraph
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked == false && checkBox2.Checked == false
                && checkBox3.Checked == false && checkBox4.Checked == false
                && checkBox5.Checked == false && checkBox6.Checked == false
                && checkBox7.Checked == true && checkBox9.Checked == false
                && checkBox10.Checked == false && checkBox11.Checked == false)
            {
                MessageBox.Show("At least one data item has to be selected.", "Warning");
                return;
            }
            Properties.Settings.Default.Check1 = checkBox1.Checked;
            Properties.Settings.Default.Check2 = checkBox2.Checked;
            Properties.Settings.Default.Check3 = checkBox3.Checked;
            Properties.Settings.Default.Check4 = checkBox4.Checked;
            Properties.Settings.Default.Check5 = checkBox5.Checked;
            Properties.Settings.Default.Check6 = checkBox6.Checked;
            Properties.Settings.Default.Enable = checkBox7.Checked;
            Properties.Settings.Default.Check7 = checkBox8.Checked;
            Properties.Settings.Default.Check8 = checkBox9.Checked;
            Properties.Settings.Default.Check9 = checkBox10.Checked;
            Properties.Settings.Default.Check10 = checkBox11.Checked;
            Properties.Settings.Default.Fpaths = textBox1.Text;
            Properties.Settings.Default.Filter = saveFileDialog1.FilterIndex;
            Properties.Settings.Default.Save();
            Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void checkBox7_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox7.Checked == true)
            {
                groupBox2.Enabled = true;
            }
            else
            {
                groupBox2.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
            textBox1.Text = saveFileDialog1.FileName.ToString();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            checkBox1.Checked = Properties.Settings.Default.Check1;
            checkBox2.Checked = Properties.Settings.Default.Check2;
            checkBox3.Checked = Properties.Settings.Default.Check3;
            checkBox4.Checked = Properties.Settings.Default.Check4;
            checkBox5.Checked = Properties.Settings.Default.Check5;
            checkBox6.Checked = Properties.Settings.Default.Check6;
            checkBox7.Checked = Properties.Settings.Default.Enable;
            checkBox8.Checked = Properties.Settings.Default.Check7;
            checkBox9.Checked = Properties.Settings.Default.Check8;
            checkBox10.Checked = Properties.Settings.Default.Check9;
            checkBox11.Checked = Properties.Settings.Default.Check10;
            textBox1.Text = Properties.Settings.Default.Fpaths;
            saveFileDialog1.FilterIndex = Properties.Settings.Default.Filter;
        }
    }
}
