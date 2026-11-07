/*

objective
write a program that can perform addition, subtraction, multiplication, and division, using only bit-wise operators, by bit-wise operators i mean the equivalent of JavaScript &, |, ^, ~, << ,>> ,>>>. (AND, OR, XOR, NOT, and SHIFTs)

rules
you can use other operators, just not for the actual operation/output. (i.e. loop-indentation is ok).
it need not actually take input, just be technically functional. (i.e. functions that take arguments).
any output is OK, you can even return a object with the sum, difference, etc.
you need not return floats for division ints are ok as well, you can round anyway you like.
as short as you can.

*/

#include <assert.h>
#include <stdint.h>

/*

ported from @copy solution

Addition and Subtraction work for any signed numbers, multiplication and division only for unsigned (this hasn't been specified).

The input is assumed to be 32 bit.

*/

uint32_t
add(uint32_t x, uint32_t y)
{
	return y ? add(x ^ y, (x & y) << 1) : x;
}

uint32_t
sub(uint32_t x, uint32_t y)
{
	return add(x, add(1, ~y));
}

uint32_t
mul(uint32_t x, uint32_t y)
{
	return x ? add(y, mul(sub(x, 1), y)) : 0;
}

uint32_t
div(uint32_t x, uint32_t y)
{
	x = sub(x, y);
	return (x >> 31) ? 0 : add(1, div(x, y));
}

int
main(void)
{
	uint32_t x, y, N;

	N = 512;
	for (x = 0; x <= N; x++) {
		for (y = 0; y <= N; y++) {
			assert(add(x, y) == x + y);
			assert(sub(x, y) == x - y);
			assert(mul(x, y) == x * y);
			if (y)
				assert(div(x, y) == x / y);
		}
	}
	return 0;
}
