/*

Find the previous permutation in lexicographical order.

For the permutation 1,2,3,…,N−1,N, the previous permutation is N,N−1,…,3,2,1.

Input
The first line of the input contains the integer N (1≤N≤10^5), representing the number of elements in the permutation.
The second line provides the permutation itself.

Output
Output N numbers representing the desired permutation.

Examples

Input #1
3
1 2 3

Answer #1
3 2 1

*/

#include <print>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &&values)
{
	prev_permutation(values.begin(), values.end());
	for (auto value : values)
		print("{} ", value);
	println();
}

int main()
{
	solve({ 1, 2, 3 });
	return 0;
}
