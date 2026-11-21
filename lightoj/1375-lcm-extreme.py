#!/usr/bin/env python3

"""

Find the result of the following code:

unsigned long long allPairLcm( int n ) {
    unsigned long long res = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = i + 1; j <= n; j++ )
            res += lcm(i, j); // lcm means least common multiple
    return res;
}
A straight forward implementation of the code may time out.

Input
Input starts with an integer T (≤ 2x10^5), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 3x10^6).

Output
For each case, print the value returned by the function 'allPairLcm(n)'. As the result can be large, we want the result modulo 2^64.

Sample
Input	Output
4
2
10
13
100000

Case 1: 2
Case 2: 1036
Case 3: 3111
Case 4: 9134672774499923824

Notes
Dataset is huge, use faster I/O Methods.

"""

from sympy import *

def triangular(n):
    return n * (n + 1) // 2

# https://www.naukri.com/code360/problem-details/sum-of-lcm_975487
def lcmsum(n):
    s = 0
    for d in divisors(n):
        s += d * totient(d)
    return n * (s + 1) // 2

def solve(n):
    r = 0
    for i in range(1, n + 1):
        r += lcmsum(i)
    return r - triangular(i)

def main():
    assert(solve(2) == 2)
    assert(solve(10) == 1036)
    assert(solve(13) == 3111)
    assert(solve(100000) == 9134672774499923824)

main()
