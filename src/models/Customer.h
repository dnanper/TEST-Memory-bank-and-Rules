#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Vehicle.h"
#include <string>

class Customer {
private:
    std::string name;
    int contact;
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;

public:
    // Constructor & Destructor
    Customer(std::string name, int contact);
    ~Customer();

    // Getters & Setters
    std::string getName() const;
    int getContact() const;
    void setName(const std::string& name);
    void setContact(int contact);

    // Vehicle management
    bool purchaseVehicle(Vehicle* vehicle);
    void displayPurchasedVehicles() const;
    int getVehicleCount() const;
};

#endif // CUSTOMER_H 