/*

Ready! Set! Fire... but where should you fire?

The battlefield is 3x3 wide grid. HQ has already provided you with an array for easier computing:

var grid = ['top left',    'top middle',    'top right',
            'middle left', 'center',        'middle right',
            'bottom left', 'bottom middle', 'bottom right']

HQ radios you with 'x' and 'y' coordinates. x=0 y=0 being 'top left' part of the battlefield;

Your duty is to create a function that takes those Xs and Ys and return the correct grid sector to be hit.

fire(0,0); => 'top left'
fire(1,2); => 'bottom middle'
etc.

Notice the grid is a monodimensional array, good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
fire(int x, int y)
{
	static const char *grid[3][3] = {
		{ "top left", "top middle", "top right" },
		{ "middle left", "center", "middle right" },
		{ "bottom left", "bottom middle", "bottom right" },
	};

	if (x < 0 || x >= 3 || y < 0 || y >= 3)
		return NULL;
	return grid[y][x];
}

int
main()
{
	assert(!strcmp(fire(0, 0), "top left"));
	assert(!strcmp(fire(1, 2), "bottom middle"));

	return 0;
}
