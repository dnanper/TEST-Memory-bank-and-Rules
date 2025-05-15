#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <limits>
#include <climits>
#include "../models/GarageOwner.h"
#include "../models/Customer.h"

using namespace std;

namespace Utils {
    // Input validation functions
    int getIntInput(const string& prompt, int min = INT_MIN, int max = INT_MAX);
    double getDoubleInput(const string& prompt, double min = -1000000.0, double max = 1000000.0);
    string getStringInput(const string& prompt);
    
    // Menu functions
    void displayMainMenu();
    void displayGarageOwnerMenu();
    void displayCustomerMenu();
    
    // Vehicle creation functions
    void addCarToGarage(GarageOwner& owner);
    void addMotorbikeToGarage(GarageOwner& owner);
    
    // Vehicle purchase function
    bool purchaseVehicleFromGarage(GarageOwner& owner, Customer& customer);
}

#endif // UTILS_H 