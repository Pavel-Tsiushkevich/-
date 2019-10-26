using System;

namespace ConsoleApp5
{
    class Example : IDisposable
    {
        private readonly int _state;

        public Example(int state)
        {
            _state = state;
        }

        public int GetState() => _state;
        // Реализуем метод Dispose()
        public void Dispose()
        {
            Console.WriteLine("\n" + "Object is free!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            //Базовый уровень:

          /*  Console.Write("Enter name: ");
            string name = Console.ReadLine();
            Console.Write("Enter your age: ");
            int age = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter your height (m): ");
            double height = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter any short: ");
            short any = Convert.ToInt16(Console.ReadLine());
            Console.Write("True or false? ");
            bool i = Convert.ToBoolean(Console.ReadLine());
            Console.WriteLine($"Name: {name}  Age: {age}  Height: {height}m  Short: {any}  Tue or false? {i}$");

            int a = 11;
            object oInt = a; //упакрвка
            int A = (int)oInt; //распаковка
            char b = 'U';
            object oChar = b;
            char B = (char)oChar;

            int num = 5;
            double numD = num;
            byte numB = Convert.ToByte(num);

            string myName = "Yana";
            Console.WriteLine($"My mame is {myName}"); //интерполяция
            string output = String.Format("My name is {0}", myName);
            Console.WriteLine(output);

            var m = Environment.Version;
            Console.WriteLine("Тип m: " + m.GetType());
            string s = m.ToString();
            Console.WriteLine("My version .NET Framework: " + s);
            Console.WriteLine("{0} = {1}: {2}", m, name, m.Equals(name));

            string str1 = "String 1";
            string str2 = "String";
            Console.WriteLine(string.Compare(str1, str2));
            Console.WriteLine(str1.Contains(str2));
            Console.WriteLine(str2.Substring(2));
            Console.WriteLine(str1.Insert(7, "5"));
            Console.WriteLine(str2.Replace("r", "w"));

            string str3 = "";
            string str4 = null;
            Console.WriteLine(string.IsNullOrEmpty(str3));
            Console.WriteLine(string.IsNullOrEmpty(str4));

           

            dynamic variable = "";
            variable = 5;

            int? n = null;
            Nullable<int> n1 = 7;
            if (n.HasValue)
                Console.WriteLine(n.Value);
            else
                Console.WriteLine("n is equal to null");
            if (n1.HasValue)
                Console.WriteLine(n1.Value);
            else
                Console.WriteLine("n1 is equal to null");

            //Средний уровень:

            (int, int) turple = (1, 3);
            void Cort((int, int) c)
            {
                Console.WriteLine($"Cortage is " + c);
            }
            Cort(turple);

            var turple2 = (first: "one", second: 2, third: "threeee");
            Console.WriteLine($"{turple2.first} + {turple2.second} = {turple2.third}");
            (int z, string q, string u) turple3 = (666, "hell", "O");
            Console.WriteLine($"{turple3.u}, {turple3.q}{turple3.u}, {turple3.z}");
            var turple4 = (1, "wow", 45);
            Console.WriteLine($"{turple4.Item1} + {turple4.Item3} = 46");
            var (name1, age1) = ("Yana", 18);
            Console.WriteLine($"I'm {name1}, {age1} y.o.");

            var (_, pop1, _) = (89, 88, 98);

            Console.WriteLine();
            void FunChecked(int g, int f)
            {
                try
                {
                    var f1 = checked(g);
                    var f2 = checked(f);
                    int result;
                    checked
                    {
                        result = f1 * f2;
                        Console.WriteLine(f1 + " * " + f2 + " = " + result);
                    }
                }
                catch (OverflowException)
                {
                    Console.WriteLine("Overflow");
                }
            }
            void FunUnchecked(int g, int f)
            {
                try
                {
                    var f1 = unchecked(g);
                    var f2 = unchecked(f);
                    int result;
                    unchecked
                    {
                        result = f1 * f2;
                        Console.WriteLine(f1 + " * " + f2 + " = " + result);
                    }
                }
                catch (OverflowException)
                {
                    Console.WriteLine("Overflow");
                }
            }
            FunChecked(3, 6);
            FunChecked(3333333, 6666666);
            FunUnchecked(4, 5);
            FunUnchecked(444444, 55555);*/

            //Повышенный уровень:

            Example obj = new Example(4);
            obj.Dispose();
            Console.WriteLine(obj.GetState());
            Console.Read();
        }
    }
}
