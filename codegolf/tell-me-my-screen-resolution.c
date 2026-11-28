/*

Output the device's screen resolution in the specific format of [width]x[height](without the brackets). For example, an output could be 1440x900.

Here's an online tester that you can use to check your own screen resolution.
https://bestfirms.com/what-is-my-screen-resolution/

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SDL3/SDL.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(2);
}

int
main()
{
	const SDL_DisplayID *ids;
	const SDL_DisplayMode *dm;
	int i, numids;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	ids = SDL_GetDisplays(&numids);
	if (!ids)
		fatal("Failed to get displays: %s", SDL_GetError());

	for (i = 0; i < numids; i++) {
		dm = SDL_GetCurrentDisplayMode(ids[i]);
		if (dm)
			printf("#%d: %dx%d\n", i, dm->w, dm->h);
	}

	SDL_Quit();
	return 0;
}
