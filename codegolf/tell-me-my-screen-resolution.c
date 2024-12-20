/*

Output the device's screen resolution in the specific format of [width]x[height](without the brackets). For example, an output could be 1440x900.

Here's an online tester that you can use to check your own screen resolution.
https://bestfirms.com/what-is-my-screen-resolution/

*/

#include <stdio.h>
#include <stdarg.h>
#include <SDL.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}

int
main()
{
	SDL_DisplayMode dm;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	if (SDL_GetCurrentDisplayMode(0, &dm) < 0)
		fatal("Failed to get screen size: %s", SDL_GetError());

	printf("%dx%d\n", dm.w, dm.h);

	SDL_Quit();
	return 0;
}
