/*

Pawel and Shaka recently became friends. They believe their friendship will last forever if they merge their favorite strings.

The lengths of their favorite strings are the same, n. Mingling two strings, P=p1p2p3...pn and Q=q1q2q3...qn, both of length n, will result in the creation of a new string R of length 2*n.
It will have the following structure:

R = p1q1p2q2...pnqn

You are given two strings P (Pawel's favorite) and S (Shaka's favorite), determine the mingled string R.

Input Format

The first line of input contains the string P.
The second line contains Q.

Output Format

Print the mingled string, R.

Constraints
1 <= n <= 10^5

The string only consists of lowercase English characters (a-z).
length(P) = length(Q) = n

Sample Input #00
abcde
pqrst
Sample Output #00
apbqcrdset

Sample Input #01
hacker
ranker
Sample Output #01
hraacnkkeerr

*/

#include <cassert>
#include <string>

using namespace std;

string mingle(const string &str1, const string &str2)
{
	string result = "";
	size_t length = max(str1.size(), str2.size());
	for (size_t i = 0; i < length; i++) {
		if (i < str1.size())
			result += str1[i];
		if (i < str2.size())
			result += str2[i];
	}
	return result;
}

int main()
{
	assert(mingle("abcde", "pqrst") == "apbqcrdset");
	assert(mingle("hacker", "ranker") == "hraacnkkeerr");

	return 0;
}
