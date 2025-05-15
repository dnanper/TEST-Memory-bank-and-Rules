#include "Utils.h"
#include "../models/Car.h"
#include "../models/Motorbike.h"
#include <iostream>
#include <limits>

using namespace std;

namespace Utils {
    // Input validation functions
    int getIntInput(const string& prompt, int min, int max) {
        int input;
        bool isValid = false;
        
        do {
            cout << prompt;
            cin >> input;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
            } else if (input < min || input > max) {
                cout << "Input must be between " << min << " and " << max << "." << endl;
            } else {
                isValid = true;
            }
        } while (!isValid);
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return input;
    }
    
    double getDoubleInput(const string& prompt, double min, double max) {
        double input;
        bool isValid = false;
        
        do {
            cout << prompt;
            cin >> input;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
            } else if (input < min || input > max) {
                cout << "Input must be between " << min << " and " << max << "." << endl;
            } else {
                isValid = true;
            }
        } while (!isValid);
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return input;
    }
    
    string getStringInput(const string& prompt) {
        string input;
        cout << prompt;
        getline(cin, input);
        return input;
    }
    
    // Menu functions
    void displayMainMenu() {
        cout << "\n===== Vehicle Market System =====" << endl;
        cout << "1. Garage Owner Menu" << endl;
        cout << "2. Customer Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "=================================" << endl;
    }
    
    void displayGarageOwnerMenu() {
        cout << "\n===== Garage Owner Menu =====" << endl;
        cout << "1. Add a Car to Inventory" << endl;
        cout << "2. Add a Motorbike to Inventory" << endl;
        cout << "3. Display Inventory" << endl;
        cout << "4. Sort Inventory by Price" << endl;
        cout << "5. Sort Inventory by Model" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "=============================" << endl;
    }
    
    void displayCustomerMenu() {
        cout << "\n===== Customer Menu =====" << endl;
        cout << "1. Purchase a Vehicle" << endl;
        cout << "2. Display Purchased Vehicles" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "=========================" << endl;
    }
    
    // Vehicle creation functions
    void addCarToGarage(GarageOwner& owner) {
        cout << "\n===== Adding a New Car =====" << endl;
        
        string brand = getStringInput("Enter brand: ");
        string model = getStringInput("Enter model: ");
        double price = getDoubleInput("Enter price ($): ", 0, 10000000);
        string color = getStringInput("Enter color: ");
        int numSeats = getIntInput("Enter number of seats: ", 1, 10);
        
        Car* newCar = new Car(brand, price, model, color, numSeats);
        owner.addVehicle(newCar);
    }
    
    void addMotorbikeToGarage(GarageOwner& owner) {
        cout << "\n===== Adding a New Motorbike =====" << endl;
        
        string brand = getStringInput("Enter brand: ");
        string model = getStringInput("Enter model: ");
        double price = getDoubleInput("Enter price ($): ", 0, 10000000);
        string engineType = getStringInput("Enter engine type: ");
        double maxSpeed = getDoubleInput("Enter maximum speed (km/h): ", 0, 500);
        
        Motorbike* newMotorbike = new Motorbike(brand, price, model, engineType, maxSpeed);
        owner.addVehicle(newMotorbike);
    }
    
    // Vehicle purchase function
    bool purchaseVehicleFromGarage(GarageOwner& owner, Customer& customer) {
        if (owner.getVehicleCount() == 0) {
            cout << "No vehicles available for purchase." << endl;
            return false;
        }
        
        owner.displayInventory();
        int vehicleIndex = getIntInput("Enter the number of the vehicle you want to purchase (0 to cancel): ", 0, owner.getVehicleCount()) - 1;
        
        if (vehicleIndex == -1) {
            cout << "Purchase canceled." << endl;
            return false;
        }
        
        Vehicle* selectedVehicle = owner.getVehicle(vehicleIndex);
        if (selectedVehicle == nullptr) {
            cout << "Invalid vehicle selection." << endl;
            return false;
        }
        
        // Add to customer's purchases
        if (customer.purchaseVehicle(selectedVehicle)) {
            // Remove from owner's inventory without deleting the vehicle
            owner.removeVehicle(vehicleIndex);
            return true;
        }
        
        return false;
    }
} 