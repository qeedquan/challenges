build:
	gcc -Wall -Wno-comment -std=c23 -o renderer ./src/*.c `pkg-config --cflags --libs sdl3` -lm

run:
	./renderer

clean:
	rm renderer
