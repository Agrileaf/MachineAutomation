using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Naming_Conventions
{

    class Rules99    // 1. Identifier names can include alpha-numeric
    {
        public static void ShowMessage()
        {
            
        }
    }

    class Rules99Works    // 1. Identifier names can include alpha-numeric
    {
        public static void ShowMessage()
        {

        }
    }

    class Rul$%^^&es    // 2. Cannot include special chars except underscore
    {
        public static void ShowMessage()
        {

        }
    }

    class 99Rules    // 3. Must start with an alph / underscore NOT a no#
    {
        public static void ShowMessage()
        {

        }
    }

    class Rules   // 3. Must start with an alph / underscore NOT a no#
    {
       public static void ShowMessage()
       {

       }
    }

    class _Rules   // 3. Must start with an alph / underscore NOT a no#
    {
       public static void ShowMessage()
       {
            double busCap = 99999;  // 4. Choose easily readable identifier names
            Console.WriteLine("Business Capital is " + busCap.ToString());

            double businessCapital = 99999;  // 4. Choose easily readable identifier names
            Console.WriteLine("Business Capital is " + businessCapital.ToString());

            string strFirstName = "Guru Writes"; // 5. Avoid "Hungarian" notations 
            int iAge = 27;                      // 5. Avoid "Hungarian" notations 
            Console.WriteLine("Name is {0} and Age is {1}", strFirstName, iAge);

            string firstName = "Guru Writes";  // 5. Avoid "Hungarian" notations
            int age = 27;                      // 5. Avoid "Hungarian" notations
            Console.WriteLine("Name is {0} and Age is {1}", firstName, age);
        
    }

    class Rules  
    {
        public static void ShowMessage()   // 6. Favour readability over brevity
        {

        }
        public static void Message()   // 6. Favour readability over brevity
        {

        }
    }

}

}
