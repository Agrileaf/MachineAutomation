using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automation.DAL;

namespace Automation.BLL
{
    public class LoginBll
    {
		public DataTable GetLoginparam()
		{
			try
			{
				LoginDal objdal = new LoginDal();
				return objdal.ReadLoginparam();
			}
			catch
			{

				throw;
			}
		}
	}
}
