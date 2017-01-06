using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Threading;
using System.Media;

namespace TestGraph
{
    public partial class Form1 : Form
    {
        private bool chk = false;
        int[] v = { -1, -1, -1, -1 };
        bool stop = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Serial.Serial.main();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            Serial.Serial.main();
            label23.Text = DateTime.Now.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text == "Connect")
            {
                serialPort1.PortName = comboBox1.SelectedItem.ToString();
                try { serialPort1.Open(); }
                catch (UnauthorizedAccessException) { MessageBox.Show("Access Denied"); return; }
                catch (ArgumentException) { MessageBox.Show("Invalid port name"); return; }
                catch (IOException) { MessageBox.Show("Port is currently in invalid state."); return; }
                catch (InvalidOperationException) { MessageBox.Show("Port is currently use by another application."); return; }

                GUIstate(0);
                chk = false;

                Thread t = new Thread(new ThreadStart(serialRec));
                t.IsBackground = true;
                t.Start();
                
            }
            else
            {
                chk = true;
                GUIstate(1);
                serialPort1.Close();
            }
        }
        private void GUIstate(int mode)
        {
            if(mode == 0)
            {
                button1.Text = "Disconnect";
                button5.Enabled = false;
                button4.Enabled = false;
                button3.Enabled = false;
                button2.Enabled = false;
                comboBox1.Enabled = false;
                stop = false;
                label15.Text = comboBox1.SelectedItem.ToString();
                label16.Text = "Running Normally";
                label17.Text = "Receiving";
                label17.ForeColor = SystemColors.ControlText;
                if(Properties.Settings.Default.Enable == true)
                {
                    label18.Text = "Logging";
                    label19.Text = Properties.Settings.Default.Fpaths;
                }
                v[0] = -1; v[1] = -1; v[2] = -1; v[3] = -1;
                toolTip1.Active = false;
            }
            else
            {
                button1.Text = "Connect";
                button5.Enabled = true;
                button4.Enabled = true;
                button3.Enabled = true;
                button2.Enabled = true;
                comboBox1.Enabled = true;
                label15.Text = "Not connected";
                label16.Text = "Not connected";
                label16.ForeColor = SystemColors.ControlText;
                if (stop == true) label17.Text = "Timed out, aborted"; else label17.Text = "Idle";
                label18.Text = "N/A"; label19.Text = "N/A"; label2.Text = "N/A"; label3.Text = "N/A"; label6.Text = "N/A"; label8.Text = "N/A"; label20.Text = "N/A";
                verticalProgressBar1.Value = 0;
                verticalProgressBar2.Value = 0;
                verticalProgressBar3.Value = 0;
                verticalProgressBar4.Value = 0;
                foreach(var series in chart1.Series) { series.Points.Clear(); }
                toolTip1.Active = false;
                checkBox6.Visible = false;
            }
        }

        private void serialRec()
        {
            string delimiter = " ";
            if (Properties.Settings.Default.Enable == true)
            {
                if (File.Exists(Properties.Settings.Default.Fpaths + ".old") == true) File.Delete(Properties.Settings.Default.Fpaths + ".old");
                if (File.Exists(Properties.Settings.Default.Fpaths) == true) File.Move(Properties.Settings.Default.Fpaths, Properties.Settings.Default.Fpaths + ".old");
                try { using (var newfile = File.Create(Properties.Settings.Default.Fpaths)) ; }
                catch (Exception ex) when (ex is DirectoryNotFoundException || ex is ArgumentException)
                {
                    MessageBox.Show("Log file saving directory invalid or not set up. Please disconnect and verify the settings in 'Log File Settings' menu.", "Error");
                    return;
                }
                if (Properties.Settings.Default.Filter == 1) delimiter = ","; else delimiter = " ";
                if (Properties.Settings.Default.Check7 == true)
                {
                    if (Properties.Settings.Default.Check1 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "DT" + delimiter);
                    if (Properties.Settings.Default.Check10 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "RT" + delimiter);
                    if (Properties.Settings.Default.Check2 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "Temp" + delimiter);
                    if (Properties.Settings.Default.Check3 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "Hum" + delimiter);
                    if (Properties.Settings.Default.Check4 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "Light" + delimiter);
                    if (Properties.Settings.Default.Check5 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "Wspd" + delimiter);
                    if (Properties.Settings.Default.Check6 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "SDE" + delimiter);
                    if (Properties.Settings.Default.Check8 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "VE" + delimiter);
                    if (Properties.Settings.Default.Check9 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, "Wdir" + delimiter);
                    File.AppendAllText(Properties.Settings.Default.Fpaths, Environment.NewLine);
                }
            }
            while (!chk)
            {
                this.Invoke((MethodInvoker)delegate
                {
  /*DATA*/          string indata = ""; string errmsg = "";
                    try { indata = serialPort1.ReadLine(); }
                    catch(TimeoutException) {label17.ForeColor = Color.Red; alarm(); stop = true; GUIstate(1); chk = true;}
                    if (stop == true) return;
                    label21.Text = "Raw data: " + indata;
                    label23.Text = DateTime.Now.ToString();
                    string[] vin = indata.Split(' ');
                    label29.Text = "Run time: " + vin[0].ToString();

  /*TEMP*/          if (Convert.ToInt32(vin[1]) >= 0)
                    {
                        if (radioButton1.Checked == true) { verticalProgressBar1.Value = Convert.ToInt32(vin[1]); label2.Text = Convert.ToInt32(vin[1]) + "°C"; }
                        else { verticalProgressBar1.Value = Convert.ToInt32(vin[1]); label2.Text = ((Convert.ToInt32(vin[1]) * 9 / 5) + 32) + "°F"; }

                        if (verticalProgressBar1.Value >= Properties.Settings.Default.highA) verticalProgressBar1.ForeColor = Color.Red;
                        else if (verticalProgressBar1.Value >= Properties.Settings.Default.medA) verticalProgressBar1.ForeColor = Color.Orange;
                        else verticalProgressBar1.ForeColor = SystemColors.Highlight;

                        if(v[0] !=-1 && Math.Abs(v[0]-Convert.ToInt32(vin[1]))>=Properties.Settings.Default.chgA)
                        { label2.ForeColor = Color.Red; alarm(); }
                        else { label2.ForeColor = SystemColors.ControlText; }
                        v[0] = Convert.ToInt32(vin[1]);
                    }
                    else
                    {
                        label2.Text = "Error"; verticalProgressBar1.Value = 0;
                        errmsg = errmsg + "Temperature sensor error." + Environment.NewLine;
                        alarm();
                    }

   /*HUM*/          if (Convert.ToInt32(vin[2]) >= 0)
                    {
                        verticalProgressBar2.Value = Convert.ToInt32(vin[2]); label3.Text = Convert.ToInt32(vin[2]) + "%";

                        if (verticalProgressBar2.Value >= Properties.Settings.Default.highB) verticalProgressBar2.ForeColor = Color.Red;
                        else if (verticalProgressBar2.Value >= Properties.Settings.Default.medB) verticalProgressBar2.ForeColor = Color.Orange;
                        else verticalProgressBar2.ForeColor = SystemColors.Highlight;

                        if (v[1] != -1 && Math.Abs(v[1] - Convert.ToInt32(vin[2])) >= Properties.Settings.Default.chgB)
                        { label3.ForeColor = Color.Red; alarm(); }
                        else { label3.ForeColor = SystemColors.ControlText; }
                        v[1] = Convert.ToInt32(vin[2]);
                    }
                    else
                    {
                        label3.Text = "Error"; verticalProgressBar2.Value = 0;
                        errmsg = errmsg + "Humidity sensor error." + Environment.NewLine;
                        alarm();
                    }

   /*LIGHT*/        label6.Text = vin[3] + " lux";
                    verticalProgressBar3.Value = Convert.ToInt32(vin[3]);
                    if (verticalProgressBar3.Value >= Properties.Settings.Default.highC) verticalProgressBar3.ForeColor = Color.Red;
                    else if (verticalProgressBar3.Value >= Properties.Settings.Default.medC) verticalProgressBar3.ForeColor = Color.Orange;
                    else verticalProgressBar3.ForeColor = SystemColors.Highlight;
           
                    if (v[2] != -1 && Math.Abs(v[2] - Convert.ToInt32(vin[3])) >= Properties.Settings.Default.chgC)
                    { label6.ForeColor = Color.Red; alarm(); }
                    else { label6.ForeColor = SystemColors.ControlText; }
                    v[2] = Convert.ToInt32(vin[3]); 

   /*WSPD*/         label8.Text = vin[4];
                    verticalProgressBar4.Value = Convert.ToInt32(Convert.ToSingle(vin[4])*100);
                    if (Convert.ToSingle(label8.Text) >= Properties.Settings.Default.highD*100) verticalProgressBar4.ForeColor = Color.Red;
                    else if (Convert.ToSingle(label8.Text) >= Properties.Settings.Default.medD*100) verticalProgressBar4.ForeColor = Color.Orange;
                    else verticalProgressBar4.ForeColor = SystemColors.Highlight;

                    if (v[3] != -1 && Math.Abs(v[3] - Convert.ToInt32(Convert.ToSingle(vin[4]) * 100)) >= Properties.Settings.Default.chgD*100)
                    { label8.ForeColor = Color.Red; alarm(); }
                    else { label8.ForeColor = SystemColors.ControlText; }
                    v[3] = Convert.ToInt32(Convert.ToSingle(vin[4]) * 100);
                    label8.Text = vin[4] + " m/s";

   /*ERROR*/        if (Convert.ToInt32(vin[5]) == 1) errmsg = errmsg + "SD card initialize failed." + Environment.NewLine;
                    else if (Convert.ToInt32(vin[5]) == 2) errmsg = errmsg + "SD card is write protected." + Environment.NewLine;
                    else if (Convert.ToInt32(vin[5]) == 3) errmsg = errmsg + "SD card new file name not available." + Environment.NewLine;

                    if (Convert.ToInt32(vin[6]) == 1) errmsg = errmsg + "Device undervoltage." + Environment.NewLine;
                    else if (Convert.ToInt32(vin[6]) == 2) errmsg = errmsg + "Device overvoltage." + Environment.NewLine;

                    if (Convert.ToInt32(vin[1]) == -1|| Convert.ToInt32(vin[2]) == -1||Convert.ToInt32(vin[5]) != 0 || Convert.ToInt32(vin[6]) != 0)
                    {
                        label16.ForeColor = Color.Red;
                        label16.Text = "View errors...";
                        toolTip1.Active = true;
                        toolTip1.SetToolTip(label16, errmsg);
                        checkBox6.Visible = true;
                    }
                    else
                    {
                        label16.ForeColor = SystemColors.ControlText;
                        label16.Text = "Running Normally";
                        toolTip1.Active = false;
                        checkBox6.Visible = false;
                    }

   /*WDIR*/         label20.Text = vin[7];

   /*LOG*/          if (Properties.Settings.Default.Enable == true)
                    {
                        if (Properties.Settings.Default.Check1 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, DateTime.Now.ToString() + delimiter);
                        if (Properties.Settings.Default.Check10 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[0] + delimiter);
                        if (Properties.Settings.Default.Check2 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[1] + delimiter);
                        if (Properties.Settings.Default.Check3 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[2] + delimiter);
                        if (Properties.Settings.Default.Check4 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[3] + delimiter);
                        if (Properties.Settings.Default.Check5 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[4] + delimiter);
                        if (Properties.Settings.Default.Check8 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[5] + delimiter);
                        if (Properties.Settings.Default.Check9 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[6] + delimiter);
                        if (Properties.Settings.Default.Check6 == true) File.AppendAllText(Properties.Settings.Default.Fpaths, vin[7] + delimiter);
                        File.AppendAllText(Properties.Settings.Default.Fpaths, Environment.NewLine);
                    }

   /*GRAPH*/        if (chart1.Series["Temp"].Points.Count() > 150) chart1.Series["Temp"].Points.RemoveAt(0);
                    chart1.Series["Temp"].Points.Add(Convert.ToDouble(vin[1]));
                    if (chart1.Series["RH"].Points.Count() > 150) chart1.Series["RH"].Points.RemoveAt(0);
                    chart1.Series["RH"].Points.Add(Convert.ToDouble(vin[2]));
                    if (chart1.Series["Light"].Points.Count() > 150) chart1.Series["Light"].Points.RemoveAt(0);
                    chart1.Series["Light"].Points.Add(Convert.ToDouble(vin[3]));
                    if (chart1.Series["Wspd"].Points.Count() > 150) chart1.Series["Wspd"].Points.RemoveAt(0);
                    chart1.Series["Wspd"].Points.Add(Convert.ToDouble(vin[4]));
                    if (Convert.ToInt32(chart1.Series["Wspd"].Points[chart1.Series["Wspd"].Points.Count - 1].YValues[0]) != 0)
                    { chart1.Series["Wspd"].Points[chart1.Series["Wspd"].Points.Count - 1].Label = vin[7]; }
                    chart1.ResetAutoValues();
                }
            );
            Thread.Sleep(1500); 
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 foo = new Form2();
            foo.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 foo = new Form3();
            foo.ShowDialog();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true) chart1.Series["Temp"].Enabled = true;
            else chart1.Series["Temp"].Enabled = false;
            chart1.ResetAutoValues();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked == true) chart1.Series["RH"].Enabled = true;
            else chart1.Series["RH"].Enabled = false;
            chart1.ResetAutoValues();
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked == true) chart1.Series["Light"].Enabled = true;
            else chart1.Series["Light"].Enabled = false;
            chart1.ResetAutoValues();
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked == true) chart1.Series["Wspd"].Enabled = true;
            else chart1.Series["Wspd"].Enabled = false;
            chart1.ResetAutoValues();
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox5.Checked == true) { chart1.Series["Wspd"].LabelForeColor = Color.Black; chart1.Series["Wspd"].SmartLabelStyle.CalloutLineColor = Color.Black; }
            else { chart1.Series["Wspd"].LabelForeColor = Color.Transparent; chart1.Series["Wspd"].SmartLabelStyle.CalloutLineColor = Color.Transparent; }
            chart1.ResetAutoValues();
        }

        private void alarm()
        {
            SoundPlayer sound = new SoundPlayer(Properties.Resources.alarm);
            if(Properties.Settings.Default.mute==false) sound.Play();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            label2.Text = verticalProgressBar1.Value.ToString() + "°C";
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            label2.Text = ((verticalProgressBar1.Value * 9 / 5) + 32).ToString() + "°F";
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox6.Checked == true) Properties.Settings.Default.mute = true;
            else Properties.Settings.Default.mute = false;
        }
    }


    public class VerticalProgressBar : ProgressBar
    {
        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.Style |= 0x04;
                return cp;
            }
        }
    }

    namespace Serial
    {
        class Serial
        {
            public static void main()
            {
                string[] ports = SerialPort.GetPortNames();
                var form = Form.ActiveForm as Form1;
                form.comboBox1.Items.Clear();
                foreach (string port in ports)
                {
                    form.comboBox1.Items.Add(port);
                }
                try { form.comboBox1.SelectedIndex = 0; }
                catch (ArgumentOutOfRangeException)
                {
                    form.comboBox1.Items.Add("No connection");
                    form.comboBox1.SelectedIndex = 0;
                }
                
            }
        }
    }
}
