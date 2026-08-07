#!/usr/bin/env python3

"""

Given two natural numbers n and k, print all possible k-length permutations of integers from 1 to n in lexicographic order.

Input
Two natural numbers n and k (1≤k≤n≤8).

Output
Print all possible k-length permutations of integers from 1 to n in lexicographic order. Each permutation should be displayed on a separate line.

Examples
Input #1
3 2

Answer #1
1 2
1 3
2 1
2 3
3 1
3 2

"""

def backtrack(n, k, used, permutation):
    if len(permutation) == k:
        print(permutation)
        return
        
    for num in range(1, n + 1):
        if not used[num]:
            used[num] = True
            permutation.append(num)
            backtrack(n, k, used, permutation)
            permutation.pop()
            used[num] = False

def solve(n, k):
    backtrack(n, k, [False]*(n + 1), [])

def main():
    solve(3, 2)

main()
