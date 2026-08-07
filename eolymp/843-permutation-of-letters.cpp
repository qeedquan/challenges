/*

Given a string consisting of m symbols. Print all permutations of the symbols of the given string.

Input
A string consisting of m (2≤m≤8) symbols. The symbols are Latin letters and digits.

Output
Print all permutations of the given string in lexicographical order.

Examples

Input #1
AB

Answer #1
AB
BA

*/

#include <cctype>
#include <print>
#include <algorithm>

using namespace std;

void solve(string letters)
{
	sort(letters.begin(), letters.end());
	do
	{
		println("{}", letters);
	} while (next_permutation(letters.begin(), letters.end()));
}

int main()
{
	solve("AB");

	return 0;
}
