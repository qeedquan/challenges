#!/usr/bin/env python3

"""

This is similar to prime factorization, where you find the smallest prime factors of a number (i.e. 8 = 2 x 2 x 2). But this time, you are to return an array/list of the smallest composite factors of any given positive integer n. If n is prime, simply return an empty list.

Examples:

Prime:

n = 2
Result: []
Composite and Positive:

n = 4
Result: [4]

n = 32
Result: [4, 8]

n = 64
Result: [4, 4, 4]

n = 96
Result: [4, 4, 6]
Rules:

The product of the factors in the list must equal the input

Standard loopholes are banned

An array/list must be returned or printed (i.e. [4])

Your program must be able to return the same results for the same numbers seen in the examples above

The factors in the array/list can be strings so [4] and ["4"] are both equally valid

A prime number is any positive integer whose only possible factors are itself and 1. 4 returns [4] but is not prime since 2 is also a factor.

A composite number for this challenge any positive integer that has 3 or more factors (including 1) like 4, whose factors are 1, 2, and 4.

Clarifications:

Given a number such as 108, there are some possibilities such as [9, 12] or [4, 27]. The first integer is to be the smallest composite integer possible (excluding 1 unless mandatory) thus the array returned should be [4, 27] since 4 < 9.

All factors after the first factor need to be as small as possible as well. Take the example of 96. Instead of simply [4, 24], 24 can still be factored down to 4 and 6 thus the solution is [4, 4, 6].

Winning Criteria:

Shortest code wins since this is code-golf.

"""

from sympy import factorint

def composites(n):
    f = factorint(n)
    p = []
    for i in f:
        for _ in range(f[i]):
            p.append(i)
    p.sort()

    if len(p) < 2:
        return []

    r = []
    i = 0
    while i < len(p):
        if len(p)-i == 3:
            r.append(p[i] * p[i + 1] * p[i + 2])
            i += 3
        else:
            r.append(p[i] * p[i + 1])
            i += 2

    return r

def main():
    assert(composites(4) == [4])
    assert(composites(8) == [8])
    assert(composites(32) == [4, 8])
    assert(composites(64) == [4, 4, 4])
    assert(composites(96) == [4, 4, 6])
    assert(composites(108) == [4, 27])

main()
