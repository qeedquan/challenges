/*

Find the first character that repeats in a String and return that character.

firstDup('tweet') => 't'
firstDup('like') => undefined
This is not the same as finding the character that repeats first. In that case, an input of 'tweet' would yield 'e'.

Another example:

In 'translator' you should return 't', not 'a'.

v      v
translator
  ^   ^
While second 'a' appears before second 't', the first 't' is before the first 'a'.

*/

#include <cassert>
#include <cstdio>
#include <cstdint>
#include <string>

using namespace std;

int firstdup(const string &input)
{
	size_t count[256] = {};
	size_t position[256] = {};
	size_t index = 0;
	for (int symbol : input)
	{
		symbol &= 0xff;
		if (!count[symbol])
			position[symbol] = index;
		count[symbol] += 1;
		index += 1;
	}

	size_t minimum = SIZE_MAX;
	int character = -1;
	for (size_t index = 0; index < 256; index++)
	{
		if (count[index] > 1 && position[index] < minimum)
		{
			minimum = position[index];
			character = index;
		}
	}
	return character;
}

int main()
{
	assert(firstdup("tweet") == 't');
	assert(firstdup("like") == -1);
	assert(firstdup("tweet") == 't');
	assert(firstdup("Ode to Joy") == ' ');
	assert(firstdup("ode to joy") == 'o');
	assert(firstdup("bar") == -1);
	assert(firstdup("123123") == '1');
	assert(firstdup("!@#$!@#$") == '!');
	assert(firstdup("1a2b3a3c") == 'a');

	return 0;
}
