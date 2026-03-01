/*

Given a non-negative integer input, write a program that converts the number to hexadecimal and returns a truthy value if the hexadecimal form of the number contains only the characters A through F and a falsey value otherwise.

Test cases

10
==> True (A in hexadecimal)

100
==> False (64 in hexadecimal)

161
==> False (A1 in hexadecimal)

11259375
==> True (ABCDEF in hexadecimal)

0
==> False (0 in hexadecimal)
Bonus: -40 bytes if your program prints Only letters for the challenge described above, Only numbers if the hexadecimal version of the number only contains the digits 0-9 and Mix if the hexadecimal number contains at least one number and at least one letter.

This is code golf. Standard rules apply. Shortest code in bytes wins. Either functions or full programs are allowed.

*/

#include <assert.h>

bool
hexlet(unsigned n)
{
	if (n == 0)
		return false;

	for (; n; n >>= 4) {
		if ((n & 0xf) < 0xa)
			return false;
	}
	return true;
}

int
main()
{
	assert(hexlet(10) == true);
	assert(hexlet(100) == false);
	assert(hexlet(161) == false);
	assert(hexlet(11259375) == true);
	assert(hexlet(0) == false);

	return 0;
}
