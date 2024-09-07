# But what is a Makefile?
# A makefile is a script used by the make build system which helps compile and link your program.
# It helps manage dependencies and makes it easy to compile your programs.

# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = bashBuddies

# Define source files
SRCS = src/main.cpp

# Define object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target executable
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file to .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

