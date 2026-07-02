#!/usr/bin/env python3

"""

For two given integers n and k find

(Z[n] + Z[n-1] - 2*Z[n−2]) mod 10000007, where Z[n] = S[n] + P[n],
S[n] = 1^k + 2^k + 3^k + ... + n^k,
P[n] = 1^1 + 2^2 + 3^3 + ... + n^n

Input
There are several test cases. Each case is a separate line that contains two positive integers n and k (1<n<2*10^8, 0<k<10^6).
The last line contains two zeros and should not be processed.

Output
For each test case print the required value in a separate line.

Examples

Input #1
10 3
9 31
83 17
5 2
0 0

Answer #1
4835897
2118762
2285275
3694

"""

def solve(n, k):
    m = 10000007
    s1 = pow(n-1, k, m)
    s2 = pow(n, k, m)
    p1 = pow(n-1, n-1, m)
    p2 = pow(n, n, m)
    return (2*s1 + s2 + 2*p1 + p2) % m

def main():
    assert(solve(10, 3) == 4835897)
    assert(solve(9, 31) == 2118762)
    assert(solve(83, 17) == 2285275)
    assert(solve(5, 2) == 3694)

main()
