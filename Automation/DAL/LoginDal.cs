using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace Automation.DAL
{
    public class LoginDal
    {
        DataTable dt = new DataTable();
        public DataTable ReadLoginparam()
        {
            Connection conn = new Connection();
            if (ConnectionState.Closed == conn.con.State)
            {
                conn.con.Open();
            }
            SqlCommand cmd = new SqlCommand("Select * From USER_LOGIN_PAGE", conn.con);
            try
            {
                SqlDataReader rd = cmd.ExecuteReader();
                dt.Load(rd);
                return dt;
            }
            catch (Exception)
            {

                throw;
            }
           

        }

        public void InsertLogindata(String _password)
        {
            Connection conn = new Connection();
            if (ConnectionState.Closed == conn.con.State)
            {
                conn.con.Open();
            }
            SqlCommand cmd = new SqlCommand("Insert into USER_LOGIN_PAGE values('" +_password + "')", conn.con);
            try
            {
                SqlDataReader rd = cmd.ExecuteReader();
                dt.Load(rd);
            }
            catch (Exception)
            {

                throw;
            }
        }

    }
}
