#include "Car.h"

using namespace std;

// Constructor & Destructor
Car::Car(string brand, double price, string model, string color, int numSeat)
    : Vehicle(brand, price, model), color(color), numSeat(numSeat) {
}

Car::~Car() {
    // Car destructor
}

// Getters & Setters
string Car::getColor() const {
    return color;
}

int Car::getNumSeat() const {
    return numSeat;
}

void Car::setColor(const string& color) {
    this->color = color;
}

void Car::setNumSeat(int numSeat) {
    this->numSeat = numSeat;
}

// Overridden methods
void Car::fuelConsumption() const {
    cout << "Car fuel consumption depends on engine size and driving conditions." << endl;
    cout << "This " << brand << " " << model << " has moderate fuel consumption." << endl;
}

void Car::displayInf() const {
    cout << "==== Car Information ====" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Price: $" << price << endl;
    cout << "Color: " << color << endl;
    cout << "Number of Seats: " << numSeat << endl;
    cout << "=========================" << endl;
} 