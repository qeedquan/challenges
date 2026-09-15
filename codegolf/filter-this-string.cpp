/*

Your task is to write a program that will filter out some characters in a string, so that the remaining spells out (part of) the other string.

Let's say we received the string "123456781234567812345678", and the second string is "314159".

First, we put a pointer on the second string:

314159
^
So the pointer is now on 3, and we replace the not-3 characters with a hashtag until the first 3:

##3456781234567812345678
We then move the pointer to the next character until we have iterated through the string.

Specs
You may use any character to replace "#", and the first string will not contain the hashtag (or the replaced hashtag).
The second string will always be longer than enough.
Both strings will only contain ASCII printable characters (U+0020-U+007F).
Testcases
input1: 123456781234567812345678
input2: 314159
output: ##3#####1##4####1###5###

input1: abcdefghijklmnopqrstuvwxyz
input2: dilemma
output: ###d####i##l##############

*/

#include <cassert>
#include <string>

using namespace std;

string filter(const string &str, const string &mask)
{
	string out = "";
	size_t index = 0;
	for (auto ch : str)
	{
		if (index < mask.length() && ch == mask[index])
			out += mask[index++];
		else
			out += "#";
	}
	return out;
}

int main()
{
	assert(filter("123456781234567812345678", "314159") == "##3#####1##4####1###5###");
	assert(filter("abcdefghijklmnopqrstuvwxyz", "dilemma") == "###d####i##l##############");
	return 0;
}
