#!/usr/bin/env python3

"""

Positive integer n is given. Append to it the digit 3 from the left and from the right.

Input
One positive integer n (n≤10^9).

Output
Append to the number n the digit 3 from the left and from the right. Print the resulting number.

Examples

Input #1
2456

Answer #1
324563

Input #2
56

Answer #2
3563

"""

def solve(n):
    s = "3" + str(abs(n)) + "3"
    r = int(s)
    if n < 0:
        r = -r
    return r

def main():
    assert(solve(2456) == 324563)
    assert(solve(56) == 3563)

main()
