/*

Task
You're given a substring s of some cyclic string. What's the length of the smallest possible string that can be concatenated to itself many times to obtain this cyclic string?

Example
For s = "cabca", the output should be 3

"cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating "abc" to itself. Thus, the answer is 3.

Input/Output
[input] string s
Constraints: 3 ≤ s.length ≤ 15.

[output] an integer

*/

#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

size_t cyclic_string(const string &input)
{
	size_t count = 1;
	for (;;)
	{
		auto result = mismatch(input.begin() + count, input.end(), input.begin());
		if (result.first == input.end())
			break;
		count += 1;
	}
	return count;
}

int main()
{
	assert(cyclic_string("cabca") == 3);
	assert(cyclic_string("aba") == 2);
	assert(cyclic_string("ccccccccccc") == 1);
	assert(cyclic_string("abaca") == 4);

	return 0;
}
