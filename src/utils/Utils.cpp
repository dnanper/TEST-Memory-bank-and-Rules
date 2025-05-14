#include "Utils.h"
#include "../models/Car.h"
#include "../models/Motorbike.h"
#include <iostream>
#include <limits>

namespace Utils {
    // Input validation functions
    int getIntInput(const std::string& prompt, int min, int max) {
        int input;
        bool isValid = false;
        
        do {
            std::cout << prompt;
            std::cin >> input;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            } else if (input < min || input > max) {
                std::cout << "Input must be between " << min << " and " << max << "." << std::endl;
            } else {
                isValid = true;
            }
        } while (!isValid);
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }
    
    double getDoubleInput(const std::string& prompt, double min, double max) {
        double input;
        bool isValid = false;
        
        do {
            std::cout << prompt;
            std::cin >> input;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            } else if (input < min || input > max) {
                std::cout << "Input must be between " << min << " and " << max << "." << std::endl;
            } else {
                isValid = true;
            }
        } while (!isValid);
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }
    
    std::string getStringInput(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }
    
    // Menu functions
    void displayMainMenu() {
        std::cout << "\n===== Vehicle Market System =====" << std::endl;
        std::cout << "1. Garage Owner Menu" << std::endl;
        std::cout << "2. Customer Menu" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "=================================" << std::endl;
    }
    
    void displayGarageOwnerMenu() {
        std::cout << "\n===== Garage Owner Menu =====" << std::endl;
        std::cout << "1. Add a Car to Inventory" << std::endl;
        std::cout << "2. Add a Motorbike to Inventory" << std::endl;
        std::cout << "3. Display Inventory" << std::endl;
        std::cout << "4. Sort Inventory by Price" << std::endl;
        std::cout << "5. Sort Inventory by Model" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "=============================" << std::endl;
    }
    
    void displayCustomerMenu() {
        std::cout << "\n===== Customer Menu =====" << std::endl;
        std::cout << "1. Purchase a Vehicle" << std::endl;
        std::cout << "2. Display Purchased Vehicles" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "=========================" << std::endl;
    }
    
    // Vehicle creation functions
    void addCarToGarage(GarageOwner& owner) {
        std::cout << "\n===== Adding a New Car =====" << std::endl;
        
        std::string brand = getStringInput("Enter brand: ");
        std::string model = getStringInput("Enter model: ");
        double price = getDoubleInput("Enter price ($): ", 0, 10000000);
        std::string color = getStringInput("Enter color: ");
        int numSeats = getIntInput("Enter number of seats: ", 1, 10);
        
        Car* newCar = new Car(brand, price, model, color, numSeats);
        owner.addVehicle(newCar);
    }
    
    void addMotorbikeToGarage(GarageOwner& owner) {
        std::cout << "\n===== Adding a New Motorbike =====" << std::endl;
        
        std::string brand = getStringInput("Enter brand: ");
        std::string model = getStringInput("Enter model: ");
        double price = getDoubleInput("Enter price ($): ", 0, 10000000);
        std::string engineType = getStringInput("Enter engine type: ");
        double maxSpeed = getDoubleInput("Enter maximum speed (km/h): ", 0, 500);
        
        Motorbike* newMotorbike = new Motorbike(brand, price, model, engineType, maxSpeed);
        owner.addVehicle(newMotorbike);
    }
    
    // Vehicle purchase function
    bool purchaseVehicleFromGarage(GarageOwner& owner, Customer& customer) {
        if (owner.getVehicleCount() == 0) {
            std::cout << "No vehicles available for purchase." << std::endl;
            return false;
        }
        
        owner.displayInventory();
        int vehicleIndex = getIntInput("Enter the number of the vehicle you want to purchase (0 to cancel): ", 0, owner.getVehicleCount()) - 1;
        
        if (vehicleIndex == -1) {
            std::cout << "Purchase canceled." << std::endl;
            return false;
        }
        
        Vehicle* selectedVehicle = owner.getVehicle(vehicleIndex);
        if (selectedVehicle == nullptr) {
            std::cout << "Invalid vehicle selection." << std::endl;
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