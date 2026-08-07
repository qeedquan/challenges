CFLAGS=-Wall -Wextra -pedantic -ggdb -g3
CFLAGS+=`pkg-config --cflags sdl3`
CFLAGS+=-fsanitize=address
CFLAGS+=-Icommon/

LDFLAGS=`pkg-config --libs sdl3`
LDFLAGS+=-lm -lGL

SRC=common/*.c

all:
	cc -o objviewer $(CFLAGS) 00-objviewer/*.c $(SRC) $(LDFLAGS)
	cc -o curves-and-surfaces $(CFLAGS) 01-curves-and-surfaces/*.c $(SRC) $(LDFLAGS)

clean:
	rm -f objviewer
	rm -f curves-and-surfaces
