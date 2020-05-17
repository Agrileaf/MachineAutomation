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
    public partial class PasswordresetForm : Form
    {
        VariablesBll Passwordresetvariable = new VariablesBll();

        public PasswordresetForm()
        {
            InitializeComponent();
            pnlResetpass.Visible = false;
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            Passwordresetvariable.Question1 =cbQuest1_resetform.SelectedIndex;
            Passwordresetvariable.Question2 =cbQuest2_resetform.SelectedIndex;
            Passwordresetvariable.Answer1 =tbAnswer1_resetform.Text;
            Passwordresetvariable.Answer2 =tbAnswer2_resetform.Text;
            Passwordresetvariable.Username =tbuser_resetform.Text;
            LoginfunctionsBll registrationpageObject = new LoginfunctionsBll();
            if (registrationpageObject.ValidateresetPassword(Passwordresetvariable))
            {
                pnlResetpass.Visible = true;
            }
        }

        private void pnlResetpass_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Passresetform_Load(object sender, EventArgs e)
        {

        }

        private void lbExit3_Click(object sender, EventArgs e)
        {
            this.Close();
            tbpassword.Text = tbresetpass.Text = null;
            tbAnswer1_resetform.Text = tbAnswer2_resetform.Text = tbuser_resetform.Text = null;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Passwordresetvariable.Username = tbuser_resetform.Text;
            Passwordresetvariable.Password = tbpassword.Text;
            Passwordresetvariable.RetypePassword = tbresetpass.Text;
            if (Passwordresetvariable.Password != Passwordresetvariable.RetypePassword)
            {
                MessageBox.Show("Password do not match", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Passwordresetvariable.Password == null || Passwordresetvariable.RetypePassword == null)
            {
                MessageBox.Show("Enter all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                LoginfunctionsBll storepassword = new LoginfunctionsBll();
                storepassword.SavePassword(Passwordresetvariable);
                this.Close();
                tbpassword.Text = tbresetpass.Text = null;
                tbAnswer1_resetform.Text = tbAnswer2_resetform.Text = tbuser_resetform.Text = null;
            }
            
        }
    }
}
