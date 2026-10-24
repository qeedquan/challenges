/*

Mine is

print("def f(n):f",*range(2**33),sep="==n==print('eovdedn'[n&1::2]);")
Rules: It must be in python. That's it.

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

int
main()
{
	static const char *sep = "==n==print('eovdedn'[n&1::2]);";
	uint64_t i;

	printf("def f(n):f%s", sep);
	for (i = 0; i <= UINT32_MAX; i++)
		printf("%" PRIu64 "%s", i, sep);
	return 0;
}
