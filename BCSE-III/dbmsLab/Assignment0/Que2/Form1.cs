using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment2
{
    public partial class Form1 : Form
    {
        private static int pagination_start = 0;
        private static int perPage = 5;
        private static string[] searchResults = new string[5];
        private static int[] endRoll = new int[4];
        private static string rollPath = "../../endRoll.txt";
        private static string dbPath = "../../database.csv";

        public Form1()
        {
            InitializeComponent();
            int i = 0;
            string[] lines = File.ReadAllLines(rollPath);
            foreach (string line in lines)
            {
                endRoll[i] = (int.Parse(line));
                i++;
            }
            AppDomain.CurrentDomain.ProcessExit += new EventHandler(OnProcessExit);
        }
        public static void writeEndRoll()
        {
            File.WriteAllText(rollPath, string.Join("\n", endRoll.Select(x => x.ToString()).ToArray()));
        }
        public string getNewRoll(int dept)
        {
            endRoll[dept]++;
            return (dept+201).ToString("D3") + endRoll[dept].ToString("D3");
        }
        public void writeRecord(string roll,string name,string add,int dept,string phone)
        {
            File.AppendAllText(dbPath, string.Format("{0};{1};{2};{3};{4}",roll,dept,name,add,phone) + Environment.NewLine);
        }
        public void readCSV()
        {
            viewPgNo.Text = (pagination_start + 1).ToString();
            if (pagination_start == 0)
                button1.Enabled = false;
            else
                button1.Enabled = true;

            var dt = new DataTable();
            dt.Columns.Add("ROLL");
            dt.Columns.Add("DEPARTMENT_CODE");
            dt.Columns.Add("STUDENT NAME");
            dt.Columns.Add("ADDRESS");
            dt.Columns.Add("PHONE");

            // Adding the rows
            int counter = 0;
            foreach (var line in File.ReadLines(dbPath).Skip(perPage * pagination_start).Take(perPage))
            {
                dt.Rows.Add(line.Split(';'));
                counter++;
            }
            if (counter == perPage)
                button2.Enabled = true;
            else
                button2.Enabled = false;
            dataGridView1.DataSource = dt;
        }        
        private void viewTab_Click(object sender, EventArgs e)
        {
            readCSV();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pagination_start--;
            readCSV();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pagination_start++;
            readCSV();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(searchRoll.Text) || searchRoll.Text.Length!=6)
            {
                modifyMsg.Text = "Enter 6 digit Roll Number";
            }
            else
            {
                modifyMsg.Text = "";
                string key = searchRoll.Text;
                bool found = false;
                string result = "";
                foreach (var line in File.ReadLines(dbPath))
                {
                    string sRoll = line.Split(';')[0];
                    if(sRoll == key)
                    {
                        result = line;
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    searchResults = result.Split(';');
                    modifyDeptCode.Text = searchResults[1];
                    modifyName.Text = searchResults[2];
                    modifyAddress.Text = searchResults[3];
                    modifyPhone.Text = searchResults[4];
                    
                    modifyName.ReadOnly = true;
                    modifyAddress.ReadOnly = true;
                    modifyPhone.ReadOnly = true;

                    button4.Enabled = true;
                    button6.Enabled = true;
                }
                else
                {
                    modifyMsg.Text = "Roll " + key + " NOT FOUND";
                    searchResults[0] = "";
                    searchResults[1] = "";
                    searchResults[2] = "";
                    searchResults[3] = "";
                    searchResults[4] = "";
                    modifyDeptCode.Text = searchResults[1];
                    modifyName.Text = searchResults[2];
                    modifyAddress.Text = searchResults[3];
                    modifyPhone.Text = searchResults[4];

                    button4.Enabled = false;
                    button6.Enabled = false;
                }
            }
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            perPage = Decimal.ToInt32(numericUpDown1.Value);
            readCSV();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (
                string.IsNullOrWhiteSpace(insertAddress.Text) ||
                string.IsNullOrWhiteSpace(insertDept.Text) ||
                string.IsNullOrWhiteSpace(insertName.Text) ||
                string.IsNullOrWhiteSpace(insertPhone.Text)
                )
            {
                MessageBox.Show("Please fill all the entries.", "Record Additon Form", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            string roll = getNewRoll(insertDept.SelectedIndex);
            writeRecord(roll, insertName.Text, insertAddress.Text, insertDept.SelectedIndex+201, insertPhone.Text);
            writeEndRoll();
            insertMsg.Text = "Student Added with Roll " + roll;
            ClearTextBoxes();
            insertDept.SelectedIndex = -1;
        }
        private void ClearTextBoxes()
        {
            Action<Control.ControlCollection> func = null;

            func = (controls) =>
            {
                foreach (Control control in controls)
                    if (control is TextBox)
                        (control as TextBox).Clear();
                    else
                        func(control.Controls);
            };

            func(Controls);
        }
        static void OnProcessExit(object sender, EventArgs e)
        {
            writeEndRoll();
        }

        private void deleteRecord(string roll)
        {
            string tempFile = Path.GetTempFileName();
            using (var sr = new StreamReader(dbPath))
            using (var sw = new StreamWriter(tempFile))
            {
                string line;

                while ((line = sr.ReadLine()) != null)
                {
                    if (line.Split(';')[0] != roll)
                        sw.WriteLine(line);
                }
            }

            File.Delete(dbPath);
            File.Move(tempFile, dbPath);
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            if (button4.Text == "MODIFY")
            {
                button4.Text = "CANCEL";
                button7.Enabled = true;
                modifyName.ReadOnly = false;
                modifyAddress.ReadOnly = false;
                modifyPhone.ReadOnly = false;
            }
            else
            {
                button4.Text = "MODIFY";
                modifyDeptCode.Text = searchResults[1];
                modifyName.Text = searchResults[2];
                modifyAddress.Text = searchResults[3];
                modifyPhone.Text = searchResults[4];
                modifyName.ReadOnly = true;
                modifyAddress.ReadOnly = true;
                modifyPhone.ReadOnly = true;
                button7.Enabled = false;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            deleteRecord(searchResults[0]);
            modifyMsg.Text = searchResults[0] + " has been removed";
            button4.Text = "MODIFY";
            searchResults[0] = "";
            searchResults[1] = "";
            searchResults[2] = "";
            searchResults[3] = "";
            searchResults[4] = "";
            modifyDeptCode.Text = searchResults[1];
            modifyName.Text = searchResults[2];
            modifyAddress.Text = searchResults[3];
            modifyPhone.Text = searchResults[4];
            modifyName.ReadOnly = true;
            modifyAddress.ReadOnly = true;
            modifyPhone.ReadOnly = true;
            searchRoll.Text = "";
            button4.Enabled = false;
            button7.Enabled = false;
            button6.Enabled = false;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (
               string.IsNullOrWhiteSpace(modifyAddress.Text) ||
               string.IsNullOrWhiteSpace(modifyName.Text) ||
               string.IsNullOrWhiteSpace(modifyPhone.Text)
               )
            {
                modifyMsg.Text = "Enter proper details";
            }
            else
            {
                string roll = searchResults[0];
                string deptCode = searchResults[1];
                string name = modifyName.Text;
                string address = modifyAddress.Text;
                string phone = modifyPhone.Text;
                deleteRecord(roll);
                writeRecord(roll, name, address, int.Parse(deptCode), phone);
                searchResults[2] = name;
                searchResults[3] = address;
                searchResults[4] = phone;

                modifyMsg.Text = searchResults[0] + " has been modified";
                button4.Text = "MODIFY";
                modifyName.ReadOnly = true;
                modifyAddress.ReadOnly = true;
                modifyPhone.ReadOnly = true;
                button7.Enabled = false;
                button6.Enabled = false;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            ClearTextBoxes();
        }
    }
}
