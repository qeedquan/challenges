/*

Construction company just have built skyscraper of immense height, but with only single appartment on each floor. Appartment cost is X at the lowest floors, but is incremented by 1000 every M floors. The goal is to calculate how much profit the company gets by selling the whole building of N storeys.

To clarify: if N = 30 and price starts with X = 10000, incrementing every M = 10 floors, then first ten apartments (at floors 0 .. 9, where 0 means "ground floor") are sold for 10000 each, next ten (at floors 10 .. 19) go for 11000, and ten last for 12000.

Input gives the number T of testcases in the first line.
Then T lines follow, each with three values N M X.

Answer should give building total prices for every testcase, space-separated. Prices are integers, no cents, pennies or kopeeks please :)

Example

input:
3
1 1 1000
3 2 1000
30 10 10000

answer:
1000 4000 330000

*/

#include <assert.h>

typedef long long vlong;

vlong
solvebf(vlong N, vlong M, vlong X)
{
	vlong full;
	vlong remain;
	vlong profit;
	vlong i;

	if (M == 0)
		return 0;

	full = N / M;
	remain = N % M;

	profit = remain * (X + full * 1000);
	for (i = 0; i < full; i++)
		profit += M * (X + i * 1000);
	return profit;
}

/*

Break N floors into blocks of M:

1. Full Blocks:
There are K = floor(N/M) complete blocks.
The price form an rithmetic progression: M*X, M*(X+1000), M*(X+2000), ...

2. Leftover Floors:
There are R = N (mod M) remaining floors at the top.
Their price will be X + (K * 1000) each

*/

vlong
solve(vlong N, vlong M, vlong X)
{
	vlong A, B, C, K, R;

	if (M == 0)
		return 0;

	K = N / M;
	R = N % M;
	A = M * K * X;
	B = 1000 * M * (K * (K - 1)) / 2;
	C = R * (X + (K * 1000));
	return A + B + C;
}

int
main()
{
	vlong N, M, K;

	assert(solve(1, 1, 1000) == 1000);
	assert(solve(3, 2, 1000) == 4000);
	assert(solve(30, 10, 10000) == 330000);

	for (N = 0; N <= 100; N++) {
		for (M = 0; M <= 100; M++) {
			for (K = 0; K <= 1000; K++)
				assert(solve(N, M, K) == solvebf(N, M, K));
		}
	}

	return 0;
}
