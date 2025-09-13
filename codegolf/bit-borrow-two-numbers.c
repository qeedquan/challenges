/*

Did you know that a small number can borrow bits from a larger number? Here's an example. Let's say our two numbers 5 and 14. First, write them out in binary:

5       14
000101  001110
First we take the smallest on bit away from the larger number, and we give it to the smallest off bit on the other number. So

This bit turns off
            |
            v
000101  001110
    ^
    |
This bit turns on
Now we have

000111  001100
and our numbers are 7 and 12. The first number is still smaller, so we continue.

000111  001100
001111  001000
Now we have 15 and 8, so we can stop. We'll call this set of operations "bit-borrowing" two numbers. Let's do another example. 20 and 61.

20        61
010100    111101
010101    111100
010111    111000
111111    100000
63        32
So our end result is 32, 63. Let's do one more. 31, and 12. 31 is already bigger than 12, so there's nothing to do! Bit-borrowing 31 and 12 gives 31 and 12, no change.

The challenge

Your challenge is to write a program or function that takes two numbers and bit-borrows them. The two numbers will always positive integers. Your input and output can be in any reasonable format.

Test IO:
Input: 2, 3
Output: 3, 2

Input: 3, 2
Output: 3, 2

Input: 8, 23
Output: 31, 0

Input: 42, 81
Output: 63, 0

Input: 38, 41
Output: 47, 32

Input: 16, 73
Output: 23, 0

Input: 17, 17
Output: 17, 17
Standard loopholes apply, and shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>

void
borrow(int x, int y, int *nx, int *ny)
{
	while (x < y) {
		x |= x + 1;
		y &= y - 1;
	}
	*nx = x;
	*ny = y;
}

void
test(int x, int y, int rx, int ry)
{
	int nx, ny;

	borrow(x, y, &nx, &ny);
	printf("%d %d\n", nx, ny);
	assert(nx == rx);
	assert(ny == ry);
}

int
main(void)
{
	test(2, 3, 3, 2);
	test(3, 2, 3, 2);
	test(8, 23, 31, 0);
	test(42, 81, 63, 0);
	test(38, 41, 47, 32);
	test(16, 73, 23, 0);
	test(17, 17, 17, 17);

	return 0;
}
