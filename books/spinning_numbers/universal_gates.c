/*

https://en.wikipedia.org/wiki/NAND_logic
https://en.wikipedia.org/wiki/NOR_logic

NAND and NOR gates are universal
This means they can be used to implement every other logic gate (including themselves)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef int (*gatefn)(int, int);

int
nand(int a, int b)
{
	return ~(a & b);
}

int
nandnot(int a, int)
{
	return nand(a, a);
}

int
nandand(int a, int b)
{
	return nand(nand(a, b), nand(a, b));
}

int
nandnand(int a, int b)
{
	return nand(nand(nand(a, a), b), b);
}

int
nandor(int a, int b)
{
	return nand(nand(a, a), nand(b, b));
}

int
nandnor(int a, int b)
{
	return nand(nand(nand(a, a), nand(b, b)), nand(nand(a, a), nand(b, b)));
}

int
nandxor(int a, int b)
{
	return nand(nand(b, nand(a, a)), nand(a, nand(b, b)));
}

int
nandxnor(int a, int b)
{
	return nand(nand(nand(a, a), nand(b, b)), nand(a, b));
}

int
nor(int a, int b)
{
	return ~(a | b);
}

int
nornot(int a, int)
{
	return nor(a, a);
}

int
noror(int a, int b)
{
	return nor(nor(a, b), nor(a, b));
}

int
nornor(int a, int b)
{
	return nor(nor(nor(a, a), b), b);
}

int
norand(int a, int b)
{
	return nor(nor(a, a), nor(b, b));
}

int
nornand(int a, int b)
{
	return nor(nor(nor(a, a), nor(b, b)), nor(nor(a, a), nor(b, b)));
}

int
norxor(int a, int b)
{
	return nor(nor(nor(a, a), nor(b, b)), nor(a, b));
}

int
norxnor(int a, int b)
{
	return nor(nor(a, nor(a, b)), nor(b, nor(a, b)));
}

void
test(const gatefn f[7])
{
	int x[7][2][2], y[7][2][2];
	int i, a, b;

	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for (a = 0; a <= 1; a++) {
		for (b = 0; b <= 1; b++) {
			x[0][a][b] = ~a;
			x[1][a][b] = a & b;
			x[2][a][b] = ~(a & b);
			x[3][a][b] = a | b;
			x[4][a][b] = ~(a | b);
			x[5][a][b] = a ^ b;
			x[6][a][b] = ~(a ^ b);
		}
	}

	for (i = 0; i < 7; i++) {
		for (a = 0; a <= 1; a++) {
			for (b = 0; b <= 1; b++) {
				y[i][a][b] = f[i](a, b) & 1;
				x[i][a][b] &= 1;
			}
		}
	}

	assert(!memcmp(x, y, sizeof(y)));
}

int
main(void)
{
	static const gatefn nandgates[] = {nandnot, nandand, nandnand, nandor, nandnor, nandxor, nandxnor};
	static const gatefn norgates[] = {nornot, norand, nornand, noror, nornor, norxor, norxnor};

	test(nandgates);
	test(norgates);

	return 0;
}
