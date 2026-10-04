/*

As input you will receive

An integer a

A list of integers that is infinite and strictly-monotonic1.

Your program should check in finite time if a appears the list.

You should output one of two distinct values. One if a appears in the list and the other if a does not.

This is code-golf so answers will be scored by their length in bytes with fewer bytes being better.

You may take an infinite lists in any of the following formats:

A list, stream, iterator or generator if your language allows them to be infinite.

A function or pointer to a function that outputs the next value when queried with no input.

A function or pointer to a function that outputs the nth value when passed n as an input.

Additionally you may repeatedly query STDIN with the assumption that each query will provide the next term in the sequence.

Test cases
Since I cannot put infinite lists in the body of a challenge I will provide the first couple terms along with a description of the list and a definition in Haskell.

6
1 2 3 4 5 6 7 8 9 10 ... (positive integers) l=[1..]
 =>
True
6
-1 -2 -3 -4 -5 -6 -7 -8 -9 -10 ... (negative integers) l=[-1,-2..]
 =>
False
109
0 2 4 6 8 10 12 14 16 18 20 ... (non-negative even integers) l=[0,2..]
 =>
False
-5
200 199 198 197 196 195 194 193 192 ... (integers smaller than 201) l=[200,199..]
 =>
True
256
1 2 3 5 8 13 21 34 55 89 144 ... (unique Fibonacci numbers) l=1:2:zipWith(+)l(tail l)
 =>
False
1
1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 ... (integers less than 2) l=[1,0..]
 =>
True

1: A strictly monotonic sequence is either entirely increasing or entirely decreasing. This means if you take the differences between consecutive elements they will all have the same sign.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
id(int x)
{
	return x;
}

int
neg(int x)
{
	return -x;
}

int
twice(int x)
{
	return x * 2;
}

int
lt200(int x)
{
	return 200 - x;
}

int
fib(int x)
{
	int a, b, c, i;

	if (x < 0)
		return 0;

	a = 0;
	b = 1;
	for (i = 0; i < x; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

int
lt2(int x)
{
	return 1 - x;
}

/*

@dingledooper

Since the list is always either strictly increasing or decreasing, we only need to check if a appears in the next |a-g(0)|+1 numbers.

*/

bool
member(int a, int (*f)(int))
{
	int i, n;

	n = abs(a - f(0)) + 1;
	for (i = 0; i < n; i++) {
		if (f(i) == a)
			return true;
	}
	return false;
}

int
main(void)
{
	assert(member(6, id) == true);
	assert(member(6, neg) == false);
	assert(member(109, twice) == false);
	assert(member(-5, lt200) == true);
	assert(member(256, fib) == false);
	assert(member(1, lt2) == true);

	return 0;
}
