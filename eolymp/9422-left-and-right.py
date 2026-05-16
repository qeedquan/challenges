#!/usr/bin/env python3

"""

Four digit positive integer is given. Swap the first and the last digit in it.

Input
One four digit positive integer n.

Output
Print the resulting number.

Examples

Input #1
1234

Answer #1
4231

"""

def solve(n):
    s = str(n)
    if len(s) > 1:
        s = s[-1] + s[1:len(s)-1] + s[0]
    return int(s)

def main():
    assert(solve(1234) == 4231)

main()

