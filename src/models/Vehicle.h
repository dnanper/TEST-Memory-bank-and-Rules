#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

using namespace std;

class Vehicle {
protected:
    string brand;
    double price;
    string model;

public:
    // Constructor & Destructor
    Vehicle(string brand, double price, string model);
    virtual ~Vehicle();

    // Getters & Setters
    string getBrand() const;
    double getPrice() const;
    string getModel() const;
    void setBrand(const string& brand);
    void setPrice(double price);
    void setModel(const string& model);

    // Virtual methods
    virtual void fuelConsumption() const = 0;
    virtual void displayInf() const = 0;
};

#endif // VEHICLE_H 