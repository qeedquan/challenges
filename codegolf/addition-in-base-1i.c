/*

Gaussian integers are complex numbers of the form a+bi where a and b are both integers.
In base -1+i, all Gaussian integers can be uniquely represented using the digits 0 and 1, without the need for a symbol to denote sign.

For instance, 1100 in base -1+i represents the decimal number 2, since

1*(-1+i)^3 + 1*(-1+i)^2 + 0*(-1+i)^1 + 0*(-1+i)^0
= (2+2i) + (-2i) + 0 + 0
= 2
Input will be two Gaussian integers in base -1+i represented using the digits 01. This can take one of the following forms:

Two separate digit strings,
Two decimal integers consisting of 01 representing the base -1+i numbers (e.g. 1100 for 2 in base -1+i),
Two binary integers representing the base -1+i numbers (e.g. decimal 12 or 0b1100 for 2 in base -1+i)
A single string separating two digit strings/binary integers by a single non-alphanumeric separator (e.g. 1100 1100 or 12,12 for 2+2)
Output the sum of the two Gaussian integers, also in base -1+i and represented using the digits 01 (in one of the formats allowed as input, not necessarily the same choice).
The output is allowed to contain a finite number of leading zeroes.

Your function or program must terminate within 2 seconds for inputs of at most 30 digits each.

Additional clarifications
You may assume that the input contains no extraneous leading zeroes. For the special case of 0, you may choose either 0 or the empty string as the representation.
Test cases
0, 0 => 0                                      # 0 + 0 = 0
0, 1 => 1                                      # 0 + 1 = 1
1, 1 => 1100                                   # 1 + 1 = 2
1100, 1100 => 111010000                        # 2 + 2 = 4
1101, 1101 => 111011100                        # 3 + 3 = 6
110111001100, 1110011011100 => 0               # 42 + (-42) = 0
11, 111 => 0                                   # i + (-i) = 0
11, 110 => 11101                               # i + (-1-i) = -1
10101, 11011 => 10010                          # (-3-2i) + (-2+3i) = (-5+i)
1010100101, 111101 => 1110100000100            # (-19+2i) + (3-4i) = (-16-2i)

Longer test cases:

11011011010110101110010001001, 111100010100101001001010010101 => 0
111111111111111111111111111111, 111111111111111111111111111111 => 100100100100100100100100100100
101101110111011101110111011101, 101101110111011101110111011101 => 11101001010001000100010001000100011100
100100010101001101010110101010, 100010011101001011111110101000 => 110000110010101100001100111100010

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <complex.h>

double complex
base1i(const char *s)
{
	double complex r;
	size_t i, n;

	r = 0;
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == '1')
			r += cpow(CMPLX(-1, 1), n - i - 1);
	}
	return r;
}

void
test(const char *s, const char *t, double complex r)
{
	static const double eps = 1e-6;
	double complex z;

	z = base1i(s) + base1i(t);
	printf("%.3f%+.3fi\n", creal(z), cimag(z));
	assert(fabs(creal(z) - creal(r)) < eps);
	assert(fabs(cimag(z) - cimag(r)) < eps);
}

int
main(void)
{
	test("0", "0", CMPLX(0, 0));
	test("0", "1", CMPLX(1, 0));
	test("1", "1", CMPLX(2, 0));
	test("1100", "1100", CMPLX(4, 0));
	test("1101", "1101", CMPLX(6, 0));
	test("110111001100", "1110011011100", CMPLX(0, 0));
	test("11", "111", CMPLX(0, 0));
	test("11", "110", CMPLX(-1, 0));
	test("10101", "11011", CMPLX(-5, 1));
	test("1010100101", "111101", CMPLX(-16, -2));
	test("11011011010110101110010001001", "111100010100101001001010010101", CMPLX(0, 0));
	test("111111111111111111111111111111", "111111111111111111111111111111", CMPLX(13108, -26214));
	test("101101110111011101110111011101", "101101110111011101110111011101", CMPLX(52430, -32768));
	test("100100010101001101010110101010", "100010011101001011111110101000", CMPLX(27371, -35043));

	return 0;
}
