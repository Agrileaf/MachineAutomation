using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Automation.Datalayer;
using Automation.Presentationlayer;

namespace Automation.Businesslayer
{
    class Registrationbll
    {
		public bool Getregparam(Regparamdll datadll)
		{
            Registordll regpagedll = new Registordll();
            bool stat = false;
            if (datadll.male == true && datadll.female == true && datadll.others == true)
            {
                MessageBox.Show("Select only one from Gender", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (datadll.male == false && datadll.female == false && datadll.others == false)
            {
                MessageBox.Show("Select Gender", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (datadll.Firstname == null || datadll.Lastname == null || datadll.Contact == null || datadll.Useraddress == null ||
                datadll.Answer1 == null || datadll.Answer2 == null || datadll.Username == null || datadll.Password == null)
            {
                MessageBox.Show("Fill all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (datadll.Question1 == -1 || datadll.Question2 == -1)
            {
                MessageBox.Show("Select Question", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (datadll.Password != datadll.Retypepassword)
            {
                MessageBox.Show("retype password should be same", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (regpagedll.ReadUserparam(datadll.Username)==1)
            {
                MessageBox.Show("User Exists", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (datadll.male)
                {
                    datadll.Gender = "Male";
                }
                else if (datadll.female)
                {
                    datadll.Gender = "Female";
                }
                else if (datadll.others)
                {
                    datadll.Gender = "Other";
                }
                datadll.Password = EncodePasswordToBase64(datadll.Password);
               
                regpagedll.StoreRegparam(datadll);
                MessageBox.Show("Registration Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                Registrform regform = new Registrform();
                stat = true;
            }
            return stat;
        }

        public bool Checklogin(Readparamdb loginparam)
        {
            Registordll regpagedll = new Registordll();
            if (regpagedll.validatelogin(loginparam) == 1)
                return true;
            else
                return false;
        }

        public bool Checkreset(Regparamdll Resetparam)
        {
            bool Stat=false;
            Registordll regpagedll = new Registordll();
            if (Resetparam.Username == null && Resetparam.Answer1 == null && Resetparam.Answer2 == null)
            {
                MessageBox.Show("Fill all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Resetparam.Question1 == -1 || Resetparam.Question2 == -1) 
            {
                MessageBox.Show("Select Question", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (regpagedll.validatereset(Resetparam) == 1)
                {
                    Stat = true;
                    MessageBox.Show("Validation Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                }
                else
                {
                    Stat = false;
                    MessageBox.Show("Validation Fail", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            return Stat;
        }

        public void Savepassword(Readparamdb param)
        {
            Registordll regpagedll = new Registordll();
            param.password = EncodePasswordToBase64(param.password);
            regpagedll.Saveresetpass(param);
            MessageBox.Show("Save Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        public string EncodePasswordToBase64(string password)
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
