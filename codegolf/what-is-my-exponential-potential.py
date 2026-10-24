#!/usr/bin/env python3

"""

We'll define the N-exponential potential of a positive integer M as the count of prefixes of MN that are perfect N-powers.

The prefixes of an integer are all the contiguous subsequences of digits that start with the first one, interpreted as numbers in base 10. For example, the prefixes of 2744 are 2, 27, 274 and 2744.

A prefix P is a perfect N-power if there exists an integer K such that K^N = P. For example, 81 is a perfect 4-power because 3^4 = 81.

Given two strictly positive integers M and N, compute the N-exponential potential of M according to the definition above.

For instance, the 2-exponential potential of 13 is 3 because 132 is 169, and 1, 16 and 169 are all perfect squares.

Test cases
Naturally, the outputs will nearly always be pretty small because powers are... well... exponentially growing functions and having multiple perfect-power prefixes is rather rare.

M, N     -> Output

8499, 2  -> 1
4,    10 -> 2
5,    9  -> 2
6,    9  -> 2
13,   2  -> 3

"""

# ported from @Chas Brown solution
def exppot(m, n):
    s = m**n
    k = 0
    while s > 0:
        if round(s**(1.0/n))**n == s:
            k += 1
        s //= 10
    return k

def main():
    assert(exppot(13, 2) == 3)
    assert(exppot(8499, 2) == 1)
    assert(exppot(4, 10) == 2)
    assert(exppot(5, 9) == 2)
    assert(exppot(6, 9) == 2)
    assert(exppot(13, 2) == 3)

main()
