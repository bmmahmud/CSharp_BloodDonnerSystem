using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data; 
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient; // added


namespace BloodDoner1
{
    public partial class Form1 : Form
    {
        MySqlConnection connection = new MySqlConnection(@"Data Source= localhost; port=3306;Initial Catalog= blood_db;User Id=root; password=''");  // connection
        MySqlCommand command;
        public Form1()
        {
            InitializeComponent();
        }

        private void Display_Load(object sender, EventArgs e)
        {
            populateDGV();
        }





        public void populateDGV()
        {
            // populate the datagridview
            string selectQuery;

           
            selectQuery = "SELECT * FROM reg_tb";
         
            DataTable table = new DataTable();
            MySqlDataAdapter adapter = new MySqlDataAdapter(selectQuery, connection);
            adapter.Fill(table);
            dataGridView_USERS.DataSource = table;
        }









        private void btnreg_Click(object sender, EventArgs e)
        {

            string insertQuery = "INSERT INTO reg_tb(Name, Mobile,Email,Address, BloodGrp) VALUES('" + textBoxName.Text + "','" + textBoxMobile.Text + "','" + textBoxEmail.Text + "','" + textBoxAddress.Text + "','" + textBoxBloodGrp.Text + "')";
            executeMyQuery(insertQuery);
            populateDGV();

        }

        private void dataGridView_USERS_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView_USERS_MouseClick(object sender, MouseEventArgs e)
        {
           
        }

        public void openConnection()
        {
            if (connection.State == ConnectionState.Closed)
            {
                connection.Open();
            }
        }

        public void closeConnection()
        {
            if (connection.State == ConnectionState.Open)
            {
                connection.Close();
            }
        }

        public void executeMyQuery(string query)
        {
            try
            {
                openConnection();
                command = new MySqlCommand(query, connection);

                if (command.ExecuteNonQuery() == 1)
                {
                    MessageBox.Show("Query Executed");
                }

                else
                {
                    MessageBox.Show("Query Not Executed");
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                closeConnection();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string updateQuery = "UPDATE reg_tb SET Name='" + textBoxName.Text + "',Mobile='" + textBoxMobile.Text + "',Email='" + textBoxEmail.Text + "',Address='" + textBoxAddress.Text + "',BloodGrp='" + textBoxBloodGrp.Text + "' WHERE Mobile =" + int.Parse(textBoxMobile.Text);
            executeMyQuery(updateQuery);
            populateDGV();
        }

        private void btnedit_Click(object sender, EventArgs e)
        {
            textBoxName.Text = dataGridView_USERS.CurrentRow.Cells[0].Value.ToString();
            textBoxMobile.Text = dataGridView_USERS.CurrentRow.Cells[1].Value.ToString();
            textBoxEmail.Text = dataGridView_USERS.CurrentRow.Cells[2].Value.ToString();
            textBoxAddress.Text = dataGridView_USERS.CurrentRow.Cells[3].Value.ToString();
            textBoxBloodGrp.Text = dataGridView_USERS.CurrentRow.Cells[4].Value.ToString();
        }

        private void btndelete_Click(object sender, EventArgs e)  // creating pblm
        {
            string deleteQuery = "DELETE FROM reg_tb WHERE Mobile = " + textBoxMobile.Text;
            executeMyQuery(deleteQuery);
            populateDGV();
        }

        private void btnsearch_Click(object sender, EventArgs e)
        {
            string selectQuery;

            List<string> bloodGrp = new List<string>(new string[] { "A+", "A-","B+" });
            if (bloodGrp.Where(x => string.Equals(textBox1.Text, x, StringComparison.OrdinalIgnoreCase)).Any())
            {
                selectQuery = "SELECT * FROM reg_tb WHERE BloodGrp= '" + textBox1.Text + "'";
                //selectQuery = "SELECT * FROM reg_tb WHERE BloodGrp = 'B+'";
                DataTable table = new DataTable();
                MySqlDataAdapter adapter = new MySqlDataAdapter(selectQuery, connection);
                adapter.Fill(table);
                dataGridView_USERS.DataSource = table;
                closeConnection();
            }
            else
            {

                MySqlDataReader mdr;
                string select;
                select = "SELECT * FROM reg_tb WHERE Mobile = " + textBox1.Text;

                command = new MySqlCommand(select, connection);
                openConnection();
                mdr = command.ExecuteReader(); // why this

                if (mdr.Read())
                {
                    textBoxName.Text = mdr.GetString("Name");
                    textBoxMobile.Text = mdr.GetInt32("Mobile").ToString();
                    textBoxEmail.Text = mdr.GetString("Email");

                    textBoxAddress.Text = mdr.GetString("Address");
                    textBoxBloodGrp.Text = mdr.GetString("bloodGrp");
                }
                else
                {
                    MessageBox.Show("User Not Found");
                }

                closeConnection();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            foreach (Control c in Controls)
            {
                if (c is TextBox)
                {
                    c.Text = "";
                }
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            clear(); // call the clear method for clearing the textboxes
            
        }

        void clear()  // add a mothod to clear the textboxes
        {
            textBoxName.Clear();
            textBoxMobile.Clear();
            textBoxEmail.Clear();
            textBoxAddress.Clear();
            textBoxBloodGrp.Text = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void radioButton7_CheckedChanged(object sender, EventArgs e) //nothing
        {

        }
    }
    }



