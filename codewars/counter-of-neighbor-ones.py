#!/usr/bin/env python3

"""

Task
Tranform of input array of zeros and ones to array in which counts number of continuous ones. If there is none, return an empty array

Example
[1, 1, 1, 0, 1] -> [3,1]
[1, 1, 1, 1, 1] -> [5]
[0, 0, 0, 0, 0] -> []

"""

def onescount(a):
    r = []
    n = len(a)
    i = 0
    while i < n:
        j = i + 1
        while j < n and a[i] == a[j]:
            j += 1

        if a[i] == 1:
            r.append(j - i)
        
        i = j

    return r

def main():
    assert(onescount([1, 1, 1, 0, 1]) == [3, 1])
    assert(onescount([1, 1, 1, 1, 1]) == [5])
    assert(onescount([0, 0, 0, 0, 0]) == [])

main()
