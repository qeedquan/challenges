#!/usr/bin/env python3

"""

A numerical polynomial is a polynomial p in one variable with rational coefficients such that for every integer i, p(i) is also an integer. The numerical polynomials have a basis given by the binomial coefficients:

p[n] = binomial(x, n)

For instance:

p0 = 1

p1 = x

p2 = x(x-1)/2 = 1/2x^2

p3 = x(x-1)(x-2)/6 = 1/6x^3 - 1/2x^2 + 1/3x

The product of any two numerical polynomials is a numerical polynomial, so there are formulas expressing pm×pn as a linear combination of p0,p1,...,pm+n.

Your job is to produce these formulas.

Goal:
Input: A pair of positive integers m and n

Output: The list of integers [a1,...,a[m+n]] of length m+n such that

p[m]*p[n] = Sum[i=1, m+n] a[i]*p[i]

This is code golf, so shortest code wins.

Examples:
Input: (1,1)

We have p1=x, so p1×p1=x^2. The leading term is 1x^2, and the leading term of p2 is 1/2! * x^2, so we set a2 = 2!/1 = 2.
Subtracting off 2*p2 we have p1*p1 - 2p2 = x2 - (x2-x) = x. Thus, we see that p1*p1 = p1 + 2*p2, so the output should be [1,2].

Input: (1,2)

p2 = 1/2*x(x−1), so p1*p2 = 1/2 * x^2 * (x-1), which has leading term 1/2*x^3.
The leading term of p3 is 1/3!*x^3 , so we set a3 = 3!/2 = 3. p1 * p2 - 3p3 = x^2 - x = 2*p2, so we deduce that p1*p2 = 0p1 + 2p2 + 3p3, so the output should be [0,2,3].

Input (2,2)

The leading term of p[2, 2] is 1/4*x^4, so we start with p[2, 2] - 4!/4 * p4. This has leading term x3, so we subtract off 3!/1 * p3 to get p[2, 2] - 4!/4p^4 - 3!/1*p3.
This expression turns out to be equal to p2, so rearranging we get that p[2, 2] = 0p1 + p2 + 6p3 + 6p4, so the output should be [0,1,6,6].

Test Cases:
(1,1) ==> [1,2]
(1,2) ==> [0,2,3]
(1,3) ==> [0, 0, 3, 4]
(1,4) ==> [0, 0, 0, 4, 5]
(2,2) ==> [0, 1, 6, 6]
(2,3) ==> [0, 0, 3, 12, 10]
(2,4) ==> [0, 0, 0, 6, 20, 15]
(3,4) ==> [0, 0, 0, 4, 30, 60, 35]
(4,4) ==> [0, 0, 0, 1, 20, 90, 140, 70]

"""

from math import *

"""

@alephalpha


I did not expect the formula to be so simple: the i-th element of the output for (m,n) is binomial(m, i-n)*binomial(i, m).

In fact, it can be proven that Sum[i=0, m+n] binomial(m, i-m)*binomial(i, m)*binomial(x, i) = binomial(x, m)*binomial(x, n).
The RHS counts the number of ways to choose two subsets of {1,2,…,x} of size m and n respectively;
while the LHS counts, for each i, the number of ways to choose a subset of size i, and two subsets of size m and n respectively whose union is the chosen subset of size i.

"""
def polynum(m, n):
    r = []
    for i in range(1, m + n + 1):
        v = 0
        if i >= n:
            v = comb(m, i - n) * comb(i, m)
        r.append(v)
    return r

def main():
    assert(polynum(1, 1) == [1, 2])
    assert(polynum(1, 2) == [0, 2, 3])
    assert(polynum(1, 3) == [0, 0, 3, 4])
    assert(polynum(1, 4) == [0, 0, 0, 4, 5])
    assert(polynum(2, 2) == [0, 1, 6, 6])
    assert(polynum(2, 3) == [0, 0, 3, 12, 10])
    assert(polynum(2, 4) == [0, 0, 0, 6, 20, 15])
    assert(polynum(3, 4) == [0, 0, 0, 4, 30, 60, 35])
    assert(polynum(4, 4) == [0, 0, 0, 1, 20, 90, 140, 70])

main()
