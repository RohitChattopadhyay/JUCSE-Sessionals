using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            result.Text = "";
            error.Text = "";
            if (double.TryParse(a.Text, out double A) && double.TryParse(b.Text, out double B))
            {
                result.Text = (A * B).ToString();
            }
            else
                error.Text = "Please Enter Numbers";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            result.Text = "";
            error.Text = "";
            if (double.TryParse(a.Text, out double A) && double.TryParse(b.Text, out double B))
            {
                if (B != 0)
                {
                    result.Text = (A / B).ToString();
                }
                else
                {
                    error.Text = "Cannot Divide with ZERO";
                }
            }
            else
                error.Text = "Please Enter Numbers";
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text += " | " + DateTime.Now.ToString();

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            result.Text = "";
            error.Text = "";
            if (double.TryParse(a.Text, out double A) && double.TryParse(b.Text, out double B))
            {
                result.Text = (A + B).ToString();
            }
            else
                error.Text = "Please Enter Numbers";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            result.Text = "";
            error.Text = ""; 
            if (double.TryParse(a.Text, out double A) && double.TryParse(b.Text, out double B))
            {
                result.Text = (A - B).ToString();
            }
            else
                error.Text = "Please Enter Numbers";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            error.Text = "";
            result.Text = "";
            a.Text = "";
            b.Text = "";
        }
    }
}
