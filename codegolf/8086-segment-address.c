/*

Given a 8086 segmented memory address, output its actual address.

A segmented memory address has format xxxx:xxxx, where each of x is one of 0-9A-F, and the two parts are parsed as hexadecimal integers. Both parts are exactly 4 digits.

To get its actual address, multiply the first part by sixteen and add the second part. You can return it in a reasonable format, e.g. integer or a length=5 string. You can choose whether to modulo the result by 220 (some old thing). Yet input format is fixed.

This is code-golf, shortest code in each language wins.

Test cases

0000:0000 -> 0x00000
1111:1111 -> 0x12221
FFFF:0000 -> 0xFFFF0
FFFF:0010 -> 0x00000 or 0x100000

*/

#include <assert.h>
#include <stdio.h>

long
seg2addr(const char *s)
{
	unsigned long lo, hi;

	if (sscanf(s, "%lx:%lx", &hi, &lo) != 2)
		return -1;
	return (hi << 4) + lo;
}

int
main(void)
{
	assert(seg2addr("0000:0000") == 0x000000UL);
	assert(seg2addr("1111:1111") == 0x12221UL);
	assert(seg2addr("FFFF:0000") == 0xFFFF0UL);
	assert(seg2addr("FFFF:0010") == 0x100000UL);

	return 0;
}
