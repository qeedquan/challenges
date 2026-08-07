/*

In this problem you have to find the permutations using the first N English capital letters. Since there can be many permutations, you have to print the first K.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains two integers N, K (1 ≤ N ≤ 26, 1 ≤ K ≤ 30).

Output
For each case, print the case number in a line. Then print the first K permutations that contain the first N English capital letters in alphabetical order. If there are less than K permutations then print all of them.

Sample
Input	Output
2
3 8
10 10

Case 1:
ABC
ACB
BAC
BCA
CAB
CBA

Case 2:
ABCDEFGHIJ
ABCDEFGHJI
ABCDEFGIHJ
ABCDEFGIJH
ABCDEFGJHI
ABCDEFGJIH
ABCDEFHGIJ
ABCDEFHGJI
ABCDEFHIGJ
ABCDEFHIJG

*/

#include <algorithm>
#include <string>
#include <print>

using namespace std;

void solve(int n, int k)
{
	const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	auto current = alphabet.substr(0, n);
	auto check = current;
	for (auto i = 0; i < k; i++)
	{
		println("{}", current);
		next_permutation(current.begin(), current.end());
		if (current == check)
			break;
	}
}

int main()
{
	solve(3, 8);
	solve(10, 10);

	return 0;
}
