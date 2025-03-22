/*

Task
How many strings equal to A can be constructed using letters from the string B? Each letter can be used only once and in one string only.

Example
For A = "abc" and B = "abccba", the output should be 2.

We can construct 2 strings A with letters from B.

Input/Output
[input] string A

String to construct, A contains only lowercase English letters.

Constraints: 3 ≤ A.length ≤ 9.

[input] string B

String containing needed letters, B contains only lowercase English letters.

Constraints: 3 ≤ B.length ≤ 50.

[output] an integer

*/

#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

size_t construction(const string &string0, const string &string1)
{
	size_t count0[256] = {};
	size_t count1[256] = {};
	for (auto symbol : string0)
		count0[symbol & 0xff] += 1;
	for (auto symbol : string1)
		count1[symbol & 0xff] += 1;

	size_t minimum = 0;
	for (auto symbol = 0; symbol < 256; symbol++)
	{
		if (!count0[symbol])
			continue;

		if (!minimum)
			minimum = count1[symbol] / count0[symbol];
		else
			minimum = min(minimum, count1[symbol] / count0[symbol]);
	}
	return minimum;
}

int main()
{
	assert(construction("abc", "abccba") == 2);
	assert(construction("hnccv", "hncvohcjhdfnhonxddcocjncchnvohchnjohcvnhjdhihsn") == 3);
	assert(construction("abc", "def") == 0);
	assert(construction("zzz", "zzzzzzzzzzz") == 3);

	return 0;
}
