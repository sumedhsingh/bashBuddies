# But what is a Makefile?
# A makefile is a script used by the make build system which helps compile and link your program.
# It helps manage dependencies and makes it easy to compile your programs.

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Include directories
INCLUDES = -IC:/DevTools/curl-win64-latest/curl-8.9.1_3-win64-mingw/include -Iinclude

# Library directories
LIBDIRS = -LC:/DevTools/curl-win64-latest/curl-8.9.1_3-win64-mingw/lib

# Libraries
LIBS = -lcurl

# Source files
SOURCES = src/main.cpp src/weather.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = bashBuddies

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)



