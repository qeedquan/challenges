#!/usr/bin/env python3

"""

Definition

Wolstenholme's theorem states that:

    binomial(ap, bp) ≡ binomial(a, b) (mod p^3)

where a and b are positive integers and p is prime, and the big parentheses thingy is Binomial coefficient.

Task
To verify that, you will be given three inputs: a, b, p, where a and b are positive integers and p is prime.

Compute:

    (binomial(ap, bp) - binomial(a, b)) / p^3

where a and b are positive integers and p is prime, and the parentheses thingy is Binomial coefficient.

Specs
Since:

    binomial(n, r) = binomial(n, n - r)

where and the parentheses thingy is Binomial coefficient.

You can assume that 2b <= a

Testcases
a b p  output
6 2 5  240360
3 1 13 3697053
7 3 13 37403621741662802118325

"""

from math import *

def wolstenholmes(a, b, p):
    return (comb(a*p, b*p) - comb(a, b)) // p**3

def main():
    assert(wolstenholmes(6, 2, 5) == 240360)
    assert(wolstenholmes(3, 1, 13) == 3697053)
    assert(wolstenholmes(7, 3, 13) == 37403621741662802118325)

main()
