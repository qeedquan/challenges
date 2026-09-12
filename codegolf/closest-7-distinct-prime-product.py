#!/usr/bin/env python3

"""

https://chat.stackexchange.com/transcript/message/30081079#30081079
(via chat)

The OEIS entry A123321 lists the sequence of numbers that are the product of seven distinct primes. For brevity, we'll call this a 7DP number. The first few numbers and their corresponding divisors are below:

510510 = 2 * 3 * 5 * 7 * 11 * 13 * 17
570570 = 2 * 3 * 5 * 7 * 11 * 13 * 19
690690 = 2 * 3 * 5 * 7 * 11 * 13 * 23
746130 = 2 * 3 * 5 * 7 * 11 * 17 * 19
The challenge here will be to find the closest 7DP number, in terms of absolute distance, from a given input.

Input
A single positive integer n in any convenient format.

Output
The closest 7DP number to n, again in any convenient format. If two 7DP numbers are tied for closest, you can output either or both.

Rules
Numbers can be assumed to fit in your language's default [int] datatype (or equivalent).
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf, so all usual golfing rules apply, and the shortest code wins.

Examples
5 -> 510510
860782 -> 870870
1425060 -> 1438710 (or 1411410, or both)

"""

from math import isqrt, prod
from sympy import primerange, integer_nthroot, primepi

# https://oeis.org/A123321
def A123321(n):
    def g(x, a, b, c, m):
        yield from (((d, ) for d in enumerate(primerange(b+1, isqrt(x//c)+1), a+1)) if m==2 else (((a2, b2), )+d for a2, b2 in enumerate(primerange(b+1, integer_nthroot(x//c, m)[0]+1), a+1) for d in g(x, a2, b2, c*b2, m-1)))
    
    def f(x):
        return int(n+x-sum(primepi(x//prod(c[1] for c in a))-a[-1][0] for a in g(x, 0, 1, 1, 7)))
    
    def bisection(f, kmin=0, kmax=1):
        while f(kmax) > kmax: kmax <<= 1
        while kmax-kmin > 1:
            kmid = kmax+kmin>>1
            if f(kmid) <= kmid:
                kmax = kmid
            else:
                kmin = kmid
        return kmax
    return bisection(f)

def closest(n):
    i = 2
    while A123321(i) < n:
        i += 1
    
    r0 = A123321(i - 1)
    r1 = A123321(i)
    if abs(r0-n) < abs(r1-n):
        return r0
    return r1

def main():
    assert(closest(5) == 510510)
    assert(closest(860782) == 870870)
    assert(closest(1425060) == 1438710)

main()
