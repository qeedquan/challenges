#include <stdio.h>
#include <limits.h>

/*

Determine the 7th term of the arithmetic sequence. 3, 5, 7, ...

A: 15

*/

void
counting()
{
	int i, x;

	puts("Counting");
	x = 3;
	for (i = 1; i <= 7; i++) {
		printf("%d: %d\n", i, x);
		x += 2;
	}
	puts("");
}

/*

-500x - 200 = -1200 - 400x

1000 = 100x
x = 10

A: x = 10

*/

void
sameness()
{
	int a, b;
	int x;

	puts("Sameness");
	for (x = 0; x < INT_MAX; x++) {
		a = (-500 * x) - 200;
		b = -1200 - (400 * x);
		if (a == b) {
			printf("x=%d\n", x);
			break;
		}
	}
	puts("");
}

/*

Karen can complete 12 coloring book pages in 30 minutes. How long will it take Karen to complete 96-page coloring book?

96/12 * 30 = 240

A: 240 minutes

*/

void
proportional_thinking()
{
	puts("Proportional Thinking");
	puts("240 minutes");
	puts("");
}

/*

There is 10% salt solution and a 30% salt solution. How much of each is needed to make 10 liters of a mixture that is 25% salt?

0.1x + 0.3y = 1 =>
y = 3
x = 1

So the mixture ratio is
3:1

A: 2.5L of 10% solution and 7.5L of 30% solution

7.5*0.3 + 2.5*0.1 = 2.5
2.5/10 = 25%

*/

void
quantity_and_denomination()
{
	puts("Quantity and Denomination");
	puts("2.5L of 10% solution and 7.5L of 30% solution");
	puts("");
}

/*

Jake can mow a lawn in 3 hours. Kellie can mow a lawn in 4 hours. If they work together, how long will it take them to mow one lawn together?

3x=1 => x=1/3
4y=1 => y=1/4

1/3 + 1/4 = 4/12 + 3/12 = 7/12

(7/12)*z = 1 => z=12/7

A: 1 5/7 hours

*/

void
whole_and_parts()
{
	puts("Whole and Parts");
	puts("1 5/7 hours");
	puts("");
}

int
main()
{
	counting();
	sameness();
	proportional_thinking();
	quantity_and_denomination();
	whole_and_parts();
	return 0;
}
