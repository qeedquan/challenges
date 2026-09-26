#!/usr/bin/env python3

"""

A programmer at the South Pole was working on a computer wearing gloves, so he could only type 0 and 1.
However, the 0 key got stuck.
Is it possible for him to type the smallest number consisting of only ones that is also a multiple of a given number n?

Input
One integer n (n≤1000) is given.

Output
Print the required number, or no if no such number exists.

Examples

Input #1
100

Answer #1
no

Input #2
57

Answer #2
111111111111111111

"""

from math import gcd

"""

https://www.reddit.com/r/learnmath/comments/15auttb/pigeonhole_principle_problem/
https://en.wikipedia.org/wiki/Repunit

It is possible to type such a number if and only if the given number n is not divisible by 2 or 5 (gcd(n, 10) = 1)

Divisibility by 2: Any number consisting only of ones (a repunit) is always odd.
If n is even, all its multiples are also even and must end in 0, 2, 4, 6, or 8.
Therefore, no multiple of an even n can consist only of ones.

Divisibility by 5: Any multiple of a number divisible by 5 must end in either 0 or 5.
Since every repunit ends in 1, it is impossible for a number consisting only of ones to be a multiple of any n divisible by 5.

Condition for Existence: For any other (n) (those ending in 1, 3, 7, or 9), a repunit multiple is guaranteed to exist.
This can be proven using the Pigeonhole Principle:

"""

def solve(n):
    if gcd(n, 10) != 1:
        return "no"
    
    p = 1
    while p%n != 0:
        p = (10 * p) + 1
    return p

def main():
    assert(solve(100) == "no")
    assert(solve(57) == 111111111111111111)
    assert(solve(3) == 111)
    assert(solve(13) == 111111)

main()

