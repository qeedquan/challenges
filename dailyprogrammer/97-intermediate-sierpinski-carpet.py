#!/usr/bin/env python3

"""

Write a function that accepts an integer n and returns a (3n × 3n ) boolean matrix containing a nth-iteration Sierpinski carpet fractal.

How many 1 bits are there in carpet(7)?

What is the largest value of n for which the matrix returned by carpet(n) fits in a terabyte?

For bonus points, write a general function center_iter(d, n) that generates fractals like the Sierpinski carpet in d dimensions. (center_iter(1, n) is the Cantor set, center_iter(2, n) the Sierpinski carpet, center_iter(3, 1) a 3x3x3 cube with the center piece removed, etc.)

"""

from functools import lru_cache

# ported from @Cosmologicon solution
@lru_cache(maxsize=None)
def carpet(n):
    if n == 0:
        return [[1]]
    a = carpet(n - 1)
    s = [0] * len(a)
    return [x*3 for x in a] + [x+s+x for x in a] + [x*3 for x in a]

def output(name, level):
    s = "P1 729 729\n"
    for x in carpet(level):
        s += " ".join(map(str, x)) + "\n"

    f = open(name, "w")
    f.write(s)
    f.close()

def main():
    output("c7.pbm", 7)

main()
