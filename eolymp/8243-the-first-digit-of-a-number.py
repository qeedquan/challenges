#!/usr/bin/env python3

"""

Find the first digit of an integer. Start counting digits from the leftmost one.

Input
One 64-bit integer containing at least one digit. The number can be negative.

Output
Print the first digit of a given integer.

Examples

Input #1
1234567890123

Answer #1
1

Input #2
-7654321

Answer #2
7

"""

def solve(n):
    return int(str(abs(n))[0])

def main():
    assert(solve(1234567890123) == 1)
    assert(solve(-7654321) == 7)

main()
