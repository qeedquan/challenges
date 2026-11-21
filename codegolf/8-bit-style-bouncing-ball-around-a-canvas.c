/*

Inspired by this listing from the Commodore 64 User's Guide:

10 PRINT "{CLR/HOME}"
20 POKE 53280,7 : POKE 53281,13
30 X = 1 : Y = 1
40 DX = 1 : DY = 1
50 POKE 1024 + X + 40 * Y, 81
60 FOR T = 1 TO 10 : NEXT
70 POKE 1024 + X + 40 * Y, 32
80 X = X + DX
90 IF X <= 0 OR X >= 39 THEN DX = -DX
100 Y = Y + DY
110 IF Y <= 0 OR Y >= 24 THEN DY = -DY
120 GOTO 50
Make a similar program in your chosen language/platform to bounce a ball-alike object around your terminal, screen, canvas or other visual display area.

You don't have to mimic the C64's PETSCII graphics exactly, a simple O or o will do, nor do you have to use the GOTO command if it exists in your language still. As long as your ball starts at the top of your canvas and travels diagonally until it hits a canvas limit, and then bounces accordingly, as follows:

Travelling downwards and right and hits the bottom of the screen area, bounces up and continues right;
Travelling up and right and hits the right-most boundary, and bounces left and up;
Travelling left and up and hits the top, bounces left and down;
Travelling left and down and reaches the left-most boundary, bounces right and down;
Hits any corner and reverses direction;
Then we're all good.

You don't have to move the ball 8-pixels at a time either, like is happening in the BASIC listing on the C64; you can move one character block or one pixel at a time, whichever you think is most appropriate.

To see this BASIC listing working, you can type it in with this online Commodore 64 emulator providing your browser supports JavaScript.

https://c64emulator.111mb.de/index.php?site=pp_javascript&lang=en&group=c64

*/

#include <stdio.h>
#include <signal.h>
#include <threads.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <err.h>

static volatile int run = 1;

void
sigint(int)
{
	run = 0;
}

void
clear()
{
	printf("\033c");
	fflush(stdout);
}

void
moveto(int x, int y)
{
	printf("\x1b[%d;%dH", x, y);
	fflush(stdout);
}

void
getdim(int *w, int *h)
{
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0)
		err(1, "ioctl");
	*w = ws.ws_row;
	*h = ws.ws_col;
}

void
sim()
{
	static const struct timespec delay = {
		.tv_nsec = 50000000,
	};

	int w, h;
	int x, y;
	int dx, dy;

	x = y = 0;
	dx = dy = 1;
	getdim(&w, &h);
	while (run) {
		clear();
		moveto(x, y);
		thrd_sleep(&delay, NULL);

		if (x < 1)
			dx = 1;
		else if (x > w)
			dx = -1;

		if (y < 1)
			dy = 1;
		else if (y > h)
			dy = -1;

		x += dx;
		y += dy;
	}
}

int
main()
{
	signal(SIGINT, sigint);
	sim();
	return 0;
}
