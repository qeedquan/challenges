/*

Task
For each given a number N, the integer S is called integer square root of N if S x S <= N and (S+1) x (S+1) > N.

In other words, S = Math.floor(Math.sqrt(N))

Your task is to calculate the integer square root of a given Number.

Note: Input is given in string format. That is, the Number may be very very large ;-)

Example
For: Number = "4", result = "2".

For: Number = "17", result = "4".

For: Number = "101", result = "10".

For: Number = "23232328323215435345345345343458098856756556809400840980980980980809092343243243243243098799634", result = "152421548093487868711992623730429930751178496967".

Input/Output
[input] string Number
number in decimal form. 0 < Number < 10^100

[output] a string
integer squareroot of Number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>

void
isqrt(const char *s, char *b)
{
	mpz_t x;

	mpz_init(x);
	mpz_init_set_str(x, s, 10);
	mpz_sqrt(x, x);
	gmp_sprintf(b, "%Zd", x);
	mpz_clear(x);
}

void
test(const char *s, const char *r)
{
	char b[256];

	isqrt(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("4", "2");
	test("17", "4");
	test("101", "10");
	test("23232328323215435345345345343458098856756556809400840980980980980809092343243243243243098799634", "152421548093487868711992623730429930751178496967");
	test("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "100000000000000000000000000000000000000000000000000");

	return 0;
}
