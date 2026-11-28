#!/usr/bin/env python3

"""

You will get an array of numbers.

Every preceding number is smaller than the one following it.

Some numbers will be missing, for instance:

[-3,-2,1,5] //missing numbers are: -1,0,2,3,4

Your task is to return an array of those missing numbers:

[-1,0,2,3,4]

"""

def missing(a):
    r = []
    for i in range(1, len(a)):
        for j in range(a[i - 1] + 1, a[i]):
            r.append(j)
    return r

def main():
    assert(missing([-3, -2, 1, 5]) == [-1, 0, 2, 3, 4])
    assert(missing([-3, -2, 1, 4]) == [-1, 0, 2, 3])
    assert(missing([]) == [])
    assert(missing([0]) == [])
    assert(missing([-4, 4]) == [-3, -2, -1, 0, 1, 2, 3])

main()
