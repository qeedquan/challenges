#!/usr/bin/env python3

"""

Task
Given 2 positive integers n and k, where n > k, output the number of surjections from a set of n distinguishable elements to a set of k distinguishable elements.

Definition
A function f: S → T is called a surjection if for every t∈T there is s∈S such that f(s) = t.

Example
When n=3 and k=2, the output is 6, since there are 6 surjections from {1,2,3} to {1,2}:

1↦1, 2↦1, 3↦2
1↦1, 2↦2, 3↦1
1↦1, 2↦2, 3↦2
1↦2, 2↦1, 3↦1
1↦2, 2↦1, 3↦2
1↦2, 2↦2, 3↦1
Testcases
n k output
5 3 150
8 4 40824
9 8 1451520
Reference
OEIS A019538

Scoring
This is code-golf. Shortest answer in bytes wins.

Standard loopholes apply.

"""

from math import *

"""

@Roman Czyborra

s(_,1)=1
s(1,_)=0
s(m,n)=n*(s(m-1,n-1)+s(m-1,n))

Why is the surjection count s(m,n)=n*s(m-1,n-1)+n*s(m-1,n)?
in order to harvest n images, i can either

squeeze a singleton [m] creation into any of the n boundaries surrounding n-1 groups
or add my new m into any of n already existing groups of [1..m-1]

"""

def surjections(n, k):
    if n < 0 or k < 0:
        return 0
    if k == 1:
        return 1
    if n == 1:
        return 0
    return k * (surjections(n - 1, k - 1) + surjections(n - 1, k))

def main():
    assert(surjections(5, 3) == 150)
    assert(surjections(8, 4) == 40824)
    assert(surjections(9, 8) == 1451520)

main()

