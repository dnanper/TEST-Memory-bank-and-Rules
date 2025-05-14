#include "GarageOwner.h"
#include <iostream>
#include <algorithm>

// Constructor & Destructor
GarageOwner::GarageOwner(std::string name)
    : name(name), vehicleCount(0), capacity(20) {
    inventory = new Vehicle*[capacity];
    for (int i = 0; i < capacity; i++) {
        inventory[i] = nullptr;
    }
}

GarageOwner::~GarageOwner() {
    // Note: We're deleting the Vehicle objects here
    // since the GarageOwner is considered the owner
    for (int i = 0; i < vehicleCount; i++) {
        delete inventory[i];
    }
    delete[] inventory;
}

// Getters & Setters
std::string GarageOwner::getName() const {
    return name;
}

void GarageOwner::setName(const std::string& name) {
    this->name = name;
}

int GarageOwner::getVehicleCount() const {
    return vehicleCount;
}

// Inventory management
bool GarageOwner::addVehicle(Vehicle* vehicle) {
    if (vehicleCount >= capacity) {
        // Expand the array if needed
        int newCapacity = capacity * 2;
        Vehicle** newArray = new Vehicle*[newCapacity];
        
        // Copy existing pointers
        for (int i = 0; i < capacity; i++) {
            newArray[i] = inventory[i];
        }
        
        // Initialize the rest to nullptr
        for (int i = capacity; i < newCapacity; i++) {
            newArray[i] = nullptr;
        }
        
        // Delete old array and update
        delete[] inventory;
        inventory = newArray;
        capacity = newCapacity;
    }
    
    inventory[vehicleCount] = vehicle;
    vehicleCount++;
    std::cout << "Vehicle added to inventory successfully!" << std::endl;
    return true;
}

bool GarageOwner::removeVehicle(int index) {
    if (index < 0 || index >= vehicleCount) {
        std::cout << "Invalid vehicle index!" << std::endl;
        return false;
    }
    
    // We don't delete the Vehicle here because it might be transferred to a Customer
    // Just rearrange the inventory to fill the gap
    for (int i = index; i < vehicleCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    inventory[vehicleCount - 1] = nullptr;
    vehicleCount--;
    std::cout << "Vehicle removed from inventory." << std::endl;
    return true;
}

Vehicle* GarageOwner::getVehicle(int index) const {
    if (index < 0 || index >= vehicleCount) {
        return nullptr;
    }
    return inventory[index];
}

void GarageOwner::displayInventory() const {
    if (vehicleCount == 0) {
        std::cout << name << "'s garage has no vehicles in inventory." << std::endl;
        return;
    }
    
    std::cout << "===== " << name << "'s Garage Inventory =====" << std::endl;
    for (int i = 0; i < vehicleCount; i++) {
        std::cout << "\nVehicle " << (i + 1) << ":" << std::endl;
        inventory[i]->displayInf();
    }
    std::cout << "=====================================" << std::endl;
}

void GarageOwner::sortByPrice() {
    if (vehicleCount <= 1) {
        return;
    }
    
    // Use a simple bubble sort
    for (int i = 0; i < vehicleCount - 1; i++) {
        for (int j = 0; j < vehicleCount - i - 1; j++) {
            if (inventory[j]->getPrice() > inventory[j + 1]->getPrice()) {
                // Swap
                Vehicle* temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Inventory sorted by price (ascending)." << std::endl;
}

void GarageOwner::sortByModel() {
    if (vehicleCount <= 1) {
        return;
    }
    
    // Use a simple bubble sort
    for (int i = 0; i < vehicleCount - 1; i++) {
        for (int j = 0; j < vehicleCount - i - 1; j++) {
            if (inventory[j]->getModel() > inventory[j + 1]->getModel()) {
                // Swap
                Vehicle* temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Inventory sorted by model (alphabetically)." << std::endl;
} 