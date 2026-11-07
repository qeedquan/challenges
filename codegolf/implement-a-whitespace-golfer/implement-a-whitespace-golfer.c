/*

Some two-dimensional esolangs, such as Forked, and some non-esolangs, such as Python, can sometimes require spaces before lines of code. This isn't very golfy. Also, I'm lazy and writing a 2d lang that needs lots of spaces before code. Your task is to write a tool that makes these languages golfier.

Of course, this will not be perfect; it cannot be used, for instance, when a number is the first character on a line of source. However, it will generally be useful.

Challenge
You will write a program or function that either...

...takes one argument, a filename or a string, or...
...reads from standard input.
Your program will act like cat, except:

If the first character on any line is a number, your code will print x spaces, where x is that number.
Otherwise, it will simply be printed.
As will every other character in the input.
Test cases
Input:

foo bar foo bar
1foo bar foo bar foo bar
2foo bar foo bar foo bar foo bar
Output:

foo bar foo bar
 foo bar foo bar foo bar
  foo bar foo bar foo bar foo bar
Input:

--------v
8|
8|
80
8,
7&
Output:

--------v
        |
        |
        0
        ,
       &
Input:

foo bar
bar foo
foo bar
Output:

foo bar
bar foo
foo bar
Input:

0123456789
1234567890
2345678901
3456789012
4567890123
Output:

123456789
 234567890
  345678901
   456789012
    567890123
Rules
Output must be exactly as input, except for lines where the first character is a number.
Your program cannot append/prepend anything to the file, except one trailing newline if you desire.
Your program may make no assumptions about the input. It may contain empty lines, no numbers, Unicode characters, whatever.
If a number with more than one digit starts a line (e.g. 523abcdefg), only the first digit (in the example, 5) should turn into spaces.
Winner
Shortest code in each language wins. Have fun and good luck!

*/

#include <stdio.h>
#include <ctype.h>

void
catws(FILE *in, FILE *out)
{
	int f, i, c;

	f = 0;
	while ((c = fgetc(in)) != EOF) {
		if (!f) {
			if (isdigit(c)) {
				for (i = '0'; i < c; i++)
					fputc(' ', out);
				f = 1;
				continue;
			}
		}
		f = (c != '\n');
		fputc(c, out);
	}
}

int
main()
{
	catws(stdin, stdout);
	return 0;
}
