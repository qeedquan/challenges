/*

Write a program that draws a recursive image.

For example, a Sierpinski triangle, a Barnsley fern, or a Mandelbrot set fractal would be good drawings.

Any recursive image will do, but try to make them look fun or interesting.

Bonus points for adding a color scheme!

Please post a link to a sample image produced by your program, and above all, be creative.

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>

// ported from @electric_machinery solution
#define SIZE 1200

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} Pixel;

Pixel pixels[SIZE + 1][SIZE];

void
plot(int x, int y, uint32_t col)
{
	if (x > SIZE || y > SIZE)
		return;

	pixels[y][x].r = (col >> 16) & 0xFF;
	pixels[y][x].g = (col >> 8) & 0xFF;
	pixels[y][x].b = col & 0xFF;
}

void
fern(int points)
{
	double x, y;
	double xn, yn;
	unsigned int px, py;
	uint32_t color;

	x = y = 0;
	xn = yn = 0;
	for (; points > 0; points--) {
		switch (rand() & 3) {
		case 0:
			color = 0x10FF50;
			xn = 0;
			yn = .16 * y;
			x = xn;
			y = yn;
			break;
		case 1:
			color = 0x10BB00;
			xn = .2 * x - .26 * y;
			yn = .2 * x + .23 * y + 1.65;
			x = xn;
			y = yn;
			break;
		case 2:
			color = 0x10FF10;
			xn = -.15 * x + .28 * y;
			yn = .26 * x + .24 * y + .44;
			x = xn;
			y = yn;
			break;
		case 3:
			color = 0x10FF00;
			xn = .85 * x + .04 * y;
			yn = -.04 * x + .98 * y + 1.6;
			x = xn;
			y = yn;
			break;
		};

		px = (x * SIZE / 10 + SIZE / 2);
		py = (y * SIZE / 10 + SIZE / 8);
		plot(px, py, color);
		plot(px + 1, py - 1, color * 0x808080);
		plot(px, py - 1, color * 0xA0A0A0);
		plot(px + 1, py, color * 0x60A0A0);

		plot(px - 1, py + 1, color * 0x808080);
		plot(px, py + 1, color * 0xA0A0A0);
		plot(px - 1, py, color * 0x101010);
	}
}

int
writeppm(const char *name)
{
	FILE *fp;
	int x, y;

	fp = fopen(name, "w");
	if (!fp)
		return -errno;

	fprintf(fp, "P3 %d %d %d\n", SIZE, SIZE, 255);
	for (y = SIZE - 1; y >= 0; y--) {
		for (x = 0; x < SIZE; x++) {
			fprintf(fp, "%d %d %d\n", pixels[y][x].r, pixels[y][x].g, pixels[y][x].b);
		}
	}

	fclose(fp);
	return 0;
}

int
main()
{
	srand(time(NULL));
	memset(pixels, 0xFF, sizeof(pixels));
	fern(5000000);
	if (writeppm("fern.ppm") < 0)
		printf("Error writing file: %s\n", strerror(errno));

	return 0;
}
