CXXFLAGS=-Wall -std=c++23
LDFLAGS=`pkg-config --cflags --libs sdl3`

all:
	c++ $(CXXFLAGS) -o pi-collision pi-collision.cpp $(LDFLAGS)

clean:
	rm -f pi-collision

