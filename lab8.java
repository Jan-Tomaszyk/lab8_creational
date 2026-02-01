


//z1

//import Pizza.PizzaBuilder;

class DatabaseConnection
{
    //System.out.println("executing query");
    private static DatabaseConnection single_instance = null;
    public String s;

    private DatabaseConnection()
    {
        s = "Hello I am a string part of Singleton class";
    }

    public static /*synchronized*/ DatabaseConnection getInstance()
    {
        if (single_instance == null)
            single_instance = new DatabaseConnection();

        return single_instance;
    }

    public void executeQuery(String query)
    {
        System.out.println(s);
        System.out.println("executing query");
        System.out.println(query);
    }
}

//z2
abstract class Vehicle
{
   public abstract void display();
   enum VehicleType
    {
        Car,
        Bike
    };
}

class Car extends Vehicle
{

    @Override
    public void display()
    {
        System.out.println("This is Car.");
    }
}

class Bike extends Vehicle
{
    @Override
    public void display() 
    {
        System.out.println("This is Bike.");
    }
}

class VehicleFactory
{
    public enum VehicleType { CAR, BIKE }

    public static Vehicle createVehicle(VehicleType type) {
        switch(type)
        {
            case CAR:
                System.out.println("Building a car!");
                return new Car();
            case BIKE:
                System.out.println("Building a bike!");
                return new Bike();
            default:
                throw new IllegalArgumentException("Unknown vehicle type");
        }
    }
}

//z3
class Pizza
{
    private final String ciasto;
    private final String sos;
    private final String wierzch;

    public Pizza(PizzaBuilder builder)
    {
        this.ciasto = builder.ciasto;
        this.sos = builder.sos;
        this.wierzch = builder.wierzch;
    }

    public static class PizzaBuilder
    {
        private String ciasto;
        private String sos;
        private String wierzch;
    

        public PizzaBuilder dough(String dough)
        {
           this.ciasto=dough;
           return this;
        }

        public PizzaBuilder sauce()
        {
           this.sos="pomidorowy";
           return this;
        }

        public PizzaBuilder topping()
        {
           this.wierzch="ser";
           return this;
        }

        public Pizza build()
        {
            return new Pizza(this);
        }
    }
    @Override
    public String toString()
    {
        return "ciasto = " + this.ciasto + ", sos = " + this.sos + 
                            ", wierzch = " + this.wierzch;
    }
}

class Director
{
    private Pizza.PizzaBuilder builder;
    public void constructMinimalViableProduct(Pizza.PizzaBuilder builder)
    {
        builder.dough("pszenne");
    }

    public void constructFullProduct(Pizza.PizzaBuilder builder)
    {
        builder.dough("pszenne");
        builder.sauce();
        builder.topping();
    }
/*     Pizza.PizzaBuilder getResult()
    {
        return builder;
    }*/
}



public class lab8 {

    public static void z1()
    {
        DatabaseConnection x = DatabaseConnection.getInstance();

        // Instantiating Singleton class with variable y
        DatabaseConnection y = DatabaseConnection.getInstance();

        // Instantiating Singleton class with variable z
        DatabaseConnection z = DatabaseConnection.getInstance();

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
        //VehicleFactory creatorA;
        Vehicle productA = VehicleFactory.createVehicle(VehicleFactory.VehicleType.CAR);
        productA.display();

        Vehicle productB = VehicleFactory.createVehicle(VehicleFactory.VehicleType.BIKE);
        productB.display();
    }
    
    public static void z3()
    {
        Director director = new Director();
        Pizza.PizzaBuilder builder = new Pizza.PizzaBuilder();
        
        director.constructMinimalViableProduct(builder);
        Pizza ciasto=builder.build();
        String pizza=ciasto.toString();        
        System.out.println(pizza);

        director.constructFullProduct(builder);
        Pizza produkt=builder.build();
        pizza=produkt.toString();        
        System.out.println(pizza);
    }
    
    public static void main(String[] args)
    {
        z1();
        z2();
        z3();        
    }
}
