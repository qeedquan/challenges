/*

Background
Boolean Algebra concerns representing values with letters and simplifying expressions.
The following is a chart for the standard notation used:

https://i.stack.imgur.com/kWE7v.png

Above is what actual boolean algebra looks like. For the purposes of this code golf, this is not the syntax that will be used.

Your Task
Given a string with three characters, return the solution to the expression.

Input:
The string will be a valid expression in boolean algebra. The second character will either be ".", which represents AND, or "+", which represents OR.
The first and third characters will be any of 0, 1, or a capital letter. If a capital letter is given, only one letter is ever given. ie. An input will never have two variables, such as A+B.

Output:
Return the evaluation of the expression as a single character.

Explained Examples

Input => Output
A+1 => 1
A + 1 evaluates to 1 because the OR statement is overridden by 1. That is, no matter what value A takes, the presence of 1 means that the statement will always evaluate to 1.

Input => Output
B+B => B
B + B evaluates to B because the OR statement is dependent on either Bs being true. If both Bs are false, then the output would also be false. So, the statement returns B since whatever value B takes, the output would return that.

Input => Output
0.H => 0
0 . H evaluates to 0 because the AND statement is overridden by 0. That is, no matter what value H takes, the presence of 0 means that the statement will always evaluate to 0.

Input => Output
1.1 => 1
1 . 1 evaluates 1 because the AND statement requires both inputs to be 1, and since they are both 1, 1 is returned.

Examples

Input => Output
A+1 => 1
B+B => B
R+0 => R
1+1 => 1
0+0 => 0

0.0 => 0
Q.Q => Q
0.A => 0
1.C => C
1.1 => 1
This is code-golf, so shortest answer wins.

*/

#include <assert.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
boolop(int a, int op, int b)
{
	if (a == b && (op == '+' || op == '.'))
		return a;

	if (a == '0' || a == '1')
		swap(&a, &b);

	if (b != '0' && b != '1')
		return -1;

	switch (op) {
	case '+':
		return (b == '0') ? a : '1';
	case '.':
		return (b == '1') ? a : '0';
	}
	return -1;
}

int
main(void)
{
	assert(boolop('A', '+', '1') == '1');
	assert(boolop('B', '+', 'B') == 'B');
	assert(boolop('R', '+', '0') == 'R');
	assert(boolop('1', '+', '1') == '1');
	assert(boolop('0', '+', '0') == '0');
	assert(boolop('1', '+', '0') == '1');

	assert(boolop('0', '.', '0') == '0');
	assert(boolop('Q', '.', 'Q') == 'Q');
	assert(boolop('0', '.', 'A') == '0');
	assert(boolop('1', '.', 'C') == 'C');
	assert(boolop('1', '.', '1') == '1');
	assert(boolop('1', '.', '0') == '0');

	return 0;
}
