/*

In the computer science class, Yura became very sad, so he came up with a game for himself.

At the beginning, he has an empty set. In each subsequent step, he thinks of a number and checks whether it belongs to the set. If the number belongs to the set, Yura shouts "Yes". If not, he shouts "No" and adds it to the set. Before thinking of a new number, Yura shouts the number of elements in the set.

The teacher got tired of Yura's shouts, so he made him write a program that would shout instead of him. But Yura doesn't know how to program, so he asked you for help.

Input
The first line contains one positive integer n (1≤n≤10^5).
Each of the following n lines contains an integer that Yura has thought of.
Yura can only think of numbers in the range from −10^9 to 10^9.

Output
On separate lines, print what Yura would shout for each query.

Examples

Input #1
5
1
2
3
4
1

Answer #1
No 1
No 2
No 3
No 4
Yes 4

*/

#include <print>
#include <vector>
#include <set>

using namespace std;

void solve(const vector<int> &numbers)
{
	set<int> seen;
	for (auto number : numbers)
	{
		if (seen.contains(number))
			println("Yes {}", seen.size());
		else
		{
			seen.insert(number);
			println("No {}", seen.size());
		}
	}
}

int main()
{
	solve({ 1, 2, 3, 4, 1 });
	return 0;
}
