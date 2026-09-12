#!/usr/bin/env python3

"""

Given a non-negative integer, n, yield the (n^2)th n-gonal number.

Further Detail:
The x-gonal numbers, or polygonal numbers, are also known as the two-dimensional figurate numbers.

Many people will be familiar with the triangular numbers, these are the 3-gonal numbers:

F(3, n) = Sum[i=1, n] i = n*(n+1) / 2

The triangular numbers are OEIS A000217:

0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, ...
Probably even more will be familiar with the square numbers, these are the 4-gonal numbers:

F(4, n) = Sum[i=1, n] (2i - 1) = n^2

The square numbers are OEIS A000290:

0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, ...

In general the kth x-gonal number is the number of pebbles required to iteratively build up an x-sided polygon by adding pebbles to x−2 of the sides,
here are a few formulae:

F(x, k) = Sum[i=1, k] (1 + Sum[j=2, i](x - 1))
        = (k^2*(x - 2) - k*(x - 4))/2
        = k*(k-1)/2 * (x - 2) + k
        = (x-3) * Sum[i=1, k-1](i) + Sum[i=1, k](i)
        = (x-2)*(k-1) + 1 + F(x, k-1)

I'm sure there are plenty more.
Note that the last one is recursive but that F(x,0)=0.

The challenge...is to golf code for G(n)=F(n,n^2)for non-negative n.
i.e. Given a non-negative integer, n, yield the (n^2)th n-gonal number.

This is not (currently) in the OEIS:

0, 1, 4, 45, 256, 925, 2556, 5929, 12160, 22761, 39700, 65461, 103104, 156325, 229516, 327825, 457216, 624529, 837540, 1105021, ...

Notes
You may yield a list of these numbers up to and including the required one if preferred.
For example, given an input of 5 you may yield either:

the integer 925, or
the list [0, 1, 4, 45, 256, 925]
...but not [0, 1, 4, 45, 256] or [1, 4, 45, 256, 925]
Results may also be results of floating point calculation and may deviate as such, so long as infinite precision floating point arithmetic would yield correct results.

Win by creating the shortest code in bytes in a language.
The overall winner will be the shortest across all languages, but please don't let golfing languages dissuade you from entering in your favourite language -
the primary goals are to challenge yourself and have fun!

"""

def seq(n):
    return (n*n*(n-2) - n + 4) * n * n / 2

def main():
    tab = [0, 1, 4, 45, 256, 925, 2556, 5929, 12160, 22761, 39700, 65461, 103104, 156325, 229516, 327825, 457216, 624529, 837540, 1105021]

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

main()
