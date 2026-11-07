#!/usr/bin/env python3

"""

Divide 1 by a sum/difference of square roots
Input: An expression that is a sum/difference of square roots of positive integers. You can assme it will not equal 0.

The general form is +-sqrt(a1) +- sqrt(a2) +- sqrt(a3) +- ... +- sqrt(an) where each an is a positive integer.
There is no guarantee the input will be sorted or that the radicals are fully simiplfied. Duplicate ak are possible.

Example:
sqrt(2) + sqrt(3) + sqrt(7) + sqrt(7) - sqrt(9) + sqrt(12)

Output: the inverse of this expression.

The output must be of the general form +-x*sqrt(a1) +- x2*sqrt(a2) + ... where each an and xn is a rational number, and the an are non-negative.
You may omit any a plus sign before x1*sqrt(a1).

Test cases (they give a list of possible correct outputs, but you should check correctness by testing if input*output==1 instead of checking if output appears in the test cases):

√1          1√1 or √1 (the omit 1 rule applies to the other test cases as well)
-√5         -1√(1/5) or -1/5√5
√2+√3       -1√2+1√3
√2+√7       -1√(2/25)+1√(7/25) or -1/5√2+1/5√7
√2+√8       1√(1/18) or 1/3√(1/2) or 1/6√2
√2+√3+√5    1√(1/8)+1√(1/12)-1√(5/24)

Allowed formats for input and output (example −123–√+4567−−√−891011−−√
) include, but are not limited to:

"-1/2√(3)+4/5√(6/7)-8/9√(10/11)" as a string. If an xk
 is 1 or -1, you can omit the coefficient, but the sign must be right (+ for 1 and - for -1) so 4√3+1√2-1√6 can be 4√3+√2-√6. Any fraction with a denominator of 1 can be changed to an integer (e.g. 4/1√(3/1) to 4√3).
the list [[-1,2],[3,1]],[[4,5],[6,7]],[[-8,9],[10,11]]
an expression (for CAS languages); the expression must have the right form so an expression like 1/(sqrt(3)+sqrt(5)+sqrt(7)) is not allowed.
The fractions and radicals do not have to be simplified, but denominators cannot be 0.

I'm pretty sure such an expression is always possible.

If that is not true, your code can do anything (error, infinite loop) on inputs whose inverse cannot be expressed in this form.

"""

from sympy import *

def solve(t):
    return expand(simplify(cancel(radsimp(1/t))))

def test(t):
    s = solve(t)
    u = simplify(t * s)
    assert(u == 1)

def main():
    test(sqrt(1))
    test(-sqrt(5))
    test(sqrt(2) + sqrt(3))
    test(sqrt(2) + sqrt(7))
    test(sqrt(2) + sqrt(8))
    test(sqrt(2) + sqrt(3) + sqrt(5))

main()

