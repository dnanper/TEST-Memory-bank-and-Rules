#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Vehicle.h"
#include <string>

class Customer {
private:
    string name;
    int contact;
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;

public:
    // Constructor & Destructor
    Customer(string name, int contact);
    ~Customer();

    // Getters & Setters
    string getName() const;
    int getContact() const;
    void setName(const string& name);
    void setContact(int contact);

    // Vehicle management
    bool purchaseVehicle(Vehicle* vehicle);
    void displayPurchasedVehicles() const;
    int getVehicleCount() const;
};

#endif // CUSTOMER_H 