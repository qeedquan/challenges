#!/usr/bin/env python3

"""

Array a of n integers and a number k are given. Find the k-th element in the sorted array a (indexing starts from 1).

Input
The first line contains two integers n and k (1≤n≤2000, 1≤k≤n).

The second line contains n integers ai(1≤i≤n, 1≤ai≤2000).

Output
Print the k-th element in the sorted array a.

Examples

Input #1
2 1
2 1

Answer #1
1

Input #2
5 3
4 7 1 8 12

Answer #2
7

"""

def solve(a, k):
    if k < 0 or k > len(a):
        return 0
    
    a.sort()
    return a[k - 1]

def main():
    assert(solve([2, 1], 1) == 1)
    assert(solve([4, 7, 1, 8, 12], 3) == 7)

main()
