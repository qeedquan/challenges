/*

In this Kata, we are going to determine if the count of each of the characters in a string can be equal if we remove a single character from that string.

For example:

solve('abba') = false -- if we remove any character, the count of each character will not be equal.
solve('abbba') = true -- if we remove one b, the count of each character becomes 2.
solve('aaaa') = true -- if we remove one character, the remaining characters have same count.
solve('wwwf') = true -- if we remove f, the remaining letters have same count.
More examples in the test cases. Empty string is not tested.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
histogram(const char *input, size_t count[256])
{
	size_t index, length;
	int symbol;

	memset(count, 0, sizeof(*count) * 256);
	for (; *input; input++) {
		symbol = *input & 0xff;
		count[symbol] += 1;
	}

	for (index = length = 0; index < 256; index++) {
		if (count[index])
			count[length++] = count[index];
	}
	return length;
}

bool
check(size_t count[], size_t length, size_t position)
{
	size_t index;
	size_t value;
	bool first;
	bool status;

	if (length == 0)
		return false;

	if (length == 1)
		return true;

	status = true;
	first = true;
	count[position] -= 1;
	for (index = 0; index < length; index++) {
		if (index == position && count[position] == 0)
			continue;

		if (first) {
			value = count[index];
			first = false;
		} else if (value != count[index]) {
			status = false;
			break;
		}
	}
	count[position] += 1;
	return status;
}

bool
solve(const char *input)
{
	size_t count[256];
	size_t length;
	size_t position;

	length = histogram(input, count);
	for (position = 0; position < length; position++) {
		if (check(count, length, position))
			return true;
	}
	return false;
}

int
main()
{
	assert(solve("wwwf") == true);
	assert(solve("aaaa") == true);
	assert(solve("abba") == false);
	assert(solve("abbba") == true);
	assert(solve("aabbcc") == false);
	assert(solve("aaaabb") == false);
	assert(solve("aabbccddd") == true);
	assert(solve("aabcde") == true);
	assert(solve("abcde") == true);
	assert(solve("aaabcde") == false);
	assert(solve("abbccc") == false);
	assert(solve("aabbccdddeee") == false);

	return 0;
}
