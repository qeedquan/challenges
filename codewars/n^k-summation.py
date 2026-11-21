#!/usr/bin/env python3

"""

Description
It is well known that

Sum[i=1, n] i = 1/2*n^2 + 1/2*n

Also

Sum[i=1, n] i^2 = 1/3*n^3 + 1/2*n^2 + 1/6*n

Task:

Sum[i=1, n] i^k

Given a natural number value k for the equation above, generate a simplified expanded form equation that would be equivalent to the summation.

Make sure your answer has terms with higher degree coming first.

For a better idea of the exact format, refer to the examples.

Notice
Test cases will get large as  k k can go up to 140, so you might consider using BigInteger

Example 1
Sum[i=1, n] i^1
equation(1) -> "1/2n^2 + 1/2n"

Example 2
Sum[i=1, n] i^4
equation(4) -> "1/5n^5 + 1/2n^4 + 1/3n^3 - 1/30n"

"""

from sympy import *

# https://en.wikipedia.org/wiki/Faulhaber%27s_formula
def equation(n):
    r = 0
    x = symbols('n')
    for i in range(n + 1):
        r += Rational(1, n + 1) * binomial(n + 1, i) * bernoulli(i) * x**(n + 1 - i)
    
    s = ""
    p = Poly(r)
    c = p.all_coeffs()
    for i in range(len(c)):
        if c[i] == 0:
            continue
        
        op = "+"
        if c[i] < 0:
            c[i] = -c[i]
            op = "-"

        s += "%s%sn^%d" % (op, str(c[i]), n - i + 1)

    s = s.lstrip("+")
    s = s.replace("^1", "")
    s = s.replace("+", " + ")
    s = s.replace("-", " - ")
    return s

def main():
    assert(equation(1) == "1/2n^2 + 1/2n")
    assert(equation(3) == "1/4n^4 + 1/2n^3 + 1/4n^2")
    assert(equation(4) == "1/5n^5 + 1/2n^4 + 1/3n^3 - 1/30n")

main()
