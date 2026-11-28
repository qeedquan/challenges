/*

You all probably know how to calculate the distance between two points in two dimensional cartesian plane. But in this problem you have to find the minimum arc distance between two points and they are on a circle centered at another point.

You will be given the co-ordinates of the points A and B and co-ordinate of the center O. You just have to calculate the minimum arc distance between A and B. In the picture, you have to calculate the length of arc ACB. You can assume that A and B will always be on the circle centered at O.

https://static.lightoj.com/images/problem-1433/5jz7u3tD-1602925148825.png?centerme

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing six integers Ox, Oy, Ax, Ay, Bx, By where (Ox, Oy) indicates the co-ordinate of O, (Ax, Ay) denote the co-ordinate of A and (Bx, By) denote the co-ordinate of B. All the integers will lie in the range [1, 10000].

Output
For each case, print the case number and the minimum arc distance. Errors less than 10-3 will be ignored.

Sample
Input	Output
5
5711 3044 477 2186 3257 7746
3233 31 3336 1489 1775 134
453 4480 1137 6678 2395 5716
8757 2995 4807 8660 2294 5429
4439 4272 1366 8741 6820 9145

Case 1: 6641.81699183
Case 2: 2295.92880
Case 3: 1616.690325
Case 4: 4155.64159340
Case 5: 5732.01250253

*/

#include <stdio.h>
#include <math.h>

double
sqr(double x)
{
	return x * x;
}

/*

arc length = (radius of the circle) * (angle created by the 2 points at the center of the circle, in radian)

The bigger the arc length, the bigger becomes the angle in between the 2 points of the cirlce and vice versa. We can see that the Circumference is the longest arc length of a circle, also we know C = 2 * π * (radius of the cirlce).

C is the arc length when θ = 2 * π
1 is the arc length when θ = (2 * π)/C
                           = (2 * π)/(2 * π *r)
                           = 1/r
S is the arc length when θ = S/r

So, S = θ * r

We can calculate the radius of the circle simply by taking the distance of any point of a circle to its center, distance = √((P1x - P2x)² + (P1y - P2y)²).

Now to calculate the angle we can use the cosine rule of triangles,

AB (Straight line, not the arc length) = √(OA²+OB²-2*OA*OB*cosθ)
=> AB²  = OA²+OB²-2*OA*OB*cosθ
=> cosθ = (OA²+OB²-AB²)/2*OA*OB
=> θ = arccos ((OA²+OB²-AB²)/2*OA*OB)

*/

double
solve(double ox, double oy, double ax, double ay, double bx, double by)
{
	double OA, OB, AB;
	double angle;

	OA = hypot(ax - ox, ay - oy);
	OB = hypot(bx - ox, by - oy);
	AB = hypot(ax - bx, ay - by);
	angle = acos((sqr(OA) + sqr(OB) - sqr(AB)) / (2 * OA * OB));
	return OA * angle;
}

int
main()
{
	printf("%f\n", solve(5711, 3044, 477, 2186, 3257, 7746));
	printf("%f\n", solve(3233, 31, 3336, 1489, 1775, 134));
	printf("%f\n", solve(453, 4480, 1137, 6678, 2395, 5716));
	printf("%f\n", solve(8757, 2995, 4807, 8660, 2294, 5429));
	printf("%f\n", solve(4439, 4272, 1366, 8741, 6820, 9145));

	return 0;
}
