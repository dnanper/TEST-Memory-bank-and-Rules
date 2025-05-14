#include "Motorbike.h"

// Constructor & Destructor
Motorbike::Motorbike(std::string brand, double price, std::string model, std::string engineType, double maxSpeed)
    : Vehicle(brand, price, model), engineType(engineType), maxSpeed(maxSpeed) {
}

Motorbike::~Motorbike() {
    // Motorbike destructor
}

// Getters & Setters
std::string Motorbike::getEnType() const {
    return engineType;
}

double Motorbike::getSpeed() const {
    return maxSpeed;
}

void Motorbike::setEnType(const std::string& engineType) {
    this->engineType = engineType;
}

void Motorbike::setSpeed(double maxSpeed) {
    this->maxSpeed = maxSpeed;
}

// Overridden methods
void Motorbike::fuelConsumption() const {
    std::cout << "Motorbike fuel consumption depends on the engine type and size." << std::endl;
    std::cout << "This " << brand << " " << model << " with " << engineType << " engine has efficient fuel consumption." << std::endl;
}

void Motorbike::displayInf() const {
    std::cout << "==== Motorbike Information ====" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Engine Type: " << engineType << std::endl;
    std::cout << "Maximum Speed: " << maxSpeed << " km/h" << std::endl;
    std::cout << "===============================" << std::endl;
} 