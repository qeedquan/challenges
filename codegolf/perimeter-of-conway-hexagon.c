/*

Background
Given a triangle ABC, extend its three sides by the opposite side length, as shown in the figure below.
Then the six points surprisingly lie on a circle called the Conway circle, whose center coincides with the incenter (the center of incircle, the circle that is tangent to the three sides from the inside).

https://i.stack.imgur.com/Ce0wV.gif

Task
Given three side lengths a,b,c of the triangle ABC, calculate the perimeter of the hexagon AbBaBcCbCaAc (formed by the six points on the Conway circle).

The answer must be within 1e-6 relative error from the expected. You can assume the side lengths form a valid non-degenerate triangle.

The shortest code in bytes wins.

Test cases
a   b   c         ans
---------------------
1   1   1    9.000000
2   2   3   20.399495
3   4   5   35.293155
6   7   12  65.799785
2.3 4.5 6.7 31.449770

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@Surculose Sputum

How
We can see that each side of the hexagon is the base of an isosceles triangle, whose vertex angle is an angle of the original triangle. For example:

CaCb is the base of CCaCb - an isosceles triangle with leg c and vertex angle C'.
AbBa is the base of CAbBa - an isosceles triangle with leg a+b and vertex angle C'.

Given the leg l and vertex angle θ of an isosleces triangle, the base is calculated as:
l*sqrt(2 - 2*cos(theta))

Consider 2 opposites side of the hexagon, says CaCb and AbBa. Since their corresponding triangles have the same vertex angle, their total length is:
c*sqrt(2 - 2cos(C')) + (a + b)*sqrt(2 - 2cos(C')) = (a + b + c)*(2 - 2cos(C'))

Then the perimeter of the hexagon is the sum of 3 opposite pairs:
(a + b + c) * (sqrt(2 - 2cos(A')) + sqrt(2 - 2cos(B')) + sqrt(2 - 2cos(C')))

The cosine of an angle can be calculated from the sides of the triangle:
2 - 2cos(C') = (c^2 - (a-b)^2) / (ab)

Thus, the final formula for the hexagon's perimeter is the one below

*/

double
perimeter(double a, double b, double c)
{
	double s1, s2, s3;

	s1 = ((a * a) - ((b - c) * (b - c))) / (b * c);
	s2 = ((b * b) - ((a - c) * (a - c))) / (a * c);
	s3 = ((c * c) - ((a - b) * (a - b))) / (a * b);
	return (a + b + c) * (sqrt(s1) + sqrt(s2) + sqrt(s3));
}

void
test(double a, double b, double c, double r)
{
	double p;

	p = perimeter(a, b, c);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(1, 1, 1, 9);
	test(2, 2, 3, 20.399495);
	test(3, 4, 5, 35.293155);
	test(6, 7, 12, 65.799785);
	test(2.3, 4.5, 6.7, 31.449770);

	return 0;
}
