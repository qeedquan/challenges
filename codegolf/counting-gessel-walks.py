#!/usr/bin/env python3

"""

OEIS A135404 gives the number of Gessel walks g(n) of length 2n. A Gessel walk is

a walk on the square lattice starting and ending at the origin
with possible steps (1,0), (-1,0), (1,1), (-1,-1)
that stays within the nonnegative quadrant.
Here are the 11 Gessel walks of length 4, where the steps above are denoted as E, W, O, I respectively.

EWEW EWOI OIEW OIOI EEWW OOII
OEWI EOIW OWEI OEIW EOWI

g(n) from n=0 is
1,2,11,85,782,8004,88044,1020162,12294260,152787976,1946310467,25302036071,...

In 2001 Ira Gessel conjectured that
g(n) = [16^n * rf(5/6, n) * rf(1/2, n)] / [rf(2, n) * rf(5/3, n)]

where rf(a, n) is the rising factorial (a)*(a+1)...*(a+n-1).

This conjecture was first proved in 2008 by a team including Doron Zeilberger, who (befitting his belief in the supremacy of his computer-based methods) wagered that no human proof would ever appear.
He was wrong and he paid the wager.

Some other formulas are given on the OEIS page; you may use any formula for your answer.

Task

Compute g(n), but this being a sequence challenge, you may choose to

output g(n) given n
output the first n terms given n
output the infinite sequence with no input, either by printing or returning a lazy list/generator

"""

from sympy import rf, Rational

# https://oeis.org/A135404
def gessel(n):
    a = 16**n
    b = rf(Rational(5, 6), n)
    c = rf(Rational(1, 2), n)
    d = rf(2, n)
    e = rf(Rational(5, 3), n)
    return (a * b * c) // (d * e)

def main():
    tab = [
        1, 2, 11, 85, 782, 8004, 88044, 1020162, 12294260, 152787976, 1946310467,
        25302036071, 334560525538, 4488007049900, 60955295750460, 836838395382645,
        11597595644244186, 162074575606984788, 2281839419729917410,
        32340239369121304038, 461109219391987625316, 6610306991283738684600
    ]

    for i in range(len(tab)):
        assert(gessel(i) == tab[i])

main()
