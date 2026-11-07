#!/usr/bin/env python3

"""

Given two positive integers a and b, output two positive integers c and d such that:

c divides a
d divides b
c and d are co-prime
the least common multiple of c and d equals the least common multiple of a and b.
If there are more than one possible answers, you can output only one or all of them.

Test cases:

 a  b  c  d
12 18  4  9
18 12  9  4
 5  7  5  7
 3  6  1  6 or 3 2
 9  9  9  1 or 1 9
 6 15  2 15 or 6 5
 1  1  1  1
This is code-golf. Shortest answer in bytes wins.

"""

# Ported from @Chas Brown solution
def f(a, b):
    c = [1, 1]
    p = 2
    while p <= a * b:
        t = m = 1
        while (a * b) % p < 1:
            m *= p
            t = b % p < 1
            a /= p**(a%p < 1)
            b /= p**t
        p += 1
        c[t] *= m
    return c

def main():
    assert(f(12, 15) == [4, 15])
    assert(f(12, 18) == [4, 9])
    assert(f(18, 12) == [9, 4])
    assert(f(5, 7) == [5, 7])
    assert(f(3, 6) == [1, 6])
    assert(f(9, 9) == [1, 9])
    assert(f(6, 6) == [1, 6])
    assert(f(1, 1) == [1, 1])

main()
