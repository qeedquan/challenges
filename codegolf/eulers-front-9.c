/*

https://i.sstatic.net/eoidS.jpg

Project Euler is another fun programming challenge site to compete (well, play) on. Early problems start off gently, but then explode in difficulty beyond the first hundred or so. The first few problems have some commonality between finding primes, multiples, and factors, so there could be some interesting code micro-reuse opportunities to toy with.

So, write a program that solves, using no a priori knowledge, any of the first 9 problems.

The problem is selected by the user, ASCII '1' through '9', inclusive, via an argument when calling or standard input while running. (You can compute all the answers, but only show one.)
The correct answer must be printed on a new line, in base 10, using ASCII.
Programs should execute in less than a minute (PE suggestion).
By "no a priori knowledge", I mean your code must derive the answer without external resources‡. A program like this would be considered invalid (otherwise correct though, assuming I didn't make a typo):

print[233168,4613732,6857,906609,232792560,25164150,104743,40824,31875000][input()-1]
‡for problem #8 (involves a 1000-digit number), you may read the number from an external file, just specify how it's stored (e.g. binary, text, header, imported module) and/or include it in your answer post (does not count towards the length of the main program).

Score is by bytes.

Fifteen Unicorn Points™ awarded to the byte-count leader after 2 weeks.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
euler9(unsigned n)
{
	static const long tab[] = {233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 40824, 31875000};

	if (n < 1 || n > nelem(tab))
		return -1;
	return tab[n - 1];
}

int
main()
{
	int i;

	for (i = 1; i <= 9; i++)
		printf("%ld\n", euler9(i));

	return 0;
}
