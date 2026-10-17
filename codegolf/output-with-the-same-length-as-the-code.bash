#!/bin/bash

cat << EOF >/dev/null

In this challenge, you should write a program or function which takes no input and prints or returns a string with the same number of bytes as the program itself. There are a few rules:

You may only output bytes in the printable ASCII range (0x20 to 0x7E, inclusive), or newlines (0x0A or 0x0D).
Your code must not be a quine, so the code and the output must differ in at least one byte.
Your code must be at least one byte long.
If your output contains trailing newlines, those are part of the byte count.
If your code requires non-standard command-line flags, count them as usual (i.e. by adding the difference to a standard invocation of your language's implementation to the byte count), and the output's length must match your solution's score. E.g. if your program is ab and requires the non-standard flag -n (we'll assume it can't be combined with standard flags, so it's 3 bytes), you should output 5 bytes in total.
The output doesn't always have to be the same, as long as you can show that every possible output satisfies the above requirements.
Usual quine rules don't apply. You may read the source code or its size, but I doubt this will be shorter than hardcoding it in most languages.
You may write a program or a function and use any of the standard methods of providing output. Note that if you print the result, you may choose to print it either to the standard output or the standard error stream, but only one of them counts.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

EOF

# Ported from @Anders Kaseorg solution
{e,,}cho
