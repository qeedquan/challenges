#!/usr/bin/env python3

"""

Consider a sequence of natural numbers for which N appears as a substring in N^2. A018834

Output the nth element of this sequence.

Rules
Program takes only n as input and outputs just one number - N.

The sequence can be 0-indexed or 1-indexed.

Sequence: 1 5 6 10 25 50 60 76 100 250 376 500 600 625 760 ...
Squares:  1 25 36 100 625 2500 3600 5776 10000 62500 141376 250000 360000 390625 577600 ...
This is code-golf so shortest code wins.

"""

# https://oeis.org/A018834
def kink2(n):
    return str(n) in str(n**2)

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if kink2(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [0, 1, 5, 6, 10, 25, 50, 60, 76, 100, 250, 376, 500, 600, 625, 760, 1000, 2500, 3760, 3792, 5000, 6000, 6250, 7600, 9376, 10000, 14651, 25000, 37600, 50000, 60000, 62500, 76000, 90625, 93760, 100000, 109376, 250000, 376000, 495475, 500000, 505025]

    assert(gen(len(tab)) == tab)

main()
