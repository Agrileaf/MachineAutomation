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
    public partial class Passresetform : Form
    {
        Regparamdll resetparam = new Regparamdll();
        Readparamdb readparam = new Readparamdb();

        public Passresetform()
        {
            InitializeComponent();
            pnlResetpass.Visible = false;
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            resetparam.Question1 =cbQuest1_resetform.SelectedIndex;
            resetparam.Question2 =cbQuest2_resetform.SelectedIndex;
            resetparam.Answer1 =tbAnswer1_resetform.Text;
            resetparam.Answer2 =tbAnswer2_resetform.Text;
            resetparam.Username =tbuser_resetform.Text;
            Registrationbll regdll = new Registrationbll();
            if (regdll.Checkreset(resetparam))
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
        }

        private void button1_Click(object sender, EventArgs e)
        {
            readparam.username = tbuser_resetform.Text;
            readparam.password = tbpassword.Text;
            readparam.Resetpass = tbresetpass.Text;
            if (readparam.password != readparam.Resetpass)
            {
                MessageBox.Show("Password do not match", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (readparam.password == null || readparam.Resetpass == null)
            {
                MessageBox.Show("Enter all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Registrationbll savepass = new Registrationbll();
                savepass.Savepassword(readparam);
                this.Close();
            }
            
        }
    }
}
