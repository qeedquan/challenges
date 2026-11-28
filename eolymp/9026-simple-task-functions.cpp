/*

You must implement the following procedure:

void solve(int n) // C++
procedure solve(number: integer); // Pascal
def solve(number): # Python
The procedure receives a two-digit integer n as input and should output its digits, separated by a space.

For example, if n=23, the procedure should output

2 3
Input
Your program should not read data from a file. The testing system will call your function with the necessary parameters.

Interaction
You must implement the following procedure:

void solve(int n) // C++
procedure solve(number: integer); // Pascal
def solve(number): # Python
The parameter n is a two-digit integer (10≤n≤99).

The procedure should output two numbers separated by a space — the digits of the number n.

Examples
Input #1
23

Answer #1
2 3

*/

#include <cassert>
#include <utility>

using namespace std;

pair<int, int> solve(int n)
{
	return { (n / 10) % 10, n % 10 };
}

int main()
{
	assert(solve(23) == make_pair(2, 3));

	return 0;
}
