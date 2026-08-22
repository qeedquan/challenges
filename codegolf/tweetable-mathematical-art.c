/*

Integer math can generate amazing patterns when laid out over a grid. Even the most basic functions can yield stunningly elaborate designs!

Your challenge
Write 3 Tweetable (meaning 140 characters or less) function bodies for the red, green, and blue values for a 1024x1024 image.

The input to the functions will be two integers i (column number for the given pixel) and j (row number for the given pixel) and the output will be an unsigned short between 0 and 1023, inclusive, which represents the amount of the given color present in the pixel (i,j).

For example, the following three functions produce the picture below:

// RED
    return (unsigned short)sqrt((double)(_sq(i-DIM/2)*_sq(j-DIM/2))*2.0);
// GREEN
    return (unsigned short)sqrt((double)(
        (_sq(i-DIM/2)|_sq(j-DIM/2))*
        (_sq(i-DIM/2)&_sq(j-DIM/2))
    ));
// BLUE
    return (unsigned short)sqrt((double)(_sq(i-DIM/2)&_sq(j-DIM/2))*2.0);

https://i.sstatic.net/da9MA.jpg

// RED
    return i&&j?(i%j)&(j%i):0;
// GREEN
    return i&&j?(i%j)+(j%i):0;
// BLUE
    return i&&j?(i%j)|(j%i):0;

https://i.sstatic.net/3z2pa.jpg

The Rules
Given this C++ code, substitute in your functions. I have provided a few macros and have included the library, and you may include complex.h. You may use any functions from these libraries and/or my macros. Please do not use any external resources beyond this.
If that version isn't working for you, make sure you're compiling with:

g++ filename.cpp -std=c++11
If that doesn't work, please use the alternate version using unsigned chars instead of unsigned shorts.

Michaelangelo has provided a cleaned up 24-bit or 48-bit color output version.

You may implement your own version in another language, but it must behave in the same way as the provided C++ version, and only functions from C++'s built-ins, the library, or the provided macros may be used to make it fair.
Post only your three function bodies - please don't include my code in your post
Please include either a smaller version or an embedded copy of your image. They are made into a ppm format and may need to be converted to another for proper viewing on stackexchange.
Function bodies (not including signature) must be 140 characters or less.
This is a popularity contest - most votes wins

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define DIM 1024

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned char uchar;
typedef uchar Pix[DIM][DIM][3];
typedef void (*colorfn)(int, int, uchar[3]);

int
isq(int x)
{
	return x * x;
}

double
sq(double x)
{
	return x * x;
}

void
hyperbolic_1(int i, int j, uchar c[3])
{
	c[0] = (unsigned short)sqrt((double)(isq(i - DIM / 2) * isq(j - DIM / 2)) * 2.0);
	c[1] = (unsigned short)sqrt((double)((isq(i - DIM / 2) | isq(j - DIM / 2)) *
	                                     (isq(i - DIM / 2) & isq(j - DIM / 2))));
	c[2] = (unsigned short)sqrt((double)(isq(i - DIM / 2) & isq(j - DIM / 2)) * 2.0);
}

void
hyperbolic_2(int i, int j, uchar c[3])
{
	c[0] = i && j ? (i % j) & (j % i) : 0;
	c[1] = i && j ? (i % j) + (j % i) : 0;
	c[2] = i && j ? (i % j) | (j % i) : 0;
}

void
table_flat(int i, int j, uchar c[3])
{
	float s;

	s = 3. / (j + 99);
	c[0] = ((int)((i + DIM) * s + j * s) % 2 + (int)((DIM * 2 - i) * s + j * s) % 2) * 127;
	c[1] = c[0];
	c[2] = c[0];
}

void
table_ripple(int i, int j, uchar c[3])
{
	float s, y;

	s = 3. / (j + 99);
	y = (j + sin((i * i + sq(j - 700) * 5) / 100. / DIM) * 35) * s;
	c[0] = ((int)((i + DIM) * s + y) % 2 + (int)((DIM * 2 - i) * s + y) % 2) * 127;
	c[1] = c[0];
	c[2] = c[0];
}

void
table_ripple_color(int i, int j, uchar c[3])
{
	float s, y;

	s = 3. / (j + 99);
	y = (j + sin((i * i + sq(j - 700) * 5) / 100. / DIM) * 35) * s;
	c[0] = ((int)((i + DIM) * s + y) % 2 + (int)((DIM * 2 - i) * s + y) % 2) * 127;
	c[1] = ((int)(5 * ((i + DIM) * s + y)) % 2 + (int)(5 * ((DIM * 2 - i) * s + y)) % 2) * 127;
	c[2] = ((int)(29 * ((i + DIM) * s + y)) % 2 + (int)(29 * ((DIM * 2 - i) * s + y)) % 2) * 127;
}

void
swirl_1(int i, int j, uchar c[3])
{
	double z[3];

	z[0] = (sqrt(sq(73. - i) + sq(609 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(860. - i) + sq(162 - j))) / 115.0))) + 1) / 200;
	z[1] = (sqrt(sq(160. - i) + sq(60 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(86. - i) + sq(860 - j))) / 115.0))) + 1) / 200;
	z[2] = (sqrt(sq(844. - i) + sq(200 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(250. - i) + sq(20 - j))) / 115.0))) + 1) / 200;

	c[0] = z[0] * 128;
	c[1] = z[1] * 128;
	c[2] = z[2] * 128;
}

void
swirl_2(int i, int j, uchar c[3])
{
	double z[3];

	z[0] = (sqrt(sq(148. - i) + sq(1000 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(500. - i) + sq(400 - j))) / 115.0))) + 1) / 200;
	z[1] = (sqrt(sq(610. - i) + sq(60 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(864. - i) + sq(860 - j))) / 115.0))) + 1) / 200;
	z[2] = (sqrt(sq(180. - i) + sq(100 - j)) + 1) / (sqrt(fabs(sin((sqrt(sq(503. - i) + sq(103 - j))) / 115.0))) + 1) / 200;

	c[0] = z[0] * 200;
	c[1] = z[1] * 200;
	c[2] = z[2] * 200;
}

void
sheet_music(int i, int j, uchar c[3])
{
	c[0] = ((int)(100 * sin((i + 400) * (j + 100) / 11115))) & i;
	c[1] = c[0];
	c[2] = c[0];
}

void
pointy(int i, int j, uchar c[3])
{
	c[0] = (sq(cos(atan2(j - 512, i - 512) / 2)) * 255);
	c[1] = (sq(cos(atan2(j - 512, i - 512) / 2 - 2 * acos(-1) / 3)) * 255);
	c[2] = (sq(cos(atan2(j - 512, i - 512) / 2 + 2 * acos(-1) / 3)) * 255);
}

void
triangle_1(int i, int j, uchar c[3])
{
	c[0] = j ^ (j - i) ^ i;
	c[1] = isq(i - DIM) + isq(j - DIM);
	c[2] = i ^ (i - j) ^ j;
}

void
randomy(int, int, uchar c[3])
{
	c[0] = rand() & 0xff;
	c[1] = rand() & 0xff;
	c[2] = rand() & 0xff;
}

void
paint(Pix p, colorfn f)
{
	int x, y;

	for (y = 0; y < DIM; y++) {
		for (x = 0; x < DIM; x++) {
			f(x, y, p[y][x]);
		}
	}
}

int
writepgm(const char *name, Pix p)
{
	FILE *f;
	int x, y;

	f = fopen(name, "w");
	if (!f)
		return -errno;

	fprintf(f, "P3 %d %d 255\n", DIM, DIM);
	for (y = 0; y < DIM; y++) {
		for (x = 0; x < DIM; x++) {
			fprintf(f, "%d %d %d\n", p[y][x][0], p[y][x][1], p[y][x][2]);
		}
	}
	fclose(f);
	return 0;
}

int
main()
{
	static const struct Func {
		const char *name;
		colorfn func;
	} ftab[] = {
		{ "hyperbolic_1",       hyperbolic_1       },
		{ "hyperbolic_2",       hyperbolic_2       },
		{ "table_flat",         table_flat         },
		{ "table_ripple",       table_ripple       },
		{ "table_ripple_color", table_ripple_color },
		{ "swirl_1",            swirl_1            },
		{ "swirl_2",            swirl_2            },
		{ "sheet_music",        sheet_music        },
		{ "pointy",             pointy             },
		{ "triangle_1",         triangle_1         },
		{ "randomy",            randomy            },
	};

	const struct Func *f;
	char name[128];
	Pix p;
	size_t i;

	for (i = 0; i < nelem(ftab); i++) {
		f = ftab + i;
		paint(p, f->func);
		snprintf(name, sizeof(name), "%s.pgm", f->name);
		writepgm(name, p);
	}
	return 0;
}
