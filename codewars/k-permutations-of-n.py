#!/usr/bin/env python3

"""

Implement a function k_permutations_of_n that accepts a list of elements lst and an integer k, and returns all permutations of elements from the list lst.
Permutations should be a list containing all unique lists of k elements from lst, in any order.

For example, if lst == [1,2,3] and k == 2 the result should be:

[[1, 2], [1, 3], [2, 1], [2, 3], [3, 1], [3, 2]]

if k > len(lst) the function should return an empty list, i.e.[]
if k == 0, the function should return [[]], because there is exactly 1 way to arrange 0 elements (remember that 0! == 1).

You can assume that the input list lst contains unique elements.

"""

def kperm(a, k):
    if k > len(a):
        return []
    if k == 0:
        return [[]]
    
    r = []
    for i, x in enumerate(a):
        p = a[:i] + a[i+1:]
        for t in kperm(p, k-1):
            r.append([x] + t)
    return r

def main():
    assert(kperm([1, 2, 3], 2) == [[1, 2], [1, 3], [2, 1], [2, 3], [3, 1], [3, 2]])

main()
