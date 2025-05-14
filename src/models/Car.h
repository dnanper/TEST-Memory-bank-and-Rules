#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string color;
    int numSeat;

public:
    // Constructor & Destructor
    Car(std::string brand, double price, std::string model, std::string color, int numSeat);
    ~Car() override;

    // Getters & Setters
    std::string getColor() const;
    int getNumSeat() const;
    void setColor(const std::string& color);
    void setNumSeat(int numSeat);

    // Overridden methods
    void fuelConsumption() const override;
    void displayInf() const override;
};

#endif // CAR_H 