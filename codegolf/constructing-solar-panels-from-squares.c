/*

I'm designing a new space station for generic super-villain purposes (something something megalaser), but I'm having trouble designing the solar panels.

My genius team of scientists can calculate exactly how many square meters of paneling we need to power the station, but the problem is our solar panels only come in squares!

Thankfully due to a generous supply of duct tape, my minions can stitch together the right squares to make up the surface area needed, but my scientists have gone on strike (something about cyanide not being an ethical coffee sweetener) and my minions are too stupid to figure out what squares they need to connect.

That's where you come in minion loyal golfer. I need some code that will take the target surface area and tell me what size solar panels my minions need to tape together to reach it.

The minions have a tiny budget, so they still have to program their computer by punchcard. Time spent programming is time not spent taping, so make sure your code is as small as possible!

The Challenge
Given a positive integer n, output the smallest list of square numbers that sums to n.

A square number is any integer that is the result of multiplying an integer by itself. For example 16 is a square number because 4 x 4 = 16
This is A000290

For example:
For n = 12, you could achieve the desired size with 4 panels of sizes [9, 1, 1, 1] (note that this is the correct answer for the Google FooBar variant of this challenge), however this is not the smallest possible list, because you can also achieve the desired size with 3 panels of sizes [4, 4, 4]
For n = 13, you can achieve the desired size with only 2 panels: [9, 4]

If n is a square number, the output should be [n].

Input
A positive integer n representing the total desired surface area of the solar panels.
Note that 0 is not positive

Output
The smallest possible list of square numbers that sums to n, sorted in descending order.
If there are multiple smallest possible lists, you may output whichever list is most convenient.

Testcases
1 -> [1]
2 -> [1,1]
3 -> [1,1,1]
4 -> [4]
7 -> [4,1,1,1]
8 -> [4,4]
9 -> [9]
12 -> [4,4,4]
13 -> [9,4]
18 -> [9,9]
30 -> [25,4,1]
50 -> [49,1] OR [25,25]
60 -> [49,9,1,1] OR [36,16,4,4] OR [25,25,9,1]
70 -> [36,25,9]
95 -> [81,9,4,1] OR [49,36,9,1] OR [36,25,25,9]
300 -> [196,100,4] OR [100,100,100]
1246 -> [841,324,81] OR one of 4 other possible 3-length solutions
12460 -> [12100,324,36] OR one of 6 other possible 3-length solutions
172593 -> [90601,70756,11236] OR one of 18 other possible 3-length solutions

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void
print(int n, int *r, int l)
{
	int i;

	printf("%d | ", n);
	for (i = 0; i < l; i++)
		printf("%d ", r[i]);
	printf("\n");
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
squares(int a, int b, int c, int d, int n, int r[4])
{
	int i, s;

	s = (a * a) + (b * b) + (c * c) + (d * d);
	if (s > n)
		return 0;
	if (s != n)
		return -1;

	r[0] = a * a;
	r[1] = b * b;
	r[2] = c * c;
	r[3] = d * d;
	qsort(r, 4, sizeof(*r), cmp);

	for (i = 0; i < 4; i++) {
		if (!r[i])
			break;
	}
	return (i) ? i : 1;
}

// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
int
solve(int n, int r[4])
{
	int a, b, c, d, l;

	if (n < 0)
		return 0;

	for (a = 0; a <= n; a++) {
		if ((l = squares(a, 0, 0, 0, n, r)) > 0)
			return l;
		for (b = 0; b <= n; b++) {
			if ((l = squares(a, b, 0, 0, n, r)) > 0)
				return l;
			if (!l)
				break;
			for (c = 0; c <= n; c++) {
				if ((l = squares(a, b, c, 0, n, r)) > 0)
					return l;
				if (!l)
					break;
				for (d = 0; d <= n; d++) {
					if ((l = squares(a, b, c, d, n, r)) > 0)
						return l;
					if (!l)
						break;
				}
			}
		}
	}
	return 0;
}

void
test(int n)
{
	int r[4], l;

	l = solve(n, r);
	print(n, r, l);
	assert(r[0] + r[1] + r[2] + r[3] == n);
}

int
main()
{
	int i;

	test(1);
	test(2);
	test(3);
	test(4);
	test(7);
	test(8);
	test(9);
	test(12);
	test(13);
	test(18);
	test(30);
	test(50);
	test(60);
	test(70);
	test(95);
	test(300);
	test(1246);
	test(12460);
	test(172593);

	for (i = 0; i <= 10000; i++)
		test(i);

	return 0;
}
