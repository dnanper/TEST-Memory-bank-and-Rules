#include "Customer.h"
#include <iostream>

// Constructor & Destructor
Customer::Customer(std::string name, int contact)
    : name(name), contact(contact), vehicleCount(0), capacity(10) {
    vehicles = new Vehicle*[capacity];
    for (int i = 0; i < capacity; i++) {
        vehicles[i] = nullptr;
    }
}

Customer::~Customer() {
    // Note: We don't delete the Vehicle objects themselves here,
    // as they might be referenced elsewhere in the system.
    // We only delete the array of pointers.
    delete[] vehicles;
}

// Getters & Setters
std::string Customer::getName() const {
    return name;
}

int Customer::getContact() const {
    return contact;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setContact(int contact) {
    this->contact = contact;
}

int Customer::getVehicleCount() const {
    return vehicleCount;
}

// Vehicle management
bool Customer::purchaseVehicle(Vehicle* vehicle) {
    if (vehicleCount >= capacity) {
        // Expand the array if needed
        int newCapacity = capacity * 2;
        Vehicle** newArray = new Vehicle*[newCapacity];
        
        // Copy existing pointers
        for (int i = 0; i < capacity; i++) {
            newArray[i] = vehicles[i];
        }
        
        // Initialize the rest to nullptr
        for (int i = capacity; i < newCapacity; i++) {
            newArray[i] = nullptr;
        }
        
        // Delete old array and update
        delete[] vehicles;
        vehicles = newArray;
        capacity = newCapacity;
    }
    
    vehicles[vehicleCount] = vehicle;
    vehicleCount++;
    std::cout << "Vehicle purchased successfully!" << std::endl;
    return true;
}

void Customer::displayPurchasedVehicles() const {
    if (vehicleCount == 0) {
        std::cout << name << " has not purchased any vehicles yet." << std::endl;
        return;
    }
    
    std::cout << "===== " << name << "'s Purchased Vehicles =====" << std::endl;
    for (int i = 0; i < vehicleCount; i++) {
        std::cout << "\nVehicle " << (i + 1) << ":" << std::endl;
        vehicles[i]->displayInf();
    }
    std::cout << "==========================================" << std::endl;
} 