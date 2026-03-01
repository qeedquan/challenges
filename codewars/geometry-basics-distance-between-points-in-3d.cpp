/*

This series of katas will introduce you to basics of doing geometry with computers.

Point objects have x, y, and z attributes. For Haskell there are Point data types described with record syntax with fields x, y, and z.

Write a function calculating distance between Point a and Point b.

Tests round answers to 6 decimal places. Tests in Haskell will not round.

*/

#include <cassert>
#include <cstdio>
#include <cmath>

template <typename T>
struct Point
{
	T x, y, z;
};

template <typename T>
T distance(const Point<T> &p, const Point<T> &q)
{
	auto dx = p.x - q.x;
	auto dy = p.y - q.y;
	auto dz = p.z - q.z;
	return sqrt((dx * dx) + (dy * dy) + (dz * dz));
}

typedef Point<double> Pointd;

void test(Pointd point1, Pointd point2, double expected)
{
	auto result = distance(point1, point2);
	printf("%.6f\n", result);
	assert(fabs(result - expected) < 1e-6);
}

int main()
{
	test(Pointd(1, 3, 5), Pointd(1, 3, 5), 0);
	test(Pointd(1, 3, 6), Pointd(4, 3, 2), 5);
	test(Pointd(-10.2, 12.5, 8.4), Pointd(0.3, 14.7, -2.8), 15.509030);
	return 0;
}
