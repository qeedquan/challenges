#!/usr/bin/env python3

"""

Task
Given a positive integer, output nth term of natural numbers, where if we group in N-sized groups and reverse all groups. You are allowed to use 0-indexing or 1-indexing. Sequences upto size 5:

1 -> 1,2,3,4,5,6,7,8,9,10,...
2 -> 2,1,4,3,6,5,8,7,10,9,...
3 -> 3,2,1,6,5,4,9,8,7,12,...
4 -> 4,3,2,1,8,7,6,5,12,11,...
5 -> 5,4,3,2,1,10,9,8,7,6,...
Rules
The input is a positive integer n.
You may use either 0-based or 1-based indexing.
You may assume the input is valid.
You may use a function or full program. If you write a function you can take f(a,b) or f(a)(b).
You can assume the excepted output doesn't exceeds your language's default integer type limits.
Additionally, you can write a full program that takes a number n and outputs the corresponding sequence infinitely.
Objective
The shortest code in each language wins.

"""

def seq(n, m):
    r = []
    if n < 1 or m < 1:
        return r

    i = 1
    while i <= m:
        L = list(range(i, i + n))
        r += L[::-1]
        i += n
    return r[:m]

def main():
    for i in range(1, 6):
        print(seq(i, 10))

main()
