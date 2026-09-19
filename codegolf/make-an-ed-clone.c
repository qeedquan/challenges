/*

ed is the standard text editor on Unix systems. Your goal is to write an ed clone.

Task
Write a program that reads an input stream and for every received end of line character, print ? followed by a end of line character.

The communication has to interactive. Means the program needs to output as soon as possible and has to accept more input after that.
There are no input lines that are longer than 105 characters + end of line character
You can choose which character or sequence you use as end of line character, as long as it does not contain any alphanumerical characters nor the ? character.
The program should not output anything else.
Shortest code wins.

Example Python Script
#/usr/bin/env python3

import sys

for line in sys.stdin:
  print("?")

*/

#include <stdio.h>

void
ed()
{
	char line[128];

	while (fgets(line, sizeof(line), stdin))
		puts("?");
}

int
main()
{
	ed();
	return 0;
}
