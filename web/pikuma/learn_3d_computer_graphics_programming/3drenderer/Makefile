build:
	gcc -Wall -std=c23 ./src/*.c `pkg-config --libs --cflags sdl3` -lm -o renderer -Wno-comment

run:
	./renderer

clean:
	rm renderer
