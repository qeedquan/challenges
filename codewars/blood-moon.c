/*

Alan is going to watch the Blood Moon (lunar eclipse) tonight for the first time in his life. But his mother, who is a history teacher, thinks the Blood Moon comes with an evil intent. The ancient Inca people interpreted the deep red coloring as a jaguar attacking and eating the moon. But who believes in Inca myths these days? So, Alan decides to prove to her mom that there is no jaguar. How? Well, only little Alan knows that. For now, he needs a small help from you. Help him solve the following calculations so that he gets enough time to prove it before the eclipse starts.

https://i.ibb.co/jRd3Z1K/Screenshot-3.png

Three semicircles are drawn on AB, AD, and AF. Here CD is perpendicular to AB and EF is perpendicular to AD.

Task
Given the radius of the semicircle ADBCA, find out the area of the lune AGFHA (the shaded area).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(double r)
{
	return (r * r) / 4;
}

void
test(double r, double a)
{
	double v;

	v = area(r);
	printf("%f\n", v);
	assert(fabs(v - a) < 1e-6);
}

int
main()
{
	test(0, 0);
	test(1, 0.25);
	test(2, 1);
	test(3, 2.25);
	return 0;
}
