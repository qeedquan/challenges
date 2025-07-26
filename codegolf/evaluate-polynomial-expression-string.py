#!/usr/bin/env python3

"""

Create a function which takes a polynomial equation, a value for x and returns the result of the operation.

Example: given 4x^2+2x-5 and x=3 output 37. This is the result of 4(3)^2+2(3)-5

Assume all polynomials are valid
Polynomial format will always be coefficient(variable)^exponent => 4x^2 except :
When exponent is 1 it will be coefficient(variable) => 4x
When coefficient is 1 it will be (variable)^exponent => x^2
Polynomials are one variable only
Use of external libraries are forbidden
The coefficient and variable input can be positive and negative numbers.
Test cases

("3x^3-5x^2+2x-10", 5)          => 250
("10x^4-5x^3-10x^2+3x+50", 3)   => 644
("10x+20", 10)                  => 120
("-20x^2+20x-50", -8)           => -1490
("9", 5)                        => 9
("8x^2+5", 0)                   => 5
Update

Polynomial format will always be coefficient(variable)^exponent => 4x^2 except :
When exponent is 1 it will be coefficient(variable) => 4x
When coefficient is 1 it will be (variable)^exponent => x^2
Removed the rule of negative exponent. My mistake. A valid polynomial does not contain negative exponent
An exponent of 0 would be just coefficient
Added test case for input 0
This is code-golf, so the shortest answer in bytes win.

"""

from sympy import *
from sympy.abc import *

def evalpoly(s, x):
    p = Poly(s, symbols('x'))
    r = p.eval(x)
    return r

def main():
    assert(evalpoly(3*x**3 - 5*x**2 + 2*x - 10, 5) == 250)
    assert(evalpoly(10*x**4 - 5*x**3 - 10*x**2 + 3*x + 50, 3) == 644)
    assert(evalpoly(10*x + 20, 10) == 120)
    assert(evalpoly(-20*x**2 + 20*x - 50, -8) == -1490)
    assert(evalpoly(9, 5) == 9)
    assert(evalpoly(8*x**2 + 5, 0) == 5)

main()
