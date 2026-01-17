/*

Task
Given a number n, return a string representing it as a sum of distinct powers of three, or return "Impossible" if that's not possible to achieve.

Input/Output
[input] integer n

A positive integer n.

1 ≤ n ≤ 10^16.

[output] a string

A string representing the sum of powers of three which adds up to n, or "Impossible" if there is no solution. If the solution does exist, it should be return as "3^a1+3^a2+ ... +3^an", where ai for 0 ≤ i ≤ n represents the corresponding exponent of the term. The terms in the string should also be sorted in descending order, meaning that higher powers should appear before the lower ones in the string ("3^0+3^1" is incorrect, whereas "3^1+3^0" is correct).

Example
For n = 4, the output should be "3^1+3^0".

4 can be represented as 3+1 which is in fact 3 to the power of 1 plus 3 to the power of 0

For n = 2, the output should be "Impossible".

There is no way to represent 2 as a sum of distinct powers of 3.

*/

#include <algorithm>
#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <boost/algorithm/string/join.hpp>

using namespace std;

typedef unsigned long long uvlong;

string sum_of_threes(uvlong n)
{
	vector<string> r;
	for (uvlong p = 0; n > 0; n /= 3)
	{
		switch (n % 3)
		{
		case 1:
			r.push_back(format("3^{0}", p));
			break;

		case 2:
			return "Impossible";
		}
		p += 1;
	}
	if (r.size() == 0)
		return "Impossible";

	reverse(r.begin(), r.end());
	return boost::algorithm::join(r, "+");
}

int main()
{
	assert(sum_of_threes(4) == "3^1+3^0");
	assert(sum_of_threes(2) == "Impossible");
	assert(sum_of_threes(27) == "3^3");
	assert(sum_of_threes(9) == "3^2");
	assert(sum_of_threes(1418194818) == "Impossible");
	assert(sum_of_threes(87754) == "3^10+3^9+3^8+3^7+3^5+3^3+3^1+3^0");
	assert(sum_of_threes(531441) == "3^12");
	assert(sum_of_threes(8312964441463288) == "Impossible");
	assert(sum_of_threes(5559060566575209) == "3^33+3^9+3^1");
	assert(sum_of_threes(243) == "3^5");

	return 0;
}
