/*

Introduction
Last year was my birthday (really!) and sadly I had to organise my own party. Well, now you know, couldn't you at least make the cake?

Challenge
Given an integer n as input, write a full program to output a birthday cake with n candles on.

Output
A piece of cake with one candle on is:

 $
 |
---
~~~
---
And a piece of cake with three candles on is:

 $ $ $
 | | |
-------
~~~~~~~
-------
I'm sure you can work it out from that

However, for input 0, you must output the following:

Congratulations on your new baby! :D
For input less than 0, you should output a candleless cake:

---
~~~
---
Nothing is allowed to be output to STDERR.

Trailing newlines and spaces are allowed.

Winning
Shortest code in bytes wins.

*/

#include <stdio.h>

void
line(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
	printf("\n");
}

void
cake(int n)
{
	int m;

	if (n == 0) {
		printf("Congratulations on your new baby! :D\n\n");
		return;
	}

	if (n > 0) {
		line(" $", n);
		line(" |", n);
	} else
		n = 1;

	m = (2 * n) + 1;
	line("-", m);
	line("~", m);
	line("-", m);
	printf("\n");
}

int
main(void)
{
	cake(-20);
	cake(0);
	cake(1);
	cake(3);

	return 0;
}
