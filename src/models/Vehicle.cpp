#include "Vehicle.h"

using namespace std;

// Constructor & Destructor
Vehicle::Vehicle(string brand, double price, string model)
    : brand(brand), price(price), model(model) {
}

Vehicle::~Vehicle() {
    // Base class destructor
}

// Getters & Setters
string Vehicle::getBrand() const {
    return brand;
}

double Vehicle::getPrice() const {
    return price;
}

string Vehicle::getModel() const {
    return model;
}

void Vehicle::setBrand(const string& brand) {
    this->brand = brand;
}

void Vehicle::setPrice(double price) {
    this->price = price;
}

void Vehicle::setModel(const string& model) {
    this->model = model;
} 