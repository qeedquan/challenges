#!/usr/bin/env python3

"""

Description
Today's challenge is to divide two polynomials. For example, long division can be implemented.

Display the quotient and remainder obtained upon division.

Input Description
Let the user enter two polynomials. Feel free to accept it as you wish to. Divide the first polynomial by the second. For the sake of clarity, I'm writing whole expressions in the challenge input, but by all means, feel free to accept the degree and all the coefficients of a polynomial.

Output Description
Display the remainder and quotient obtained.

Challenge Input
1:

4x^3 + 2x^2 - 6x + 3

x - 3

2:

2x^4 - 9x^3 + 21x^2 - 26x + 12

2x - 3

3:

10x^4 - 7x^2 -1

x^2 - x + 3

Challenge Output
1:

Quotient: 4x^2 + 14x + 36 Remainder: 111

2:

Quotient: x^3 - 3x^2 +6x - 4 Remainder: 0

3:

Quotient: 10x^2 + 10x - 27 Remainder: -57x + 80

Bonus
Go for long division and display the whole process, like one would on pen and paper.

"""

from sympy import *
from sympy.abc import *

def main():
    assert(div(4*x**3 + 2*x**2 - 6*x + 3, x - 3) == (4*x**2 + 14*x + 36, 111))
    assert(div(2*x**4 - 9*x**3 + 21*x**2 - 26*x + 12, 2*x - 3) == (x**3 - 3*x**2 + 6*x - 4, 0))
    assert(div(10*x**4 - 7*x**2 - 1, x**2 - x + 3) == (10*x**2 + 10*x - 27, -57*x + 80))

main()
