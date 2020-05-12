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
    class LoginfunctionsBll
    {
		public bool GetRegistrationdata(VariablesBll Registrationdata)
		{
            LoginfunctionsDll regpagedll = new LoginfunctionsDll();

            bool status = false;

            if (Registrationdata.GendertypeMale == false && Registrationdata.GendertypeFemale == false && Registrationdata.GendertypeOthers == false)
            {
                MessageBox.Show("Select Gender", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Registrationdata.FirstName == null || Registrationdata.LastName == null || Registrationdata.Contact == null || Registrationdata.UserAddress == null ||
                Registrationdata.Answer1 == null || Registrationdata.Answer2 == null || Registrationdata.Username == null || Registrationdata.Password == null)
            {
                MessageBox.Show("Fill all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Registrationdata.Question1 == -1 || Registrationdata.Question2 == -1)
            {
                MessageBox.Show("Select Question", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Registrationdata.Password != Registrationdata.RetypePassword)
            {
                MessageBox.Show("retype password should be same", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (regpagedll.ValidateUsername(Registrationdata.Username)==1)
            {
                MessageBox.Show("User Exists", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (Registrationdata.GendertypeMale)
                {
                    Registrationdata.Gender = "Male";
                }
                else if (Registrationdata.GendertypeFemale)
                {
                    Registrationdata.Gender = "Female";
                }
                else if (Registrationdata.GendertypeOthers)
                {
                    Registrationdata.Gender = "Other";
                }
                Registrationdata.Password = EncodePasswordToBase64(Registrationdata.Password);
               
                regpagedll.StoreRegistrationData(Registrationdata);
                MessageBox.Show("Registration Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                RegistrationForm regform = new RegistrationForm();
                status = true;
            }
            return status;
        }

        public bool CheckLogin(VariablesBll Loginparam)
        {
            LoginfunctionsDll regpagedll = new LoginfunctionsDll();
            if (regpagedll.ValidateLogin(Loginparam) == 1)
                return true;
            else
                return false;
        }

        public bool ValidateresetPassword(VariablesBll Resetparam)
        {
            bool Stat=false;
            LoginfunctionsDll regpagedll = new LoginfunctionsDll();
            if (Resetparam.Username == null && Resetparam.Answer1 == null && Resetparam.Answer2 == null)
            {
                MessageBox.Show("Fill all feilds", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (Resetparam.Question1 == -1 || Resetparam.Question2 == -1) 
            {
                MessageBox.Show("Select Question", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (regpagedll.ValidateUsername(Resetparam.Username) < 1)
            {
                MessageBox.Show("User not found", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (regpagedll.ValidateSecuriryquestion(Resetparam) == 1)
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

        public void SavePassword(VariablesBll param)
        {
            LoginfunctionsDll regpagedll = new LoginfunctionsDll();
            param.Password = EncodePasswordToBase64(param.Password);
            regpagedll.UpdatePassword(param);
            MessageBox.Show("Save Success", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        public string EncodePasswordToBase64(string password)
        {
            // try
            // {
            //      byte[] encData_byte = new byte[password.Length];
            //      encData_byte = System.Text.Encoding.UTF8.GetBytes(password);
            //      string encodedData = Convert.ToBase64String(encData_byte);
            //      return encodedData;
            // }
            // catch (Exception ex)
            //   {
            //      throw new Exception("Error in base64Encode" + ex.Message);
            //   }
            return password;
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
