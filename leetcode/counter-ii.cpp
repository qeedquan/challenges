/*

Description
Write a function createCounter. It should accept an initial integer init. It should return an object with three functions.

The three functions are:

increment() increases the current value by 1 and then returns it.
decrement() reduces the current value by 1 and then returns it.
reset() sets the current value to init and then returns it.

Example 1:

Input: init = 5, calls = ["increment","reset","decrement"]
Output: [6,5,4]
Explanation:
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4

Example 2:

Input: init = 0, calls = ["increment","increment","decrement","reset","reset"]
Output: [1,2,1,0,0]
Explanation:
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0

Constraints:

-1000 <= init <= 1000
0 <= calls.length <= 1000
calls[i] is one of "increment", "decrement" and "reset"

*/

#include <cassert>

class Counter
{
private:
	int value;
	int init;

public:
	Counter(int init)
	{
		this->init = init;
		this->value = init;
	}

	int increment()
	{
		return ++value;
	}

	int decrement()
	{
		return --value;
	}

	int reset()
	{
		value = init;
		return value;
	}
};

int main()
{
	auto counter = Counter(5);
	assert(counter.increment() == 6);
	assert(counter.reset() == 5);
	assert(counter.decrement() == 4);

	counter = Counter(0);
	assert(counter.increment() == 1);
	assert(counter.increment() == 2);
	assert(counter.decrement() == 1);
	assert(counter.reset() == 0);
	assert(counter.reset() == 0);

	return 0;
}
