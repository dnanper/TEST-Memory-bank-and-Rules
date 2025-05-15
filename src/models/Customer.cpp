#include "Customer.h"
#include "Car.h"
#include "Motorbike.h"
#include <iostream>

using namespace std;

// Constructor & Destructor
Customer::Customer(string name, int contact)
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
string Customer::getName() const {
    return name;
}

int Customer::getContact() const {
    return contact;
}

void Customer::setName(const string& name) {
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
    cout << "Vehicle purchased successfully!" << endl;
    return true;
}

void Customer::displayPurchasedVehicles() const {
    if (vehicleCount == 0) {
        cout << name << " has not purchased any vehicles yet." << endl;
        return;
    }
    
    cout << "===== " << name << "'s Purchased Vehicles =====" << endl;
    
    // First display all cars
    cout << "\n----- Cars -----" << endl;
    int carCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Car* car = dynamic_cast<Car*>(vehicles[i]);
        if (car) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            car->displayInf();
            carCount++;
        }
    }
    
    if (carCount == 0) {
        cout << "No cars purchased." << endl;
    }
    
    // Then display all motorbikes
    cout << "\n----- Motorbikes -----" << endl;
    int motorbikeCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Motorbike* motorbike = dynamic_cast<Motorbike*>(vehicles[i]);
        if (motorbike) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            motorbike->displayInf();
            motorbikeCount++;
        }
    }
    
    if (motorbikeCount == 0) {
        cout << "No motorbikes purchased." << endl;
    }
    
    cout << "==========================================" << endl;
} 