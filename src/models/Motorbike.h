#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle {
private:
    std::string engineType;
    double maxSpeed;

public:
    // Constructor & Destructor
    Motorbike(std::string brand, double price, std::string model, std::string engineType, double maxSpeed);
    ~Motorbike() override;

    // Getters & Setters
    std::string getEnType() const;
    double getSpeed() const;
    void setEnType(const std::string& engineType);
    void setSpeed(double maxSpeed);

    // Overridden methods
    void fuelConsumption() const override;
    void displayInf() const override;
};

#endif // MOTORBIKE_H 