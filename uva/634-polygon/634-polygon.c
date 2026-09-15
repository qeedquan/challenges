#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

bool
in(Point v[], size_t n, Point p)
{
	double x1, y1;
	double x2, y2;
	double x, y;
	double d;
	int pos;
	int neg;
	size_t i, i2;

	if (n < 3)
		return false;

	pos = 0;
	neg = 0;
	x = p.x;
	y = p.y;
	for (i = 0; i < n; i++) {
		i2 = (i + 1) % n;
		x1 = v[i].x;
		y1 = v[i].y;
		x2 = v[i2].x;
		y2 = v[i2].y;

		d = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
		if (d > 0)
			pos += 1;
		else if (d < 0)
			neg += 1;

		if (pos > 0 && neg > 0)
			return false;
	}
	return true;
}

int
main()
{
	Point v1[] = {
		{ 1, 1 },
		{ 1, 3 },
		{ 3, 3 },
		{ 3, 1 },
	};

	Point v2[] = {
		{ 1, 1 },
		{ 1, 9 },
		{ 3, 9 },
		{ 3, 5 },
		{ 5, 5 },
		{ 5, 9 },
		{ 7, 9 },
		{ 7, 1 },
		{ 5, 1 },
		{ 5, 3 },
		{ 3, 3 },
		{ 3, 1 },
	};

	Point p1 = { 2, 2 };
	Point p2 = { 4, 2 };

	assert(in(v1, nelem(v1), p1) == true);
	assert(in(v2, nelem(v2), p2) == false);

	return 0;
}
