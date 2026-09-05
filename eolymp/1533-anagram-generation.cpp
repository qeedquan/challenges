/*

Write a program that generates all possible unique words from a given set of letters.

For example, from the word abc, all possible permutations of the letters are: abc, acb, bac, bca, cab, and cba.

Input words may contain duplicate letters. The program must not output the same word more than once. All words should be printed in ascending alphabetical order.

Input
The first line contains the number of test cases t.
Each of the following lines contains one word consisting of Latin letters (from A to Z).
Uppercase and lowercase letters are considered different.

Output
For each test case, print all unique words that can be formed from the given letters in ascending alphabetical order.
Each word should be printed on a separate line.
In alphabetical order, uppercase letters are considered smaller than their lowercase counterparts.

Examples

Input #1
3
aAb
abc
acba

Answer #1
Aab
Aba
aAb
abA
bAa
baA
abc
acb
bac
bca
cab
cba
aabc
aacb
abac
abca
acab
acba
baac
baca
bcaa
caab
caba
cbaa

*/

#include <cctype>
#include <print>
#include <algorithm>

using namespace std;

int compare(char a, char b)
{
	auto ua = toupper(a);
	auto ub = toupper(b);
	if (ua != ub)
		return ua < ub;
	return a < b;
}

void solve(string letters)
{
	sort(letters.begin(), letters.end(), compare);
	do
	{
		println("{}", letters);
	} while (next_permutation(letters.begin(), letters.end(), compare));
}

int main()
{
	solve("aAb");
	solve("abc");
	solve("acba");
	solve("hello");

	return 0;
}
