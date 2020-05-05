using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;


namespace Automation.Datalayer
{
    class Registordll
    {
        public void StoreRegparam(Regparamdll da)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserAdd", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Firstname", da.Firstname);
            Sqlcmd.Parameters.AddWithValue("@Lastname", da.Lastname);
            Sqlcmd.Parameters.AddWithValue("@Contact", da.Contact);
            Sqlcmd.Parameters.AddWithValue("@Gender", da.Gender);
            Sqlcmd.Parameters.AddWithValue("@Useraddress", da.Useraddress);
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", da.Question1);
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", da.Question2);
            Sqlcmd.Parameters.AddWithValue("@Username", da.Username);
            Sqlcmd.Parameters.AddWithValue("@Password", da.Password);
            Sqlcmd.ExecuteNonQuery();
        }
    }
}
