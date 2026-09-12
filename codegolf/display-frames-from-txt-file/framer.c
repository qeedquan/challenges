/*

The Task:
Given a .txt file with frames of ASCII art each separated by a \n (see this example if you are unclear) output a motion picture with frame with 1 frame per second.

Note that there is a trailing \n on the final frame.

Each frames dimensions will be:

X<80
Y<20
The Rules
The Previous frame must be cleared before the next is displayed, so just printing each frame onto the terminal isn't a valid answer.
New You can grab the file name however you want, either from it being stored in a variable or from sys args.
New The images must Loop indefinitely
This is code golf: smallest program wins.
Example
Input
0   0
0   0
00000
0   0
0   0

00000
0
00000
0
00000

0   0
 0 0
  0
  0
  0

Output

https://i.stack.imgur.com/tEy7a.gif

Un-golfed
import curses, time

stdscr = curses.initscr()

Frames = file.read(file('Frames.txt')).split('\n')
while True:
    y = 0
    for i in range(len(Frames)):
        stdscr.addstr(y,0,Frames[i])
        stdscr.refresh()
        y += 1
        if Frames[i] == '':
            y = 0
            stdscr.clear()
            time.sleep(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <err.h>
#include <ncurses.h>

volatile sig_atomic_t quit;

void
sighandle(int)
{
	quit = 1;
}

void
usage(void)
{
	fprintf(stderr, "usage: <framefile>\n");
	exit(2);
}

void
frame(WINDOW *win, FILE *fp)
{
	char line[256];
	int y;

	while (!quit) {
		y = 0;
		while (!quit && fgets(line, sizeof(line), fp)) {
			mvwaddstr(win, y, 0, line);
			wrefresh(win);
			y = (y + 1) % INT_MAX;
			if (line[0] == '\n') {
				y = 0;
				wclear(win);
				sleep(1);
			}
		}
		rewind(fp);
	}
}

int
main(int argc, char *argv[])
{
	WINDOW *win;
	FILE *fp;

	if (argc < 2)
		usage();

	signal(SIGTERM, sighandle);
	signal(SIGQUIT, sighandle);
	signal(SIGINT, sighandle);

	fp = fopen(argv[1], "rb");
	if (!fp)
		err(1, "open");

	win = initscr();
	if (!win)
		errx(1, "Failed to init screen");

	frame(win, fp);

	endwin();
	fclose(fp);

	return 0;
}
