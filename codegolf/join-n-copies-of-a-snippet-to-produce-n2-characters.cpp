/*

Challenge
Write the shortest snippet of code possible such that, when N copies of it are concatenated together, the number of characters output is N2. N will be a positive integer.

For example if the snippet was soln();, then running soln(); would print exactly 1 character, and running soln();soln(); would print exactly 4 characters, and running soln();soln();soln(); would print exactly 9 characters, etc.

Any characters may be in the output as long as the total number of characters is correct. To avoid cross-OS confusion, \r\n newlines are counted as one character.

Programs may not read their own source or read their file size or use other such loopholes. Treat this like a strict quine challenge.

The output may go to stdout or a file or a similar alternative. There is no input.

Comments in the code are fine, as is exiting mid-execution.

Any characters may be in the program. The shortest submission in bytes wins.

*/

#include <iostream>
#include <string>

using namespace std;

string str;

void solution()
{
	cout << str << endl;
	str += "xx";
}

int main()
{
	solution();
	solution();
	solution();
	return 0;
}
