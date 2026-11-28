/*

Consider these seven ASCII train cars.

Engine (E)

            __
======      \/
| [] |=========
|              )
================
 O-O-O   O-O-O \\
Passenger car (P)

===============
| [] [] [] [] |
===============
 O-O       O-O
Boxcar (B)

===============
|-|-|  |  |-|-|
===============
 O-O       O-O
Tanker (T)

 _____---_____
(             )
===============
 O-O       O-O
Hopper (H)

_______________
\ | | | | | | /
===============
 O-O       O-O
Flatbed (F)

===============
 O-O       O-O
Caboose (C)

    =====
====|   |====
| []     [] |
=============
 O-O     O-O
Write a program that when given a sequence of the characters EPBTHFC, outputs its ASCII train representation, using -- for the car couplings. The leftmost input characters become the rightmost train cars. The train is always facing right.

For example, an input of EEHTBPFC should produce

                                                                                                                __                __
    =====                                                                                           ======      \/    ======      \/
====|   |====                   ===============  ===============   _____---_____   _______________  | [] |=========   | [] |=========
| []     [] |                   | [] [] [] [] |  |-|-|  |  |-|-|  (             )  \ | | | | | | /  |              )  |              )
=============--===============--===============--===============--===============--===============--================--================
 O-O     O-O    O-O       O-O    O-O       O-O    O-O       O-O    O-O       O-O    O-O       O-O    O-O-O   O-O-O \\  O-O-O   O-O-O \\

Details
This is code golf; the shortest program in bytes wins.
Any sequence of one or more of the letters EPBTHFC is valid input.
Your program must be able to output all 7 car types exactly as they appear above.
Take input from the command line or directly from the user (e.g. message box). Output to stdout. (Quotes around input are fine.)
The height of the output should either be 6 or the maximum height needed for the train cars being drawn.
Do not put couplings (--) at the front of the first car or the back of the last car.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char **
at(int c)
{
	static const char *E[] = {
		"            __   ",
		"======      \\/   ",
		"| [] |=========  ",
		"|              ) ",
		"================ ",
		" O-O-O   O-O-O \\\\",
	};

	static const char *P[] = {
		"               ",
		"               ",
		"===============",
		"| [] [] [] [] |",
		"===============",
		" O-O       O-O ",
	};

	static const char *B[] = {
		"               ",
		"               ",
		"===============",
		"|-|-|  |  |-|-|",
		"===============",
		" O-O       O-O ",
	};

	static const char *T[] = {
		"               ",
		"               ",
		" _____---_____ ",
		"(             )",
		"===============",
		" O-O       O-O ",
	};

	static const char *H[] = {
		"               ",
		"               ",
		"_______________",
		"\\ | | | | | | /",
		"===============",
		" O-O       O-O ",
	};

	static const char *F[] = {
		"               ",
		"               ",
		"               ",
		"               ",
		"===============",
		" O-O       O-O ",
	};

	static const char *C[] = {
		"             ",
		"    =====    ",
		"====|   |====",
		"| []     [] |",
		"=============",
		" O-O     O-O ",
	};

	switch (toupper(c)) {
	case 'E':
		return E;
	case 'P':
		return P;
	case 'B':
		return B;
	case 'T':
		return T;
	case 'H':
		return H;
	case 'F':
		return F;
	case 'C':
		return C;
	}
	return NULL;
}

void
draw(const char *s)
{
	const char **p;
	size_t i, n, y;

	puts(s);
	n = strlen(s);
	for (y = 0; y < 6; y++) {
		for (i = n; i > 0; i--) {
			p = at(s[i - 1]);
			if (!p)
				continue;

			printf("%s", p[y]);
			if (i > 1) {
				if (y == 4)
					printf("--");
				else
					printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	draw("EEHTBPFC");

	return 0;
}
