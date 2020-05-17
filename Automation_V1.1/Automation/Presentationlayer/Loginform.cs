using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Automation.Datalayer;
using Automation.Businesslayer;

namespace Automation.Presentationlayer
{
    public partial class LoginForm : Form
    {

        VariablesBll Logindata = new VariablesBll();
        public LoginForm()
        {
            InitializeComponent();
        }

        private void Loginform_Load(object sender, EventArgs e)
        {

        }

        private void lbExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void lbResetpswd_Click(object sender, EventArgs e)
        {
            
            PasswordresetForm resetpassform = new PasswordresetForm();
            resetpassform.Show();
            
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            
            RegistrationForm RegistrationformObject = new RegistrationForm();
            RegistrationformObject.Show(); 

        }

        private void btnSignin_Click(object sender, EventArgs e)
        {
            Logindata.Username = tbUsername.Text;
            Logindata.Password = tbPassword.Text;
            LoginfunctionsBll LoginpageObject= new LoginfunctionsBll();
            if (LoginpageObject.CheckLogin(Logindata))
            {
                MessageBox.Show("Login Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                MainForm MainformObject = new MainForm();
                MainformObject.Show();
                tbPassword.Text = tbUsername.Text = null;
            }
            else
            {
                MessageBox.Show("Invalid login details", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }
    }
}
