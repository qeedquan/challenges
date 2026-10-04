/*

G-code is a set of instructions used to manipulate machines in CNC, 3d printing, or other similar applications. It controlls the position of a tool, manuvering it to create a path.

Your goal is to interpret a cut-down version of g-code, to find where the tool ends up after it has finished executing.

You will receive the input as a series of g-code commands, with their arguments. Everything after the first semicolon in a line ;, denoting a comment, is ignored. For example:

G90; enter absolute mode
G00 X2 Y2; quickly go to (2,2)
G01 X10 Y10 F100; go to (10,10) at a feed rate of 100
G91; enter relative mode
G01 X5 Y0; move relatively by (5,0)
The final position would be (15,10,0)

You only need to handle these commands:

Command	Arguments	Description
G90	None	Enter absolute mode
G91	None	Enter relative mode
G00	X, Y, Z coordinates	Go to X, Y, Z coordinates quickly
G01	X, Y, Z coordinates, F feed rate	Go to X, Y, Z coordinates at feed rate F
Importantly, arguments are all optional. In other words, if an axis is omitted, the tool will simply not move on that axis. If the feedrate is omitted, it will use the previous feed rate. You can assume that at least one axis is always provided. Each given axis will be provided in alphabetical order, followed by the feed rate if there is one.

The tool position will always be positive in every axis. However a relative movement may contain negative values.

Note that the feed rate will not actually affect your final position so you can ignore it. But it may be included in your input, so you must not error if this happens.

The first command will always be G90 or G91 (although these commands may also appear subsequently), and the tool will always start at (0,0,0).

Comments may also be present. The line will be formatted as command and arguments (each separated by a space), followed by an optional semicolon and a comment. The semicolon will not have a space before it.

While input and output is flexible, you must still parse each line. I.e.: you cannot format your input such that the data structure itself indicates the commands and arguments. It must be a string or similar containing the entire command.

Code golf scoring.

Test cases
====
G90
G00 X2 Y2; MOVE TO START POINT
G01 X10 Y10 F100
====> (10,10,0)

====
G90
G00 X10 Y10
G91; ENTER RELATIVE MODE
G01 X1 Y2 F100
====> (11,12,0)

====
G90
G00 X1 Y1 Z1
G90
G00 X2 Y2 Z2
====> (2,2,2)

====
G91
G00 X1 Y1 Z1
G90
G00 X2 Y2 Z2
G91
G01 X1 Y2 Z3 F100
====> (3,4,5)

====
G90
G00 X2 Y2
G91
G00 Y2
====> (2,4,0)

====
G90
G00 X10 Y10 Z10
G91
G00 X-2 Y-3 Z-4
====> (8,7,6)

====
G90
G00 X12 Z34; TODO: REPLACE WITH;G00 X23 Z45
====> (12,0,34)

====
G90
G00 X10 Y10
G90
====> (10,10,0)

====
G90
G00 X10 Y10
G90
G91
G01 X1 Y1
G90
====> (11,11,0)

====
G90
G00 X3 Z5
G00 Y7
====> (3,7,5)

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y, z;
	int mode;
} Mach;

typedef struct {
	int code;
	int mask;
	int x, y, z;
} Op;

void
move(Mach *m, int x, int y, int z, int mask)
{
	if (m->mode) {
		x += m->x;
		y += m->y;
		z += m->z;
	}
	if (mask & 0x2)
		m->x = x;
	if (mask & 0x4)
		m->y = y;
	if (mask & 0x8)
		m->z = z;
}

int
decode(const char *line, Op *op)
{
	op->mask = 0;
	while (*line && *line != ';') {
		while (isspace(*line))
			line++;

		switch (*line) {
		case 'G':
			op->code = atoi(line + 1);
			op->mask |= 0x1;
			break;
		case 'X':
			op->x = atoi(line + 1);
			op->mask |= 0x2;
			break;
		case 'Y':
			op->y = atoi(line + 1);
			op->mask |= 0x4;
			break;
		case 'Z':
			op->z = atoi(line + 1);
			op->mask |= 0x8;
			break;
		}

		while (*line && *line != ';' && !isspace(*line))
			line++;
	}
	return op->mask & 0x1;
}

void
interpret(Mach *m, const char **lines, size_t nline)
{
	size_t i;
	Op op;

	memset(m, 0, sizeof(*m));
	memset(&op, 0, sizeof(op));
	for (i = 0; i < nline; i++) {
		if (!decode(lines[i], &op))
			continue;

		switch (op.code) {
		case 0:
		case 1:
			move(m, op.x, op.y, op.z, op.mask);
			break;
		case 90:
			m->mode = 0;
			break;
		case 91:
			m->mode = 1;
			break;
		}
	}
}

void
test(const char **lines, size_t nline, int rx, int ry, int rz)
{
	Mach m[1];

	interpret(m, lines, nline);
	printf("%d %d %d\n", m->x, m->y, m->z);
	assert(m->x == rx);
	assert(m->y == ry);
	assert(m->z == rz);
}

int
main()
{
	const char *lines1[] = {
		"G90; enter absolute mode",
		"G00 X2 Y2; quickly go to (2,2)",
		"G01 X10 Y10 F100; go to (10,10) at a feed rate of 100",
		"G91; enter relative mode",
		"G01 X5 Y0; move relatively by (5,0)",
	};

	const char *lines2[] = {
		"G90",
		"G00 X2 Y2; MOVE TO START POINT",
		"G01 X10 Y10 F100",
	};

	const char *lines3[] = {
		"G90",
		"G00 X10 Y10",
		"G91; ENTER RELATIVE MODE",
		"G01 X1 Y2 F100",
	};

	const char *lines4[] = {
		"G90",
		"G00 X1 Y1 Z1",
		"G90",
		"G00 X2 Y2 Z2",
	};

	const char *lines5[] = {
		"G91",
		"G00 X1 Y1 Z1",
		"G90",
		"G00 X2 Y2 Z2",
		"G91",
		"G01 X1 Y2 Z3 F100",
	};

	const char *lines6[] = {
		"G90",
		"G00 X10 Y10 Z10",
		"G91",
		"G00 X-2 Y-3 Z-4",
	};

	const char *lines7[] = {
		"G90",
		"G00 X12 Z34; TODO: REPLACE WITH;G00 X23 Z45",
	};

	const char *lines8[] = {
		"G90",
		"G00 X10 Y10",
		"G90",
	};

	const char *lines9[] = {
		"G90",
		"G00 X10 Y10",
		"G90",
		"G91",
		"G01 X1 Y1",
		"G90",
	};

	const char *lines10[] = {
		"G90",
		"G00 X3 Z5",
		"G00 Y7",
	};

	test(lines1, nelem(lines1), 15, 10, 0);
	test(lines2, nelem(lines2), 10, 10, 0);
	test(lines3, nelem(lines3), 11, 12, 0);
	test(lines4, nelem(lines4), 2, 2, 2);
	test(lines5, nelem(lines5), 3, 4, 5);
	test(lines6, nelem(lines6), 8, 7, 6);
	test(lines7, nelem(lines7), 12, 0, 34);
	test(lines8, nelem(lines8), 10, 10, 0);
	test(lines9, nelem(lines9), 11, 11, 0);
	test(lines10, nelem(lines10), 3, 7, 5);

	return 0;
}
