/*

This is the tale of Zephyr, the greatest time traveler the world will never know. Even those who are aware of Zephyr's existence know very little about her. For example, no one has any clue as to which time-period she is originally from.

But we do know the story of the first time she set out to chart her own path in the time stream. Zephyr had just finished building her time machine which she named - "Dokhina Batash". She was making the final adjustments for her first trip when she noticed that a vital program was not working properly. The program was supposed to take a number N and find what Zephyr called its Onoroy value.

The Onoroy value of an integer N is the number of ones in its binary representation. For example, the number 13 (11012) has an Onoroy value of 3. Needless to say, this was an easy problem for the great mind of Zephyr. She solved it quickly and was on her way.

You are now given a similar task. Find the first number after N which has the same Onoroy value as N.

Input
Input starts with an integer T (≤ 65), denoting the number of test cases.

Each case begins with an integer N (1 ≤ N ≤ 109).

Output
For each case of input you have to print the case number and the desired result.

Sample
Input	Output
5
23
14232
391
7
8

Case 1: 27
Case 2: 14241
Case 3: 395
Case 4: 11
Case 5: 16

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <limits>

typedef unsigned int uint;

using namespace std;

string dec2bin(uint n)
{
	string s = "";
	for (int i = numeric_limits<int>::digits; i >= 0; i--)
		s += (n & (1 << i)) ? '1' : '0';
	return s;
}

uint bin2dec(string s)
{
	uint r = 0;
	for (uint i = 0; i < numeric_limits<uint>::digits; i++)
		r = (r << 1) + (s[i] - '0');
	return r;
}

uint solve(uint n)
{
	auto s = dec2bin(n);
	next_permutation(s.begin(), s.end());
	return bin2dec(s);
}

int main()
{
	assert(solve(23) == 27);
	assert(solve(14232) == 14241);
	assert(solve(391) == 395);
	assert(solve(7) == 11);
	assert(solve(8) == 16);

	return 0;
}
