/*

A palindromic number or numeral palindrome is a 'symmetrical' number like 19891, that remains the same when its digits are reversed.
In this problem you will be given an integer, you have to say whether the number is a palindromic number or not.

Input
Input starts with an integer T (≤ 20000), denoting the number of test cases.

Each case starts with a line containing an integer n (0 ≤ n < 10^9).

Output
For each case, print the case number and Yes if n is palindromic, otherwise print No.

Sample
Input	Output
5
1
21
16161
523125
0

Case 1: Yes
Case 2: No
Case 3: Yes
Case 4: No
Case 5: Yes

*/

#include <cassert>
#include <string>

typedef unsigned uint;

using namespace std;

uint reverse(int n)
{
	uint r = 0;
	for (; n > 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

string solve(uint n)
{
	if (n == reverse(n))
		return "Yes";
	return "No";
}

int main()
{
	assert(solve(1) == "Yes");
	assert(solve(21) == "No");
	assert(solve(16161) == "Yes");
	assert(solve(523125) == "No");
	assert(solve(0) == "Yes");

	return 0;
}
