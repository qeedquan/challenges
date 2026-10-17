/*

Description

In recent days, people always design new things with multifunction. For instance, you can not only use cell phone to call your friends, but you can also use your cell phone take photographs or listen to MP3. Another example is the combination between watch and television. These kinds of multifunction items can always improve people's daily life and are extremely favored by users.

The company Mr. Umbrella invented a new kind umbrella "UmBasketella" for people in Rainbow city recently and its idea also comes from such multifunction--the combination of umbrella and daily necessities. This kind of umbrella can be used as a basket and you can put something you want to carry in it. Since Rainbow city rains very often, such innovative usage is successful and "UmBasketella" sells very well. Unfortunately, the original "UmBasketella" do not have an automatic volume control technology so that it is easily damaged when users try to put too many things in it. To solve this problem, you are needed to design an "UmBasketella" with maximum volume. Suppose that "UmBasketella" is a cone-shape container and its surface area (include the bottom) is known, could you find the maximum value of the cone?

Input

Input contains several test cases. Eash case contains only one real number S, representing the surface area of the cone. It is guaranteed that 1≤S≤10000.

Output

For each test case, output should contain three lines.
The first line should have a real number representing the maximum volume of the cone.
Output the height of the cone on the second line and the radius of the bottom area of the cone on the third line.
All real numbers should rounded to 0.01.

Sample Input

30

Sample Output

10.93
4.37
1.55

Source

PKU Campus 2009 (POJ Monthly Contest – 2009.05.17), cyqclark

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

void
cone(double s, double *v, double *h, double *r)
{
	double r2, h2;

	r2 = s / (4 * M_PI);
	h2 = s * (s - (2 * M_PI * r2)) / (M_PI * M_PI * r2);
	*r = sqrt(r2);
	*h = sqrt(h2);
	*v = sqrt(M_PI * M_PI * r2 * r2 * h2) / 3.0;
}

void
test(double s, double rv, double rh, double rr)
{
	static const double eps = 1e-2;

	double v, h, r;

	cone(s, &v, &h, &r);
	printf("%.2f %.2f %.2f\n", v, h, r);
	assert(fabs(v - rv) < eps);
	assert(fabs(h - rh) < eps);
	assert(fabs(r - rr) < eps);
}

int
main(void)
{
	test(30, 10.93, 4.37, 1.55);

	return 0;
}
