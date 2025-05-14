# 📘 Class Diagram Overview

## 🔹 Base Class: `Vehicle`

- **Attributes:**

  - `string brand`
  - `double price`
  - `string model`

- **Methods:**

  - Getters & Setters
  - `virtual void fuelConsumption()`
  - `virtual void displayInf()`
  - Constructor
  - Destructor

---

## 🔸 Derived Class: `Car` (inherits from `Vehicle`)

- **Attributes:**

  - `string color`
  - `int numSeat`

- **Methods:**

  - `string getColor()`
  - `int getNumSeat()`
  - `void setColor(string)`
  - `void setNumSeat(int)`
  - `void fuelConsumption() override`
  - `void displayInf() override`
  - Constructor
  - Destructor

---

## 🔸 Derived Class: `Motorbike` (inherits from `Vehicle`)

- **Attributes:**

  - `string engineType`
  - `double maxSpeed`

- **Methods:**

  - `string getEnType()`
  - `double getSpeed()`
  - `void setEnType(string)`
  - `void setSpeed(double)`
  - `void fuelConsumption() override`
  - `void displayInf() override`
  - Constructor
  - Destructor

---

## 🧍 Class: `Customer`

- **Attributes:**

  - `string name`
  - `int contact`
  - `Vehicle** arr[]` → stores purchased cars or bikes

- **Methods:**

  ...

---

## 🧑‍🔧 Class: `GarageOwner`

- **Attributes:**

  - `string name`
  - `Vehicle** arr[]` → stores available cars or bikes

- **Methods:**

  ...

---

## 🔧 Functional Highlights

- Garage owner can:

  - Add vehicles
  - Display list of all vehicles
  - Sort vehicles by price
  - Sort vehicles by model

- Customer can:

  - Buy car or bike (add to their own array)
  - Display purchased vehicles

---

## ✅ Notes

- All classes implement proper memory handling (constructors/destructors)
- Virtual methods allow polymorphism for `displayInf()` and `fuelConsumption()`
- Uses double pointer `Vehicle**` arrays to manage dynamic lists of vehicles
- Use Object Oriented Programming principles for design and implementation
