/*

Welcome to the grinder.

Your task is to make big rocks into small rocks by grinding them.

Take an input of a big rock of size n > 3  and grind it.

Continue to grind the rocks by dumping them into the grinder until the size of all the rocks are 2.

rocks are always grinded into equal even halves. If the result of a grinding is odd take result - 1.

Print the output of each grinding as you proceed.

Examples
input: 5

output: 22

The result are two rocks of size 2

input: 50

output:

2424 //two rocks of size 24
12121212 //four rocks of size 12
66666666 //8 rocks of size 6
2222222222222222
the result is 16 rocks of size 2

input: 30

output:

1414
6666
22222222
the result is 8 rocks of size 2

This is code-golf so the shortest code wins! Have fun and good luck!

*/

#include <stdio.h>

void
grind(unsigned n)
{
	unsigned i, l;

	l = 1;
	do {
		for (i = 0; i < l; i++)
			printf("%u", n);
		printf("\n");

		l *= 2;
		n /= 2;
		if (n & 1)
			n -= 1;
	} while (n >= 2);
	printf("\n");
}

int
main(void)
{
	grind(5);
	grind(50);
	grind(30);

	return 0;
}
