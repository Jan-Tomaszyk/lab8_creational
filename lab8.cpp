#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>

/*
#include <sstream>
#include <list>
#include <set>
#include <random>
#include <cstdlib>
#include <ctime>*/

using namespace std;

//z1
class DatabaseConnection
{
private:
    static DatabaseConnection * instance;
    //static std::mutex mutex_;
protected:
   DatabaseConnection(string value){value_=value;}
   ~DatabaseConnection() {}
   string value_;
public:
    DatabaseConnection(DatabaseConnection &other) = delete;
    void operator=(const DatabaseConnection &) = delete;

    static DatabaseConnection* getInstance(string value)
    {
        if (!instance)
        {
            instance = new DatabaseConnection(value);
        };
        return instance;
    }
    string value() const
    {
        return value_;
    }
};

//z2
class Vehicle
{
protected:
    string vehicleType;
public:
    Vehicle(string vehicleType) : vehicleType(vehicleType){}
    inline virtual void getVehicleType() const=0;
    enum VehicleType
    {
        Car,
        Bike
    };
};

class Car : public Vehicle
{
public:
    Car() : Vehicle("Car"){}
    inline virtual void getVehicleType() const
    {
        cout<<vehicleType<<endl;
    }

};

class Bike : public Vehicle
{
public:
    Bike() : Vehicle("Bike"){}
    inline virtual void getVehicleType() const
    {
        cout<<vehicleType<<endl;
    }
};

class VehicleFactory
{
public:
    static Vehicle* createVehicle(const Vehicle::VehicleType tt)
    {
        switch(tt)
        {
            case Vehicle::VehicleType::Car:
                cout<<"Buduje samochód!"<<std::endl;
                return new Car();
            case Vehicle::VehicleType::Bike:
                cout<<"Buduje Rower!"<<std::endl;
                return new Bike();
        }
    }
};

//z3
class Pizza {
    vector<std::string> parts;
public:
    Pizza(){}

    class Builder
    {
        Pizza* product;
    public:
        Builder()
        {
            this->Reset();
        }
        ~Builder()
        {
            delete product;
        }
        void Reset()
        {
            this->product= new Pizza();
        }

        Builder& setDough()
        {
            this->product->parts.push_back("ciasto pszeniczne");
        }

        Builder& setSauce()
        {
            this->product->parts.push_back("sos pomidorowy");
        }

        Builder& setTopping()
        {
            this->product->parts.push_back("ser, pomidor, oregano");
        }

        Pizza* build()//* - dodana
        {
            Pizza* result = (this->product);
            this->Reset();
            return result;
        }
    };
    class Director
    {
        //@var Builder
    private:
        Builder* builder;
    /**
     * The Director works with any builder instance that the client code passes
     * to it. This way, the client code may alter the final type of the newly
     * assembled product.
     */
    public:
        void set_builder(Builder* builder)
        {
            this->builder=builder;
        }
    /**
     * The Director can construct several product variations using the same
     * building steps.
     */
        void BuildMinimalViableProduct()
        {
            this->builder->setDough();
        }
    
        void BuildFullFeaturedProduct()
        {
            this->builder->setDough();
            this->builder->setSauce();
            this->builder->setTopping();
            //this->builder->set();
        }
    };


    void display()const
    {
        cout << "Części pizzy: ";
        for (size_t i=0; i<parts.size(); i++)
        {
            if(parts[i]== parts.back()){
                cout << parts[i];
            }
            else
            {
                cout << parts[i] << ", ";
            }
        }
        cout << "\n\n"; 
    }
};

//z4

DatabaseConnection* DatabaseConnection::instance = nullptr;

void z1()
{
    DatabaseConnection* connection1 = DatabaseConnection::getInstance("FOO");
    DatabaseConnection* connection2 = DatabaseConnection::getInstance("BAR");
    cout << "Czy obie instancje są takie same? " << (connection1 == connection2) << endl;
}

void z2()
{
    Vehicle* werT34 = VehicleFactory::createVehicle(Vehicle::VehicleType::Bike);
    
    cout<<"Wybudowano rower: ";
    werT34->getVehicleType();

    Vehicle* brama = VehicleFactory::createVehicle(Vehicle::VehicleType::Car);

    cout<<"Wybudowano auto: ";
    brama->getVehicleType();

    //cin.get();
}

void z3(Pizza::Director& director)
{
    Pizza::Builder* builder = new Pizza::Builder();
    director.set_builder(builder);
    cout << "niepełny produkt:\n"; 
    director.BuildMinimalViableProduct();
    
    Pizza* p= builder->build();
    p->display();
    delete p;

    cout << "Standard full featured product:\n"; 
    director.BuildFullFeaturedProduct();

    p= builder->build();
    p->display();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    cout << "Custom product:\n";
    builder->setDough();
    builder->setTopping();
    p=builder->build();
    p->display();
    delete p;

    delete builder;
}

int main()
{
    string kont = "T";
    while (kont == "T" || kont == "t")
    {
        int odp;
        cout << "Wybierz zadanie do aktywacji(1-3)";
        cin >> odp;
        switch (odp)
        {
        case 1:
            z1();
            break;
        case 2:
            z2();
            break;
        default:
            Pizza::Director* director= new Pizza::Director();
            z3(*director);
            delete director;
            break;
        }
        cout << "Czy chcesz kontynuacji?(T/N)";
        cin >> kont;
    }
    return 0;
}

