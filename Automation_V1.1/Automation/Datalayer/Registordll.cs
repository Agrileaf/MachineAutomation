using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
using Automation.Datalayer;
using Automation.Businesslayer;

namespace Automation.Datalayer
{
    class Registordll
    {
        Registrationbll regpagebll = new Registrationbll();

        public void StoreRegparam(Regparamdll da)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("addUsers", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Firstname", da.Firstname);
            Sqlcmd.Parameters.AddWithValue("@Lastname", da.Lastname);
            Sqlcmd.Parameters.AddWithValue("@Contact", da.Contact);
            Sqlcmd.Parameters.AddWithValue("@Gender", da.Gender);
            Sqlcmd.Parameters.AddWithValue("@Useraddress", da.Useraddress);
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", da.Question1);
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", da.Question2);
            Sqlcmd.Parameters.AddWithValue("@Answer1", da.Answer1);
            Sqlcmd.Parameters.AddWithValue("@Answer2", da.Answer2);
            Sqlcmd.Parameters.AddWithValue("@Username", da.Username);
            Sqlcmd.Parameters.AddWithValue("@Password", da.Password);
            Sqlcmd.ExecuteNonQuery();
        }

        public int ReadUserparam(String username)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("Userchecking", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Username", username);
            int result = (Int32)Sqlcmd.ExecuteScalar();
            return result;
        }

        public int validatelogin(Readparamdb loginparam)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("loginchecking", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            String dat = regpagebll.EncodePasswordToBase64(loginparam.password);
            Sqlcmd.Parameters.AddWithValue("@Username", loginparam.username);
            Sqlcmd.Parameters.AddWithValue("@Password", dat);
            int result = (Int32)Sqlcmd.ExecuteScalar();
            return result;
        }

        public int validatereset(Regparamdll da)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("resetchecking", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Username", da.Username);
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", da.Question1);
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", da.Question2);
            Sqlcmd.Parameters.AddWithValue("@Answer1", da.Answer1);
            Sqlcmd.Parameters.AddWithValue("@Answer2", da.Answer2);
            int result = (Int32)Sqlcmd.ExecuteScalar();
            return result;
        }

        public void Saveresetpass(Readparamdb da)
        {
            Connectiondb conn = new Connectiondb();
            conn.con.Close();
            conn.con.Open();
            SqlCommand Sqlcmd = new SqlCommand("updatepass", conn.con);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            da.password = regpagebll.EncodePasswordToBase64(da.password);
            Sqlcmd.Parameters.AddWithValue("@Username", da.username);
            Sqlcmd.Parameters.AddWithValue("@Password", da.password);
            Sqlcmd.ExecuteNonQuery();
        }
    }
}
