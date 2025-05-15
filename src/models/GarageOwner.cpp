#include "GarageOwner.h"
#include "Car.h"
#include "Motorbike.h"
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

// Constructor & Destructor
GarageOwner::GarageOwner(string name)
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
string GarageOwner::getName() const {
    return name;
}

void GarageOwner::setName(const string& name) {
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
    cout << "Vehicle added to inventory successfully!" << endl;
    return true;
}

bool GarageOwner::removeVehicle(int index) {
    if (index < 0 || index >= vehicleCount) {
        cout << "Invalid vehicle index!" << endl;
        return false;
    }
    
    // We don't delete the Vehicle here because it might be transferred to a Customer
    // Just rearrange the inventory to fill the gap
    for (int i = index; i < vehicleCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    inventory[vehicleCount - 1] = nullptr;
    vehicleCount--;
    cout << "Vehicle removed from inventory." << endl;
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
        cout << name << "'s garage has no vehicles in inventory." << endl;
        return;
    }
    
    cout << "===== " << name << "'s Garage Inventory =====" << endl;
    
    // First display all cars
    cout << "\n----- Cars -----" << endl;
    int carCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Car* car = dynamic_cast<Car*>(inventory[i]);
        if (car) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            car->displayInf();
            carCount++;
        }
    }
    
    if (carCount == 0) {
        cout << "No cars in inventory." << endl;
    }
    
    // Then display all motorbikes
    cout << "\n----- Motorbikes -----" << endl;
    int motorbikeCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Motorbike* motorbike = dynamic_cast<Motorbike*>(inventory[i]);
        if (motorbike) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            motorbike->displayInf();
            motorbikeCount++;
        }
    }
    
    if (motorbikeCount == 0) {
        cout << "No motorbikes in inventory." << endl;
    }
    
    cout << "=====================================" << endl;
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
    
    cout << "Inventory sorted by price (ascending)." << endl;
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
    
    cout << "Inventory sorted by model (alphabetically)." << endl;
} 