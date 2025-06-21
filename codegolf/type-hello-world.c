/*

Write a program which generates keyboard events which type Hello, World!.

It doesn't have to be platform-independent.

It can't leave any keys pressed. For example, in Java, Robot.KeyPress('H'); will leave H pressed, so you must release it with Robot.KeyRelease('H');

You may assume that the caps lock is off when your program is run. Capital letters can be typed either by holding shift and pressing the letter, or by toggling caps lock. For the !, you'll probably have to use the shift method.

*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

typedef struct {
	const char *buffer;
	size_t index;
} Text;

SDL_Window *window;
SDL_Renderer *renderer;

Uint32 start;
Text text;

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
event(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			exit(0);
		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit(0);
			default:
				fputc(ev.key.keysym.sym, stdout);
				fflush(stdout);
				break;
			}
		}
	}
}

void
update(void)
{
	Uint32 now;
	SDL_Event ev;

	now = SDL_GetTicks();
	if (now - start < 50)
		return;

	memset(&ev, 0, sizeof(ev));
	if (text.buffer[text.index] == '\0')
		ev.type = SDL_QUIT;
	else {
		ev.type = SDL_KEYDOWN;
		ev.key.keysym.sym = text.buffer[text.index++];
	}

	SDL_PushEvent(&ev);
	start = now;
}

int
main(void)
{
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	text.buffer = "Hello, World!\n";
	text.index = 0;

	start = SDL_GetTicks();
	for (;;) {
		event();
		update();
	}

	return 0;
}
