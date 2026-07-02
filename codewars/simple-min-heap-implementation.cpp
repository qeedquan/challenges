/*

Heap
Heap is a data structure, that takes elements in arbitrary order, and returns them in a sorted order one by one.

Implementing a min heap
In this kata, we will implement a min heap, it is going to have 2 methods:

push
Takes a value and adds it to a heap

pop
Finds the smallest value in the heap, removes it from the heap, and returns it

var heap = new MinHeap();
heap.push(4);
heap.push(1);
heap.push(7);
heap.push(9);
heap.push(2);

console.log( heap.pop()); // 1
console.log( heap.pop()); // 2
console.log( heap.pop()); // 4
console.log( heap.pop()); // 7
console.log( heap.pop()); // 9

Please note that for this kata we do not assess the effiency of your implementation, so anything that acts like a heap will pass the tests.

You can read more about heap wikipedia ( http://en.wikipedia.org/wiki/Heap_%28data_structure%29 )

*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> heap;
	heap.push(4);
	heap.push(1);
	heap.push(7);
	heap.push(9);
	heap.push(2);
	while (!heap.empty())
	{
		cout << heap.top() << endl;
		heap.pop();
	}

	return 0;
}
