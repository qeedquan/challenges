/*

Our dear Sultan is visiting a country where there are n different types of coin. He wants to collect
as many different types of coin as you can. Now if he wants to withdraw X amount of money from a
Bank, the Bank will give him this money using following algorithm.

withdraw(X){
    if( X == 0) return;
    Let Y be the highest valued coin that does not exceed X.
    Give the customer Y valued coin.
    withdraw(X-Y);
}

Now Sultan can withdraw any amount of money from the Bank. He should maximize the number
of different coins that he can collect in a single withdrawal.

Input
First line of the input contains T the number of test cases. Each of the test cases starts with n
(1 ≤ n ≤ 1000), the number of different types of coin. Next line contains n integers C1, C2, …, Cn the
value of each coin type. C1 < C2 < C3 < . . . < Cn < 1000000000. C1 equals to 1.

Output
For each test case output one line denoting the maximum number of coins that Sultan can collect in a
single withdrawal. He can withdraw infinite amount of money from the Bank.

Sample Input
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20

Sample Output
6
4

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
collect(int *c, size_t n)
{
	size_t i;
	int s, r;

	s = r = 0;
	for (i = 0; i < n; i++) {
		if (n - 1 == i || s + c[i] < c[i + 1]) {
			s += c[i];
			r += 1;
		}
	}
	return r;
}

int
main()
{
	int c1[] = { 1, 2, 4, 8, 16, 32 };
	int c2[] = { 1, 3, 6, 8, 15, 20 };

	assert(collect(c1, nelem(c1)) == 6);
	assert(collect(c2, nelem(c2)) == 4);

	return 0;
}
