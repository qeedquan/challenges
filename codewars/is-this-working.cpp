/*

Rewriting selfies
Let's get rid of the `self` usage, by using arrow functions!

This can be achieved without arrow functions as well, but the point would be to learn the differences.

Reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions

*/

#include <iostream>

using namespace std;

struct Counter
{
	int count = 0;

	void updateCount()
	{
		count++;
	}
};

int main()
{
	Counter counter;
	for (auto index = 0; index <= 10; index++)
	{
		cout << counter.count << endl;
		counter.updateCount();
	}
	return 0;
}
