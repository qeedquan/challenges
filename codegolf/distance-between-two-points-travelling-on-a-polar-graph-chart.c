/*

Brief Problem Explanation
Write a program to find the minimum distance between two points traveling only on rays emanating from the origin and circles centered on the origin.

Explanation of Premise
Now let's imagine we are on a plane, and on this plane we are only allowed to travel in special ways. We are allowed to travel on any ray emanating from the origin.

https://i.sstatic.net/9joWo.png

We can also travel on any circle centered at a circle

https://i.sstatic.net/3pXmM.png

Now our goal is to travel from one point on this plane to another. However, we can't just travel in a simple Euclidian path, we can only do this if the points happen to fall on a ray emanating from the center.

https://i.sstatic.net/sIKca.png

We can travel on this one because it falls on a one of our rays.

https://i.sstatic.net/tWa2n.png

We can also travel on circles centered at the origin.

https://i.sstatic.net/x8Me0.png

Examples
Now here is the challenge:

We've got to get from one point to another in the shortest path; often this is a combination of traveling on circles and rays.

https://i.sstatic.net/Lp1YE.png

This, however, it could also be traveling on two rays.

https://i.sstatic.net/w0nQH.png

Sometimes there exist two paths that travel the minimum distance.

https://i.sstatic.net/kMoqW.png

Problem
Your challenge is to write a program that when given two points will give us the minimum distance between them if we follow these rules. The inputs can be given in either rectangular or polar forms and the output ought to be one number, the distance between.

Test Cases
(with rectangular input)

(1,1) (1,-1) -> ~ 2.22144
(0,0) (1, 1) -> ~ 1.41421
(1,0) (-0.4161 , 0.90929) -> ~ 2
(1,1) (1, 0) -> ~ 1.19961
(1,2) (3, 4) -> ~ 3.16609

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
rect2polar(double x, double y, double *r, double *t)
{
	*r = hypot(x, y);
	*t = atan2(y, x);
}

double
distance(double x1, double y1, double x2, double y2)
{
	double r1, t1;
	double r2, t2;
	double t;

	rect2polar(x1, y1, &r1, &t1);
	rect2polar(x2, y2, &r2, &t2);
	t = acos(cos(t1 - t2));
	if (t < 2)
		return fabs(r1 - r2) + (t * fmin(r1, r2));
	return r1 + r2;
}

void
test(double x1, double y1, double x2, double y2, double r)
{
	double d;

	d = distance(x1, y1, x2, y2);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-4);
}

int
main()
{
	test(1, 1, 1, -1, 2.22144);
	test(0, 0, 1, 1, 1.41421);
	test(1, 0, -0.4161, 0.90929, 2);
	test(1, 1, 1, 0, 1.19961);
	test(1, 2, 3, 4, 3.16609);

	return 0;
}
