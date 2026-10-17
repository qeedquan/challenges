/*

Today Vasya found a great way to earn money. He offers his diary to Peter for p rubles a day.
There are days when Peter does not do well on an exam, and the results, of course, are recorded in the diary.
To avoid upsetting his family, he rents Vasya's diary.
After studying the basics of economics, Vasya decides to attract customers by announcing that every m-th day of rental is completely free.

Peter rented the diary for n days. Now Vasya is trying to figure out how many rubles he will receive as a result of this transaction.

Input
Three positive integers n, m, and p (n,m,p<10001).

Output
Print Vasya's profit.

Examples
Input #1
15 10 2

Answer #1
28

*/

#include <assert.h>

int
solve(int n, int m, int p)
{
	int r;

	if (m == 0)
		return 0;

	r = (n / m) * p;
	return (n * p) - r;
}

int
main()
{
	assert(solve(15, 10, 2) == 28);

	return 0;
}
