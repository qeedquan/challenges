#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <SDL3/SDL.h>

enum {
	MAXSTARS = 10000,
};

typedef struct {
	float x, y, z, pz;
} Star;

SDL_Window *window;
SDL_Renderer *renderer;

Star stars[MAXSTARS];

float width;
float height;
float speed;

int paused;

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

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
}

float
unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float
linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(unlerp(x, a, b), c, d);
}

void
starinit(Star *s)
{
	s->x = (SDL_randf() * 2 * width) - width;
	s->y = (SDL_randf() * 2 * height) - height;
	s->z = SDL_randf() * width;
	s->pz = s->z;
}

void
starupdate(Star *s)
{
	s->z -= speed;
	if (s->z < 1) {
		s->z = width;
		s->x = (SDL_randf() * 2 * width) - width;
		s->y = (SDL_randf() * 2 * height) - height;
		s->pz = s->z;
	}
}

void
stardraw(Star *s)
{
	float sx, sy;
	float px, py;

	sx = linear_remap(s->x / s->z, 0, 1, 0, width);
	sy = linear_remap(s->y / s->z, 0, 1, 0, height);

	px = linear_remap(s->x / s->pz, 0, 1, 0, width);
	py = linear_remap(s->y / s->pz, 0, 1, 0, height);

	s->pz = s->z;

	px += width / 2;
	py += height / 2;
	sx += width / 2;
	sy += height / 2;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, px, py, sx, sy);
}

void
initsdl()
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", strerror(errno));

	w = 800;
	h = 800;
	if (!SDL_CreateWindowAndRenderer("Starfield", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create SDL window: %s", strerror(errno));

	SDL_srand(time(NULL));

	width = w;
	height = h;
}

void
reset()
{
	size_t i;

	for (i = 0; i < MAXSTARS; i++)
		starinit(&stars[i]);
}

void
event()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key) {
			case SDLK_ESCAPE:
				exit(0);
			case SDLK_SPACE:
				paused = !paused;
				break;
			case SDLK_RETURN:
				reset();
				break;
			}
			break;
		case SDL_EVENT_WINDOW_RESIZED:
			width = ev.window.data1;
			height = ev.window.data2;
			reset();
			break;
		}
	}
}

void
update()
{
	size_t i;
	float mx, my;

	if (paused)
		return;

	SDL_GetMouseState(&mx, &my);
	speed = linear_remap(mx, 0, width, 0, 50);

	for (i = 0; i < MAXSTARS; i++)
		starupdate(&stars[i]);
}

void
draw()
{
	size_t i;

	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
	for (i = 0; i < MAXSTARS; i++)
		stardraw(&stars[i]);
	SDL_RenderPresent(renderer);
}

int
main()
{
	initsdl();
	reset();
	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
