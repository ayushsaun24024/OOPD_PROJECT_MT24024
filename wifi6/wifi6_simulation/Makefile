# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall
OPTFLAGS = -O3
DEBUGFLAGS = -g -O0
SHARED_FLAGS = -fPIC

# Target name
TARGET = bin/simulation
SHARED_LIB = lib/libsimulation.so

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Object files specifically for shared library (compiled with -fPIC)
SHARED_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%_shared.o, $(SRCS))

# Default target: build everything
all: directories optimized debug shared

# Create necessary directories
directories:
	mkdir -p bin lib $(OBJ_DIR)

# Compile optimized version
optimized: directories $(OBJS)
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -o $(TARGET) $(OBJS)

# Compile debug version
debug: directories $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o $(TARGET)_debug $(OBJS)

# Generate shared object file (.so)
shared: directories $(SHARED_OBJS)
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) -shared -o $(SHARED_LIB) $(SHARED_OBJS)

# Compile .cpp to .o (for static compilation)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile .cpp to .o (for shared library with -fPIC)
$(OBJ_DIR)/%_shared.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) -I$(INC_DIR) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TARGET)_debug $(SHARED_LIB) $(OBJ_DIR)/*.o

# Phony targets
.PHONY: all directories optimized debug shared clean
