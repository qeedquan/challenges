/*

You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].

The array describes transactions, where each transaction must be completed exactly once in some order. At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi must hold true. After performing a transaction, money becomes money - costi + cashbacki.

Return the minimum amount of money required before any transaction so that all of the transactions can be completed regardless of the order of the transactions.

Example 1:

Input: transactions = [[2,1],[5,0],[4,2]]
Output: 10
Explanation:
Starting with money = 10, the transactions can be performed in any order.
It can be shown that starting with money < 10 will fail to complete all transactions in some order.

Example 2:

Input: transactions = [[3,0],[0,3]]
Output: 3
Explanation:
- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
Thus, starting with money = 3, the transactions can be performed in any order.

Constraints:

1 <= transactions.length <= 10^5
transactions[i].length == 2
0 <= costi, cashbacki <= 10^9

Hint 1
Split transactions that have cashback greater or equal to cost apart from transactions that have cashback less than cost. You will always earn money in the first scenario.

Hint 2
For transactions that have cashback greater or equal to cost, sort them by cost in descending order.

Hint 3
For transactions that have cashback less than cost, sort them by cashback in ascending order.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

vlong
money(vlong t[][2], size_t n)
{
	vlong l, r, *p;
	size_t i;

	l = r = 0;
	for (i = 0; i < n; i++) {
		p = t[i];
		l = max(l, p[0] - max(p[0] - p[1], 0));
		r += max(p[0] - p[1], 0);
	}
	r += l;
	return r;
}

int
main()
{
	vlong t1[][2] = { { 2, 1 }, { 5, 0 }, { 4, 2 } };
	vlong t2[][2] = { { 3, 0 }, { 0, 3 } };

	assert(money(t1, nelem(t1)) == 10);
	assert(money(t2, nelem(t2)) == 3);

	return 0;
}
