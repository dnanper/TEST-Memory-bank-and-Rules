# Vehicle Market System

An object-oriented C++ application that simulates a marketplace for vehicles, demonstrating inheritance, polymorphism, and dynamic memory management concepts.

## Features

- **Vehicle Hierarchy**: Base `Vehicle` class with specialized `Car` and `Motorbike` derivatives
- **Polymorphism**: Virtual methods for type-specific behaviors
- **Memory Management**: Manual allocation/deallocation using new/delete operators
- **Garage Owner Functionality**:
  - Add vehicles to inventory
  - Display inventory list
  - Sort vehicles by price or model
- **Customer Functionality**:
  - Purchase vehicles from garage owners
  - View purchased vehicles

## System Requirements

- C++11 compatible compiler (g++, MSVC, etc.)
- Make (optional - for building with the provided Makefile)

## Project Structure

```
vehicle-market/
├── src/
│   ├── models/            # Core class implementations
│   │   ├── Vehicle.h/cpp  # Base class for all vehicles
│   │   ├── Car.h/cpp      # Derived car class
│   │   ├── Motorbike.h/cpp # Derived motorbike class
│   │   ├── Customer.h/cpp # Customer class
│   │   └── GarageOwner.h/cpp # Garage owner class
│   ├── utils/             # Utility functions
│   │   ├── Utils.h/cpp    # Input validation and helper functions
│   └── main.cpp           # Main program entry point
├── Makefile               # Build configuration
└── README.md              # Project documentation
```

## Building the Project

### Using Make (Linux/macOS/MinGW on Windows)

To build the project with Make, run:

```bash
make
```

This will compile all source files and create the executable `vehicle_market` (or `vehicle_market.exe` on Windows).

To clean the build files:

```bash
make clean
```

To rebuild from scratch:

```bash
make rebuild
```

### Manual Build (Windows without Make)

If you don't have Make installed, you can build the project manually using g++:

1. Create the obj directories:

```powershell
mkdir obj\models obj\utils
```

2. Compile the source files:

```powershell
cd src
g++ -std=c++11 -c models/Vehicle.cpp models/Car.cpp models/Motorbike.cpp models/Customer.cpp models/GarageOwner.cpp utils/Utils.cpp main.cpp
```

3. Link the object files:

```powershell
g++ -o ../vehicle_market.exe Vehicle.o Car.o Motorbike.o Customer.o GarageOwner.o Utils.o main.o
```

4. Clean up object files (optional):

```powershell
del *.o
```

## Running the Application

After building, run the application:

**Linux/macOS:**

```bash
./vehicle_market
```

**Windows:**

```powershell
.\vehicle_market.exe
```

Follow the on-screen prompts to interact with the system.

## Usage Flow

1. Initialize with a garage owner and customer
2. Add vehicles to the garage inventory
3. As a customer, purchase vehicles from the garage
4. View and manage inventory/purchases through the menu system

## Memory Management

The application implements proper memory management:

- The `GarageOwner` class manages the memory for vehicles in inventory
- When a vehicle is sold, the ownership transfers to the `Customer`
- All dynamic memory is properly deallocated when objects are destroyed
