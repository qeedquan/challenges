#!/usr/bin/env python3

"""

Watson set a simple task for Rybka: to find the sum of all integers less than N that are divisible by A or B, and print this sum modulo 1000000007 (10^9+7). Help Rybka solve this task.

Input
The input consists of a single line containing three integers N, A, and B.

1≤N,A,B<10^18.

Output
Print the required sum modulo 1000000007.

Examples
Input #1
7 2 3

Answer #1
15

"""

from math import lcm

def triangular(n):
    return n * (n + 1) // 2

def som(n, d):
    c = (n - 1) // d
    return d * triangular(c)

"""

https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
https://artofproblemsolving.com/wiki/index.php/Principle_of_Inclusion-Exclusion

Principle of Inclusion-Exclusion

Total Sum = S(A) + S(B) - S(LCM(A, B))

D = Count = floor((N-1)/D)
S(D) = D * Count*(Count+1)/2

"""

def solve(n, a, b):
    m = 1000000007
    return (som(n, a) + som(n, b) - som(n, lcm(a, b))) % m

def main():
    assert(solve(7, 2, 3) == 15)
    assert(solve(20, 4, 7) == 61)

main()
