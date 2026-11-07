/*

The relational operators in C programming language are shown in the table below. Of course the last two are also known as equality operators.

These operators compare the value of the two operands it is working on (The value on its left and the value on its right) and returns true or false (one or zero).
For example value of 2 > 3 is interpreted as "false" (As 2 is actually less than 3),
value of 3 != 4 is interpreted as true and value of 3 >= 3 is also interpreted as true.
You have to find out this interpretation using a program.

Input
The input file contains around 12000 lines of input.
Each line contains two integers a and b separated by an operator ">", ">=", "<", "<=", "==" or "!=".
Input is terminated by a line which contains an "E" instead of the operators.
Note that there is also a space between any operator and operand.
You can assume (−10000≤a,b≤10000).

Output
For each line of input produce one line of output.
This line contains the serial of output followed by a string "true" or "false" (without the quotes) which denotes how the expression is interpreted in C language.
Look at the output for sample input for details.

Examples
Input #1
3 != 3
4 < 4
4 <= 5
3 E 3

Answer #1
Case 1: false
Case 2: false
Case 3: true

*/

#include <cassert>
#include <string>

using namespace std;

bool relop(int a, const string &op, int b)
{
	if (op == ">")
		return a > b;
	if (op == ">=")
		return a >= b;
	if (op == "<")
		return a < b;
	if (op == "<=")
		return a <= b;
	if (op == "==")
		return a == b;
	if (op == "!=")
		return a != b;
	return false;
}

int main()
{
	assert(relop(3, "!=", 3) == false);
	assert(relop(4, "<", 4) == false);
	assert(relop(4, "<=", 5) == true);

	return 0;
}
