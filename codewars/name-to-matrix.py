#!/usr/bin/env python3

"""

Given a name, turn that name into a perfect square matrix (nested array with the amount of arrays equivalent to the length of each array).

You will need to add periods (.) to the end of the name if necessary, to turn it into a matrix.

If the name has a length of 0, return "name must be at least one letter"

Examples
"Bill" ==> [ ["B", "i"],
             ["l", "l"] ]

"Frank" ==> [ ["F", "r", "a"],
              ["n", "k", "."],
              [".", ".", "."] ]

"""

from math import *

def matrixify(s):
    n = len(s)
    l = ceil(sqrt(n))
    m = []
    i = 0
    for y in range(l):
        p = []
        for x in range(l):
            if i < n:
                p.append(s[i])
            else:
                p.append('.')
            i += 1
        m.append(p)
    return m

def main():
    assert(matrixify("Bill") == [['B', 'i'], ['l', 'l']])
    assert(matrixify("Frank") == [['F', 'r', 'a'], ['n', 'k', '.'], ['.', '.', '.']])

main()

