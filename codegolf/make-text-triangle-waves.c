/*

I was messing around on my 'ol TI-84 CE and made a program that produced this output (it was actually bigger but that is not the point):

 *
 *  *
 *  *  *
 *  *
 *
 *  *
 *  *  *
 *  *
 *
...
I evolved it to take input text and make the triangle waves out of that. The final step was to also take a number to specify the size (n>0). But I am super lazy so you must do it for me!

Challenge
Given a string and number (n > 0), output a triangle wave. This should be in the following format (with * as the string input)

 *
 *  *
 *  *  *
 *  *  * *
 *  *  * * (...)
 *  *  * *
 *  *  *
 *  *
 *
 *
 *  *
 *  *  *
 *  *  * *
 *  *  * * (...)
 *  *  * *
 *  *  *
 *  *
 *
 (...)
Each line starts with 1 space on the left edge.

The first line should have * on the right edge, for a full line of *.

Every line after that, for the next n - 1 lines, you add *, <linenumber> times. So for n=3:

 *
 *  *
 *  *  *
 *  *
 *
Then, output this full triangle infinitely:
 *
 *  *
 *  *  *
 *  *
 *
 *  *
 *  *  *
 *  *
 *
Note that you can't have something like this, for n=2:

 *
 *  *
 *
 *
 *  *
 *
You must trim the repeated single *.

Another example, with a multichar string input:

'hi', 4 ->

 hi
 hi  hi
 hi  hi  hi
 hi  hi  hi  hi
 hi  hi  hi
 hi  hi
 hi
 hi  hi
 hi  hi  hi
...
Assorted other rules:
Output must be immediately visible (i.e. it will wait to display until the program ends)

You may take the input in any reasonable way, so ["hi",3] is allowed but ["h",1,"i"] is not. However, you may not use Ans to take input in TI-Basic programs.

You must continue the pattern forever, or until the program ends due to memory limits.

You do not need to have trailing spaces but leading spaces are required.

You must print up to one line at a time. (i.e. each line must be printed all at once, you can't print each triangle iteration by itself)

The one space padding is before and after each instance of the text

Here is an answer you can use to check your output. (with video)

Leading or trailing newlines are fine.

*/

#include <stdio.h>

void
line(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf(" %s ", s);
	printf("\n");
}

void
output(const char *s, int n)
{
	int i;

	for (i = 1; i <= n; i++)
		line(s, i);
	for (i = n - 1; i >= 2; i--)
		line(s, i);
}

int
main()
{
	output("hi", 4);

	return 0;
}
