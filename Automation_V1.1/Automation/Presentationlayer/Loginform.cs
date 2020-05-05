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
    public partial class Loginform : Form
    {


        public Loginform()
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
            
            Passresetform resetpassform = new Passresetform();
            resetpassform.Show();
            
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            
            Registrform regform = new Registrform();
            regform.Show(); 

        }

        private void btnSignin_Click(object sender, EventArgs e)
        {

        }
    }
}
