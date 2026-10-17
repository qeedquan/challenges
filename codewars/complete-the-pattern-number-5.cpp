/*

Task:
You have to write a function pattern which creates the following pattern up to n/2 number of lines.

If n <= 1 then it should return "" (i.e. empty string).
If any odd number is passed as argument then the pattern should last up to the largest even number which is smaller than the passed odd number.
Examples:
n = 8:

22
4444
666666
88888888
n = 5:

22
4444
Note: There are no spaces in the pattern.

Hint: Use \n in string to jump to next line.

*/

#include <iostream>

using namespace std;

void pattern(int n)
{
	cout << "n=" << n << endl;
	for (auto i = 2; i <= n; i += 2)
	{
		for (auto j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	pattern(-25);
	pattern(0);
	pattern(1);
	pattern(2);
	pattern(5);
	pattern(8);
	return 0;
}
