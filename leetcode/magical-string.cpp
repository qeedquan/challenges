/*

A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.

Example 1:

Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.

Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 10^5

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// https://oeis.org/A156077
int magical_string(int n)
{
	string s = " 122";
	for (auto i = 3; i <= n; i++)
	{
		if (i & 1)
			s.append(s[i] - '0', '1');
		else
			s.append(s[i] - '0', '2');
	}
	return count(begin(s), begin(s) + n + 1, '1');
}

int main()
{
	const vector<int> tab = {
		1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 7, 7, 8, 9, 9, 9, 10, 10, 11,
		12, 12, 13, 13, 13, 14, 15, 15, 16, 17, 17, 18, 18, 18, 19, 19,
		19, 20, 21, 21, 22, 22, 22, 23, 23, 24, 25, 25, 26, 27, 27, 27,
		28, 28, 28, 29, 30, 30, 31, 31, 31, 32, 32, 32, 33, 34, 34, 35,
		36, 36, 37, 37, 37, 38,
	};

	assert(magical_string(6) == 3);
	assert(magical_string(1) == 1);
	
	for (size_t i = 0; i < tab.size(); i++)
		assert(magical_string(i + 1) == tab[i]);

	return 0;
}
