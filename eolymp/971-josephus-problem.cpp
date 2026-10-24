/*

In a circle, there are N objects labeled from 1 to N.
Starting from the first object, every k-th object is eliminated from the circle in turn,
and this process continues until only one object remains.

For example, if N=10 and k=3, the order of elimination will be: 3, 6, 9, 2, 7, 1, 8, 5, 10. The object labeled 4 will be the last one remaining.

Input
The input contains two positive integers N and k. 1≤N≤500, 1≤k≤100.

Output
The output should contain a single number—the label of the remaining object.

Examples

Input #1
10 3

Answer #1
4

*/

#include <cassert>

int josephus(int n, int k)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	assert(josephus(10, 3) == 4);

	return 0;
}
