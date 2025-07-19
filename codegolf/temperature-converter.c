/*

This is a byte sized challenge where you have to convert an input temperature in one of the three units (Celsius, Kelvin and Fahrenheit) to the other two.

Input
You would be provided with a temperature as a number followed by a unit (separated by space). The temperature can be an integer or a floating point number (23 vs 23.0 or 23.678).

You can submit a function or a full program that reads the space separated string from STDIN/ARGV/function argument or the closest equivalent and prints the output to STDOUT or closest equivalent.

Output
Your output should be the temperature converted to the other two formats, separated by a newline and followed by the corresponding unit character on each line (optionally separated by a space). The order of the two units does not matter.

Output precision

The converted number should be accurate to at least 4 decimal places without rounding.
Trailing zeroes or decimal places are optional as long as first 4 decimal places (without rounding) are precise. You can also skip the 4 zeroes and/or the decimal point in case the actual answer has 4 zeroes after the decimal point.
There should not be any leading zeroes
Any number format is acceptable as long as it fulfills the above three requirements.
Unit representation
Unit of temperature can only be one of the following:

C for Celsius
K for Kelvin
F for Fahrenheit
Examples
Input:

23 C
Output:

73.4 F
296.15 K
Input:

86.987 F
Output:

303.6983 K
30.5483 C
Input:

56.99999999 K
Output:

-216.1500 C
-357.0700 F
This is code-golf so shortest entry in bytes wins! Happy Golfing!

*/

#include <stdio.h>
#include <string.h>

typedef double (*unitfn)(double);

double
fahr2cel(double F)
{
	return ((F - 32) * 5) / 9;
}

double
fahr2kel(double F)
{
	return (((F - 32) * 5) / 9) + 273.15;
}

double
cel2kel(double C)
{
	return C + 273.15;
}

double
cel2fahr(double C)
{
	return ((C * 9) / 5) + 32;
}

double
kel2fahr(double K)
{
	return (((K - 273.15) * 9) / 5) + 32;
}

double
kel2cel(double K)
{
	return K - 273.15;
}

int
conv(const char *s)
{
	static const unitfn funcs[3][3] = {
	    {NULL, cel2fahr, cel2kel},
	    {fahr2cel, NULL, fahr2kel},
	    {kel2cel, kel2fahr, NULL},
	};

	static const char units[] = "CFK";

	unitfn f;
	double x, y;
	char c, *p;
	int i;

	if (sscanf(s, "%lf %c", &x, &c) != 2)
		return -1;

	p = strchr(units, c);
	if (!p)
		return -1;

	printf("[%s]\n", s);
	for (i = 0; i < 3; i++) {
		f = funcs[p - units][i];
		if (!f)
			continue;

		y = f(x);
		printf("%.4f %c\n", y, units[i]);
	}
	printf("\n");

	return 0;
}

int
main()
{
	conv("23 C");
	conv("86.987 F");
	conv("56.99999999 K");

	return 0;
}
