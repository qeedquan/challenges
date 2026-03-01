/*

In this question I defined a "chain" function as a function that:
https://codegolf.stackexchange.com/questions/135127/make-an-infinite-chain

is a permutation, meaning that every value maps to and is mapped to by exactly one value.

and allows any value can be obtained from any other value by repeated applications of the function or its inverse.

There are a lot of functions that do this and some of them are pretty simple (see the answers on that question). Now we are going to define a separate class of functions I am going to call "interwoven" functions. An interwoven function is a function on a set A, that has two infinite partitions a0 and a1 such that the function is a chain function on both a0 and a1.

This means that no value in a0 can map to a value in a1 under the function or vice versa.

Task
Your task is to write a code that performs or defines an interwoven function on the positive integers. Your function can be anything as long as it satisfies the criteria for being interwoven. You should include a explanation as to why your function is interwoven in the answer.

This is a code-golf question so answers will be scored in bytes, with less bytes being better.

*/

#include <stdio.h>

// Ported from @Uriel solution
int
f(int n)
{
	if (1 < n && n < 4)
		return (n * 2) % 5;
	return n - ((n & 2) * 4) + 4;
}

void
iterate(int n, int l)
{
	int i;

	for (i = 0; i < l; i++) {
		printf("%d", n);
		if (i + 1 < l)
			printf(" => ");
		n = f(n);
	}
	printf("\n");
}

int
main(void)
{
	iterate(22, 15);
	iterate(23, 15);

	return 0;
}
