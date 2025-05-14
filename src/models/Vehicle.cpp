#include "Vehicle.h"

// Constructor & Destructor
Vehicle::Vehicle(std::string brand, double price, std::string model)
    : brand(brand), price(price), model(model) {
}

Vehicle::~Vehicle() {
    // Base class destructor
}

// Getters & Setters
std::string Vehicle::getBrand() const {
    return brand;
}

double Vehicle::getPrice() const {
    return price;
}

std::string Vehicle::getModel() const {
    return model;
}

void Vehicle::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Vehicle::setPrice(double price) {
    this->price = price;
}

void Vehicle::setModel(const std::string& model) {
    this->model = model;
} 