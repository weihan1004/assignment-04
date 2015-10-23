# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

TARGET := main

SRC := $(wildcard *.cpp)

CXX := clang++
CXXFLAGS := -std=c++11

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall run

all: $(TARGET)

clean:
	-rm $(TARGET)

cleanall: clean

run: all
	./$(TARGET)

# -----------------------------------------------------------------------------

$(TARGET): $(SRC) $(wildcard *.h)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@
