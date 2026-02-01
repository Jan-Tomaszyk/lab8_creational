
//z1
class DatabaseConnection
{
    private static DatabaseConnection single_instance = null;
    public String s;

    private DatabaseConnection()
    {
        s = "Hello I am a string part of Singleton class";
    }

    public static /*synchronized*/ DatabaseConnection getInstance()
    {
        if (single_instance == null)
            single_instance = new Singleton();

        return single_instance;
    }

    public void executeQuery(String query)
    {
       println("executing query");
    }
}

//z2
abstract class Vehicle {
   
}

class Car extends Vehicle {
    
}

class Bike extends Vehicle {
  
}

class VehicleFactory {
  
}

//z3
class Pizza {
  
    private Pizza(PizzaBuilder builder) {
        
    }

    public static class PizzaBuilder {
        

        public PizzaBuilder dough(String dough) {
           
        }

        public PizzaBuilder sauce() {
           
        }

        public PizzaBuilder topping() {
           
        }

        public Pizza build() {

    }

    @Override
  
}


public class Main {
    /*public static void main(String[] args)
    {
        
    }*/
    public static void z1()
    {
        Singleton x = Singleton.getInstance();

        // Instantiating Singleton class with variable y
        Singleton y = Singleton.getInstance();

        // Instantiating Singleton class with variable z
        Singleton z = Singleton.getInstance();

        // Printing the hash code for above variable as
        // declared
        System.out.println("Hashcode of x is "
                           + x.hashCode());
        System.out.println("Hashcode of y is "
                           + y.hashCode());
        System.out.println("Hashcode of z is "
                           + z.hashCode());

        // Condition check
        if (x == y && y == z) {

            System.out.println(
                "Three objects point to the same memory location on the heap i.e, to the same object");
        }

        else
        {    
            System.out.println(
                "Three objects DO NOT point to the same memory location on the heap");
        }
    }
    public static void z2()
    {

    }
    public static void z3()
    {
        System.out.println(pizza);
    }
    public static void main(String[] args)
    {
        z1();
        z2();
        z3();        
    }
}
