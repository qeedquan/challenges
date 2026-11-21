#!/usr/bin/env python3

"""

Given a four-digit natural number, swap its middle two digits.

Input
The only line contains a four-digit natural number.

Output
Output the new number after swapping the middle digits.

Examples

Input #1
4765

Answer #1
4675

"""

def solve(n):
    s = str(n)
    if len(s) >= 3:
        s = s[:-3] + s[-2] + s[-3] + s[-1]
    return int(s)

def main():
    assert(solve(8010) == 8100)
    assert(solve(9620) == 9260)
    assert(solve(4765) == 4675)

main()
