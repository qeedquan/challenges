#!/usr/bin/env python3

def flipsort(a):
    c = 0
    for i in range(1, len(a)):
        j = i
        while j > 0 and a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            j -= 1
            c += 1
    return c

def main():
    assert(flipsort([1, 2, 3]) == 0)
    assert(flipsort([2, 3, 1]) == 2)

main()
