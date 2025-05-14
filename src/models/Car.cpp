#include "Car.h"

// Constructor & Destructor
Car::Car(std::string brand, double price, std::string model, std::string color, int numSeat)
    : Vehicle(brand, price, model), color(color), numSeat(numSeat) {
}

Car::~Car() {
    // Car destructor
}

// Getters & Setters
std::string Car::getColor() const {
    return color;
}

int Car::getNumSeat() const {
    return numSeat;
}

void Car::setColor(const std::string& color) {
    this->color = color;
}

void Car::setNumSeat(int numSeat) {
    this->numSeat = numSeat;
}

// Overridden methods
void Car::fuelConsumption() const {
    std::cout << "Car fuel consumption depends on engine size and driving conditions." << std::endl;
    std::cout << "This " << brand << " " << model << " has moderate fuel consumption." << std::endl;
}

void Car::displayInf() const {
    std::cout << "==== Car Information ====" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Number of Seats: " << numSeat << std::endl;
    std::cout << "=========================" << std::endl;
} 