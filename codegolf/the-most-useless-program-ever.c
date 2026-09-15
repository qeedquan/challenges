/*

Inspired by The Most Useless Machine Ever.

Write the shortest program that does the following:

create a graphical window, then immediately close the window and exit the program.
do this in some visually apparent manner. Like the "arm" that pushes the switch in the machine, the program must use some visual method in the GUI to close itself.
this visual method must be what causes the program to close; you cannot just show it as something on the side (though there may be other things off to the side)
Note:

The program does not have to be visible long enough for the visible activity to be seen by a human as long as the activity is the cause of the closing.
The window must be a GUI (must display a graphical window that contains the visible exit method).
The visual method needs to be something the user could do if it wasn't done automatically. Explain what needs to be changed in the code for the user to be able to do this (Thanks to Iszi).
The program must close if there is no interference from the user, but if the user interferes, then it does not need to close automatically.
Please include an explanation of what it is that causes the program to close.
Example: a window containing a button which is programmatically clicked, running a short snippet of code that closes the program.

*/

#include <stdio.h>
#include <SDL3/SDL.h>

int
main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (!SDL_Init(SDL_INIT_VIDEO))
		goto error;

	if (!SDL_CreateWindowAndRenderer("Useless", 256, 256, 0, &window, &renderer))
		goto error;

	if (0) {
	error:
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	return 0;
}
