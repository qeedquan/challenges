/*

Definition
A Dyck path of length 2n can be defined as a two-dimensional path such that:

The path consists of straight lines of equal length.
The path goes left to right while moving either up or down. Each step is an up-right or down-right slanted line.
The final and initial heights of the path are the same, and the path never goes below that height.
Here is an example for n=4:

 /\/\
/    \/\

The number of Dyck paths of length 2n, n≥1 is the n-Catalan number: 1, 2, 5, 14, 42,…

The challenge
Given n≥1, draw all Dyck paths of length 2n in ASCII art, using characters /, \, space and newline.

Blank space around the path is fine.

The paths can be output in any order, without repetitions.

Additional rules
Input and output means are flexible as usual.
For example, the paths can be directly displayed, or output as a string with newlines, or as an array of strings where each string is line of output.
If the paths are directly displayed, they should be clearly separated by blank space.
Programs or functions are allowed.
Standard loopholes are forbidden.
The shortest code in bytes wins.

Test cases
Additional test cases can be generated with this program (not golfed).

n=1:

/\

n=2:

/\/\

 /\
/  \

n=3:

/\/\/\

   /\
/\/  \

 /\
/  \/\

 /\/\
/    \

  /\
 /  \
/    \

n=4:

/\/\/\/\

     /\
/\/\/  \

   /\
/\/  \/\

   /\/\
/\/    \

    /\
   /  \
/\/    \

 /\
/  \/\/\

 /\  /\
/  \/  \

 /\/\
/    \/\

 /\/\/\
/      \

    /\
 /\/  \
/      \

  /\
 /  \
/    \/\

  /\
 /  \/\
/      \

  /\/\
 /    \
/      \

   /\
  /  \
 /    \
/      \

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
newpath(int length)
{
	char *path;
	int index;

	if (length < 0)
		return NULL;

	length = (2 * length) + 1;
	path = calloc(length, length);
	if (!path)
		return NULL;

	index = 0;
	while (index < length * length / 2) {
		index += 1;
		path[index] = '\n';
		if (index % length)
			path[index] = ' ';
	}
	return path;
}

void
recurse(int length, char *path, int current, int height, int direction)
{
	static const char symbols[] = "\\\n/";

	int position;

	height += direction;
	if (height < 0)
		return;

	position = current + ((length + direction) / 2 - height) * length;
	if (position < 0)
		position = 0;

	path[position] = symbols[direction + 1];
	if (++current - length) {
		recurse(length, path, current, height, -1);
		recurse(length, path, current, height, 1);
	} else if (!height)
		puts(path + 1);

	path[position] = ' ';
}

int
dyck(int length)
{
	char *path;

	path = newpath(length);
	if (!path)
		return -1;

	printf("n=%d\n", length);
	recurse((2 * length) + 1, path, 0, 0, 0);
	printf("\n");

	free(path);
	return 0;
}

int
main()
{
	int length;

	for (length = 1; length <= 4; length++)
		dyck(length);

	return 0;
}
