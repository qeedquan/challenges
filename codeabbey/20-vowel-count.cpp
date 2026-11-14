/*

This is a simple problem to get introduced to string processing. We will be given several lines of text - and for each of them we want to know the number of vowels (i.e. letters a, o, u, i, e, y). Note: that y is regarded as vowel for purpose of this task.

Though simple, this technique is important in cipher-breaking approaches. For example refer to Caesar Cipher Cracker problem.

Input data contain number of test-cases in the first line.
Then the specified number of lines follows each representing one test-case.
Lines consist only of lowercase English (Latin) letters and spaces.
Answer should contain the number of vowels in each line, separated by spaces.

Example:

input data:
4
abracadabra
pear tree
o a kak ushakov lil vo kashu kakao
my pyx

answer:
5 4 13 2

*/

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

size_t vowels(const string &text)
{
	size_t count = 0;
	for (auto symbol : text)
	{
		switch (tolower(symbol))
		{
		case 'a':
		case 'o':
		case 'u':
		case 'i':
		case 'e':
		case 'y':
			count += 1;
			break;
		}
	}
	return count;
}

int main()
{
	assert(vowels("abracadabra") == 5);
	assert(vowels("pear tree") == 4);
	assert(vowels("o a kak ushakov lil vo kashu kakao") == 13);
	assert(vowels("my pyx") == 2);

	return 0;
}
