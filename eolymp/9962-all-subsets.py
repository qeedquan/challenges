#!/usr/bin/env python3

"""

For the first n natural numbers, generate and display all possible ordered subsets.

Input
A single natural number n (1≤n≤10).

Output
Print all ordered subsets of the integers from 1 to n in lexicographical order. Each subset should be printed on a new line.

Examples
Input #1
3

Answer #1
1
1 2
1 2 3
1 3
2
2 3
3

"""

def subsets(length):
    def dfs(index, path):
        if len(path) > 0:
            print(path)
        for i in range(index, length + 1):
            dfs(i + 1, path + [i])
    dfs(1, [])

def main():
    subsets(3)

main()
