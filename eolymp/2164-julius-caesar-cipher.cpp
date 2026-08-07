/*

Julius Caesar used his own method of text encryption.
Each letter was replaced by the letter located k positions forward in the alphabet, with the alphabet considered cyclic.

Given the encrypted text, restore the original message.

Input
The first line contains the encrypted message, consisting of at most 255 uppercase Latin letters.

The second line contains an integer k (1≤k≤10).

Output
Print the decrypted text.

Examples

Input #1
XPSE
1

Answer #1
WORD

Input #2
ZABC
3

Answer #2
WXYZ

*/

#include <cassert>
#include <string>

using namespace std;

string solve(const string &text, int shift)
{
	string result = "";
	for (auto symbol : text)
	{
		if (!('A' <= symbol && symbol <= 'Z'))
		{
			result += symbol;
			continue;
		}

		if (symbol - shift >= 'A')
			result += symbol - shift;
		else
			result += 26 + (symbol - shift);
	}
	return result;
}

int main()
{
	assert(solve("XPSE", 1) == "WORD");
	assert(solve("ZABC", 3) == "WXYZ");

	return 0;
}
