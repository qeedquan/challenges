#!/usr/bin/env python3

"""

SPECIFICATION

Given m variables, create every combination up to order n. For example,

The output of mapping two variables (a and b) to order 1 would be:

a
b
a b

The output of mapping two variables (a and b) to order 2 would be:

a
a2
b
b2
a b
a2 b
a b2
a2 b2

The output of mapping two variables (a and b) to order 3 would be:

a
a2
a3
b
b2
b3
a b
a2 b
a3 b
a3 b2
a b2
a b3
a2 b3
a2 b2
a3 b3

The output of mapping three variables (a, b, and c) to order 1 would be:

a
b
c
a b
b c
a c
a b c

The output of mapping m variables to order n would be:

etc.
WINNING CRITERIA

Output every possible combination as outlined above. Order does not matter. Where in your code you print to the screen does not matter. All that matters is that what shows up in your output is correct.

"""

import itertools

def vgon(v, n):
    m = len(v)
    for p in itertools.product(range(n + 1), repeat=m):
        s = ""
        for i in range(len(p)):
            if p[i] == 0:
                continue

            s += "%c" % (v[i])
            if p[i] > 1:
                s += "^%d" % (p[i])

        if s != "":
            print(s)
    print()

def main():
    vgon("ab", 1)
    vgon("ab", 2)
    vgon("ab", 3)
    vgon("abc", 1)

main()
