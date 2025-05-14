#ifndef GARAGE_OWNER_H
#define GARAGE_OWNER_H

#include "Vehicle.h"
#include <string>

class GarageOwner {
private:
    std::string name;
    Vehicle** inventory;
    int vehicleCount;
    int capacity;

public:
    // Constructor & Destructor
    GarageOwner(std::string name);
    ~GarageOwner();

    // Getters & Setters
    std::string getName() const;
    void setName(const std::string& name);
    int getVehicleCount() const;

    // Inventory management
    bool addVehicle(Vehicle* vehicle);
    bool removeVehicle(int index);
    Vehicle* getVehicle(int index) const;
    void displayInventory() const;
    void sortByPrice();
    void sortByModel();
};

#endif // GARAGE_OWNER_H 