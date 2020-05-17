using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
using Automation.Datalayer;
using Automation.Businesslayer;
using System.Runtime.InteropServices.WindowsRuntime;

namespace Automation.Datalayer
{
    public class LoginfunctionsDll
    {

       private static SqlConnection ConnectDatabase = new SqlConnection("Data Source=ATHISHAY-PC" + "\\" + "MSSQLSERVER02;Initial Catalog=Automation;Integrated Security=True");
        
        public void StoreRegistrationData(VariablesBll resgistrationformFeild)
        {
            ConnectDatabase.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserLogin", ConnectDatabase);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Functionality", "ADDUSER");
            Sqlcmd.Parameters.AddWithValue("@Firstname", resgistrationformFeild.FirstName);
            Sqlcmd.Parameters.AddWithValue("@Lastname", resgistrationformFeild.LastName);
            Sqlcmd.Parameters.AddWithValue("@Contact", resgistrationformFeild.Contact);
            Sqlcmd.Parameters.AddWithValue("@Gender", resgistrationformFeild.Gender);
            Sqlcmd.Parameters.AddWithValue("@Useraddress", resgistrationformFeild.UserAddress);
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", resgistrationformFeild.Question1);
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", resgistrationformFeild.Question2);
            Sqlcmd.Parameters.AddWithValue("@Answer1", resgistrationformFeild.Answer1);
            Sqlcmd.Parameters.AddWithValue("@Answer2", resgistrationformFeild.Answer2);
            Sqlcmd.Parameters.AddWithValue("@Username", resgistrationformFeild.Username);
            Sqlcmd.Parameters.AddWithValue("@Password", resgistrationformFeild.Password);
            Sqlcmd.ExecuteNonQuery();
            ConnectDatabase.Close();
        }

        public int ValidateUsername(string username)
        {
            ConnectDatabase.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserLogin", ConnectDatabase);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Functionality", "VALIDATEUSERNAME");
            Sqlcmd.Parameters.AddWithValue("@Firstname", "");
            Sqlcmd.Parameters.AddWithValue("@Lastname", "");
            Sqlcmd.Parameters.AddWithValue("@Contact", "");
            Sqlcmd.Parameters.AddWithValue("@Gender", "");
            Sqlcmd.Parameters.AddWithValue("@Useraddress", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", "");
            Sqlcmd.Parameters.AddWithValue("@Answer1", "");
            Sqlcmd.Parameters.AddWithValue("@Answer2", "");
            Sqlcmd.Parameters.AddWithValue("@Username", username);
            Sqlcmd.Parameters.AddWithValue("@Password", "");
            int result = (int)Sqlcmd.ExecuteScalar();
            ConnectDatabase.Close();
            return result;
        }

        public int ValidateLogin(VariablesBll loginData)
        {
            ConnectDatabase.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserLogin", ConnectDatabase);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Functionality", "VALIDATELOGIN");
            Sqlcmd.Parameters.AddWithValue("@Firstname", "");
            Sqlcmd.Parameters.AddWithValue("@Lastname", "");
            Sqlcmd.Parameters.AddWithValue("@Contact", "");
            Sqlcmd.Parameters.AddWithValue("@Gender", "");
            Sqlcmd.Parameters.AddWithValue("@Useraddress", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", "");
            Sqlcmd.Parameters.AddWithValue("@Answer1", "");
            Sqlcmd.Parameters.AddWithValue("@Answer2", "");
            Sqlcmd.Parameters.AddWithValue("@Username", loginData.Username);
            Sqlcmd.Parameters.AddWithValue("@Password", loginData.Password);
            SqlDataReader Readdata = Sqlcmd.ExecuteReader();
            if (Readdata.Read())
                return 1;
            else
                return 0;
             
        }

        public int ValidateSecurityquestion(VariablesBll resetpasswordData)
        {
            ConnectDatabase.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserLogin", ConnectDatabase);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Functionality", "VALIDATESECURITYQUESTIONS");
            Sqlcmd.Parameters.AddWithValue("@Firstname", "");
            Sqlcmd.Parameters.AddWithValue("@Lastname", "");
            Sqlcmd.Parameters.AddWithValue("@Contact", "");
            Sqlcmd.Parameters.AddWithValue("@Gender", "");
            Sqlcmd.Parameters.AddWithValue("@Useraddress", "");
            Sqlcmd.Parameters.AddWithValue("@Password", "");
            Sqlcmd.Parameters.AddWithValue("@Username", resetpasswordData.Username);
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", resetpasswordData.Question1);
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", resetpasswordData.Question2);
            Sqlcmd.Parameters.AddWithValue("@Answer1", resetpasswordData.Answer1);
            Sqlcmd.Parameters.AddWithValue("@Answer2", resetpasswordData.Answer2);
            int result = (int)Sqlcmd.ExecuteScalar();
            ConnectDatabase.Close();
            return result;
        }

        public void UpdatePassword(VariablesBll loginParam)
        {
            ConnectDatabase.Open();
            SqlCommand Sqlcmd = new SqlCommand("UserLogin", ConnectDatabase);
            Sqlcmd.CommandType = CommandType.StoredProcedure;
            Sqlcmd.Parameters.AddWithValue("@Functionality", "UPDATEPASSWORD");
            Sqlcmd.Parameters.AddWithValue("@Firstname", "");
            Sqlcmd.Parameters.AddWithValue("@Lastname", "");
            Sqlcmd.Parameters.AddWithValue("@Contact", "");
            Sqlcmd.Parameters.AddWithValue("@Gender", "");
            Sqlcmd.Parameters.AddWithValue("@Useraddress", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q1", "");
            Sqlcmd.Parameters.AddWithValue("@Security_Q2", "");
            Sqlcmd.Parameters.AddWithValue("@Answer1", "");
            Sqlcmd.Parameters.AddWithValue("@Answer2", "");
            Sqlcmd.Parameters.AddWithValue("@Username", loginParam.Username);
            Sqlcmd.Parameters.AddWithValue("@Password", loginParam.Password);
            Sqlcmd.ExecuteNonQuery();
            
            ConnectDatabase.Close();
        }
    }
}
