using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Automation.Datalayer
{
    //pulic to access variables on other files by creating object for class
    public class VariablesBll
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Contact { get; set; }
        public string Gender { get; set; }
        public string UserAddress { get; set; }
        public int Question1 { get; set; }
        public int Question2 { get; set; }
        public string Answer1 { get; set; }
        public string Answer2 { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
        public string RetypePassword { get; set; }
        public bool GendertypeMale { get; set; }
        public bool GendertypeFemale { get; set; }
        public bool GendertypeOthers { get; set; }
    }
}
