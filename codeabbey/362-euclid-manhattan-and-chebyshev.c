/*

This problem is not much of a puzzle, rather an excercise on DRY principle, so it may be especially useful to review other's solutions after solving.

Since school we get used to the thought that distance between two points is just the length of the straight line connecting them. In other words, for two points (Xa, Ya) and (Xb, Yb) in Cartesian plane, distance is calculated according to Pythagorean theorem:

D  =  sqrt((Xa-Ya)^2 + (Xb-Yb)^2)  =  hypot(Xa-Ya, Xb-Yb)
(some programming languages have this convenient function hypot)

Well, it is the distance called Euclidean (yeah, that's logical - formula is Pythagorean so the distance is Euclidean). However mathematicians find this too dull :)

Mathematicians had introduced more general term for distance between points in space and called it the metric of the space. And they introduced different metrics! Let's get acquainted with two unusual (but familiar) metrics!

Three Travellers
Three travelling salesmen are facing their usual task - to visit several cities of Ruritania and return to the starting point (cyclic route), each of them chosing the shortest possible route (according to his own metric). These are Ruritanian Salesmen and they are named Euclid, Manhattan and Chebyshev according to their manners of travelling.

Euclid is the most ordinary fellow and travels by straight line connecting the cities
Manhattan is poor at navigation, thus he travels only along north-south and west-east directions; i.e. he first goes straight north or south to reach the latitude of the target city and then travels along this latitude (Ruritania is flat country, not spheric)
Chebyshev is chess-king-like, his manner is similar to Manhattan but he also can run along diagonals, (and his diagonal movements are sqrt(2) faster than normal orthogonal).
So for example, if they start from coordinates (0, 0) and the target city is at famous (4, 3) point, then (assuming the speed of 1 ruritanian mile per hour), Euclid reaches the target in 5 hours, Manhattan in 7 while Chebyshev arrives the first of all, just in 4 hours.

Problem Statement
We are given a list of cities (their coordinates) to be visited by these three friends. Find the shortest route and tell the travelling time for each of them.

Input data give the number of cities (N) in the first line. Then N lines contain coordinate pairs for these cities.

Answer should contain three values - travelling times for Euclid, Manhattan and Chebyshev, rounded to nearest integer where necessary.

Example

input: 2 0 0 3 4

answer: 10 14 8

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

double
euclidean(Point p, Point q)
{
	return hypot(p.x - q.x, p.y - q.y);
}

double
manhattan(Point p, Point q)
{
	return abs(p.x - q.x) + abs(p.y - q.y);
}

double
chebyshev(Point p, Point q)
{
	return fmax(abs(p.x - q.x), abs(p.y - q.y));
}

void
distances(Point from, Point to, double result[3])
{
	result[0] += euclidean(from, to);
	result[1] += manhattan(from, to);
	result[2] += chebyshev(from, to);
}

void
solve(Point *cities, size_t ncities)
{
	double result[3];
	size_t i;

	memset(result, 0, sizeof(result));
	for (i = 0; i < ncities; i++)
		distances(cities[i], cities[(i + 1) % ncities], result);

	result[0] = round(result[0]);
	result[1] = round(result[1]);
	result[2] = round(result[2]);

	printf("%.0f %.0f %.0f\n", result[0], result[1], result[2]);
}

int
main()
{
	Point cities[] = {
		{ 0, 0 },
		{ 3, 4 },
	};

	solve(cities, nelem(cities));
	return 0;
}
