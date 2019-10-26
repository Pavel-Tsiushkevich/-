using System;
using System.Collections.Generic;

namespace ConsoleApp6
{
    partial class Program
    {
        public partial class Customer
        {
            public string name; 
            private int age = 18;    

            public int Age
            {
                get { return age; }
                set
                {
                    age = value;
                }
            }

            /*public int age { get; set; }*/
            /*public int age { private get; set; }*/

            public int ID { get; private set; }
            public readonly bool isCustomerRegistered;

            public static int count = 0;

            public Customer()
            {
                name = "Неизвестно";
                age = 0;
                Random random = new Random();
                ID = random.Next(0, 1000);
                Customer.count++;
                this.isCustomerRegistered = true;
            }     

            public Customer(string n)
            {
                name = n;
                age = 0;
                Random random = new Random();
                ID = random.Next(0, 1000);
                Customer.count++;
                this.isCustomerRegistered = true;
            }         

            public Customer(string name, int age)
            {
                this.name = name;
                this.age = age;
                Random random = new Random();
                ID = random.Next(0, 1000);
                Customer.count++;
                this.isCustomerRegistered = true;
            }

            public override string ToString()
            {
                return $"Имя: {this.name}  Возраст: {this.age} ID: {this.ID}";
            }
            public override bool Equals(object obj)
            {
                Customer otherCustomer = obj as Customer;
                if(otherCustomer != null)
                {
                    if(this.ID == otherCustomer.ID)
                    {
                        return true;
                    }
                }
                return false;
            }
            public override int GetHashCode()
            {
                return 3 * this.age * this.name.Length % 7;
            }


            public string GetName(ref Customer customer)
            {
                return customer.name;
            }


            public static void DisplayCountOfCustomers()
            {
                Console.WriteLine(Customer.count);
            }

            ~Customer()
            {
                Console.WriteLine("Customer goes out");
            }

            public Customer(Customer prevCustomer)
            {
                name = prevCustomer.name;
                ID = prevCustomer.ID;
                age = prevCustomer.age;
            }
        }

        public class CollectionManager
        {
            private static CollectionManager collectionManager;

            private CollectionManager()
            { }

            public static CollectionManager getInstance()
            {
                if (collectionManager == null)
                    collectionManager = new CollectionManager();
                return collectionManager;
            }


            public List<Customer> customers;
            public void AddCustomer(Customer customer)
            {
                this.customers.Add(customer);
            }
            public void RemoveCustomer(Customer customer)
            {
                this.customers.Remove(customer);
            }
            public bool Contains(Customer customer)
            {
                if (this.customers.Contains(customer))
                {
                    return true;
                }
                return false;
            }
            public List<Customer> GetNewCustomersList(Customer customer)
            {
                List<Customer> customers = this.customers;
                customers.Add(customer);
                return customers;
            }
            public int count
            {
                get
                {
                    return this.customers.Count;
                }
                set
                {

                }
            }
            public Customer this[int index]
            {
                get
                {
                    if(index >= this.customers.Count)
                    {
                        Console.WriteLine("Error");
                        return null;
                    }
                    else
                    {
                        return this.customers[index];
                    }
                }
                set
                {
                    if(index > this.customers.Count)
                    {
                        this.customers.Add(value);
                    }
                    else
                    {
                        this.customers[index] = value;
                    }
                }
            }

            public override string ToString()
            {
                return "This is CollectionManeger object";
            }
            public override bool Equals(object obj)
            {
                Console.WriteLine("There is only one CollectionManeger object");
                return false;
            }
            public override int GetHashCode()
            {
                return 7 * this.customers.Count % 3;
            }
        }

        public class StrangeDisposableThing : IDisposable
        {
            bool disposed = false;

            public void Dispose()
            {
                Dispose(true);
                GC.SuppressFinalize(this);
            }

            protected virtual void Dispose(bool disposing)
            {
                if (disposed)
                    return;

                if (disposing)
                {
                    Console.WriteLine("111");
                }
                
                disposed = true;
            }

            ~StrangeDisposableThing()
            {
                Dispose(false);
            }
        }

        static void Main(string[] args)
        {
            Customer tom = new Customer();
            tom.name = "Tom";
            tom.Age = 19;
            Console.WriteLine(tom.ToString());

            Customer nady = new Customer("Nady",25);
            Console.WriteLine(nady.ToString());

            Customer guk = new Customer("Vova");
            Console.WriteLine(guk.ToString());

            Customer tany = new Customer();
            Console.WriteLine(tany.ToString());
            
            var colManager = CollectionManager.getInstance();
            Console.WriteLine(colManager);
            var rider = CollectionManager.getInstance();
            Console.WriteLine(colManager.GetHashCode());

            var neGuk = new { Age = 19, name = "NeVova" };
            Console.WriteLine(neGuk);

//Console.WriteLine(neGuk.GetType());
        }
    }
}
