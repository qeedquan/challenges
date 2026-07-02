/*

This is a window:

---
| |
---
Let's add some walls |. Put two spaces on either side of it so that the window has plenty of room.

|  ---  |
|  | |  |
|  ---  |
Now let's add a roof and a ceiling. To keep the window in the middle of the room, let's add one more row above it and below it.

---------
|       |
|  ---  |
|  | |  |
|  ---  |
|       |
---------
Now, just add a roof. Put a slash as far left as possible, and a backslash as far right as possible, and we have this:

/       \
---------
|       |
|  ---  |
|  | |  |
|  ---  |
|       |
---------
Then move the slash up one and right one. Move the backslash up one and left one:

 /     \
/       \
---------
|       |
|  ---  |
|  | |  |
|  ---  |
|       |
---------
Repeat until the two slashes meet, then add an asterisk where they meet:

    *
   / \
  /   \
 /     \
/       \
---------
|       |
|  ---  |
|  | |  |
|  ---  |
|       |
---------
And you're done! This is a 1x1 house. a 2x2 house would look like this:

        *
       / \
      /   \
     /     \
    /       \
   /         \
  /           \
 /             \
/               \
-----------------
|       |       |
|  ---  |  ---  |
|  | |  |  | |  |
|  ---  |  ---  |
|       |       |
|-------|-------|
|       |       |
|  ---  |  ---  |
|  | |  |  | |  |
|  ---  |  ---  |
|       |       |
-----------------
and a 3x2 house:

            *
           / \
          /   \
         /     \
        /       \
       /         \
      /           \
     /             \
    /               \
   /                 \
  /                   \
 /                     \
/                       \
-------------------------
|       |       |       |
|  ---  |  ---  |  ---  |
|  | |  |  | |  |  | |  |
|  ---  |  ---  |  ---  |
|       |       |       |
|-------|-------|-------|
|       |       |       |
|  ---  |  ---  |  ---  |
|  | |  |  | |  |  | |  |
|  ---  |  ---  |  ---  |
|       |       |       |
-------------------------
The challenge
You must write a full program that takes two integers, x and y, and prints a house that is X rooms wide and Y rooms tall. Your program should be able to handle houses up to 10x10. IO can be in any reasonable format. Trailing spaces on each line are allowed, and one trailing newline is allowed.

Shortest answer in bytes wins.

*/

#include <stdio.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
at(int r, int h, int x, int y, int X, int Y)
{
	if (y <= h) {
		if (y == 0 && x == h)
			return '*';
		if (y == h - x)
			return '/';
		if (y == x - h)
			return '\\';
		return ' ';
	}

	if (Y == 0) {
		if (X != 0)
			return '-';
		if (y < h + 2 || y == h + (r * 6) + 1)
			return '-';
	}
	if ((Y == 2 || Y == 4) && X > 2 && X < 6)
		return '-';

	if (X == 0)
		return '|';
	if (Y == 3 && (X == 3 || X == 5))
		return '|';

	return ' ';
}

void
house(int c, int r)
{
	int x, y, w, h;
	int X, Y;

	printf("%dx%d\n", c, r);
	h = c * 4;
	w = h * 2;
	for (y = 0; y < h + (r * 6) + 2; y++) {
		for (x = 0; x <= w; x++) {
			X = x % 8;
			Y = mod(y - h - 1, 6);
			putchar(at(r, h, x, y, X, Y));
		}
		putchar('\n');
	}
	putchar('\n');
}

int
main()
{
	house(1, 1);
	house(2, 2);
	house(3, 2);
	house(4, 4);
	house(8, 2);
	return 0;
}
