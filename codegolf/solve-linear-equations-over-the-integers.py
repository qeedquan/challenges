#!/usr/bin/env python3

"""

All variables in this question are integer valued.

Input
4 integers w, x, y, z. They can be positive or negative and will be less than 1048576 in absolute value.

Output
The general solution to the equation.

aw+bx+cy+dz=0.

The variables a,b,c,d must all be integer values.

Output format
Your output should consist of three tuples each with four parts, one for each of the values a, b, c, d. Let me explain by example:

Input: -118, 989, 918, -512

Mathematical answer:
        b = 2 n_0
        c = 9 n_0 + 256 n_1 + 81 a
        d = 20 n_0 + 459 n_1 + 145 a
Explanation: n_0 and n_1 are integers that you can set to anything you like. The solution says: a can also be set to any integer value, b must be twice whatever you set n_0 to. This means that a can be set to any integer, c can now be calculated in terms of three variables we have already set and so can d.

The format of your output should be 3 tuples (#,#,#,#), (#,#,#,#), (#,#,#,#). We can assume three free integer variables n0, n1 and n2 and so (a,b,c,d) = (#,#,#,#)n0 + (#,#,#,#)n1 + (#,#,#,#)n2. In the example above the output would therefore be:

Output: (0, 2, 9, 20), (0, 0, 256, 459), (1, 0, 81, 145)

Examples
Example one:

 Input: -6, 3, 7, 8

 Mathematical answer:
          c = 2a + 3b + 8n
          d = -a - 3b - 7n
          n is any integer

 Output: (1, 0, 2, -1), (0, 1, 3, -3), (0, 0, 8, -7)
Example two:

Input: -116, 60, 897, 578

Mathematical answer:
        c = 578 n + 158 a + 576 b
        d = -897 n - 245 a - 894 b
        n is any integer

Output: (1, 0, 158, -245), (0, 1, 576, -894), (0, 0, 578, -897)
Example three:

Input: 159, -736, -845, -96

Output: (1, 0, 27, -236), (0, 1, 64, -571), (0, 0, 96, -845)
Discussion
To understand this challenge further it is worth looking at this possible general solution which does not work [(z, 0, 0, -w), (0, z, 0, -x), (0, 0, z, -y)]. The problem with this is that there are solutions to the problem instances above which are not the sum of any integer multiples of those tuples. For example: take input -6, 3, 7, 8 from Example 1. The proposed solution would give the tuples:

(8, 0, 0, 6), (0, 8, 0, -3), (0, 0, 8, -7)
Why doesn't this work?

There is a solution for this instance with a = 1, b = 1, c = 13, d = -11 because -6+3+7*13-11*8 = 0.
However there are no integers n_0, n_1, n_2 to make n_0 * (8, 0, 0, 6) + n_1 * (0, 8, 0, -3) + n_2 * (0, 0, 8, -7) = (1, 1, 13, -11) .

"""

from sympy import sympify
from sympy.solvers.diophantine import diophantine
from sympy.abc import symbols

"""

https://mathworld.wolfram.com/HermiteNormalForm.html
https://en.wikipedia.org/wiki/Lenstra%E2%80%93Lenstra%E2%80%93Lov%C3%A1sz_lattice_basis_reduction_algorithm (in the Z basis)

"""
def solve(expr):
    a, b, c, d = symbols("a b c d")
    eq = sympify(expr)
    syms = (a, b, c, d)
    return diophantine(eq, syms=syms)

def main():
    print(solve("-118*a + 989*b + 918*c - 512*d"))
    print(solve("-6*a + 3*b + 7*c + 8*d"))
    print(solve("159*a - 736*b - 845*c - 96*d"))

main()
