/*

Description

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

Input

第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。

Output

对输入的每组数据M和N，用一行输出相应的K。

Sample Input

1
7 3

Sample Output

8

Source

lwx@POJ

*/

#include <assert.h>

int
divisions(int m, int n)
{
	if (m < 0 || n < 0)
		return 0;

	if (n > m)
		return divisions(m, m);

	if (m == 0)
		return 1;

	if (n == 0)
		return 0;

	return divisions(m, n - 1) + divisions(m - n, n);
}

int
main(void)
{
	assert(divisions(7, 3) == 8);

	return 0;
}
