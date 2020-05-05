using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Automation.BLL;
using Automation.DAL;



namespace Automation.PAL
{
    public partial class LoginForm : Form
    {
        LoginDal da = new LoginDal();
        LoginBll ba = new LoginBll();
        DataTable dt = new DataTable();
        public LoginForm()
        {
            InitializeComponent();
        }

      
        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void LoginPal_Load(object sender, EventArgs e)
        {

        }

        private void pnlPasseset_Paint(object sender, PaintEventArgs e)
        {

        }

        private void btnLogin_Click_1(object sender, EventArgs e)
        {
            da.Username = tbUsername.Text;
            da.Password = tbPswd.Text;
            dt = ba.LoginUser(da);
            if (dt.Rows.Count > 0)
            {
                tbUsername.Clear();
                tbPswd.Clear();
                MessageBox.Show("Login Success", "", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                this.Hide();
                MainForm Main_fm = new MainForm();
                Main_fm.Show();
            }
            else
            {
                MessageBox.Show("Invalid User or Password", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            pnlLogin.Visible = false;
            // pnlPasseset.Visible = false;
            PnlQuestion.Visible = true;
        }

        private void btn1Submit_Click(object sender, EventArgs e)
        {
            da.Question1 = tbQuestion1.Text;
            da.Question2 = tbQuestion2.Text;
            da.Question3 = tbQuestion3.Text;
            dt = ba.VarifyReset(da);
            if (dt.Rows.Count > 0)
            {
                tbQuestion1.Clear();
                tbQuestion2.Clear();
                tbQuestion3.Clear();
                //this.Hide();
                MessageBox.Show("Success", "", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                pnlLogin.Visible = false;
                pnlPasseset.Visible = true;
                PnlQuestion.Visible = false;
            }
            else
            {
                MessageBox.Show("Invalid answers", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void btn1Exit_Click(object sender, EventArgs e)
        {
            pnlLogin.Visible = true;
            pnlPasseset.Visible = true;
            PnlQuestion.Visible = true;
        }

        private void btn2Submit_Click(object sender, EventArgs e)
        {
            String password_A = tbPassword.Text;
            String password_B = tbresetPassword.Text;

            da.ResetPass_F1 = tbPassword.Text;
            da.ResetPass_F2 = tbresetPassword.Text;
            if (String.Equals(password_A, password_B))
            {
                ba.ResetPassword(da);
                MessageBox.Show("Success login Now ", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                pnlLogin.Visible = true;
                pnlPasseset.Visible = true;
                PnlQuestion.Visible = true;
            }
            else 
            {
                MessageBox.Show("Passwords do not match", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
