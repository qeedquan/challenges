/*

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Your code will be tested with the following pseudocode:

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.

 

Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 

Constraints:

1 <= nestedList.length <= 500
The values of the integers in the nested list is in the range [-10^6, 10^6].

*/

#include <iostream>
#include <vector>

using namespace std;

class NestedInteger
{
private:
	int type;
	int integer;
	vector<NestedInteger> list;

public:
	NestedInteger(int integer)
	{
		this->type = 'i';
		this->integer = integer;
	}

	NestedInteger(vector<NestedInteger> list)
	{
		this->type = 'l';
		this->list = list;
	}

	vector<NestedInteger> &getList()
	{
		return list;
	}

	bool isInteger()
	{
		return type == 'i';
	}

	int getInteger()
	{
		return integer;
	}
};

class NestedIterator
{
private:
	vector<int> values;
	size_t index;

	void flatten(vector<NestedInteger> &list)
	{
		for (auto item : list)
		{
			if (item.isInteger())
				values.push_back(item.getInteger());
			else
				flatten(item.getList());
		}
	}

public:
	NestedIterator(vector<NestedInteger> &list)
	{
		flatten(list);
		index = 0;
	}

	int next()
	{
		return values[index++];
	}

	bool hasNext()
	{
		return index < values.size();
	}
};

void test(vector<NestedInteger> &list)
{
	NestedIterator iterator(list);
	while (iterator.hasNext())
		cout << iterator.next() << " ";
	cout << endl;
}

int main()
{
	vector<NestedInteger> list1 = { NestedInteger(1), NestedInteger(1) };
	vector<NestedInteger> list2 = { list1, NestedInteger(2), list1 };

	vector<NestedInteger> list3 = { NestedInteger(6) };
	vector<NestedInteger> list4 = { NestedInteger(4), list3 };
	vector<NestedInteger> list5 = { NestedInteger(1), list4 };

	test(list2);
	test(list5);

	return 0;
}
