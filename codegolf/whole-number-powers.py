#!/usr/bin/env python3

"""

Some numbers like 64 can be expressed as a whole-number power in multiple ways:

64 ^ 1
 8 ^ 2
 4 ^ 3
 2 ^ 6
Output a sorted array of all possible such powers (here, [1,2,3,6]) in as few bytes as possible.

Input
A positive whole number that's greater than 1 and less than 10000.

Output
An array of whole-number powers p (including 1) for which the input can be expressed as a^p with whole-number a. The outputs may have decimals, as long as they are in order.

Any floating point issues must be handled by the program.

Examples
Input: 3
Output: [1]

Input: 9
Output: [1, 2]

Input: 81
Output: [1, 2, 4]

Input: 729
Output: [1, 2, 3, 6]

"""

def wnp(n):
    if n < 2:
        return []

    r = []
    for i in range(2, n + 1):
        x = i
        c = 1
        while x < n:
            x *= i
            c += 1
        if x == n:
            r.append(c)
    return sorted(r)

def main():
    assert(wnp(3) == [1])
    assert(wnp(9) == [1, 2])
    assert(wnp(64) == [1, 2, 3, 6])
    assert(wnp(81) == [1, 2, 4])
    assert(wnp(729) == [1, 2, 3, 6])

main()
