all:
	cc -Wall -Wextra -o calculator calculator.c $(shell pkg-config --cflags --libs sdl3) -lm

clean:
	rm -f calculator
