#!/usr/bin/env python3

"""

A prime gap is the difference between two consecutive primes. More specifically, if p and q are primes with p <q and p+1, p+2, ..., _q_−1 are not primes, the primes p and q define a gap of n = q_−_p. The gap is said to be started by p, and to have length n.

It is known that arbitrarily large prime gaps exist. That is, given n there exists a prime gap of length n or larger. However, a prime gap of length exactly n may not exist (but a larger one will).

The challenge
Given a positive integer n, output the first prime that starts a gap of length n or larger.

As an example, for input 4 the output should be 7, because 7 and 11 are the first consecutive primes that differ by at least 4 (the previous gaps are 1, from 2 to 3; 2, from 3 to 5; and 2, from 5 to 7). For input 3 the answer should also be 7 (there are no gaps of length 3).

Additional rules
The algorithm should theoretically work for arbitrarily high n. In practice, it is acceptable if the program is limited by time, memory or data-type size.

Input and output can be taken by any reasonable means.

Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

Shortest code in bytes wins.

Test cases
Input -> Output

1        2
2        3
3        7
4        7
6        23
10       113
16       523
17       523
18       523
30       1327
50       19609
100      370261
200      20831323

"""

from sympy import nextprime

# https://oeis.org/A104138
def primegap(n):
    if n < 1:
        return 0
    p = 2
    while True:
        q = nextprime(p)
        if q - p >= n:
            return p
        p = q

def main():
    assert(primegap(1) == 2)
    assert(primegap(2) == 3)
    assert(primegap(3) == 7)
    assert(primegap(4) == 7)
    assert(primegap(6) == 23)
    assert(primegap(10) == 113)
    assert(primegap(16) == 523)
    assert(primegap(17) == 523)
    assert(primegap(18) == 523)
    assert(primegap(30) == 1327)
    assert(primegap(50) == 19609)
    assert(primegap(100) == 370261)
    assert(primegap(200) == 20831323)

main()
