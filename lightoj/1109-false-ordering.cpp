/*

We define b is a Divisor of a number a if a is divisible by b. So, the divisors of 12 are {1, 2, 3, 4, 6, 12}. So, 12 has 6 divisors.

Now you have to order all the integers from 1 to 1000. x will come before y if:

Number of divisors of x is less than number of divisors of y.
Number of divisors of x is equal to number of divisors of y and x > y.
Input
Input starts with an integer T (≤ 1005), denoting the number of test cases.

Each case contains an integer n (1 ≤ n ≤ 1000).

Output
For each case, print the case number and the nth number after ordering.

Sample
Input	Output
5
1
2
3
4
1000

Case 1: 1
Case 2: 997
Case 3: 991
Case 4: 983
Case 5: 840

*/

#include <cassert>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Comparator
{
private:
	vector<int> divisors;

public:
	Comparator(int size)
	{
		divisors.resize(size + 1);
		for (int i = 1; i <= size; i++)
		{
			int k = i;
			while (k <= size)
			{
				divisors[k] += 1;
				k += i;
			}
		}
	}

	bool operator()(int x, int y)
	{
		if (divisors[x] < divisors[y])
			return true;
		if (divisors[x] > divisors[y])
			return false;
		return x > y;
	}
};

vector<int> build(int size)
{
	vector<int> table;
	table.resize(size + 1);
	iota(table.begin(), table.end(), 0);
	sort(table.begin(), table.end(), Comparator(size));
	return table;
}

int main()
{
	auto table = build(1000);
	assert(table[1] == 1);
	assert(table[2] == 997);
	assert(table[3] == 991);
	assert(table[4] == 983);
	assert(table[1000] == 840);

	return 0;
}
