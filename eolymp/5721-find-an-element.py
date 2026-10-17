#!/usr/bin/env python3

"""

Array of n integers is given. Find its k-th element in decreasing order.

Input
First line contains the number of elements n (1≤n≤10^5) in array, and integer k (1≤k≤10^5).
Second line contains n integers, not greater than 10^9 by absolute value.

Output
Print the k-th element of array sorted in decreasing order, or -1 if such element does not exist.

Examples

Input #1
10 3
1 8 2 1 4 7 3 2 3 6

Answer #1
6

"""

def solve(a, k):
    n = len(a)
    if k < 0 or k > n:
        return -1
    a.sort()
    return a[n - k]

def main():
    assert(solve([1, 8, 2, 1, 4, 7, 3, 2, 3, 6], 3) == 6)

main()
