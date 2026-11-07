/*

Sound synthesizers use envelope generators to control how certain parameters of the sound (such as overall loudness) change with time.
In many synthesizers an envelope is defined by four parameters, as represented in the following figure from Wikipedia:

Attack time (A): time taken for the envelope to reach its maximum level, starting from zero, when the key is first pressed.
Decay time (D): time taken for the envelope to reach the specified sustain level.
Sustain level (S): level which is maintained, after the initial attack and decay, for as long as the key is being pressed.
Release time (R): time taken for the envelope to reach zero when the key is released.

https://i.sstatic.net/lazZO.png

The challenge
Input the four parameters A, D, S, R and plot the envelope.

Parameters will be integer values from 0 to 127.

The maximum level (reached at the end of the attack phase) will be assumed to be 127.

The horizontal segment at the sustain level will be assumed to have duration 64 (in the actual sound this duration is not fixed, but is determined by the amount of time that the key is held).

Format and further details
The output should be an image in raster or vector format. If it's raster, the polygonal line should occupy at least 50 pixels vertically an horizontally.

The image can be either displayed or produced as a file in a standard image format. The file can be written to disk, or its exact contents can be output, either to STDERR or as function return argument.

The graph need only contain the polygonal line that defines the envelope. The scale of each axis can be freely chosen. Other elements such as axis lines, numeric labels or line colors are optional.

Input means and format are flexible as usual. For example, you can take the four numbers in any order, or an array containing them. A program or a function can be provided. Standard loopholes are forbidden.

Shortest code in bytes wins.

Test cases
Input is in the format [A D S R]. Note that the scale is different in each figure (in accordance with the rule that scale can be freely chosen)

[15 30 70 40]
https://i.sstatic.net/9dSO4.png

[64 64 64 64]
https://i.sstatic.net/s5012.png

[0 10 50 80]
https://i.sstatic.net/9e6jE.png

[0 0 90 80]
https://i.sstatic.net/kOo4E.png

[5 50 0 0]
https://i.sstatic.net/u8fnH.png

[5 50 0 80]
https://i.sstatic.net/C5SW5.png

[24 32 127 48]
https://i.sstatic.net/vY3Sp.png

*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

typedef struct {
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	SDL_Color color;
	int x, y;
	int w, h;
} Plot;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
plotgo(Plot *p, int x, int y)
{
	SDL_SetRenderDrawColor(p->renderer, p->color.r, p->color.g, p->color.b, p->color.a);
	SDL_RenderLine(p->renderer, p->x, p->h - p->y - 1, x, p->h - y - 1);
	p->x = x;
	p->y = y;
}

void
plotasdr(Plot *p, int A, int D, int S, int R)
{
	char file[128];

	snprintf(file, sizeof(file), "env_%d.%d.%d.%d.png", A, D, S, R);

	SDL_SetRenderDrawColor(p->renderer, 255, 255, 255, 255);
	SDL_RenderClear(p->renderer);

	p->x = 0;
	p->y = 0;
	plotgo(p, A, 127);
	plotgo(p, A + D, S);
	D += A + 64;
	plotgo(p, D, S);
	plotgo(p, D + R, 0);
	SDL_RenderPresent(p->renderer);
	if (!SDL_SavePNG(p->surface, file))
		fprintf(stderr, "Failed to save PNG file: %s: %s", file, SDL_GetError());
}

void
plotinit(Plot *p)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	SDL_SetHint(SDL_HINT_RENDER_LINE_METHOD, "3");

	p->w = 256;
	p->h = 128;
	p->surface = SDL_CreateSurface(p->w, p->h, SDL_PIXELFORMAT_RGBA8888);
	if (!p->surface)
		fatal("Failed to create surface: %s", SDL_GetError());

	p->renderer = SDL_CreateSoftwareRenderer(p->surface);
	if (!p->renderer)
		fatal("Failed to create renderer: %s", SDL_GetError());

	p->color = (SDL_Color){ 80, 156, 209, 255 };
}

void
plotfree(Plot *p)
{
	SDL_DestroyRenderer(p->renderer);
	SDL_DestroySurface(p->surface);
	SDL_Quit();
}

int
main()
{
	Plot p[1];

	plotinit(p);
	plotasdr(p, 15, 30, 70, 40);
	plotasdr(p, 64, 64, 64, 64);
	plotasdr(p, 0, 10, 50, 80);
	plotasdr(p, 0, 0, 90, 80);
	plotasdr(p, 5, 50, 0, 0);
	plotasdr(p, 5, 50, 0, 80);
	plotasdr(p, 24, 32, 127, 48);
	plotfree(p);

	return 0;
}
