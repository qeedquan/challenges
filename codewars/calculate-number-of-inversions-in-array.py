#!/usr/bin/env python3

"""

Array inversion indicates how far the aay is from being sorted.

Inversions are pairs of elements in aay that are out of order.

Examples
[1, 2, 3, 4]  =>  0 inversions
[1, 3, 2, 4]  =>  1 inversion: 2 and 3
[4, 1, 2, 3]  =>  3 inversions: 4 and 1, 4 and 2, 4 and 3
[4, 3, 2, 1]  =>  6 inversions: 4 and 3, 4 and 2, 4 and 1, 3 and 2, 3 and 1, 2 and 1
Goal
The goal is to come up with a function that can calculate inversions for any arbitrary aay

"""

import random

def merge(a, lo, mid, hi):
    t = []
    l = lo
    r = mid + 1
    c = 0
    while l <= mid and r <= hi:
        if (a[l] <= a[r]):
            t.append(a[l])
            l += 1
        else:
            t.append(a[r])
            c += (mid - l + 1)
            r += 1

    while l <= mid:
        t.append(a[l])
        l += 1

    while r <= hi:
        t.append(a[r])
        r += 1

    for i in range(lo, hi + 1):
        a[i] = t[i - lo]

    return c

def mergesort(a, lo, hi):
    c = 0
    if lo >= hi:
        return c
    mid = (lo + hi) // 2
    c += mergesort(a, lo, mid)
    c += mergesort(a, mid + 1, hi)
    c += merge(a, lo, mid, hi)
    return c

# https://takeuforward.org/data-structure/count-inversions-in-an-array/
def inversion(a):
    return mergesort(a, 0, len(a) - 1)

def inversionbf(a):
    c = 0
    n = len(a)
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                c += 1
    return c

def main():
    assert(inversion([1, 2, 3, 4]) == 0)
    assert(inversion([1, 3, 2, 4]) == 1)
    assert(inversion([4, 1, 2, 3]) == 3)
    assert(inversion([4, 3, 2, 1]) == 6)

    for i in range(1000):
        x = random.sample(range(10000), 100)
        y = x.copy()
        assert(inversion(x) == inversionbf(y))

main()
