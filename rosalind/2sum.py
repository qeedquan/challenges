#!/usr/bin/env python3

"""

Problem
Given: A positive integer k≤20, a positive integer n≤10^4, and k arrays of size n containing integers from -10^5 to 10^5.

Return: For each array A[1..n], output two different indices 1≤p<q≤n such that A[p]=-A[q] if exist, and "-1" otherwise.

Sample Dataset
4 5
2 -3 4 10 5
8 2 4 -2 -8
-5 2 3 2 -4
5 4 -5 6 8

Sample Output
-1
2 4
-1
1 3

"""

def twosum(array):
    target = 0
    indices = {}
    for index in range(len(array)):
        if array[index] in indices:
            return (indices[array[index]] + 1, index + 1)
        indices[target - array[index]] = index
    return -1

def main():
    assert(twosum([8, 2, 4, -2, -8]) == (2, 4))
    assert(twosum([2, -3, 4, 10, 5]) == -1)
    assert(twosum([8, 2, 4, -2, -8]) == (2, 4))
    assert(twosum([-5, 2, 3, 2, -4]) == -1)
    assert(twosum([5, 4, -5, 6, 8]) == (1, 3))

main()
