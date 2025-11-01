#!/usr/bin/env python3

"""

The deleteValues function takes an array and removes elements that answer true to the pred function.

For some reason, some of the elements of the array for which the predicate holds are not deleted...

Can you fix the code?

"""

def iseven(x):
    return x%2 == 0

def isodd(x):
    return x%2 != 0

def delete(a, f):
    j = 0
    for i in range(len(a)):
        if not f(a[i]):
            a[j], j = a[i], j + 1
    return a[:j]

def main():
    print(delete([2, 5, 6, 8, 11, 12, 13, 14, 15], iseven))
    print(delete([2, 5, 6, 8, 11, 12, 13, 14, 15], isodd))

main()
