/*

The right bit shift operator >> act a division-by-two for an unsigned integer, but not for a signed integer. For exmaple the output of the program

int main();

int main() {
        unsigned int m{ 57};
        unsigned int n{-57};

        std::cout << (m >> 2) << std::endl;    // output of "14"
        std::cout << (m >> 5) << std::endl;    // output of "1"

        std::cout << (n >> 2) << std::endl;    // output of "1073741809"
        std::cout << (n >> 5) << std::endl;    // output of "134217726"

        return 0;
}

This is because 11111111111111111111111111000110, which is the 32-bit two's-complement representation of -57 when right shifted by two and five are 00111111111111111111111111110001 and 00000111111111111111111111111110, respectively. Both of these numbers are positive.

An arithmetic shift corrects this by padding the number with 1s on the left.

Thus, an arithmetic right shift of -57 when shifted to the left by two and five yeilds 11111111111111111111111111110001 and 11111111111111111111111111111110, respectively.

Note, however, that we must be careful: 11111111111111111111111111111111 is the representation of -1, and any left-shift after this should therefore become zero: 00000000000000000000000000000000.

To implement an arithmetic right shift of n, the most significant bit (the left-most) must be repeated n times, unless n is greater than or equal to the number of bits in the type, in which case, the result is 0.

Signed int
Implement these functions.

int arithmetic_right_shift( int value, std::size_t n );
Templated
For a templated data type, you will have to recall that the size of the type can be found using the sizeof operator.

template <typename T>
T arithmetic_right_shift( T value, std::size_t n );

*/

#include <assert.h>
#include <limits.h>

// https://stackoverflow.com/questions/31879878/how-can-i-perform-arithmetic-right-shift-in-c-in-a-portable-way
int
sar(int x, unsigned n)
{
	static const int signshift = (sizeof(int) * CHAR_BIT) - 1;

	int s;

	s = -((unsigned)x >> signshift);
	return ((s ^ x) >> n) ^ s;
}

int
main(void)
{
	assert(sar(-57, 2) == -15);
	assert(sar(-57, 5) == -2);

	return 0;
}
