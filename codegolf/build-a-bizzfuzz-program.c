/*

In traditional FizzBuzz, you are asked to print the numbers from 1 to 100, but replacing every multiple of 3 with "Fizz", every multiple of 5 with "Buzz", and every multiple of both 3 and 5 (i.e. 15) with "FizzBuzz".

However, as an evil interviewer, I've invented my own twisted version of FizzBuzz, which I've decided to name BizzFuzz and give to you in a coding interview.

The rules of the game are:

Print each number from 1 to 100, except if the number meets one of the conditions below.

If the number is divisible by 4, print "Fizz".
If the number is divisible by 5, print "Buzz".

If the number is divisible by 4, but the number immediately after it is divisible by 5, print "FizzBuzz" instead of "Fizz", and print the next number regularly.

If the number is divisible by 5, but the number immediately after it is divisible by 4, print "BuzzFizz" instead of "Buzz", and print the next number regularly.

If the number is immediately before a number divisible by both 4 and 5, print "Bizz".

If the number is immediately after a number divisible by both 4 and 5, print "Fuzz".

If the number is divisible by both 4 and 5, print "BizzFuzz".

The shortest code to implement all these rules in any language wins.

*/

#include <stdio.h>

void
bizzfuzz(int n)
{
	static const char *strings[] = {"Fizz", "Buzz", "Bizz", "Fuzz", "BizzFuzz", "FizzBuzz", "BuzzFizz"};
	static const char op[] = "ediifiiiaibiaiigiiic";
	static const size_t oplen = sizeof(op) - 1;

	int c, i;

	for (i = 1; i <= n; i++) {
		c = op[i % oplen];
		if (c == 'i')
			printf("%d\n", i);
		else
			printf("%s\n", strings[c - 'a']);
	}
}

int
main()
{
	bizzfuzz(100);
	return 0;
}
