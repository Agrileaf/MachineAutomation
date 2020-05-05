using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Automation.DAL
{
    public class Connection
    {
        private const String ConnString = "Data Source=ATHISHAY-PC"+"\\"+"MSSQLSERVER02;Initial Catalog=LOGIN1;Integrated Security=True";
        public SqlConnection con = new SqlConnection(ConnString);

    }
}
