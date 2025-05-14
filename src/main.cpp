#include <iostream>
#include "models/Vehicle.h"
#include "models/Car.h"
#include "models/Motorbike.h"
#include "models/Customer.h"
#include "models/GarageOwner.h"
#include "utils/Utils.h"

// Function prototypes
void handleGarageOwnerMenu(GarageOwner& owner);
void handleCustomerMenu(Customer& customer, GarageOwner& owner);

int main() {
    std::cout << "===== Welcome to Vehicle Market System =====" << std::endl;
    
    // Initialize the garage owner
    std::string ownerName = Utils::getStringInput("Enter garage owner name: ");
    GarageOwner garageOwner(ownerName);
    
    // Initialize the customer
    std::string customerName = Utils::getStringInput("Enter customer name: ");
    int customerContact = Utils::getIntInput("Enter customer contact: ", 0, 9999999);
    Customer customer(customerName, customerContact);
    
    // Sample data (optional)
    Car* sampleCar1 = new Car("Toyota", 25000, "Camry", "Blue", 5);
    Car* sampleCar2 = new Car("Honda", 28000, "Accord", "Red", 5);
    Motorbike* sampleBike = new Motorbike("Yamaha", 12000, "YZF", "V-Twin", 280);
    garageOwner.addVehicle(sampleCar1);
    garageOwner.addVehicle(sampleCar2);
    garageOwner.addVehicle(sampleBike);
    
    // Main menu loop
    bool running = true;
    while (running) {
        Utils::displayMainMenu();
        int choice = Utils::getIntInput("Enter your choice: ", 0, 2);
        
        switch (choice) {
            case 1:
                handleGarageOwnerMenu(garageOwner);
                break;
                
            case 2:
                handleCustomerMenu(customer, garageOwner);
                break;
                
            case 0:
                std::cout << "Thank you for using Vehicle Market System. Goodbye!" << std::endl;
                running = false;
                break;
        }
    }
    
    return 0;
}

void handleGarageOwnerMenu(GarageOwner& owner) {
    bool backToMain = false;
    
    while (!backToMain) {
        Utils::displayGarageOwnerMenu();
        int choice = Utils::getIntInput("Enter your choice: ", 0, 5);
        
        switch (choice) {
            case 1:
                Utils::addCarToGarage(owner);
                break;
                
            case 2:
                Utils::addMotorbikeToGarage(owner);
                break;
                
            case 3:
                owner.displayInventory();
                break;
                
            case 4:
                owner.sortByPrice();
                break;
                
            case 5:
                owner.sortByModel();
                break;
                
            case 0:
                backToMain = true;
                break;
        }
    }
}

void handleCustomerMenu(Customer& customer, GarageOwner& owner) {
    bool backToMain = false;
    
    while (!backToMain) {
        Utils::displayCustomerMenu();
        int choice = Utils::getIntInput("Enter your choice: ", 0, 2);
        
        switch (choice) {
            case 1:
                Utils::purchaseVehicleFromGarage(owner, customer);
                break;
                
            case 2:
                customer.displayPurchasedVehicles();
                break;
                
            case 0:
                backToMain = true;
                break;
        }
    }
} 