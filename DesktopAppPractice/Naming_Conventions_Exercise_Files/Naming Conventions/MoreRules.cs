using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Naming_Conventions
{
    class MoreRules
    {
        public static void ShowMessage(double sellingPrice)
        {
            int i = 0;
            string firstName = "Gaurav";
            const int CurrentCricketScore = 99;

            Console.WriteLine("Value of i {0} and FirstName is {1}", i, firstName);
            Console.WriteLine("Current Cricket Score is " + CurrentCricketScore.ToString());

        }
    }
}
