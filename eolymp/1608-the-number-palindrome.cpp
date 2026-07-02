/*

Check if the given number is a palindrome.

A number is called a palindrome if it reads the same forwards and backwards.

Input
One non-negative 32-bit integer.

Output
Print Yes if the number is a palindrome, and No otherwise.

Examples

Input #1
121

Answer #1
Yes

Input #2
10

Answer #2
No

Input #4
519767348

Answer #4
No

*/

#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string solve(int n)
{
	auto s = to_string(abs(n));
	auto t = s;
	reverse(t.begin(), t.end());
	return (s == t) ? "Yes" : "No";
}

int main()
{
	assert(solve(121) == "Yes");
	assert(solve(10) == "No");
	assert(solve(519767348) == "No");

	return 0;
}
