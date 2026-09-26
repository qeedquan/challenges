#!/usr/bin/env python3

"""

A positive integer  k is a Loeschian number if k can be expressed as i^2 + j^2 + i*j for i, j integers.

For example, the first positive Loeschian numbers are:
1 (i=1,j=0);
3 (i=j=1);
4 (i=2,j=0);
7 (i=2,j=1);
9 (i=−3,j=3); ...

Note that i,j for a given k are not unique. For example, 9 can also be generated with i=3,j=0.

Other equivalent characterizations of these numbers are:
k can be expressed as i^2 + j^2 + i*j for i, j non-negative integers.
(For each pair of integers i, j there's a pair of non-negative integers that gives the same k)

There is a set of  k contiguous hexagons that forms a tesselation on a hexagonal grid so that corresponding cells
are the same distance apart (see illustrations for  k=4 and for  k=7).
(Because of this property, these numbers find application in mobile cellular communication networks.)

See more characterizations in the OEIS page of the sequence.

The challenge
Given a positive integer, output a truthy result if it is a Loeschian number, or a falsy result otherwise.

The program or function should handle (say in less than a minute) inputs up to 1000, or up to data type limitations.

Code golf. Shortest wins.

Test cases
The following numbers should output a truthy result:

1, 4, 7, 12, 13, 108, 109, 192, 516, 999
The following numbers should output a falsy result:

2, 5, 10, 42, 101, 102, 128, 150, 501, 1000

"""

from math import sqrt

# https://oeis.org/A003136
def loeschian(n):
    if n < 0:
        return False
    if n%3 == 2:
        return False
    if n in [0, 1, 3]:
        return True
    m = int(round(2*sqrt(n/3)))
    for y in range(m + 1):
        for x in range(y + 1):
            if n == x**2 + y**2 + x*y:
                return True
    return False

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if loeschian(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        0, 1, 3, 4, 7, 9, 12, 13, 16, 19, 21, 25, 27, 28, 31, 36, 37, 39, 43,
        48, 49, 52, 57, 61, 63, 64, 67, 73, 75, 76, 79, 81, 84, 91, 93, 97, 100,
        103, 108, 109, 111, 112, 117, 121, 124, 127, 129, 133, 139, 144, 147,
        148, 151, 156, 157, 163, 169, 171, 172, 175, 181, 183, 189, 192
    ]

    truthy = [1, 4, 7, 12, 13, 108, 109, 192, 516, 999]
    falsy = [2, 5, 10, 42, 101, 102, 128, 150, 501, 1000]

    for i in truthy:
        assert(loeschian(i) == True)
    for i in falsy:
        assert(loeschian(i) == False)

    assert(gen(len(tab)) == tab)

main()
