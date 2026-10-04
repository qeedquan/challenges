#!/usr/bin/env python3

"""

Find the maximum digit in a positive integer n.

Input
One positive integer n (n<10^18).

Output
Print the maximum digit in the positive integer n.

Examples

Input #1
2354

Answer #1
5

Input #2
609432232423423

Answer #2
9

"""

def solve(n):
    return int(max(str(abs(n))))

def main():
    assert(solve(2354) == 5)
    assert(solve(609432232423423) == 9)

main()
