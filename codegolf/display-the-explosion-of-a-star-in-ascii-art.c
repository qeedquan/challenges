/*

The goal is to animate a star exploding in ASCII art, starting from a single star character * to a supernovae and finally to the space void.

Rules :

You have to display only 80 characters per line on 24 lines (this is the default terminal size on Linux)
Only these 95 printable characters from ASCII are allowed
Steps:
The initial star must be * and centred horizontally and vertically
The star has to grow to show that it explodes
At the end the screen must be empty (the star has disappeared)
Length of the code or languages are irrelevant
Votes will decide of the most creative and beautiful results. Have you ever seen an exploding star? Let's see how you imagine this.
I've added an answer using Python as an example, but you're encouraged to create something different or better.

You have one week to participate, the winner will be chosen on 2014-04-01.

Samples of output (with some frames only):

# start





                                        *





# during explosion

                                    ****#****
                                 ***#@##*#@#****
                               *@**@@@*##**#*#**#*
                              **@@*#**#@*#@****#***
                              ****@*@***#****@**@@*
                             *******@***@@***#****#*
                              *#***#*##@****##@@@**
                              **#@###****@*********
                               *****@**@*@*****@**
                                 ************@**
                                    ****#****


# star is expanding

                                        *
                               ********* **@******
                           ****   **#**@ #**#*#   ****
                         ***  **  **##** *@@*@*  **  ***
                       **  *  @@   *@*#* ***@*   *#  *  **
                     *** #  *  *#  *@#** ***@*  **  @  * *@*
                    ** *  * ** *@  ****@ @****  ** #* *  * **
                   ** * @* * ** *@  #### *#**  ** ** * @* * **
                  *# * # ** * #* *  **** ****  @ ** * ** * * #*
                 ** * *# * @ * #  @  @*@ *#*  *  @ # # * @* * **
                 *# * * * * # * @* * **# *#* * ** * * * * * # **
                 ** # * * @ * * # * # ** @* * * * * * # @ @ * **
                *# * * * * * * * * # * * * * * * @ @ * * * * * **
                 *# * @ * @ * @ * * * ** *@ * * # * * * * * @ @*
                 *# # @ * * # * *@ * *** @#@ @ ** * @ @ * * # **
                 *# * ** * * * @  @  **@ ***  *  @ * * * @* * #*
                  ** * * ** * #@ *  #*** **##  * #* * #@ * * @*
                   *# * *@ * @@ *#  **** @***  ** ** * #* * #*
                    *# *  * *@ **  @**@* *@#**  ** ** *  * @*
                     *#* @  *  @@  **##* ****@  **  #  * @**
                       **  @  #*   @*@#* @*@*#   @#  *  **
                         *#*  @*  @#*@*# **#*@#  **  ***
                           ****   *##**# #***@*   @***
                               ****@**@* *****@***

# star is disappearing

               *  -  -  --  --   ------- -------   --  --  -  -  *
             ** -  -  -  --  --   ------ ------   --  --  -  -  - **
            * -- - -- -- --  --   ------ ------   --  -- -- -- - -- *
          ** - -  - -- -- --  --  ------ ------  --  -- -- -- -  - - **
         *  - - -- - -- -  -  --   ----- -----   --  -  - -- - -- - -  *
        ** - - - -- - -- -  -  --  ----- -----  --  -  - -- - -- - - - **
        * - - - -  - - -  - -- --  ----- -----  -- -- -  - - -  - - - - *
       * - - - -  - - - -- - -- --  ---- ----  -- -- - -- - - -  - - - - *
      * -- - - - - - - - -- - -- -  ---- ----  - -- - -- - - - - - - - -- *
      * - - - - - - - -- - - - -  -  --- ---  -  - - - - -- - - - - - - - *
      * - - - - - - - - - - - - -- - --- --- - -- - - - - - - - - - - - - *
      * - - - - - - - - - - - - - - - -- -- - - - - - - - - - - - - - - - *
     * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
      * - - - - - - - - - - - - - - - -- -- - - - - - - - - - - - - - - - *
      * - - - - - - - - - - - - -- - --- --- - -- - - - - - - - - - - - - *
      * - - - - - - - -- - - - -  -  --- ---  -  - - - - -- - - - - - - - *
      * -- - - - - - - - -- - -- -  ---- ----  - -- - -- - - - - - - - -- *
       * - - - -  - - - -- - -- --  ---- ----  -- -- - -- - - -  - - - - *
        * - - - -  - - -  - -- --  ----- -----  -- -- -  - - -  - - - - *
        ** - - - -- - -- -  -  --  ----- -----  --  -  - -- - -- - - - **
         *  - - -- - -- -  -  --   ----- -----   --  -  - -- - -- - -  *
          ** - -  - -- -- --  --  ------ ------  --  -- -- -- -  - - **
            * -- - -- -- --  --   ------ ------   --  -- -- -- - -- *
             ** -  -  -  --  --   ------ ------   --  --  -  -  - **

# the star is gone
















(there is nothing)
Animated example of output:

https://i.sstatic.net/R3mLw.gif

If you want some inspiration, you can look at an effect from Captain Blood, a game from 1988.
https://www.youtube.com/watch?t=1m4s&v=NwN3x8GzzFc&feature=youtu.be

*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <curses.h>

// ported from @r3mainer solution

#define NUM_FRAMES 150
#define NUM_BLOBS 800
#define PERSPECTIVE 50.0

typedef struct {
	double x, y, z;
} spaceblob;

void *
xmalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		abort();
	return ptr;
}

double
prng()
{
	static long long s = 1;
	s = s * 1488248101 + 981577151;
	return ((s % 65536) - 32768) / 32768.0;
}

int
main()
{
	char *frames[NUM_FRAMES], *p;
	int i, j, x, y, v, rows, cols, i0;
	int maxx, minx, maxy, miny;
	double bx, by, bz, br, r;
	spaceblob *blobs;
	struct timespec delay = {
		.tv_nsec = 1000000000
	};

	// Initialize ncurses and get window dimensions
	initscr();
	getmaxyx(stdscr, rows, cols);
	minx = -cols / 2;
	maxx = cols + minx - 1;
	miny = -rows / 2;
	maxy = rows + miny - 1;

	// Generate random blob coordinates
	blobs = xmalloc(NUM_BLOBS * sizeof(spaceblob));
	for (i = 0; i < NUM_BLOBS; i++) {
		bx = prng();
		by = prng();
		bz = prng();
		br = sqrt(bx * bx + by * by + bz * bz);
		blobs[i].x = (bx / br) * (1.3 + 0.2 * prng());
		blobs[i].y = (0.5 * by / br) * (1.3 + 0.2 * prng());
		blobs[i].z = (bz / br) * (1.3 + 0.2 * prng());
	}

	// Generate animation frames
	for (i = 0; i < NUM_FRAMES; i++) {
		p = frames[i] = xmalloc(cols * rows + 1);
		for (y = miny; y <= maxy; y++) {
			for (x = minx; x <= maxx; x++) {

				// Show a single '*' in first frame
				if (i == 0) {
					*p++ = (x == 0 && y == 0) ? '*' : ' ';
					continue;
				}

				// Show expanding star in next 7 frames
				if (i < 8) {
					r = sqrt(x * x + 4 * y * y);
					*p++ = (r < i * 2) ? '@' : ' ';
					continue;
				}

				// Otherwise show blast wave
				r = sqrt(x * x + 4 * y * y) * (0.5 + (prng() / 3.0) * cos(16. * atan2(y * 2. + 0.01, x + 0.01)) * .3);
				v = i - r - 7;
				if (v < 0)
					*p++ = (i < 19) ? "%@W#H=+~-:."[i - 8] : ' '; // initial flash
				else if (v < 20)
					*p++ = " .:!HIOMW#%$&@08O=+-"[v];
				else
					*p++ = ' ';
			}
		}

		// Add blobs with perspective effect
		if (i > 6) {
			i0 = i - 6;
			for (j = 0; j < NUM_BLOBS; j++) {
				bx = blobs[j].x * i0;
				by = blobs[j].y * i0;
				bz = blobs[j].z * i0;
				if (bz < 5 - PERSPECTIVE || bz > PERSPECTIVE)
					continue;
				x = cols / 2 + bx * PERSPECTIVE / (bz + PERSPECTIVE);
				y = rows / 2 + by * PERSPECTIVE / (bz + PERSPECTIVE);
				if (x >= 0 && x < cols && y >= 0 && y < rows)
					frames[i][x + y * cols] = (bz > 40) ? '.' : (bz > -20) ? 'o'
					                                                       : '@';
			}
		}

		// Terminate the text string for this frame
		*p = '\0';
	}

	// Now play back the frames in sequence
	// Hide text cursor
	curs_set(0);
	for (i = 0; i < NUM_FRAMES; i++) {
		erase();
		mvaddstr(0, 0, frames[i]);
		refresh();
		nanosleep(&delay, NULL);
		// Change to 30 fps after first frame
		delay.tv_nsec = 33333333;
	}
	// Unhide cursor
	curs_set(1);
	endwin();

	free(blobs);
	for (i = 0; i < NUM_FRAMES; i++)
		free(frames[i]);

	return 0;
}
