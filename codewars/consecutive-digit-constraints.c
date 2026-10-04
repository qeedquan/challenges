/*

This kata is based on Project Euler Problem 164 ( https://projecteuler.net/problem=164 )

Objective
Write a function that takes a number n and returns the number of n digit numbers (without leading zeros) that no three consecutive digits have a sum greater than 9

Examples
| n  |  number of numbers
|--------------------------
| 1  |  9 (0 doesn't count)
| 2  | 45
| 3  | 165

Note:
n ranges from 1 to 500
Code length limit = 5000 to avoid hard coded solutions

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
numbers(vlong n)
{
	vlong p[10][10];
	vlong q[10][10];
	vlong a, b, c;
	vlong u, v;
	vlong i, r;

	if (n < 1)
		return 0;
	if (n == 1)
		return 9;

	memset(p, 0, sizeof(p));
	for (a = 1; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			if (a + b <= 9)
				p[a][b] = 1;
		}
	}

	for (i = 3; i <= n; i++) {
		memset(q, 0, sizeof(q));
		for (a = 0; a < 10; a++) {
			for (b = 0; b < 10; b++) {
				if (p[a][b] == 0)
					continue;

				v = p[a][b];
				u = 9 - (a + b);
				if (u < 0)
					continue;
				for (c = 0; c <= u; c++)
					q[b][c] += v;
			}
		}
		memcpy(p, q, sizeof(p));
	}

	for (r = a = 0; a < 10; a++) {
		for (b = 0; b < 10; b++)
			r += p[a][b];
	}
	return r;
}

int
main()
{
	assert(numbers(1) == 9);
	assert(numbers(2) == 45);
	assert(numbers(3) == 165);
	assert(numbers(4) == 990);
	assert(numbers(5) == 5445);

	return 0;
}
