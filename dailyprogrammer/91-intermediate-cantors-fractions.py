#!/usr/bin/env python3

"""

Famous mathematician Georg Cantor once thought of a cool way to enumerate strictly positive rational numbers (i.e. x > 0): in an infinite 2D matrix of all rationals where A[x,y] = (x / y), start counting from A[1,1] and then zig-zag your way out like this:

http://www.homeschoolmath.net/teaching/rationals-countable.gif

Using this enumeration, write a program that outputs the first 1000 distinct strictly positive fractions as decimal numbers. (The repeated ones are crossed out in the above image, e.g. 2/2 = 1/1, so skip 2/2.)

"""

import math
import sys

def diagonal(l):
    r = []
    n = 1
    d = 0
    s = -1
    for _ in range(l):
        n, d = n + s, d - s
        if d == 0:
            n, s = n + 1, -s
        elif n == 0:
            d, s = d + 1, -s
        elif math.gcd(n + d, n) == 1:
            r.append((n, d))
    return r

def output(r):
    for i in range(len(r)):
        print("%2d/%2d" % (r[i][0], r[i][1]), end=' ')
        if i%10 == 9:
            print()
    print()

def main():
    l = 500
    if len(sys.argv) >= 2:
        l = int(sys.argv[1])
    r = diagonal(l)
    output(r)

main()
