/*

Given a string representing a series of aircraft marshalling hand signals, write a function or program to calculate the final position of an aircraft following these signals.

N.B.: Co-ordinates in this challenge are represented as a pair of Cartesian co-ordinates, plus a compass direction heading: (x, y, h) where x is the x-coordinate, y is the y-coordinate, and h is one of N, E, S, or W.

You start with an aircraft at (0, 0, N) on an imaginary grid, with engines off. Your input is a string containing comma-delimeted pairs of characters, where each pair represents one marshalling signal. You must follow each marshalling signal in turn, and output the co-ordinates in (x, y, h) form of the aircraft's final position.

If a signal requires your aircraft to move, assume it moves one unit in the required direction for each signal of that type that it receives. If a signal requires your aircraft to turn, assume it turns 90 degrees in the required direction for each signal of that type that it receives.

An aircraft cannot move if its engines are off. If your aircraft's engines are off and you receive a movement/turn signal, do not apply the movement/turn.

Signals
Each marshalling signal is represented by one pair of characters. The first of the pair represents the position of the marshaller's left arm, from the aircraft's point of view, and the second the right arm from the same POV. This handy chart of signals may help.

o/  —  START ENGINES (no movement, no turn)
-/  —  CUT ENGINES   (no movement, no turn)
-~  —  TURN LEFT     (no movement, left turn)
~-  —  TURN RIGHT    (no movement, right turn)
~~  —  COME FORWARD  (forward movement, no turn)
::  —  MOVE BACK     (backward movement, no turn)
/\  —  NORMAL STOP   (no movement, no turn)
This is not the complete list of marshalling signals, but it's all you're required to support.

Input
Input is a comma-delimeted string containing pairs of characters. This string will always be valid - you do not have to validate the input.

Output
Output is a set of co-ordinates as described above. You can return this in any convenient format - if your language supports multiple return values, you may use that; alternatively, you can use a string (the brackets surrounding the co-ordinates are non-compulsory), array, tuple, list, or whatever else you find convenient. The only rule is that it must contain x, y, and h values, in that order.

Test Cases
Input  —  Output
o/,~~,~~,~-,::  —  (-1, 2, E)
::,~-,o/,/\,~~,-~,~~,~~,~~  —  (-3, 1, W)
o/,::,-/,~~,o/,~-,~~,~~,~-  —  (2, -1, S)
o/,~-,~-,::,::,~-,~~,-~  —  (-1, 2, S)
~-,~-,o/,::,::,-/,~~,-~  —  (0, -2, N)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y, h;
} Location;

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

Location
locate(const char **s, size_t n)
{
	static const char dir[] = "NESW";

	int x, y, h;
	int f, d;
	size_t i;

	x = y = h = f = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "o/")) {
			f = 1;
			continue;
		}

		if (!strcmp(s[i], "-/")) {
			f = 0;
			continue;
		}

		if (!f)
			continue;

		if (!strcmp(s[i], "-~")) {
			h = mod(h - 1, 4);
			continue;
		}
		if (!strcmp(s[i], "~-")) {
			h = mod(h + 1, 4);
			continue;
		}

		if (!strcmp(s[i], "~~"))
			d = 1;
		else if (!strcmp(s[i], "::"))
			d = -1;
		else
			continue;

		switch (h) {
		case 0:
			y += d;
			break;
		case 1:
			x += d;
			break;
		case 2:
			y -= d;
			break;
		case 3:
			x -= d;
			break;
		}
	}

	return (Location){x, y, dir[h]};
}

void
test(const char **s, size_t n, Location r)
{
	Location l;

	l = locate(s, n);
	printf("%d %d %c\n", l.x, l.y, l.h);
	assert(l.x == r.x);
	assert(l.y == r.y);
	assert(l.h == r.h);
}

int
main()
{
	const char *s1[] = {"o/", "~~", "~~", "~-", "::"};
	const char *s2[] = {"::", "~-", "o/", "/\\", "~~", "-~", "~~", "~~", "~~"};
	const char *s3[] = {"o/", "::", "-/", "~~", "o/", "~-", "~~", "~~", "~-"};
	const char *s4[] = {"o/", "~-", "~-", "::", "::", "~-", "~~", "-~"};
	const char *s5[] = {"~-", "~-", "o/", "::", "::", "-/", "~~", "-~"};

	Location r1 = {-1, 2, 'E'};
	Location r2 = {-3, 1, 'W'};
	Location r3 = {2, -1, 'S'};
	Location r4 = {-1, 2, 'S'};
	Location r5 = {0, -2, 'N'};

	test(s1, nelem(s1), r1);
	test(s2, nelem(s2), r2);
	test(s3, nelem(s3), r3);
	test(s4, nelem(s4), r4);
	test(s5, nelem(s5), r5);

	return 0;
}
