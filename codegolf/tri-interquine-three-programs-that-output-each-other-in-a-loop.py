#!/usr/bin/env python3

"""

Related: Interquine

Program A outputs program B's code when run, and B outputs C's source, and C outputs A's source.

This time you can't exchange two characters and exchange again :)

Requirements:
Only one language across all programs
Standard loopholes restrictions apply
All programs are different. One program that outputs itself does not qualify. Two that output each other does not qualify, too.
All programs are non-empty, or at least 1 byte in length.
There's nothing to read because stdin is connected to /dev/null (You can abuse this rule if you can). Output goes to stdout.
Do not use functions that generate random results.
Additional:

Give explanations if possible
Score is length of the shortest one (can you generate a long program from a short one?). Please write the length of all programs and highlight the smallest number. Trailing newline does not count. Lowest score wins.

"""

"""

@Leaky Nun

The last expression goes from 1*2%7 to 2*2%7 to 4*2%7 then back to 1*2%7.

"""

s='s=%r;print(s%%(s,%i*2%%7))';print(s%(s,1*2%7))
