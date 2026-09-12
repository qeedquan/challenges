#!/usr/bin/env python3

"""

There is an implementation of quicksort algorithm. Your task is to fix it. All inputs are correct.

See also: https://en.wikipedia.org/wiki/Quicksort

"""

import random

def quicksort(a):
    if len(a) < 2:
        return a
    l = [x for x in a[1:] if x <= a[0]]
    r = [x for x in a[1:] if x > a[0]]
    return quicksort(l) + [a[0]] + quicksort(r)

def main():
    for i in range(1000):
        a = [random.choice(range(i)) for _ in range(i)]
        assert(quicksort(a) == sorted(a))

main()
