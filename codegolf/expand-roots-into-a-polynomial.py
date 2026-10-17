#!/usr/bin/env python3

"""

Challenge
Given the roots of a polynomial separated by spaces as input, output the expanded form of the polynomial.

For example, the input

1 2
represents this equation:

(x-1)(x-2)
And should output:

x^2-3x+2
The exact format of output is not important, it can be:

1x^2+-3x^1+2x^0
or:

0 0 0
1x^3+0x^2+0x^1+0
or:

3 14 15 92
1x^4+-124x^3+3241x^2+-27954x^1+57960

Scoring/Rules
eval and likes are disallowed.
You may use any version of Python or any other language.

"""

from sympy import *
from sympy.abc import *

def expand_roots(c):
    if len(c) == 0:
        return 0

    p = 1
    for r in c:
        p *= (x - r)

    return expand(p)

def main():
    assert(expand_roots([1, 2]) == (x**2 - 3*x + 2))
    assert(expand_roots([3, 14, 15, 92]) == (x**4 - 124*x**3 + 3241*x**2 - 27954*x**1 + 57960))

main()
