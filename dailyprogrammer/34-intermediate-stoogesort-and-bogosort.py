#!/usr/bin/env python3

"""

Your task today is show the implementation of two sorting algorithms Stooge sort and Bogosort in anyway you like!

"""

import random

def stoogesort(a, i, j):
    if a[j] < a[i]:
        a[i], a[j] = a[j], a[i]
    if j - i + 1 >= 3:
        t = (j - i + 1) // 3
        stoogesort(a, i, j - t)
        stoogesort(a, i + t, j)
        stoogesort(a, i, j - t)
    return a

def bogosort(a):
    c = list(range(len(a)))
    while a != c:
        random.shuffle(a)
    return a

def main():
    x = list(range(100))
    y = list(range(10))
    random.shuffle(x)
    random.shuffle(y)
    print(stoogesort(x, 0, len(x) - 1))
    print(bogosort(y))

main()
