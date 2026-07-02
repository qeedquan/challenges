/*

Introduction
Compute is a esoteric joke language.

From the esolangs entry:

Compute has no required syntax and has the power to solve any and all problems. It is smart enough to interpret any human language (English, Spanish, Latin, etc), any programming language (C++, Java, brainfuck, etc), or any kind of data you can think of. The only downfall is that there is absolutely no I/O.

Some example programs
Hello World
A basic Hello World program

What is love?
Determines was love is (baby don't hurt me).

When will we ever graduate?
Determines the exact date of this site to get out of beta.

The Challenge
Your task is to write a full Compute interpreter. This sounds pretty hard, but keep in mind that Compute has absolutly no I/O. So your interpreter will just sleep one second for every line in the input program and output \n\nDone. after this (this is the only exception to the no I/O thing).

You can find the official interpreter at the bottom of this site.
Note that the official interpreter pauses one second for every character in the given source code. To avoid long waiting times while testing your interpreter with meaningful questions we stay with lines in this challenge.

Rules
The input might contain multiple lines seperated by a \n. There will always be at least one line.
Unlike the official implementation you don't have to take a file as input. You can take the Compute program in any form of input you want.
The only output allowed is \n\nDone.. A trailing newline is allowed.
Function or full program allowed.
Default rules for input/output.
Standard loopholes apply.
This is code-golf, so lowest byte-count wins. Tiebreaker is earlier submission.

*/

#include <stdio.h>
#include <time.h>
#include <threads.h>

const char *
nextline(const char *s)
{
	while (*s) {
		s++;
		if (s[-1] == '\n')
			break;
	}
	return s;
}

void
compute(const char *s)
{
	const struct timespec t = {
	    .tv_sec = 1,
	};

	while (*s) {
		s = nextline(s);
		thrd_sleep(&t, NULL);
	}
	puts("\n\nDone.");
}

int
main(void)
{
	compute("Hello World");
	compute("What is love?");
	compute("When will we ever graduate?");
	compute("3\n2\n1");
	compute("42");

	return 0;
}
