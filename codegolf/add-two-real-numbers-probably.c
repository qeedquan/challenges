/*

The problem statement here is pretty simple, take two real numbers on the range [0,1) as input and output their sum, with probability 1.

The catch here is that there are a lot of real numbers. There are in fact so many real numbers that it is impossible to fit all of them into any finite data type. As such, any way to input real numbers has to be potentially infinite, and any algorithm that handles arbitrary real numbers cannot consume all of the input.

For this challenge you will input (and output) real numbers as lazy sequence (e.g. stream, generator, lazy list, function) of bits, representing their binary expansion. You can assume that the input will be normalized and will not end in an infinite repetition of 1.

Even with this special input format it isn't possible to add any two real numbers. Any potential algorithm can be tricked into an infinite loop.

So instead we are going to settle for almost working. To "work" on a pair of inputs your program needs to be able to output any bit of the output in finite time. For example, if you output a generator I should be able to read to the 5th bit without the program getting stuck in a loop. Your answer needs to work with probability 1, meaning that the measure of the set of inputs which your program does work needs to have measure 1. The behavior for which the program doesn't work is undefined it can loop forever give an incorrect answer etc. so long as these cases themselves have measure zero.

This is code-golf the goal is to minimize the size of your source code as measured in bytes.

Examples
Here are some examples of rational numbers being added. You do not need to support any of these specific numbers.

1/3  = 0.01010101010101010...
+
1/5  = 0.00110011001100110...
=
8/15 = 0.10001000100010001...

3/8  = 0.011000000000000000...
+
3/16 = 0.001100000000000000...
=
9/16 = 0.100100000000000000...

17/95    = 0.001011011100111101111110101001110001001011011100111101111110101...
+
3/13     = 0.001110110001001110110001001110110001001110110001001110110001001...
=
506/1235 = 0.011010001110001100101111111000100010011010001110001100101111111...

*/

#include <stdio.h>

typedef int (*iterfn)(void *);

int
next(void *ud)
{
	const char **p;
	int r;

	p = ud;
	r = (*p)[0];
	*p += 1;
	return r;
}

/*

@loop walt

How?
Count bits that differ between the inputs without outputting anything until an equal bit is encountered. Output this bit followed by counter times its complement. Reset counter and start over.

Note:
Since this algorithm needs to delay until a specific bit is found for output, it has a lead-lag output.

*/

char *
add(iterfn f, void *a, void *b, char *p)
{
	size_t l;
	int x, y;
	int i, n;

	l = 0;
	n = 0;
	for (;;) {
		x = f(a);
		y = f(b);
		if (!x || !y)
			break;

		if (x != y) {
			n++;
		} else {
			p[l++] = x;
			for (i = 0; i < n; i++)
				p[l++] = (x == '0') ? '1' : '0';
			n = 0;
		}
	}
	p[l] = '\0';
	return p;
}

void
test(const char *a, const char *b, const char *r)
{
	char p[128];

	add(next, &a, &b, p);
	printf("%s\n%s\n\n", p + 1, r);
}

int
main()
{
	test("01010101010101010", "00110011001100110", "10001000100010001");
	test("011000000000000000", "001100000000000000", "100100000000000000");
	test("001011011100111101111110101001110001001011011100111101111110101", "001110110001001110110001001110110001001110110001001110110001001", "011010001110001100101111111000100010011010001110001100101111111");

	return 0;
}
