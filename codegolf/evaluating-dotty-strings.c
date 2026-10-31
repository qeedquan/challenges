/*

Write a program that takes in an odd length string containing only the characters . and :. With the aid of an initially empty stack, generate a number from this string as follows:

For every character c in the string (going from left to right)...

If c is . and the stack has less than 2 elements, push 1 on the stack.
If c is . and the stack has 2 or more elements, pop the two top values off the stack and push their sum onto the stack.
If c is : and the stack has less than 2 elements, push 2 on the stack.
If c is : and the stack has 2 or more elements, pop the two top values off the stack and push their product onto the stack.
The resulting number is the value at the top of the stack. Your program should print this number to stdout (with an optional trailing newline).

(A little analysis shows that there is only ever one number left unless the string has even length, which is why we are ignoring those. In fact, the stack never has more than 2 elements.)

For example, the number for ::...:.:. is 9:

  2   1   2   2    /______ stack just after the character below is handled
2 2 4 4 5 5 7 7 9  \
: : . . . : . : .  <-- string, one character at a time
As a sanity check, here are the numbers for all strings of length 1, 3, and 5:

. 1
: 2
... 2
..: 1
.:. 3
.:: 2
:.. 3
:.: 2
::. 4
::: 4
..... 3
....: 2
...:. 4
...:: 4
..:.. 2
..:.: 1
..::. 3
..::: 2
.:... 4
.:..: 3
.:.:. 5
.:.:: 6
.::.. 3
.::.: 2
.:::. 4
.:::: 4
:.... 4
:...: 3
:..:. 5
:..:: 6
:.:.. 3
:.:.: 2
:.::. 4
:.::: 4
::... 5
::..: 4
::.:. 6
::.:: 8
:::.. 5
:::.: 4
::::. 6
::::: 8
The shortest program in bytes wins. Tiebreaker is earlier post.

You may assume the input is always valid, i.e. a string containing only . and : whose length is odd.
Instead of writing a program, you may write a function that takes in a valid string and prints or returns the generated number.

*/

#include <assert.h>
#include <stdio.h>

int
proc(int *stk, int sp, int val, int op)
{
	if (sp < 2)
		stk[sp++] = val;
	else {
		sp--;
		if (op == '+')
			stk[sp - 1] += stk[sp];
		else
			stk[sp - 1] *= stk[sp];
	}
	return sp;
}

int
eval(const char *s)
{
	int stk[3], sp;
	size_t i;

	sp = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '.')
			sp = proc(stk, sp, 1, '+');
		else if (s[i] == ':')
			sp = proc(stk, sp, 2, '*');
	}
	return (sp) ? stk[sp - 1] : 0;
}

int
main(void)
{
	assert(eval("::...:.:.") == 9);
	assert(eval(".") == 1);
	assert(eval(":") == 2);
	assert(eval("...") == 2);
	assert(eval("..:") == 1);
	assert(eval(".:.") == 3);
	assert(eval(".::") == 2);
	assert(eval(":..") == 3);
	assert(eval(":.:") == 2);
	assert(eval("::.") == 4);
	assert(eval(":::") == 4);
	assert(eval(".....") == 3);
	assert(eval("....:") == 2);
	assert(eval("...:.") == 4);
	assert(eval("...::") == 4);
	assert(eval("..:..") == 2);
	assert(eval("..:.:") == 1);
	assert(eval("..::.") == 3);
	assert(eval("..:::") == 2);
	assert(eval(".:...") == 4);
	assert(eval(".:..:") == 3);
	assert(eval(".:.:.") == 5);
	assert(eval(".:.::") == 6);
	assert(eval(".::..") == 3);
	assert(eval(".::.:") == 2);
	assert(eval(".:::.") == 4);
	assert(eval(".::::") == 4);
	assert(eval(":....") == 4);
	assert(eval(":...:") == 3);
	assert(eval(":..:.") == 5);
	assert(eval(":..::") == 6);
	assert(eval(":.:..") == 3);
	assert(eval(":.:.:") == 2);
	assert(eval(":.::.") == 4);
	assert(eval(":.:::") == 4);
	assert(eval("::...") == 5);
	assert(eval("::..:") == 4);
	assert(eval("::.:.") == 6);
	assert(eval("::.::") == 8);
	assert(eval(":::..") == 5);
	assert(eval(":::.:") == 4);
	assert(eval("::::.") == 6);
	assert(eval(":::::") == 8);

	return 0;
}
