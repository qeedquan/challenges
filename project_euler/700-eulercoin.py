#!/usr/bin/env python3

"""

Leonhard Euler was born on 15 April 1707.

Consider the sequence 1504170715041707n mod 4503599627370517.

An element of this sequence is defined to be an Eulercoin if it is strictly smaller than all previously found Eulercoins.

For example, the first term is 1504170715041707 which is the first Eulercoin. The second term is 3008341430083414 which is greater than 1504170715041707 so is not an Eulercoin. However, the third term is 8912517754604 which is small enough to be a new Eulercoin.

The sum of the first 2 Eulercoins is therefore 1513083232796311.

Find the sum of all Eulercoins.

"""

# https://www.ivl-projecteuler.com/overview-of-problems/5-difficulty/problem-700
# https://github.com/vojta-janousek/Project-Euler/blob/master/700.py
def solve(n, m):
    r, y2 = 0, 1
    while y2 != 0:
        (x1, y1) = divmod(m, n)
        (x2, y2) = divmod(n, y1)
        for i in range(x2, 0, -1):
            r += y2 + i*y1
        m, n = y1, y2
    return r

def main():
    print(solve(1504170715041707, 4503599627370517))

main()
