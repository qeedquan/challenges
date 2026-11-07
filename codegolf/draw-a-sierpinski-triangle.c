/*

The Sierpinsky Triangle is a fractal created by taking a triangle, decreasing the height and width by 1/2, creating 3 copies of the resulting triangle, and place them such each triangle touches the other two on a corner. This process is repeated over and over again with the resulting triangles to produce the Sierpinski triangle, as illustrated below.

https://i.stack.imgur.com/MrjJN.png

Write a program to generate a Sierpinski triangle. You can use any method you want to generate the pattern, either by drawing the actual triangles, or by using a random algorithm to generate the picture. You can draw in pixels, ascii art, or whatever you want, so long as the output looks similar to the last picture shown above. Fewest characters wins.

*/

#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y, z;
} vec3;

typedef struct {
	int x, y, z;
} vec3i;

// ported from https://www.shadertoy.com/view/7sSczG
void
sierpinski(int w, int h, double z, char c0, char c1)
{
	vec3 p, q;
	vec3i c;
	int x, y;

	for (y = h - 1; y >= 0; y--) {
		for (x = 0; x < w; x++) {
			p.x = x * 1.0 / w;
			p.y = y * 1.0 / h;

			q.x = 1 - p.x + (0.5 * p.y);
			q.y = p.x + (0.5 * p.y);
			q.z = 1 - p.y;

			q.x = fmin(q.x, 1);
			q.y = fmin(q.y, 1);
			q.z = fmin(q.z, 1);

			c.x = q.x * z;
			c.y = q.y * z;
			c.z = q.z * z;
			if (c.x & c.y & c.z)
				putchar(c0);
			else
				putchar(c1);
		}
		printf("\n");
	}
}

int
main(void)
{
	sierpinski(100, 60, 16, '@', ' ');
	return 0;
}
