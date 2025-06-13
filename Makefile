# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++20

# Paths to Raylib includes and libraries
INCLUDE_PATH = -I./include/  # Path to header files
LIBRARY_PATH = -L./lib/ # Path to libraylib.a

# Libraries to link against (raylib and other dependencies)
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source files
SRC = $(wildcard src/*.cpp)


# Output executable
OUT = run

# Build target
all: $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) $(SRC) -o $(OUT) $(LIBRARY_PATH) $(LIBS)

# Clean target to remove the executable
clean:
	rm -f $(OUT)
