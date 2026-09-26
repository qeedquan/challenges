#!/usr/bin/env python3

"""

Let's say we have a n × n lattice; we can then divide the lattice into two sections by drawing a line through the lattice. Everything to one side of the line is in one set and everything else in another.

How many ways can we divide the lattice in the manner?

For example lets take a 2 × 2 lattice:

. .
. .
We can make 2 partitions dividing the lattice in half like so:

× ×    × o
o o    × o
We can also partition off each of the corners:

× o    o ×    o o    o o
o o    o o    × o    o ×
Lastly we can put all of the points in one partition by missing the lattice entirely:

× ×
× ×
This makes for a total of 7 partitions. Note that the following partition is not valid because it cannot be made with a single straight line.

× o
o ×
Here is a 3 × 3 lattice

. . .
. . .
. . .
There are 4 purely horizontal or vertical partitions

× × ×    × × ×    × o o    × × o
× × ×    o o o    × o o    × × o
o o o    o o o    × o o    × × o
There are 4 corner partitions

× o o    o o ×    o o o    o o o
o o o    o o o    o o o    o o o
o o o    o o o    o o ×    × o o
There are 4 larger corner partitions

× × o    o × ×    o o o    o o o
× o o    o o ×    o o ×    × o o
o o o    o o o    o × ×    × × o
There are 8 partitions of partial corners

× × o    o × ×    o o ×    o o o    o o o    o o o    o o o    × o o
o o o    o o o    o o ×    o o ×    o o o    o o o    × o o    × o o
o o o    o o o    o o o    o o ×    o × ×    × × o    × o o    o o o
There are 8 knights move partitions

× × o    o × ×    × × ×    o o o    o o ×    × o o    o o o    × × ×
× o o    o o ×    o o ×    o o ×    o o ×    × o o    × o o    × o o
× o o    o o ×    o o o    × × ×    o × ×    × × o    × × ×    o o o
And there is one whole partition

× × ×
× × ×
× × ×
That makes for 29 partitions in total.

Task
Given a number n as input, output the number of partitions that can be made in this fashion of an n × n lattice.

This is a code-golf question so answers will be scored in bytes, with less bytes being better.

Test Cases
Here are the first 34 courtesy of the OEIS:

1, 7, 29, 87, 201, 419, 749, 1283, 2041, 3107, 4493, 6395, 8745, 11823, 15557, 20075, 25457, 32087, 39725, 48935, 59457, 71555, 85253, 101251, 119041, 139351, 161933, 187255, 215137, 246691, 280917, 319347, 361329, 407303
OEIS A114043

"""

from sympy import *

# http://oeis.org/A114043
def partitions(n):
    if n < 1:
        return 0

    v = 0
    for i in range(2, n):
        v += (n-i)*(2*n-i)*totient(i)
    return 4*n**2 - 6*n + 3 + 2*v

def main():
    tab = [1, 7, 29, 87, 201, 419, 749, 1283, 2041, 3107, 4493, 6395, 8745, 11823, 15557, 20075, 25457, 32087, 39725, 48935, 59457, 71555, 85253, 101251, 119041, 139351, 161933, 187255, 215137, 246691, 280917, 319347, 361329, 407303]
    for i in range(len(tab)):
        assert(partitions(i+1) == tab[i])

main()
