all:
	cc -Wall -Wextra -o quickdraw quickdraw.c -lraylib -lX11 -lm

gen:
	go run convert.go cat.json > cat.h 

clean:
	rm -f quickdraw

