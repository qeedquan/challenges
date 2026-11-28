CXXFLAGS=-Wall -Wextra -std=c23
LDFLAGS=`pkg-config --cflags --libs sdl3` -lm

all:
	cc $(CXXFLAGS) -o rollover rollover.c $(LDFLAGS)
	
clean:
	rm -f rollover

