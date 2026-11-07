#!/usr/bin/env python3

"""

Most everyone here is familiar with Pascal's Triangle. It's formed by successive rows, where each element is the sum of its two upper-left and upper-right neighbors. Here are the first 5 rows (borrowed from Generate Pascal's triangle):

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
We're going to take Pascal's Triangle and perform some sums on it (hah-ha). For a given input n, output the columnar sum of the first n rows of Pascal's Triangle. For example, for input 5, the output would be formed by

            1
          1   1
        1   2   1
      1   3   3   1
[+] 1   4   6   4   1
----------------------
    1 1 5 4 9 4 5 1 1
So the output would be [1, 1, 5, 4, 9, 4, 5, 1, 1].

Note that you don't necessarily need to generate Pascal's Triangle to calculate the summation - that's up to your implementation if it's shorter to do so or not.

Input
A single positive integer n with n >= 1 in any convenient format.

Output
The resulting array/list of the column-wise summation of the first n rows of Pascal's triangle, as outlined above. Again, in any suitable format.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Examples
[input]
[output]

1
[1]

2
[1, 1, 1]

3
[1, 1, 3, 1, 1]

5
[1, 1, 5, 4, 9, 4, 5, 1, 1]

11
[1, 1, 11, 10, 54, 44, 155, 111, 286, 175, 351, 175, 286, 111, 155, 44, 54, 10, 11, 1, 1]

"""

from sympy import Poly, series, symbols

"""

@alephalpha

The sum of first n rows is the coefficients of the polynomial (generating function)
((x^2 + 1)^n - x^n) / (x^2 + 1 - x)

"""
def pcs(n):
    x = symbols('x')
    f = ((x**2 + 1)**n - x**n) / (x**2 + 1 - x)
    s = series(f, x, n=2*n)
    p = Poly(s.removeO(), x)
    return p.all_coeffs()

def main():
    assert(pcs(1) == [1])
    assert(pcs(2) == [1, 1, 1])
    assert(pcs(3) == [1, 1, 3, 1, 1])
    assert(pcs(5) == [1, 1, 5, 4, 9, 4, 5, 1, 1])
    assert(pcs(11) == [1, 1, 11, 10, 54, 44, 155, 111, 286, 175, 351, 175, 286, 111, 155, 44, 54, 10, 11, 1, 1])

main()
