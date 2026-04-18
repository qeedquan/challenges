/*

The expression N!, read as “N factorial,” denotes the product of the first N positive integers, where
N is nonnegative. So, for example,
N N!
0 1
1 1
2 2
3 6
4 24
5 120
10 3628800

For this problem, you are to write a program that can compute the last non-zero digit of any
factorial for (0 ≤ N ≤ 10000). For example, if your program is asked to compute the last nonzero digit
of 5!, your program should produce “2” because 5! = 120, and 2 is the last nonzero digit of 120.

Input
Input to the program is a series of nonnegative integers not exceeding 10000, each on its own line with
no other letters, digits or spaces. For each integer N, you should read the value and compute the last
nonzero digit of N!.

Output
For each integer input, the program should print exactly one line of output. Each line of output should
contain the value N, right-justified in columns 1 through 5 with leading blanks, not leading zeroes.
Columns 6 - 9 must contain ‘ -> ’ (space hyphen greater space). Column 10 must contain the single
last non-zero digit of N!.

Sample Input
1
2
26
125
3125
9999

Sample Output
1 -> 1
2 -> 2
26 -> 4
125 -> 8
3125 -> 2
9999 -> 8

*/

#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

// https://oeis.org/A008904
int facts(int n)
{
	if (n < 0)
		return 0;

	auto r = 1;
	for (auto i = 2; i <= n; i++)
	{
		r *= i;
		while (!(r % 10))
			r /= 10;
		r %= 100000;
	}
	return r % 10;
}

int main()
{
	static const int tab[] = {
		1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 8, 8, 6, 8, 2, 8, 8, 6,
		8, 2, 4, 4, 8, 4, 6, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2,
		2, 4, 2, 8, 2, 2, 4, 2, 8, 6, 6, 2, 6, 4, 2, 2, 4, 2,
		8, 4, 4, 8, 4, 6, 6, 6, 2, 6, 4, 6, 6, 2, 6, 4, 8, 8,
		6, 8, 2, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2, 2, 4, 2, 8,
		2, 2, 4, 2, 8, 6, 6, 2, 6
	};

	assert(facts(1) == 1);
	assert(facts(2) == 2);
	assert(facts(26) == 4);
	assert(facts(125) == 8);
	assert(facts(3125) == 2);
	assert(facts(9999) == 8);

	for (unsigned i = 0; i < size(tab); i++)
		assert(facts(i) == tab[i]);

	return 0;
}
