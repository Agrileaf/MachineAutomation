using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Automation.Presentationlayer
{
    public partial class Passresetform : Form
    {
        public Passresetform()
        {
            InitializeComponent();
            pnlResetpass.Visible = false;
        }

        private void btnRegistor_Click(object sender, EventArgs e)
        {
            pnlResetpass.Visible = true;
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
    }
}
