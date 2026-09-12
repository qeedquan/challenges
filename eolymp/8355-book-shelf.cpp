/*

Mamed arranges his books on a shelf. If the shelf is empty, he simply places a book there.
If there are already books on the shelf, he places the new book either to the left or to the right of the existing books.
Similarly, he removes books only from the left or right edge.
Based on the given information, it is necessary to simulate Mamed's actions and print the numbers of the books he will remove.

Input
The first line contains the number of operations n (1≤n≤10^4) that Mamed performed.
The following n lines contain the details of the operations:

Each operation of placing a book on the shelf is described by a pair of numbers.
The first number (1 or 2) indicates which edge the book is placed on (left or right), and the second number (from 0 to 10^4) represents the number of the book.

Operations of removing a book from the shelf are described by a single number: 3 or 4, indicating which edge the book is removed from (left or right).

Output
For each operation of removing a book from the shelf, print the number of the book being removed.

Examples

Input #1
10
1 1
2 2
1 3
2 7
2 9
3
4
3
3
4

Answer #1
3
9
1
2
7

*/

#include <deque>
#include <string>
#include <vector>
#include <print>

using namespace std;

void solve(const vector<vector<int> > &commands)
{
	deque<int> deque;
	for (auto command : commands)
	{
		auto operation = 0;
		auto value = 0;
		if (command.size() >= 1)
			operation = command[0];
		if (command.size() >= 2)
			value = command[1];

		switch (operation)
		{
		case 1:
			deque.push_front(value);
			break;
		case 2:
			deque.push_back(value);
			break;
		case 3:
			println("{}", deque.front());
			deque.pop_front();
			break;
		case 4:
			println("{}", deque.back());
			deque.pop_back();
			break;
		}
	}
}

int main()
{
	solve({
		{ 1, 1 },
		{ 2, 2 },
		{ 1, 3 },
		{ 2, 7 },
		{ 2, 9 },
		{ 3 },
		{ 4 },
		{ 3 },
		{ 3 },
		{ 4 },
	});

	return 0;
}
