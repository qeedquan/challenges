/*

You just got done with your set at the gym, and you are wondering how much weight you could lift if you did a single repetition. Thankfully, a few scholars have devised formulas for this purpose (from Wikipedia) :
https://en.wikipedia.org/wiki/One-repetition_maximum

Epley
1 RM = w * (1 + r/30)

McGlothin
1 RM = 100*w / (101.3 - 2.67123*r)

Lombardi
1 RM = w*r^0.10

Your function will receive a weight w and a number of repetitions r and must return your projected one repetition maximum. Since you are not sure which formula to use and you are feeling confident, your function will return the largest value from the three formulas shown above, rounded to the nearest integer. However, if the number of repetitions passed in is 1 (i.e., it is already a one rep max), your function must return w. Also, if the number of repetitions passed in is 0 (i.e., no repetitions were completed), your function must return 0.

*/

#include <stdio.h>
#include <math.h>

double
epley(double w, double r)
{
	return w * (1 + (r / 30));
}

double
mcglothin(double w, double r)
{
	return (100 * w) / (101.3 - (2.67123 * r));
}

double
lombardi(double w, double r)
{
	return w * pow(r, 0.10);
}

int
calculate(double w, double r)
{
	double x;

	x = epley(w, r);
	x = fmax(x, mcglothin(w, r));
	x = fmax(x, lombardi(w, r));
	return round(x);
}

int
main()
{
	double w, r;

	for (w = 0; w <= 20; w++) {
		for (r = 0; r <= 5; r++)
			printf("%-4.1f %-4.1f %-4.1f | ", epley(w, r), mcglothin(w, r), lombardi(w, r));
		printf("\n");
	}
	return 0;
}
