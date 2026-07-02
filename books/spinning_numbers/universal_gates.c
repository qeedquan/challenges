/*

https://en.wikipedia.org/wiki/NAND_logic
https://en.wikipedia.org/wiki/NOR_logic

NAND and NOR gates are universal
This means they can be used to implement every other logic gate (including themselves)

https://web.cecs.pdx.edu/~mperkows/temp/JULY8/0010.Reversible-gates-intro.pdf
https://en.wikipedia.org/wiki/Toffoli_gate
https://en.wikipedia.org/wiki/Fredkin_gate

Toffolli and Fredkin gates are universal reversible gates
Originally the gates were meant for reversible computing, they also found important uses in quantum computing.

A reversible gate is one where there is a one-to-one correspondence between the inputs and the outputs
(i.e., if in the truth table of the gate there is a distinct output row for each distinct input row).
In Boolean algebra, such a function is both one-to-one (or injective) and onto (or surjective).
This means that the output has to be the same size as the input and the transformation is a permutation.
This is why Toffolli and Fredkin gates can be represented as a permutation matrix.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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
nandimp(int a, int b)
{
	return nand(nand(nand(a, a), nand(a, a)), nand(b, b));
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

int
norimp(int a, int b)
{
	return nor(nor(nor(a, a), b), nor(nor(a, a), b));
}

void
fredkin(int a, int b, int c, int *ra, int *rb, int *rc)
{
	int s;

	s = (a ^ b) & c;
	*ra = (a ^ s) & 1;
	*rb = (b ^ s) & 1;
	*rc = c;
}

int
fredkinnot(int a, int)
{
	int x, y, z;

	fredkin(0, 1, a, &x, &y, &z);
	return y;
}

int
fredkinand(int a, int b)
{
	int x, y, z;

	fredkin(a, 0, b, &x, &y, &z);
	return y;
}

int
fredkinnand(int a, int b)
{
	return fredkinnot(fredkinand(a, b), 0);
}

int
fredkinor(int a, int b)
{
	int x, y, z;

	fredkin(a, 1, b, &x, &y, &z);
	return x;
}

int
fredkinnor(int a, int b)
{
	return fredkinnand(fredkinnand(fredkinnand(a, a), fredkinnand(b, b)), fredkinnand(fredkinnand(a, a), fredkinnand(b, b)));
}

int
fredkinxor(int a, int b)
{
	return fredkinnand(fredkinnand(b, fredkinnand(a, a)), fredkinnand(a, fredkinnand(b, b)));
}

int
fredkinxnor(int a, int b)
{
	return fredkinnand(fredkinnand(fredkinnand(a, a), fredkinnand(b, b)), fredkinnand(a, b));
}

int
fredkinimp(int a, int b)
{
	return fredkinnand(fredkinnand(fredkinnand(a, a), fredkinnand(a, a)), fredkinnand(b, b));
}

void
toffollir(int a, int b, int c, int *ra, int *rb, int *rc)
{
	*ra = a;
	*rb = b;
	*rc = (c ^ (a & b)) & 1;
}

int
toffolli(int a, int b, int c)
{
	int x, y, z;

	toffollir(a, b, c, &x, &y, &z);
	return z;
}

int
toffollinot(int a, int)
{
	return toffolli(a, 1, 1);
}

int
toffolliand(int a, int b)
{
	return toffolli(a, b, 0);
}

int
toffollinand(int a, int b)
{
	return toffolli(a, b, 1);
}

int
toffollior(int a, int b)
{
	return toffolli(1, b, toffolli(a, b, a));
}

int
toffollinor(int a, int b)
{
	return toffolli(toffolli(a, 1, toffolli(b, a, b)), 1, 1);
}

int
toffollixor(int a, int b)
{
	return toffolli(a, 1, b);
}

int
toffollixnor(int a, int b)
{
	return toffollinot(toffollixor(a, b), 0);
}

int
toffolliimp(int a, int b)
{
	return toffollinand(toffollinand(toffollinand(a, a), toffollinand(a, a)), toffollinand(b, b));
}

void
test(const gatefn f[8])
{
	int x[8][2][2], y[8][2][2];
	int a, b;
	size_t i;

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
			x[7][a][b] = ~a | b;
		}
	}

	for (i = 0; i < nelem(x); i++) {
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
	static const gatefn nandgates[] = { nandnot, nandand, nandnand, nandor, nandnor, nandxor, nandxnor, nandimp };
	static const gatefn norgates[] = { nornot, norand, nornand, noror, nornor, norxor, norxnor, norimp };
	static const gatefn fredkingates[] = { fredkinnot, fredkinand, fredkinnand, fredkinor, fredkinnor, fredkinxor, fredkinxnor, fredkinimp };
	static const gatefn toffolligates[] = { toffollinot, toffolliand, toffollinand, toffollior, toffollinor, toffollixor, toffollixnor, toffolliimp };

	test(nandgates);
	test(norgates);
	test(fredkingates);
	test(toffolligates);

	return 0;
}
