CXXFLAGS=-Wall -Wextra -std=c23
LDFLAGS=`pkg-config --cflags --libs sdl3` -lm

all:
	cc $(CXXFLAGS) -o sensitive_squares sensitive_squares.c $(LDFLAGS)
	
clean:
	rm -f sensitive_squares

