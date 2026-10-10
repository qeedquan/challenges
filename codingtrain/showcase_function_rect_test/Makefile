CXXFLAGS=-Wall -Wextra -std=c23
LDFLAGS=`pkg-config --cflags --libs sdl3` -lm

all:
	cc $(CXXFLAGS) -o rect_test rect_test.c $(LDFLAGS)
	
clean:
	rm -f rect_test

