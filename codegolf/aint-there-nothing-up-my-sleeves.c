/*

Note: reference to Nothing up my sleeve number.

Your task is to take no input and generate this exact output:

d76aa478 e8c7b756 242070db c1bdceee f57c0faf 4787c62a a8304613 fd469501
698098d8 8b44f7af ffff5bb1 895cd7be 6b901122 fd987193 a679438e 49b40821
f61e2562 c040b340 265e5a51 e9b6c7aa d62f105d 02441453 d8a1e681 e7d3fbc8
21e1cde6 c33707d6 f4d50d87 455a14ed a9e3e905 fcefa3f8 676f02d9 8d2a4c8a
fffa3942 8771f681 6d9d6122 fde5380c a4beea44 4bdecfa9 f6bb4b60 bebfbc70
289b7ec6 eaa127fa d4ef3085 04881d05 d9d4d039 e6db99e5 1fa27cf8 c4ac5665
f4292244 432aff97 ab9423a7 fc93a039 655b59c3 8f0ccc92 ffeff47d 85845dd1
6fa87e4f fe2ce6e0 a3014314 4e0811a1 f7537e82 bd3af235 2ad7d2bb eb86d391
A trailing newline is optional.

The MD5 hash for the version with trailing newline is:

FC1D37B5295177E7F28509EC9197688F
The MD5 hash for the version without trailing newline is:

FAC194EC5EFD2E5A5AC07C2A4925699B
How the string is generated
Those 64 strings are actually the 64 hexadecimal numbers used in the MD5 hash.

The pseudocode for them:

numbers = floor(2^32 × abs(sin(i))) for i in [1,2,...,64]
The reference Python code:

from math import*
for i in range(8):print" ".join("{:08x}".format(int(abs(2**32*sin(-~j))))for j in range(8*i,8*i+8))
Ungolfed:

from math import*
for i in range(8):
    temp = []
    for j in range(8*i,8*i+8):
        temp += ["{:08x}".format(int(abs(2**32*sin(j+1))))]
    print " ".join(temp)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void
nosleeves(void)
{
	long i, j, v;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			v = 0x100000000L * sin((8 * i) + j + 1);
			printf("%08lx", labs(v));
			if (j + 1 < 8)
				printf(" ");
		}
		printf("\n");
	}
}

int
main(void)
{
	nosleeves();
	return 0;
}
