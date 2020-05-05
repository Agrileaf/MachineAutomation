using System;
using System.Windows.Forms;
using Automation.Businesslayer;
using Automation.Datalayer;

namespace Automation.Presentationlayer
{
    public partial class Registrform : Form
    {
        Regparamdll regparam = new Regparamdll();
        public Registrform()
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
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            regparam.Firstname =tbFname_regform.Text;
            regparam.Lastname =tbLname_regform.Text;
            regparam.Contact = tbContact_regform.Text;
            regparam.Gender = "Male";
            regparam.Useraddress = tbAddr_regform.Text;
            regparam.Question1 =cbQes1_regform.Text;
            regparam.Question2 =cbQes2_regform.Text;
            regparam.Username =tbUser_regform.Text;
            regparam.Password =tbPass_regform.Text;
            Registordll regpagedll = new Registordll();
            regpagedll.StoreRegparam(regparam);
            MessageBox.Show("Registration Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }
    }
}
