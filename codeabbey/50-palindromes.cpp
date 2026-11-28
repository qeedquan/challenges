/*

The word or whole phrase which has the same sequence of letters in both directions is called a palindrome. Here are few examples:

Stats
Amore, Roma
No 'x' in Nixon
Was it a cat I saw?
As you see, case of the letters is ignored. Spaces and punctuations are ignored too.

Your goal in this programming exercise is to determine, whether the phrase represents a palindrome or not.

Input data contains number of phrases in the first line.
Next lines contain one phrase each.
Answer should have a single letter (space separated) for each phrase: Y if it is a palindrome and N if not.

Example:

input data:
3
Stars
O, a kak Uwakov lil vo kawu kakao!
Some men interpret nine memos

answer:
N Y Y

*/

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

bool isskip(int c)
{
	return isspace(c) || ispunct(c);
}

int palindrome(const string &s)
{
	size_t n = s.size();
	if (n == 0)
		return 'Y';

	size_t i = 0;
	size_t j = n - 1;
	for (;;)
	{
		while (i < j && isskip(s[i]))
			i += 1;
		while (j > i && isskip(s[j]))
			j -= 1;

		if (i >= j)
			break;

		if (tolower(s[i]) != tolower(s[j]))
			return 'N';

		i += 1;
		j -= 1;
	}
	return 'Y';
}

int main()
{
	assert(palindrome("Stats") == 'Y');
	assert(palindrome("Amore, Roma") == 'Y');
	assert(palindrome("No 'x' in Nixon") == 'Y');
	assert(palindrome("Was it a cat I saw?") == 'Y');
	assert(palindrome("Stars") == 'N');
	assert(palindrome("O, a kak Uwakov lil vo kawu kakao!") == 'Y');
	assert(palindrome("Some men interpret nine memos") == 'Y');

	return 0;
}
