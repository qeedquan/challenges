#!/usr/bin/env python3

"""

In a five-digit natural number, eliminate the digits located in the even positions, specifically the second and fourth digits.

Input
A five-digit natural number.

Output
The result after removing the specified digits.

Examples

Input #1
12345

Answer #1
135

"""

def solve(n):
    s = str(abs(n))
    s = s[:1] + s[2:3] + s[4:]
    r = int(s)
    if n < 0:
        r = -r
    return r

def main():
    assert(solve(12345) == 135)

main()
