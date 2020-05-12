using System;
using System.Windows.Forms;
using Automation.Businesslayer;
using Automation.Datalayer;


namespace Automation.Presentationlayer
{
    public partial class RegistrationForm : Form
    {
        VariablesBll Registorationdata = new VariablesBll();
        public RegistrationForm()
        {
            InitializeComponent();
        }

        private void Registrform_Load(object sender, EventArgs e)
        {

        }

        private void lbExit2_Click(object sender, EventArgs e)
        {
            //this.Close();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void lbExit1_Click_1(object sender, EventArgs e)
        {
            this.Close();
            tbFname_regform.Text = tbLname_regform.Text = tbContact_regform.Text = tbAddr_regform.Text = cbQes1_regform.Text = cbQes2_regform.Text = null;
            tbUser_regform.Text = tbPass_regform.Text = tbretypepass_regform.Text = tbAns1_regform.Text = tbAns2_regform.Text = null;
            cbMale.CheckState = cbFemale.CheckState = cbOther.CheckState = CheckState.Unchecked;
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            Registorationdata.FirstName =tbFname_regform.Text;
            Registorationdata.LastName =tbLname_regform.Text;
            Registorationdata.Contact = tbContact_regform.Text;
            Registorationdata.UserAddress = tbAddr_regform.Text;
            Registorationdata.Question1 = cbQes1_regform.SelectedIndex;
            Registorationdata.Question2 = cbQes2_regform.SelectedIndex;
            Registorationdata.Username =tbUser_regform.Text;
            Registorationdata.Password =tbPass_regform.Text;
            Registorationdata.RetypePassword = tbretypepass_regform.Text;
            Registorationdata.Answer1 = tbAns1_regform.Text;
            Registorationdata.Answer2 = tbAns2_regform.Text;
            Registorationdata.GendertypeMale = cbMale.Checked;
            Registorationdata.GendertypeFemale = cbFemale.Checked;
            Registorationdata.GendertypeOthers = cbOther.Checked;

            LoginfunctionsBll regdll = new LoginfunctionsBll();
            if (regdll.GetRegistrationdata(Registorationdata))
            {
                this.Close();

                tbFname_regform.Text = tbLname_regform.Text = tbContact_regform.Text = tbAddr_regform.Text = cbQes1_regform.Text = cbQes2_regform.Text = null;
                tbUser_regform.Text = tbPass_regform.Text = tbretypepass_regform.Text = tbAns1_regform.Text = tbAns2_regform.Text = null;
                cbMale.CheckState = cbFemale.CheckState = cbOther.CheckState = CheckState.Unchecked;
            }
            

        }

        private void cbMale_CheckedChanged(object sender, EventArgs e)
        {
            if (cbMale.Checked)
            {
                cbFemale.CheckState = CheckState.Unchecked;
                cbOther.CheckState = CheckState.Unchecked;
            }
        }

        private void cbFemale_CheckedChanged(object sender, EventArgs e)
        {
            if (cbFemale.Checked)
            {
                cbMale.CheckState = CheckState.Unchecked;
                cbOther.CheckState = CheckState.Unchecked;
            }
        }

        private void cbOther_CheckedChanged(object sender, EventArgs e)
        {
            if (cbOther.Checked)
            {
                cbMale.CheckState = CheckState.Unchecked;
                cbFemale.CheckState = CheckState.Unchecked;
            }

        }
    }
}
