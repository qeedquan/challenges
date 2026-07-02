/*

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise. 

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.

*/

#include <cassert>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct UnionFind
{
	UnionFind(int n)
	{
		id.resize(n);
		iota(begin(id), end(id), 0);
	}

	void unite(int u, int v)
	{
		id[find(u)] = find(v);
	}

	int find(int u)
	{
		if (id[u] == u)
			return u;

		id[u] = find(id[u]);
		return id[u];
	}

private:
	vector<int> id;
};

bool assignable(const vector<string> &equations)
{
	UnionFind uf(26);

	for (const auto &eq : equations)
	{
		if (eq.size() == 4 && eq[1] == '=')
		{
			auto x = eq[0] - 'a';
			auto y = eq[3] - 'a';
			uf.unite(x, y);
		}
	}

	for (const auto &eq : equations)
	{
		if (eq.size() == 4 && eq[1] == '!')
		{
			auto x = eq[0] - 'a';
			auto y = eq[3] - 'a';
			if (uf.find(x) == uf.find(y))
				return false;
		}
	}

	return true;
}

int main()
{
	assert(assignable({ "a==b", "b!=a" }) == false);
	assert(assignable({ "b==a", "a==b" }) == true);

	return 0;
}
