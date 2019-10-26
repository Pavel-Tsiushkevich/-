using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "kntvbj";
           // string.ToUpper(str);
            Console.WriteLine(str.ToUpperInvariant);

           // char[] ar = new char[str.Length];
            //for (int i = 0; i < str.Length; i++)
            //{
            //    ar[i] = str[i];
            //}
            //Console.WriteLine(ar);
            //for(int i=0;i< str.Length; i++)
            //{
            //    
            //}
            //Console.WriteLine(ar);
            
            Console.ReadKey();
        }
    }
}
