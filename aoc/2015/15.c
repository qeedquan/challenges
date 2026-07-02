/*

--- Day 15: Science for Hungry People ---
Today, you set out on the task of perfecting your milk-dunking cookie recipe. All you have to do is find the right balance of ingredients.

Your recipe leaves room for exactly 100 teaspoons of ingredients. You make a list of the remaining ingredients you could use to finish the recipe (your puzzle input) and their properties per teaspoon:

capacity (how well it helps the cookie absorb milk)
durability (how well it keeps the cookie intact when full of milk)
flavor (how tasty it makes the cookie)
texture (how it improves the feel of the cookie)
calories (how many calories it adds to the cookie)
You can only measure ingredients in whole-teaspoon amounts accurately, and you have to be accurate so you can reproduce your results in the future. The total score of a cookie can be found by adding up each of the properties (negative totals become 0) and then multiplying together everything except calories.

For instance, suppose you have these two ingredients:

Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8
Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3
Then, choosing to use 44 teaspoons of butterscotch and 56 teaspoons of cinnamon (because the amounts of each ingredient must add up to 100) would result in a cookie with the following properties:

A capacity of 44*-1 + 56*2 = 68
A durability of 44*-2 + 56*3 = 80
A flavor of 44*6 + 56*-2 = 152
A texture of 44*3 + 56*-1 = 76
Multiplying these together (68 * 80 * 152 * 76, ignoring calories for now) results in a total score of 62842880, which happens to be the best score possible given these ingredients. If any properties had produced a negative total, it would have instead become zero, causing the whole score to multiply to zero.

Given the ingredients in your kitchen and their properties, what is the total score of the highest-scoring cookie you can make?

--- Part Two ---
Your cookie recipe becomes wildly popular! Someone asks if you can make another recipe that has exactly 500 calories per cookie (so they can use it as a meal replacement). Keep the rest of your award-winning process the same (100 teaspoons, same ingredients, same scoring system).

For example, given the ingredients above, if you had instead selected 40 teaspoons of butterscotch and 60 teaspoons of cinnamon (which still adds to 100), the total calorie count would be 40*8 + 60*3 = 500. The total score would go down, though: only 57600000, the best you can do in such trying circumstances.

Given the ingredients in your kitchen and their properties, what is the total score of the highest-scoring cookie you can make with a calorie total of 500?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
xint(char **s)
{
	int r;
	char *ep;

	for (r = 0; **s; *s += 1) {
		if (isdigit(**s) || **s == '-') {
			r = strtol(*s, &ep, 0);
			*s = ep;
			break;
		}
	}
	return r;
}

void
load(const char *name, int p[4][5])
{
	FILE *fp;
	char b[128], *s;
	int i, j;

	fp = fopen(name, "rb");
	if (!fp) {
		printf("Failed to load file: %s\n", strerror(errno));
		exit(1);
	}

	memset(p, 0, 4 * sizeof(*p));
	for (i = 0; i < 4; i++) {
		if (!fgets(b, sizeof(b), fp))
			break;

		s = b;
		for (j = 0; j < 5; j++)
			p[i][j] = xint(&s);
	}

	fclose(fp);
}

int
score(int p[4][5], int a, int b, int c, int d, bool f)
{
	int i, r, x;

	if (f) {
		x = (p[0][4] * a) + (p[1][4] * b) + (p[2][4] * c) + (p[3][4] * d);
		if (x != 500)
			return 0;
	}

	r = 1;
	for (i = 0; i < 4; i++) {
		x = (p[0][i] * a) + (p[1][i] * b) + (p[2][i] * c) + (p[3][i] * d);
		if (x <= 0)
			return 0;
		r *= x;
	}
	return r;
}

int
solve(int p[4][5], bool f)
{
	int a, b, c, d, n, r;

	n = 101;
	r = INT_MIN;
	for (a = 0; a < n; a++) {
		for (b = 0; b < n - a; b++) {
			for (c = 0; c < n - a - b; c++) {
				d = (n - 1) - a - b - c;
				r = max(r, score(p, a, b, c, d, f));
			}
		}
	}
	return r;
}

int
main()
{
	int p[4][5];

	load("15.txt", p);
	printf("%d\n", solve(p, false));
	printf("%d\n", solve(p, true));

	return 0;
}
