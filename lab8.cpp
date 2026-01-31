#include <iostream>
#include <string>
#include <vector>
#include <memory>
/*
#include <sstream>
#include <list>
#include <set>
#include <random>
#include <cstdlib>
#include <ctime>*/

using namespace std;

//z1
class DatabaseConnection {

public:
    static DatabaseConnection* getInstance() {}

};

//z2
class Vehicle {

};

class Car : public Vehicle {

};

class Bike : public Vehicle {

};

class VehicleFactory {

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



void z1()
{
    cout << "Czy obie instancje są takie same? " << (connection1 == connection2) << endl;
}

void z2()
{
    cout << "Czy obie instancje są takie same? " << (connection1 == connection2) << endl;
}

void z1()
{
    cout << "Czy obie instancje są takie same? " << (connection1 == connection2) << endl;
}

int main()
{
    string kont = "T";
    while (kont == "T" || kont == "t")
    {
        int odp;
        cout << "Wybierz zestaw zadań do aktywacji";
        cin >> odp;
        switch (odp)
        {
        case 1:
            c
            break;
        default:
            break;
        }
        cout << "Czy chcesz kontynuacji?(T/N)";
        cin >> kont;
    }
    return 0;
}

