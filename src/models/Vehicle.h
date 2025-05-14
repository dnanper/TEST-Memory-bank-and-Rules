#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
protected:
    std::string brand;
    double price;
    std::string model;

public:
    // Constructor & Destructor
    Vehicle(std::string brand, double price, std::string model);
    virtual ~Vehicle();

    // Getters & Setters
    std::string getBrand() const;
    double getPrice() const;
    std::string getModel() const;
    void setBrand(const std::string& brand);
    void setPrice(double price);
    void setModel(const std::string& model);

    // Virtual methods
    virtual void fuelConsumption() const = 0;
    virtual void displayInf() const = 0;
};

#endif // VEHICLE_H 