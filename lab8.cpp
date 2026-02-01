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
                std::cout<<"Buduje samochód!"<<std::endl;
                return new Car();
            case Vehicle::VehicleType::Bike:
                std::cout<<"Buduje Rower!"<<std::endl;
                return new Bike();
        }
    }
};

//z3
class Pizza {

public:
    class Builder {

    public:
        Builder& setDough() {

        }

        Builder& setSauce() {

        }

        Builder& setTopping() {

        }

        Pizza build() {

        }
    };


    void display() const {

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

void z3()
{

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
            z3();
            break;
        }
        cout << "Czy chcesz kontynuacji?(T/N)";
        cin >> kont;
    }
    return 0;
}

