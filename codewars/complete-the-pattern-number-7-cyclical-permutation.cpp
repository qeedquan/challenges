/*

Task:
You have to write a function pattern which creates the following pattern (See Examples) upto desired number of rows.

If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.

Examples:
pattern(9):

123456789
234567891
345678912
456789123
567891234
678912345
789123456
891234567
912345678

pattern(5):

12345
23451
34512
45123
51234

Note: There are no spaces in the pattern

Hint: Use \n in string to jump to next line

*/

#include <iostream>

using namespace std;

void pattern(int n)
{
	cout << "n=" << n << endl;
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < n; j++)
			cout << ((i + j) % n) + 1;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	pattern(5);
	pattern(9);
	return 0;
}
