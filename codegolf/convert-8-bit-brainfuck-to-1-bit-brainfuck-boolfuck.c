/*

Goal
Input is a Brainfuck program for 8 bit cells, output it for 1 bit cells.

Explanation
We all know Brainfuck, normally it uses 8 bit cells. But there are implementations where a cell is just 1 bit, sometimes called Boolfuck. A Brainfuck program that is written for 8 bit cells most likely does not work when cells are just 1 bit. The goal is to write a conversation program that converts a Brainfuck program that works with 8 bit cells to one that works with 1 bit cells.

You can convert it with this Table:

+-----------------+---------------------------------------------------------+
| 8 Bit Brainfuck | Boolfuck                                                |
+-----------------+---------------------------------------------------------+
| +               | >[>]+<[+<]>>>>>>>>>[+]<<<<<<<<<                         |
| -               | >>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]<<<<<<<<<        |
| <               | <<<<<<<<<                                               |
| >               | >>>>>>>>>                                               |
| ,               | >,>,>,>,>,>,>,>,<<<<<<<<                                |
| .               | >;>;>;>;>;>;>;>;<<<<<<<<                                |
| [               | >>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<] |
| ]               | >>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]              |
+-----------------+---------------------------------------------------------+
Standard Boolfuck uses ; instead of . for output.

Rules
Input is a 0 to 255 long valid Brainfuck programs with only []-+,.<>.
Output a valid 1 bit Brainfuck or Boolfuck program that does exactly the same as the Brainfuck program.
The table above is only a suggestion, you can use a different conversion as long as it works and doesn't use more than 16 times the amount of cells 64 times the amount of code length compared to 8 bit Brainfuck.
The endianness of the input and output can be chosen, but they have to be the same.
Both ; and . are valid for output a cell.
Both + and - are valid for inverting a cell.
Your score
Every [],.+-;<> in your source code counts 1, every other byte counts 8. The sum gives your score.

Smallest score wins.

Ungolfed Example
#!/usr/bin/env python3

import sys

for line in sys.stdin:
  for c in line:
    if c=='+' : print(">[>]+<[+<]>>>>>>>>>[+]<<<<<<<<<")
    if c=='-' : print(">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]<<<<<<<<<")
    if c=='<' : print("<<<<<<<<<")
    if c=='>' : print(">>>>>>>>>")
    if c==',' : print(">,>,>,>,>,>,>,>,<<<<<<<<")
    if c=='.' : print(">;>;>;>;>;>;>;>;<<<<<<<<")
    if c=='[' : print(">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]")
    if c==']' : print(">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]")

*/

#include <stdio.h>

char *
conv(const char *s, char *b)
{
	size_t i;
	char *p;

	p = b;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '+':
			p += sprintf(p, ">[>]+<[+<]>>>>>>>>>[+]<<<<<<<<<");
			break;
		case '-':
			p += sprintf(p, ">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]<<<<<<<<<");
			break;
		case '<':
			p += sprintf(p, "<<<<<<<<<");
			break;
		case '>':
			p += sprintf(p, ">>>>>>>>>");
			break;
		case ',':
			p += sprintf(p, ">,>,>,>,>,>,>,>,<<<<<<<<");
			break;
		case '.':
			p += sprintf(p, ">;>;>;>;>;>;>;>;<<<<<<<<");
			break;
		case '[':
			p += sprintf(p, ">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]");
			break;
		case ']':
			p += sprintf(p, ">>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]");
			break;
		}
	}
	*p = '\0';

	return b;
}

int
main()
{
	char b[256];

	printf("%s\n", conv("+-<>,.[]", b));
	return 0;
}
