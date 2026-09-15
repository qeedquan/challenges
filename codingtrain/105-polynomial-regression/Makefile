CXXFLAGS=-Wall -Wextra -std=c++23 $(shell pkg-config --cflags --libs eigen3)
LDFLAGS=-lraylib -lX11 -lm

all:
	c++ $(CXXFLAGS) -o cubicfit cubicfit.cpp $(LDFLAGS)
	
clean:
	rm -f cubicfit

