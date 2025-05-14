CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = src
OBJ_DIR = obj

# Find all source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/models/*.cpp) $(wildcard $(SRC_DIR)/utils/*.cpp)
# Generate object file names from source files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
# Target executable
TARGET = vehicle_market

all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Linking $@..."
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete!"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create required directories
$(shell mkdir -p $(OBJ_DIR)/models $(OBJ_DIR)/utils)

# Clean build files
clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Clean complete!"

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild 