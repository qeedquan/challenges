/*

A young, innovative company has developed a new keyboard with an ergonomic design.
This keyboard is potentially compatible with Windows OS, as it includes keys like Ctrl, Win, Alt, ScrLk, NumLock, CapsLock, Left Shift, Right Shift, and others.
However, the keyboard sends information about pressed keys as a single integer in the decimal numeral system.

Your task is to write a program that determines if a specific key is pressed based on the given key number.
Each pressed key is represented by a single bit value in the binary representation of the number, with bits numbered from right to left, starting at zero.

Input
The first line contains two integers: n (0≤n<1024) – the code received from the keyboard, and m (0≤m<10) – the number of the key to be checked, separated by at least one space.

Output
Print YES if the key is pressed, and NO otherwise.

Examples

Input #1
127 3

Answer #1
YES

*/

#include <assert.h>
#include <string.h>

const char *
solve(int n, int k)
{
	n >>= k;
	if (n & 1)
		return "YES";
	return "NO";
}

int
main()
{
	assert(!strcmp(solve(127, 3), "YES"));

	return 0;
}
