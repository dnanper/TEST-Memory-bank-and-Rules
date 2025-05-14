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
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    MKDIR = if not exist "$1" mkdir "$1"
    RM = rmdir /s /q
else
    MKDIR = mkdir -p $1
    RM = rm -rf
endif

all: directories $(TARGET)

# Create directories
directories:
	@echo "Creating directories..."
ifeq ($(OS),Windows_NT)
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	@if not exist "$(OBJ_DIR)\models" mkdir "$(OBJ_DIR)\models"
	@if not exist "$(OBJ_DIR)\utils" mkdir "$(OBJ_DIR)\utils"
else
	@mkdir -p $(OBJ_DIR)/models $(OBJ_DIR)/utils
endif

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Linking $@..."
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete!"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
ifeq ($(OS),Windows_NT)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<
else
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<
endif

# Clean build files
clean:
	@echo "Cleaning..."
ifeq ($(OS),Windows_NT)
	@if exist "$(OBJ_DIR)" rmdir /s /q "$(OBJ_DIR)"
	@if exist "$(TARGET)" del "$(TARGET)"
else
	@rm -rf $(OBJ_DIR) $(TARGET)
endif
	@echo "Clean complete!"

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild directories 