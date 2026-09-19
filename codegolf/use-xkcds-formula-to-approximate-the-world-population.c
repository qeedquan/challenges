/*

In xkcd 1047, Randall Munroe lists "slightly wrong" approximations of assorted quantities and numbers with varying precision and complexity, such as that the number of liters in a gallon is very close to 3 + π⁄4.
In the middle of the comic, he gives an intermission: a way to estimate the world (and United States) population based for a given year.

https://xkcd.com/1047/

(Cropped from xkcd: Approximations by Randall Munroe)

Your task is to write a program that implements these formulas to approximate the current world and U.S. populations, replicated as follows.

World population
Take the last two digits of the current year.
Subtract the number of leap years (including the current year) since Hurricane Katrina (2005). For these purposes, any year divisible by 4 is considered a leap year.
Add a decimal point between the two numbers (the same as dividing by 10).
Add 6. This gives the result in billions of people.

U.S. population
Take the last two digits of the current year.
Subtract 10.
Multiply by 3.
Add 10.
Add 3 to the beginning (for this challenge, some numbers will be negative, so add 300 instead). Somehow I didn't notice that just concatenating wouldn't work because the program I used to generate the results just added 300.
This gives the result in millions of people.
Details
This formula "should stay current for a decade or two," but you must be able to theoretically handle any year 2000–2039 inclusive. For some cases, the leap years since Katrina will have a negative or zero value.

You are free to simplify the formula in any way, as long as all outputs match the ones below.

For the year, use the year according to the computer's clock. It must work next year and any other year this century, so you cannot simply hardcode 2015. For convenience, you might want to include a way to specify the year as a variable or input to test other years.

The output should be the approximated world population (in billions of people), followed by some delimiter (e.g. space or comma), followed by the U.S. population (in millions of people). You may also write a function that returns or prints a string or an array of numbers or strings.

This is code golf, so shortest code in bytes wins. Tiebreaker is earliest post.

Test cases
This is a list of all possible years, followed by the two outputs.

Year   World  U.S.
2000    6.1   280
2001    6.2   283
2002    6.3   286
2003    6.4   289
2004    6.4   292
2005    6.5   295
2006    6.6   298
2007    6.7   301
2008    6.7   304
2009    6.8   307
2010    6.9   310
2011    7     313
2012    7     316
2013    7.1   319
2014    7.2   322
2015    7.3   325
2016    7.3   328
2017    7.4   331
2018    7.5   334
2019    7.6   337
2020    7.6   340
2021    7.7   343
2022    7.8   346
2023    7.9   349
2024    7.9   352
2025    8     355
2026    8.1   358
2027    8.2   361
2028    8.2   364
2029    8.3   367
2030    8.4   370
2031    8.5   373
2032    8.5   376
2033    8.6   379
2034    8.7   382
2035    8.8   385
2036    8.8   388
2037    8.9   391
2038    9     394
2039    9.1   397

*/

#include <stdio.h>
#include <math.h>

void
population(int y, double *w, double *u)
{
	if (y < 1) {
		*w = *u = 0;
		return;
	}

	y %= 40;
	*w = 0.1 * (61 + y - floor(y / 4.0));
	*u = (y * 3) + 280;
}

int
main(void)
{
	double w, u;
	int y;

	for (y = 2000; y <= 2039; y++) {
		population(y, &w, &u);
		printf("%4d\t%.1f\t%.0f\n", y, w, u);
	}

	return 0;
}
