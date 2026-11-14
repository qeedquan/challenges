#!/usr/bin/env python3

"""

Three-digit number is given. Rearrange its digits to get the maximum number (written with the same digits). Then this maximum number should be squared and printed.

Input
One three-digit positive integer.

Output
Print the square of maximum number.

Examples
Input #1
327

Answer #1
535824

"""

def solve(n):
    s = sorted(str(abs(n)), reverse=True)
    r = int(''.join(s))
    return r * r

def main():
    assert(solve(327) == 535824)

main()
