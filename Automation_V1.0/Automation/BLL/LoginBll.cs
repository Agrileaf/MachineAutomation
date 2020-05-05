using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automation.DAL;
using System.Data.SqlClient;

namespace Automation.BLL
{
    public class LoginBll
    {
        private const String ConnString = "Data Source=ATHISHAY-PC"+"\\"+"MSSQLSERVER02;Initial Catalog=LOGIN1;Integrated Security=True";
        SqlConnection conn = new SqlConnection(ConnString);

        public DataTable LoginUser(LoginDal da)
        {
            DataTable dt = new DataTable();
            conn.Close();
            conn.Open();
            String encodedString = EncodePasswordToBase64(da.Password);
            SqlCommand con = new SqlCommand("Select * from USER_LOGIN_PAGE where USERNAME = '" +da.Username+"' and PASSWORD = '"+ encodedString + "'",conn);
            SqlDataAdapter sda = new SqlDataAdapter(con);
            sda.Fill(dt);
            
            return dt;

        }

        public DataTable VarifyReset(LoginDal da)
        {
            DataTable dt = new DataTable();
            conn.Close();
            conn.Open();
            SqlCommand con = new SqlCommand("select *from RESET_LOGIN_PARM where Question1 = '" + da.Question1 + "' and Question2 = '" + da.Question2 + "' and Question3 = '" + da.Question3 + "'", conn);
            SqlDataAdapter sda = new SqlDataAdapter(con);
            sda.Fill(dt);
            return dt;

        }

        public DataTable ResetPassword(LoginDal da)
        {
            DataTable dt = new DataTable();
            conn.Close();
            conn.Open();
            String encodedPassword = EncodePasswordToBase64(da.ResetPass_F2);
            SqlCommand con = new SqlCommand("UPDATE USER_LOGIN_PAGE SET PASSWORD = @password", conn);
            con.Parameters.Add("password", encodedPassword);
            con.ExecuteNonQuery();
            return dt;
        }

        public static string EncodePasswordToBase64(string password)
        {
            try
            {
                byte[] encData_byte = new byte[password.Length];
                encData_byte = System.Text.Encoding.UTF8.GetBytes(password);
                string encodedData = Convert.ToBase64String(encData_byte);
                return encodedData;
            }
            catch (Exception ex)
            {
                throw new Exception("Error in base64Encode" + ex.Message);
            }
        } //this function Convert to Decord your Password
        public string DecodeFrom64(string encodedData)
        {
            System.Text.UTF8Encoding encoder = new System.Text.UTF8Encoding();
            System.Text.Decoder utf8Decode = encoder.GetDecoder();
            byte[] todecode_byte = Convert.FromBase64String(encodedData);
            int charCount = utf8Decode.GetCharCount(todecode_byte, 0, todecode_byte.Length);
            char[] decoded_char = new char[charCount];
            utf8Decode.GetChars(todecode_byte, 0, todecode_byte.Length, decoded_char, 0);
            string result = new String(decoded_char);
            return result;
        }
    }
}
