CFLAGS=-Wall -Wextra
LDFLAGS=-lraylib -lX11 -lm

all:
	cc $(CFLAGS) -o basic basic.c $(LDFLAGS)
	cc $(CFLAGS) -o quadratic quadratic.c $(LDFLAGS)
	cc $(CFLAGS) -o cubic cubic.c $(LDFLAGS)

clean:
	rm -f basic quadratic cubic

