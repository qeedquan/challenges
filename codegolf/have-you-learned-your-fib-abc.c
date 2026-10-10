/*

I don't like numbers, but I do like the Fibonacci sequence. I'm sure we could work something out.

Please read one integer n from STDIN and output the nth Fibonacci number in base 26 (abcdefghijklmnopqrstuvwxyz instead of 0123456789) to STDOUT.

The first Fibonacci number is 0. The second one is 1. The nth fibonacci number is the sum of the n-2nd and n-1st Fibonacci numbers.

First 32 fib-abc numbers:

fib(0) = a
fib(1) = b
fib(2) = b
fib(3) = c
fib(4) = d
fib(5) = f
fib(6) = i
fib(7) = n
fib(8) = v
fib(9) = bi
fib(10) = cd
fib(11) = dl
fib(12) = fo
fib(13) = iz
fib(14) = on
fib(15) = xm
fib(16) = blz
fib(17) = cjl
fib(18) = dvk
fib(19) = gev
fib(20) = kaf
fib(21) = qfa
fib(22) = baff
fib(23) = bqkf
fib(24) = cqpk
fib(25) = egzp
fib(26) = gxoz
fib(27) = leoo
fib(28) = scdn
fib(29) = bdgsb
fib(30) = bvivo
fib(31) = cypnp

This is code golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

char *
rev(char *s, size_t n)
{
	size_t i;
	int c;

	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
	return s;
}

char *
base26(uvlong n, char *s)
{
	size_t i;

	i = 0;
	do {
		s[i++] = 'a' + (n % 26);
		n /= 26;
	} while (n);
	s[i] = '\0';

	return rev(s, i);
}

uvlong
fib(uvlong n)
{
	uvlong a, b, c, i;

	a = 0;
	b = 1;
	for (i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

char *
fib26(uvlong n, char *s)
{
	return base26(fib(n), s);
}

void
test(uvlong n, const char *r)
{
	char s[128];

	fib26(n, s);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main()
{
	test(0, "a");
	test(1, "b");
	test(2, "b");
	test(3, "c");
	test(4, "d");
	test(5, "f");
	test(6, "i");
	test(7, "n");
	test(8, "v");
	test(9, "bi");
	test(10, "cd");
	test(11, "dl");
	test(12, "fo");
	test(13, "iz");
	test(14, "on");
	test(15, "xm");
	test(16, "blz");
	test(17, "cjl");
	test(18, "dvk");
	test(19, "gev");
	test(20, "kaf");
	test(21, "qfa");
	test(22, "baff");
	test(23, "bqkf");
	test(24, "cqpk");
	test(25, "egzp");
	test(26, "gxoz");
	test(27, "leoo");
	test(28, "scdn");
	test(29, "bdgsb");
	test(30, "bvivo");
	test(31, "cypnp");

	return 0;
}
