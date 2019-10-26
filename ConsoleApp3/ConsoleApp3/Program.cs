using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "fbfdn";

            Console.WriteLine(str);
            char[] ar = new char[str.Length];
            for (int i = 0; i < str.Length; i++)
            {
                
                ar[i] = str[i];
            }
            for (int i = 0; i < str.Length; i++)
            {
                Console.WriteLine(ar[i]);
            }
           
        }
    }
}
