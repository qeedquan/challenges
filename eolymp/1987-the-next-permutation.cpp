/*

A string of decimal digits is given. Print the permutation of these decimal digits such that its value is the immediate next number after the input number.
For example:

123→132
279134399742→279134423799

It is possible that some permutation has no larger value. For example, 987.

Input
The first line contains the number of input test cases p (1≤p≤1000).
Each of the next lines represents a separate test case and contains its number and a corresponding set of at most 80 decimal digits.

Output
For each test case, print one line. If there is no larger permutation for the input digits,
print the data set number followed by a single space and the string BIGGEST.
If the solution exists, print the test case number, a single space, and the next permutation of the input digits.

Examples
Input #1
3
1 123
2 279134399742
3 987

Answer #1
1 132
2 279134423799
3 BIGGEST

*/

#include <algorithm>
#include <print>

using namespace std;

void solve(int n, string s)
{
	string t = s;
	next_permutation(t.begin(), t.end());

	print("{} ", n);
	if (s > t)
		print("BIGGEST");
	else
		print("{}", t);
	println();
}

int main()
{
	solve(1, "123");
	solve(2, "279134399742");
	solve(3, "987");

	return 0;
}
