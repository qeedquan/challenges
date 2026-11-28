#!/usr/bin/env python3

"""

The first two MU-numbers are 2 and 3. Every other MU-number is the smallest number not yet appeared that can be expressed as the product of two earlier distinct MU-numbers in exactly one way.

Here are the first 10

2, 3, 6, 12, 18, 24, 48, 54, 96, 162
Task
Given a positive number calculate and output the nth MU-number.

This is a code-golf competition so you should aim to make your source code as small as possible.

OEIS A007335

"""

def ismu(u, n, h, i, r):
    ur = u[r]
    ui = u[i]

    if ur <= ui:
        return h

    if ur*ui > n:
        r -= 1
    elif ur*ui < n:
        i += 1
    else:
        if h:
            return False
        h = True
        i += 1
        r -= 1
    return ismu(u, n, h, i, r)

# http://oeis.org/A007335
def mu(l):
    u = [0, 2, 3]
    i = 2
    n = 2
    while i < l:
        n += 1
        if ismu(u, n, False, 1, i):
            i += 1
            u.append(n)
    return u[1:]

def main():
    tab = [2, 3, 6, 12, 18, 24, 48, 54, 96, 162, 192, 216, 384, 486, 768, 864, 1458, 1536, 1944, 3072, 3456, 4374, 6144, 7776, 12288, 13122, 13824, 17496, 24576, 31104, 39366, 49152, 55296, 69984, 98304, 118098, 124416, 157464, 196608, 221184, 279936]
    assert(mu(len(tab)) == tab)

main()
