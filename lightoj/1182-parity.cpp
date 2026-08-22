/*

Given an integer n, first we represent in binary. Then we count the number of ones. We say n has odd parity if the number of one's is odd. Otherwise we say n has even parity.

For example, 21 = (10101)2 has odd parity since the number of one's is 3. 6 = (110)2 has even parity.

Now you are given n, we have to say whether n has even or odd parity.

Input
Input starts with an integer T (≤ 1000), denoting the number of test cases.

Each case contains an integer n (1 ≤ n < 2^31).

Output
For each case, print the case number and odd if n has odd parity, otherwise print even.

Sample
Input	Output
2
21
6

Case 1: odd
Case 2: even

*/

#include <cassert>
#include <bit>
#include <string>

using namespace std;

string solve(unsigned n)
{
	if (popcount(n) & 1)
		return "odd";
	return "even";
}

int main()
{
	assert(solve(21) == "odd");
	assert(solve(6) == "even");

	return 0;
}
