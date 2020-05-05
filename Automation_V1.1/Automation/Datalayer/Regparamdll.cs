using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Automation.Datalayer
{
    class Regparamdll
    {
        public String Firstname { get; set; }
        public String Lastname { get; set; }
        public String Contact { get; set; }
        public String Gender { get; set; }
        public String Useraddress { get; set; }
        public int Question1 { get; set; }
        public int Question2 { get; set; }
        public String Answer1 { get; set; }
        public String Answer2 { get; set; }
        public String Username { get; set; }
        public String Password { get; set; }
        public String Retypepassword { get; set; }
        public bool male { get; set; }
        public bool female { get; set; }
        public bool others { get; set; }
    }

    class Readparamdb
    {
        public String username { get; set; }
        public String password { get; set; }
        public String Resetpass { get; set; }
    }
}
