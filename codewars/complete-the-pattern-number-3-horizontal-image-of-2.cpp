/*

Description:
Task:
You have to write a function pattern which creates the following pattern upto n number of rows. If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.

Pattern:
(n)
(n)(n-1)
(n)(n-1)(n-2)
................
.................
(n)(n-1)(n-2)....4
(n)(n-1)(n-2)....43
(n)(n-1)(n-2)....432
(n)(n-1)(n-2)....4321
Examples:
pattern(4):

4
43
432
4321
pattern(6):

6
65
654
6543
65432
654321
Note: There are no blank spaces

Hint: Use \n in string to jump to next line

*/

#include <iostream>

using namespace std;

void pattern(int n)
{
	cout << "n=" << n << endl;
	for (auto i = 1; i <= n; i++)
	{
		for (auto j = 0; j < i; j++)
			cout << n - j;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	pattern(-25);
	pattern(0);
	pattern(1);
	pattern(4);
	pattern(5);
	pattern(6);

	return 0;
}