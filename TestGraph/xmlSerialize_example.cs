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
        public static loadConfig cfg = new loadConfig();
        public Form2()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(checkBox1.Checked == false && checkBox2.Checked == false
                && checkBox3.Checked == false && checkBox4.Checked == false
                && checkBox5.Checked == false && checkBox6.Checked == false
                && checkBox7.Checked == true)
            {
                MessageBox.Show("At least one data item has to be selected.", "Warning");
                return;
            }
            save();
            Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void checkBox7_CheckedChanged(object sender, EventArgs e)
        {
            if(checkBox7.Checked == true)
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
            if (File.Exists("config.xml"))
            {
                load();
            }
            else
            {
                MessageBox.Show("config.xml does not exist. Default config loaded.","Warning");
            }
        }

        public void load()
        {
            XmlSerializer serial = new XmlSerializer(typeof(loadConfig));
            using (FileStream stream = File.OpenRead("config.xml"))
            {
                cfg = (loadConfig)serial.Deserialize(stream);
            }
            checkBox1.Checked = Convert.ToBoolean(cfg.Check1);
            checkBox2.Checked = Convert.ToBoolean(cfg.Check2);
            checkBox3.Checked = Convert.ToBoolean(cfg.Check3);
            checkBox4.Checked = Convert.ToBoolean(cfg.Check4);
            checkBox5.Checked = Convert.ToBoolean(cfg.Check5);
            checkBox6.Checked = Convert.ToBoolean(cfg.Check6);
            checkBox7.Checked = Convert.ToBoolean(cfg.Enable);
            checkBox8.Checked = Convert.ToBoolean(cfg.Check7);
            textBox1.Text = Convert.ToString(cfg.Fpaths);
            saveFileDialog1.FilterIndex = Convert.ToInt32(cfg.Filter);
        }

        public void save()
        {
            using (StreamWriter swrite = new StreamWriter("config.xml"))
            {
                cfg.Enable = Convert.ToString(checkBox7.Checked);
                cfg.Check1 = Convert.ToString(checkBox1.Checked);
                cfg.Check2 = Convert.ToString(checkBox2.Checked);
                cfg.Check3 = Convert.ToString(checkBox3.Checked);
                cfg.Check4 = Convert.ToString(checkBox4.Checked);
                cfg.Check5 = Convert.ToString(checkBox5.Checked);
                cfg.Check6 = Convert.ToString(checkBox6.Checked);
                cfg.Check7 = Convert.ToString(checkBox8.Checked);
                cfg.Fpaths = Convert.ToString(textBox1.Text);
                cfg.Filter = Convert.ToString(saveFileDialog1.FilterIndex);
                                
                XmlSerializer serial = new XmlSerializer(typeof(loadConfig));
                serial.Serialize(swrite, cfg);
            }
        }
    }

    public class loadConfig
    {
        public string Enable { get; set; }
        public string Fpaths { get; set; }
        public string Filter { get; set; }
        public string Check1 { get; set; }
        public string Check2 { get; set; }
        public string Check3 { get; set; }
        public string Check4 { get; set; }
        public string Check5 { get; set; }
        public string Check6 { get; set; }
        public string Check7 { get; set; }
    }
}
