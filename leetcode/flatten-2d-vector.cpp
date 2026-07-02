/*

Problem:
Implement an iterator to flatten a 2d vector.

For example, Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.

*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Vector2D
{
	vector<vector<int>> values;
	size_t row;
	size_t col;

public:
	Vector2D(const vector<vector<int>> &values) : values(values)
	{
		row = 0;
		col = 0;
	}

	int next()
	{
		if (!hasNext())
			return 0;

		auto ret = values[row][col++];
		while (row < values.size() && col >= values[row].size())
		{
			row += 1;
			col = 0;
		}
		return ret;
	}

	bool hasNext()
	{
		if (row >= values.size() || col >= values[row].size())
			return false;
		return true;
	}
};

int main()
{
	auto it = Vector2D({{1, 2}, {3}, {4, 5, 6}});
	while (it.hasNext())
		cout << it.next() << endl;

	return 0;
}
