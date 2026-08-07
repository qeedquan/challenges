#!/usr/bin/env python3

"""

Given a non-negative number in base p, determine its value modulo p−1.
Output the result in base p without leading zeros.

Input
The first line contains the integer p (2≤p≤10).
The second line contains the representation of the number in base p, consisting of at most 1000 digits and having no leading zeros.

Output
Output a single number in base p — the answer to the problem, without leading zeros.

Examples

Input #1
10
123456781987654321

Answer #1
1

"""

def digsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

"""

The value of any number in base p modulo (p-1) is equal to the sum of its digits modulo (p-1).
If the final result is 0, the answer is 0 (unless the original number was 0).

"""

def solve(p, n):
    return digsum(n) % (p - 1)

def main():
    assert(solve(10, 123456781987654321) == 1)

main()

