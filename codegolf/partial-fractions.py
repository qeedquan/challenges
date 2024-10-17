#!/usr/bin/env python3

"""

Given an input of a string, output the partial fraction in string form.
The partial fraction decomposition of a rational fraction of the form f(x)/g(x) , where f and g are polynomials, is its expression as:

f(x)/g(x) = p(x) + Sum[j] f[j](x)/g[j](x)

In this case p is 0, because we assume that the numerator is smaller than the denominator.

Input:
In the form of an a list of the coefficients:

[[1, 4], [[1,3], [1,3]]]
For (x+4)/(x+3)^2.

Output:
In the form of a list too:

[[[1], [1, 3]], [[1], [1, 6, 9]]]

For 1/(x+3) + 1/(x+3)^2.

Assumptions
The power of - x^ can be of any power greater than 1
The fractions are factorised whenever possible
You can output the elements of a list or the list itself
You can take the input as a list or separate elements
The numerator highest degree is always lower than the denominator highest degree
You can take the input and output in any order
The input will not be in a way such that the numerator and denominator have a factor in common
You can assume all inputs take this form:

something / ((something)*(something)...)

Note there can be multiple fractions e.g.:

(x+4)/((x+1)(x-2)(x+3)^2)

Note:
This is not as easy as it looks This only gets harder. There are multiple cases to follow:

Linear factors
N(x)/((ax + b)(cx + d)) = A/(ax + b) + B/(cx + d)

Repeated linear factors
N(x)/(ax + b)^2 = A/(ax + b) + B/(ax + b)^2

Quadratic factor (non-factorisable)
N(x)/((ax + b)(x^2 + bx + c)) = A/(ax + b) + (Bx + C)/(x^2 + bx + c)

Testcases
Case 1:
[1,4], [[1,3], [1,2]] -> [[-1], [1,3]], [[2], [1,2]]

Case 2:
[1,4], [[1,3], [1,3]] -> [[1], [1,3]], [[1], [[1,3], [1,3]]]

Case 3:
[2,-1,4], [[1,0], [1,0,4]] -> [[1], [1,0]], [[1,-1], [1,0,4]]

"""

from sympy import *
from sympy.abc import *

def main():
    pretty_print(apart((x + 4) / ((x + 3)*(x + 2))))
    pretty_print(apart((x + 4) / (x + 3)**2))
    pretty_print(apart((2*x**2 - x + 4)/(x*(x**2 + 4))))

main()
