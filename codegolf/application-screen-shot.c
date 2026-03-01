/*

Write the minimal code you need to take a screenshot of your application window. I am not asking for a function or program; just only a code segment.

It has obviously to be a GUI application; console applications not allowed.

Input:

None.

Output:

The valid outputs are:

Clipboard. Then post a screenshot of the Paste contents on a drawing program.
A file. Upload it somewhere and post a link to it here.
Inside any other window different from the window that was shoot. Post screenshot of the new window here.
As it is code-golf minimum number of characters wins!

*/

#include <err.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>

int
main(int, char **)
{
	Display *display;
	Window window;
	cairo_surface_t *surface;
	int screen;

	display = XOpenDisplay(NULL);
	if (!display)
		errx(1, "Failed to open display");

	screen = DefaultScreen(display);
	window = DefaultRootWindow(display);
	surface = cairo_xlib_surface_create(display, window, DefaultVisual(display, screen),
	                                    DisplayWidth(display, screen), DisplayHeight(display, screen));

	if (cairo_surface_write_to_png(surface, "screenshot.png") != CAIRO_STATUS_SUCCESS)
		errx(1, "Failed to write screenshot to file");

	cairo_surface_destroy(surface);

	return 0;
}
