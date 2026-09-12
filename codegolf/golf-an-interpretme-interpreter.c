/*

This is a very simple challenge.

The joke language InterpretMe consists of one command; *, which causes the program to take input of an InterpretMe program and execute it.

An InterpretMe program will interpret as many InterpretMe programs as there are * in input.

Your goal is to create a program that interprets InterpretMe in as few bytes as possible.

Input
Input will consist of one line ASCII strings, unicode utf-8 strings if you really want, or any character encoding that your language uses, if you want it that much. These strings can either be inputted at the start, or at the start of every run of InterpretMe interpreter. If they are all inputted at the start, the program must output every program line as it begins it.

Output
In this challenge, there will be no output unless the option of one input is chosen, otherwise only termination and non-termination

Test cases consist not of input and output, but input and termination. A newline denotes a new input to be interpreted as InterpretMe.

If using one input at the start, this could be considered what is outputted when these programs are inputted, followed by inactive (do nothing) lines.

1. *   (executes input as an interpret me program, finishes)
2. *   (^same)
3. **  (executes input as an interpret me program, then does this again after the first program is done, finishes)
4. hi  (nothing, first star of previous line finishes)
5. **  (same as the other two star line)
6. hi  (nothing, first star of previous line finishes)
7. hi  (nothing, second star of line 5 finishes, so second star of line 3 finishes, so line 2 finishes, so line one finishes)
[termination] (not outputted)
hi  (does nothing and finishes)
[termination]
*hi  (executes inputted program, finishes)
*yo  (executes inputted program, finishes)
hey  (nothing)
[termination]
Again, this is code-golf, so fewer bytes is better

*/

#include <stdio.h>

void
interpret()
{
	int c, i;

	for (i = 1; i > 0; i--) {
		for (;;) {
			c = fgetc(stdin);
			if (c == '\n' || c == EOF)
				break;
			if (c == '*')
				i++;
		}
	}
}

int
main()
{
	interpret();
	return 0;
}
