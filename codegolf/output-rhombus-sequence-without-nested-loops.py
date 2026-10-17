#!/usr/bin/env python3

"""

The following is the rhombus sequence.

1
121
12321
1234321
123454321
12345654321
1234567654321
123456787654321
12345678987654321
Your task is to output this, taking no input and using standard output methods (STDOUT, list of numbers or list of strings, etc.).

There's a hitch. You may only use up to one loop - no nested loops. Recursion counts as a loop, so you can either recurse or loop, not both. Non-standard languages will be dealt with on a case-by-case basis.

This is code-golf, so shortest program in bytes wins. This is kolmorgorov-complexity, so you may not take any input whatsoever.

"""

def rhombus():
    i = 0
    exec("i=i*10+1; print(i*i);" * 9)

def main():
    rhombus()

main()
