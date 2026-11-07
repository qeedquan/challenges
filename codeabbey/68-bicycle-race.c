/*

Two bicyclist start moving from different cities heading to meet each other somewhere in the middle (not exactly since they travel with different speed).

The road is laid in straight line between two cities.

You will be given the distance between cities S (in kilometers) and speed values for two bicyclists (A and B in kilometers per hour). Your task is to find their meeting point (its distance from the first of cities).

Input data will have the number of test-cases in the first line.
Next lines will contain three values each S A B.
Answer should contain the distances between first city and rendezvous point (i.e. distance travelled by first cyclist before they meet), separated with spaces.

Example:

input data:
2
10 1 1
20 1 2

answer:
5 6.66666667
Note: the floating point values should have precision 10e-7 or better

*/

#include <stdio.h>

/*

To find the meeting point's distance from the first city, calculate the time it takes for both bicyclists to meet,
and then multiply that time by the speed of the first bicyclist.

Time to meet (t)
Time = Distance_S / (Speed_A + Speed_B)

Distance from the first city Distance_A
Distance_A = Speed_A * Time = S * (A / (A + B))

*/

double
solve(double s, double a, double b)
{
	double t;

	t = s / (a + b);
	return a * t;
}

int
main()
{
	printf("%f\n", solve(10, 1, 1));
	printf("%f\n", solve(20, 1, 2));

	return 0;
}
