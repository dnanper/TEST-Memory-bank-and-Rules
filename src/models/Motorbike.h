#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle {
private:
    string engineType;
    double maxSpeed;

public:
    // Constructor & Destructor
    Motorbike(string brand, double price, string model, string engineType, double maxSpeed);
    ~Motorbike() override;

    // Getters & Setters
    string getEnType() const;
    double getSpeed() const;
    void setEnType(const string& engineType);
    void setSpeed(double maxSpeed);

    // Overridden methods
    void fuelConsumption() const override;
    void displayInf() const override;
};

#endif // MOTORBIKE_H 