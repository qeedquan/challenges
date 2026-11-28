/*

The Shotgun numbers are a sequence with a rather simple definition but some interesting structure. Start with the natural numbers:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ...
Now take all numbers at indices divisible by 2, group them into pairs, and swap the numbers in each pair:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, ...
   ^     ^     ^     ^      ^       ^       ^
    <--->       <--->        <----->         <----
1, 4, 3, 2, 5, 8, 7, 6, 9, 12, 11, 10, 13, 16, ...
Now do the same with indices divisible by 3:

1, 4, 3, 2, 5, 8, 7, 6, 9, 12, 11, 10, 13, 16, ...
      ^        ^        ^           ^
       <------>          <--------->
1, 4, 8, 2, 5, 3, 7, 6, 10, 12, 11, 9, 13, 16, ...
And then for 4, 5, 6, and so on:

1, 4, 8, 2, 5, 3, 7, 6, 10, 12, 11, 9, 13, 16, ...
1, 4, 8, 6, 5, 3, 7, 2, 10, 12, 11, 14, 13, 16, ...
1, 4, 8, 6, 12, 3, 7, 2, 10, 5, 11, 14, 13, 16, ...
1, 4, 8, 6, 12, 14, 7, 2, 10, 5, 11, 3, 13, 16, ...
...
After k such steps, the first k+1 numbers will be fixed. So we can define the infinite sequence of Shotgun numbers as the limit of letting k go to infinity. The first 66 numbers are:

1, 4, 8, 6, 12, 14, 16, 9, 18, 20, 24, 26, 28, 22, 39, 15, 36, 35, 40, 38, 57, 34, 48, 49, 51, 44,
46, 33, 60, 77, 64, 32, 75, 56, 81, 68, 76, 58, 100, 55, 84, 111, 88, 62, 125, 70, 96, 91, 98, 95,
134, 72, 108, 82, 141, 80, 140, 92, 120, 156, 124, 94, 121, 52, 152, 145, ...
Fun fact: Despite being obtained by only permuting the natural numbers, this sequence does not contain any primes.

The Challenge
Given an integer n > 0, find the nth Shotgun number. You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and return the output or print it to STDOUT (or closest alternative).

This is code golf, so the shortest submission (in bytes) wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A064494
int
shotgun(int n)
{
	int i;

	for (i = n; i > 1; i--) {
		if (n % i)
			continue;
		if (!(n % (i * 2)))
			n -= i;
		else
			n += i;
	}
	return n;
}

int
main(void)
{
	static const int tab[] = {
		1, 4, 8, 6, 12, 14, 16, 9, 18, 20, 24, 26, 28, 22, 39, 15, 36, 35, 40,
		38, 57, 34, 48, 49, 51, 44, 46, 33, 60, 77, 64, 32, 75, 56, 81, 68, 76,
		58, 100, 55, 84, 111, 88, 62, 125, 70, 96, 91, 98, 95, 134, 72, 108,
		82, 141, 80, 140, 92, 120, 156, 124, 94, 121, 52, 152, 145
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(shotgun(i + 1) == tab[i]);

	return 0;
}
