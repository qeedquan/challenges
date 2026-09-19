#!/usr/bin/env python3

"""

Background
The Sidi polynomial of degree n – or the (n+1)th Sidi polynomial – is defined as follows.

Sn(x) = Sum[k=0, n] s[n, k] where s[n, k] = (-1)^k * binomial(n, k) * (k + 1)^n

The Sidi polynomials have several interesting properties, but so do their coefficients. The latter form OEIS sequence A075513.

Task
Write a full program or a function that, given a non-negative integer n, prints or returns the absolute sum of the coefficients of the Sidi polynomial of degree n, that is

Σn=∑k=0n|sn;k|

These sums form OEIS sequence A074932.

If you prefer 1-based indexing, you can take a positive integer n
 instead and compute the absolute sum of the coefficients of the n
th Sidi polynomial.

Because this is code-golf, you must make your code as short as possible. All standard rules apply.

Test cases (0-based)
 n           Σ

 0           1
 1           3
 2          18
 3         170
 4        2200
 5       36232
 6      725200
 7    17095248
 8   463936896
 9 14246942336
Test cases (1-based)
 n           Σ

 1           1
 2           3
 3          18
 4         170
 5        2200
 6       36232
 7      725200
 8    17095248
 9   463936896
10 14246942336

"""

from math import *

# https://oeis.org/A075513
def sidi(n, k):
    return (-1)**k * comb(n, k) * (k + 1)**n

# https://oeis.org/A074932
def sidias(n):
    r = 0
    for k in range(n+1):
        r += abs(sidi(n, k))
    return r

def main():
    tab = [1, 3, 18, 170, 2200, 36232, 725200, 17095248, 463936896, 14246942336, 488428297984, 18491942300416, 766293946203136, 34498781924766720, 1676731077272217600, 87501958444207351808, 4880017252828686155776]

    for i in range(len(tab)):
        assert(sidias(i) == tab[i])

main()
