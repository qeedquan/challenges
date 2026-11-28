/*

Problem
given input a,b,c

where a,b,c are positive even integers

and a > b > c

Make a box of any allowed character with dimensions a x a

Center a box of a different allowed character with dimensions b x b within the previous

Center a box of another different allowed character with dimensions c x c within the previous

Allowed Characters are ASCII characters are in [a-zA-z0-9!@#$%^&*()+,./<>?:";=_-+]

Input a=6, b=4, c=2

######
#****#
#*@@*#
#*@@*#
#****#
######
Input a=8, b=6, c=2

########
#******#
#******#
#**@@**#
#**@@**#
#******#
#******#
########
Input a=12, b=6, c=2

############
############
############
###******###
###******###
###**@@**###
###**@@**###
###******###
###******###
############
############
############

Rules
Shortest code wins
Remember that you can choose which char to print within the range given
Trailing newlines accepted
Trailing whitespace accepted
functions may return string with newlines, string array, or print it

*/

#include <stdio.h>
#include <string.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
sort3d(int *a, int *b, int *c)
{
	if (*a < *b)
		swap(a, b);
	if (*a < *c)
		swap(a, c);
	if (*b < *c)
		swap(b, c);
}

int
in(int x, int y, int r)
{
	return (-r <= x && x < r) && (-r <= y && y < r);
}

void
boxes(int a, int b, int c)
{
	int x, y, xc, yc;

	sort3d(&a, &b, &c);
	printf("a=%d b=%d c=%d\n", a, b, c);
	for (y = 0; y < a; y++) {
		for (x = 0; x < a; x++) {
			xc = x - (a / 2);
			yc = y - (a / 2);
			if (in(xc, yc, c / 2))
				printf("@");
			else if (in(xc, yc, b / 2))
				printf("*");
			else
				printf("#");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	boxes(6, 4, 2);
	boxes(8, 6, 2);
	boxes(12, 6, 2);
	boxes(16, 14, 12);

	return 0;
}
