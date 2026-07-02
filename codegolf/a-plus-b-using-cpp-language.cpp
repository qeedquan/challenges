/*

I'm golfing a program to sum two numbers in C++.

Example:

10 3
13
I found out that this problem can be solved in 54 symbols (without spaces and so on) using C++. My code (63 symbols):

#include <iostream>
main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b;
}
I have no idea how to make my program shorter. Can you help me, please?

*/

#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}
