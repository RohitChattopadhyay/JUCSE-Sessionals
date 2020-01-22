namespace Assignment2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.viewTab = new System.Windows.Forms.TabPage();
            this.viewPgNo = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.tableLayoutPanel5 = new System.Windows.Forms.TableLayoutPanel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.insertTab = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.insertDept = new System.Windows.Forms.ComboBox();
            this.insertAddress = new System.Windows.Forms.TextBox();
            this.insertPhone = new System.Windows.Forms.TextBox();
            this.insertName = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.modifyTab = new System.Windows.Forms.TabPage();
            this.modifyMsg = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.button4 = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.modifyDeptCode = new System.Windows.Forms.TextBox();
            this.modifyAddress = new System.Windows.Forms.TextBox();
            this.modifyName = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.searchRoll = new System.Windows.Forms.TextBox();
            this.button5 = new System.Windows.Forms.Button();
            this.modifyPhone = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.tableLayoutPanel6 = new System.Windows.Forms.TableLayoutPanel();
            this.button8 = new System.Windows.Forms.Button();
            this.insertMsg = new System.Windows.Forms.Label();
            this.viewTab.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.tableLayoutPanel5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.insertTab.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.modifyTab.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            this.tableLayoutPanel6.SuspendLayout();
            this.SuspendLayout();
            // 
            // viewTab
            // 
            this.viewTab.Controls.Add(this.viewPgNo);
            this.viewTab.Controls.Add(this.label14);
            this.viewTab.Controls.Add(this.numericUpDown1);
            this.viewTab.Controls.Add(this.label13);
            this.viewTab.Controls.Add(this.label12);
            this.viewTab.Controls.Add(this.tableLayoutPanel5);
            this.viewTab.Controls.Add(this.dataGridView1);
            this.viewTab.Location = new System.Drawing.Point(4, 22);
            this.viewTab.Name = "viewTab";
            this.viewTab.Padding = new System.Windows.Forms.Padding(3);
            this.viewTab.Size = new System.Drawing.Size(768, 400);
            this.viewTab.TabIndex = 2;
            this.viewTab.Text = "VIEW";
            this.viewTab.UseVisualStyleBackColor = true;
            this.viewTab.Enter += new System.EventHandler(this.viewTab_Click);
            // 
            // viewPgNo
            // 
            this.viewPgNo.AutoSize = true;
            this.viewPgNo.Location = new System.Drawing.Point(92, 61);
            this.viewPgNo.Name = "viewPgNo";
            this.viewPgNo.Size = new System.Drawing.Size(0, 13);
            this.viewPgNo.TabIndex = 8;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(14, 61);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(72, 13);
            this.label14.TabIndex = 7;
            this.label14.Text = "Page Number";
            this.label14.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(715, 59);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            13,
            0,
            0,
            0});
            this.numericUpDown1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(50, 20);
            this.numericUpDown1.TabIndex = 6;
            this.numericUpDown1.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(615, 61);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(94, 13);
            this.label13.TabIndex = 5;
            this.label13.Text = "Records Per Page";
            // 
            // label12
            // 
            this.label12.Font = new System.Drawing.Font("Roboto", 15.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(0, 20);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(768, 23);
            this.label12.TabIndex = 4;
            this.label12.Text = "ALL RECORDS";
            this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel5
            // 
            this.tableLayoutPanel5.ColumnCount = 2;
            this.tableLayoutPanel5.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel5.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel5.Controls.Add(this.button1, 0, 0);
            this.tableLayoutPanel5.Controls.Add(this.button2, 1, 0);
            this.tableLayoutPanel5.Location = new System.Drawing.Point(0, 374);
            this.tableLayoutPanel5.Name = "tableLayoutPanel5";
            this.tableLayoutPanel5.RowCount = 1;
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel5.Size = new System.Drawing.Size(765, 27);
            this.tableLayoutPanel5.TabIndex = 3;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(3, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(376, 21);
            this.button1.TabIndex = 1;
            this.button1.Text = "PREVIOUS";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(385, 3);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(377, 21);
            this.button2.TabIndex = 2;
            this.button2.Text = "NEXT";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.HighlightText;
            this.dataGridView1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridView1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridView1.DefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridView1.Location = new System.Drawing.Point(0, 87);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(765, 284);
            this.dataGridView1.TabIndex = 0;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.viewTab);
            this.tabControl1.Controls.Add(this.insertTab);
            this.tabControl1.Controls.Add(this.modifyTab);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(776, 426);
            this.tabControl1.TabIndex = 0;
            // 
            // insertTab
            // 
            this.insertTab.Controls.Add(this.insertMsg);
            this.insertTab.Controls.Add(this.tableLayoutPanel1);
            this.insertTab.Controls.Add(this.label1);
            this.insertTab.Location = new System.Drawing.Point(4, 22);
            this.insertTab.Name = "insertTab";
            this.insertTab.Padding = new System.Windows.Forms.Padding(3);
            this.insertTab.Size = new System.Drawing.Size(768, 400);
            this.insertTab.TabIndex = 3;
            this.insertTab.Text = "INSERT";
            this.insertTab.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 27.97927F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 72.02073F));
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.label5, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.insertDept, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.insertAddress, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.insertPhone, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.insertName, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel6, 1, 4);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(137, 105);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 5;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(478, 145);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(3, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(127, 29);
            this.label3.TabIndex = 2;
            this.label3.Text = "NAME";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(3, 29);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(127, 25);
            this.label5.TabIndex = 6;
            this.label5.Text = "ADDRESS";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(3, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(127, 29);
            this.label2.TabIndex = 3;
            this.label2.Text = "DEPARTMENT";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(3, 87);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(127, 29);
            this.label4.TabIndex = 4;
            this.label4.Text = "PHONE NUMBER";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // insertDept
            // 
            this.insertDept.FormattingEnabled = true;
            this.insertDept.Items.AddRange(new object[] {
            "Computer Science Engineering",
            "Electronics and Telecommunication",
            "Civil Engineering",
            "Architecture"});
            this.insertDept.Location = new System.Drawing.Point(136, 61);
            this.insertDept.Name = "insertDept";
            this.insertDept.Size = new System.Drawing.Size(339, 21);
            this.insertDept.TabIndex = 10;
            // 
            // insertAddress
            // 
            this.insertAddress.Location = new System.Drawing.Point(136, 32);
            this.insertAddress.Multiline = true;
            this.insertAddress.Name = "insertAddress";
            this.insertAddress.Size = new System.Drawing.Size(339, 20);
            this.insertAddress.TabIndex = 9;
            // 
            // insertPhone
            // 
            this.insertPhone.Location = new System.Drawing.Point(136, 90);
            this.insertPhone.Name = "insertPhone";
            this.insertPhone.Size = new System.Drawing.Size(339, 20);
            this.insertPhone.TabIndex = 11;
            // 
            // insertName
            // 
            this.insertName.Location = new System.Drawing.Point(136, 3);
            this.insertName.Name = "insertName";
            this.insertName.Size = new System.Drawing.Size(339, 20);
            this.insertName.TabIndex = 8;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(3, 3);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(225, 23);
            this.button3.TabIndex = 12;
            this.button3.Text = "ADD STUDENT";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("Roboto", 15.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(0, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(768, 23);
            this.label1.TabIndex = 1;
            this.label1.Text = "Admission Form";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // modifyTab
            // 
            this.modifyTab.Controls.Add(this.modifyMsg);
            this.modifyTab.Controls.Add(this.label11);
            this.modifyTab.Controls.Add(this.tableLayoutPanel2);
            this.modifyTab.Location = new System.Drawing.Point(4, 22);
            this.modifyTab.Name = "modifyTab";
            this.modifyTab.Padding = new System.Windows.Forms.Padding(3);
            this.modifyTab.Size = new System.Drawing.Size(768, 400);
            this.modifyTab.TabIndex = 4;
            this.modifyTab.Text = "MODIFY";
            this.modifyTab.UseVisualStyleBackColor = true;
            // 
            // modifyMsg
            // 
            this.modifyMsg.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.modifyMsg.Location = new System.Drawing.Point(144, 285);
            this.modifyMsg.Name = "modifyMsg";
            this.modifyMsg.Size = new System.Drawing.Size(478, 23);
            this.modifyMsg.TabIndex = 5;
            this.modifyMsg.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label11
            // 
            this.label11.Font = new System.Drawing.Font("Roboto", 15.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(-4, 31);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(768, 23);
            this.label11.TabIndex = 4;
            this.label11.Text = "Modify Record";
            this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 27.97927F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 72.02073F));
            this.tableLayoutPanel2.Controls.Add(this.button4, 0, 5);
            this.tableLayoutPanel2.Controls.Add(this.label10, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.label8, 0, 4);
            this.tableLayoutPanel2.Controls.Add(this.label7, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.label6, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.modifyDeptCode, 1, 4);
            this.tableLayoutPanel2.Controls.Add(this.modifyAddress, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.modifyName, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel3, 1, 5);
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel4, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.modifyPhone, 1, 3);
            this.tableLayoutPanel2.Controls.Add(this.label9, 0, 3);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(144, 100);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 6;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(478, 154);
            this.tableLayoutPanel2.TabIndex = 3;
            // 
            // button4
            // 
            this.button4.Enabled = false;
            this.button4.Location = new System.Drawing.Point(3, 128);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(127, 23);
            this.button4.TabIndex = 0;
            this.button4.Text = "MODIFY";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click_1);
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(3, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(127, 25);
            this.label10.TabIndex = 12;
            this.label10.Text = "ENTER ROLL NUMBER";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(3, 100);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(127, 25);
            this.label8.TabIndex = 8;
            this.label8.Text = "DEPARTMENT CODE";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(3, 50);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(127, 25);
            this.label7.TabIndex = 10;
            this.label7.Text = "ADDRESS";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(3, 25);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(127, 25);
            this.label6.TabIndex = 7;
            this.label6.Text = "NAME";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // modifyDeptCode
            // 
            this.modifyDeptCode.Location = new System.Drawing.Point(136, 103);
            this.modifyDeptCode.Name = "modifyDeptCode";
            this.modifyDeptCode.ReadOnly = true;
            this.modifyDeptCode.Size = new System.Drawing.Size(339, 20);
            this.modifyDeptCode.TabIndex = 10;
            // 
            // modifyAddress
            // 
            this.modifyAddress.Location = new System.Drawing.Point(136, 53);
            this.modifyAddress.Name = "modifyAddress";
            this.modifyAddress.ReadOnly = true;
            this.modifyAddress.Size = new System.Drawing.Size(339, 20);
            this.modifyAddress.TabIndex = 9;
            // 
            // modifyName
            // 
            this.modifyName.Location = new System.Drawing.Point(136, 28);
            this.modifyName.Name = "modifyName";
            this.modifyName.ReadOnly = true;
            this.modifyName.Size = new System.Drawing.Size(339, 20);
            this.modifyName.TabIndex = 8;
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Controls.Add(this.button6, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.button7, 0, 0);
            this.tableLayoutPanel3.Location = new System.Drawing.Point(133, 125);
            this.tableLayoutPanel3.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(345, 29);
            this.tableLayoutPanel3.TabIndex = 11;
            // 
            // button6
            // 
            this.button6.Enabled = false;
            this.button6.Location = new System.Drawing.Point(175, 3);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(167, 23);
            this.button6.TabIndex = 1;
            this.button6.Text = "DELETE";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.Enabled = false;
            this.button7.Location = new System.Drawing.Point(3, 3);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(166, 23);
            this.button7.TabIndex = 2;
            this.button7.Text = "SAVE";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 2;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Controls.Add(this.searchRoll, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.button5, 1, 0);
            this.tableLayoutPanel4.Location = new System.Drawing.Point(133, 0);
            this.tableLayoutPanel4.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 1;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(345, 25);
            this.tableLayoutPanel4.TabIndex = 13;
            // 
            // searchRoll
            // 
            this.searchRoll.Location = new System.Drawing.Point(3, 3);
            this.searchRoll.Name = "searchRoll";
            this.searchRoll.Size = new System.Drawing.Size(166, 20);
            this.searchRoll.TabIndex = 5;
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(175, 2);
            this.button5.Margin = new System.Windows.Forms.Padding(3, 2, 3, 1);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(167, 22);
            this.button5.TabIndex = 6;
            this.button5.Text = "SEARCH";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // modifyPhone
            // 
            this.modifyPhone.Location = new System.Drawing.Point(136, 78);
            this.modifyPhone.Name = "modifyPhone";
            this.modifyPhone.ReadOnly = true;
            this.modifyPhone.Size = new System.Drawing.Size(339, 20);
            this.modifyPhone.TabIndex = 14;
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(3, 75);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(127, 25);
            this.label9.TabIndex = 9;
            this.label9.Text = "PHONE NUMBER";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // tableLayoutPanel6
            // 
            this.tableLayoutPanel6.ColumnCount = 2;
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 67.24638F));
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 32.75362F));
            this.tableLayoutPanel6.Controls.Add(this.button3, 0, 0);
            this.tableLayoutPanel6.Controls.Add(this.button8, 1, 0);
            this.tableLayoutPanel6.Location = new System.Drawing.Point(133, 116);
            this.tableLayoutPanel6.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel6.Name = "tableLayoutPanel6";
            this.tableLayoutPanel6.RowCount = 1;
            this.tableLayoutPanel6.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel6.Size = new System.Drawing.Size(345, 29);
            this.tableLayoutPanel6.TabIndex = 12;
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(234, 3);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(108, 23);
            this.button8.TabIndex = 13;
            this.button8.Text = "CLEAR";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // insertMsg
            // 
            this.insertMsg.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.insertMsg.Location = new System.Drawing.Point(137, 290);
            this.insertMsg.Name = "insertMsg";
            this.insertMsg.Size = new System.Drawing.Size(478, 23);
            this.insertMsg.TabIndex = 6;
            this.insertMsg.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "001710501073 | Assignment 2";
            this.viewTab.ResumeLayout(false);
            this.viewTab.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.tableLayoutPanel5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.insertTab.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.modifyTab.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel4.ResumeLayout(false);
            this.tableLayoutPanel4.PerformLayout();
            this.tableLayoutPanel6.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage viewTab;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage insertTab;
        private System.Windows.Forms.TabPage modifyTab;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox insertDept;
        private System.Windows.Forms.TextBox insertName;
        private System.Windows.Forms.TextBox insertAddress;
        private System.Windows.Forms.TextBox insertPhone;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox searchRoll;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TextBox modifyAddress;
        private System.Windows.Forms.TextBox modifyDeptCode;
        private System.Windows.Forms.TextBox modifyName;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox modifyPhone;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel5;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label viewPgNo;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label modifyMsg;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel6;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Label insertMsg;
    }
}

