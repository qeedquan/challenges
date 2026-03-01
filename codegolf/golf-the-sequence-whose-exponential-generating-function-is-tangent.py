#!/usr/bin/env python3

"""

Almost every function can be expressed as a polynomial with infinite terms.

For example, e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! + ...

For example, sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

The coefficients of the n-th terms form a sequence, and the corresponding function is called the Generating Function of the sequence.

The coefficients of the n-th terms form a sequence.

Often, the n-th term would have a denominator of n!. Therefore, we multiply the coefficient by n! to obtain another sequence, whose Exponential Generating Function would be the original function.

For example, the sequence whose Exponential Generating Function is e^x would be 1,1,1,1,....

For example, the sequence whose Exponential Generating Function is sin(x) would be 0,1,0,-1,0,1,0,-1,....

Task
Your task is to find the n-th term of the sequence whose Exponential Generating Function is tan(x).

Testcases
n result
0 0
1 1
2 0
3 2
4 0
5 16
6 0
7 272
8 0
9 7936
10 0
11 353792
12 0
13 22368256
14 0
15 1903757312
16 0
17 209865342976
18 0
19 29088885112832
20 0
21 4951498053124096
22 0
23 1015423886506852352
24 0
25 246921480190207983616
26 0
(Copied from here.) (Warning: the 0-th term is different)

Example implementation
# copied from https://github.com/Mego/Seriously/blob/v2.0/SeriouslyCommands.py#L16
def memoized(f):
    memo = {}
    def m_fun(*args):
        if args in memo:
            return memo[args]
        else:
            res = f(*args)
            memo[args] = res
            return res
    return m_fun

# copied from https://github.com/Mego/Seriously/blob/v2.0/SeriouslyCommands.py#L169
@memoized
def binomial(n,r):
    if r > n:
        return 0
    elif r==n:
        return 1
    res = 1
    i = 1
    while i<=r:
        res *= (n+1-i)
        res /= i
        i+=1
    return int(res)

# 2*u(n+1) = Sum_{k=0..n} binomial(n, k)*u(k)*u(n-k)
# from A000111
@memoized
def u(n):
    if n<0: return 0
    if n==0: return 1
    if n==1: return 1
    return sum([binomial(n-1,k)*u(k)*u(n-1-k) for k in range(n)])//2     

def t(n):
    if n%2 == 0: return 0
    return u(n)

print('\n'.join([str(x) + ' ' + str(t(x)) for x in range(26)]))

Ideone it!

References
Generating function on Wikipedia
Exponential generating function on Wikipedia
Exponential generating function example on Wikipedia
Generating function on MathWorld
Exponential generating function on MathWorld
Taylor series on Wikipedia
Derivation of first 9 terms of required sequence
Obligatory OEIS A009006 (Note that the 0-th term is different)
Algorithm
OEIS A000111: up/down numbers

"""

import math

def memoized(f):
    memo = {}
    def m_fun(*args):
        if args in memo:
            return memo[args]    
        res = f(*args)
        memo[args] = res
        return res
    
    return m_fun

# https://oeis.org/A000111
@memoized
def euler(n):
    if n < 0:
        return 0
    if n < 2:
        return 1

    r = 0
    for k in range(n):
        r += math.comb(n-1, k) * euler(k) * euler(n-1-k)
    return r//2

def gftan(n):
    if n%2 == 0:
        return 0
    return euler(n)

def main():
    tab = [0, 1, 0, 2, 0, 16, 0, 272, 0, 7936, 0, 353792, 0, 22368256, 0, 1903757312, 0, 209865342976, 0, 29088885112832, 0, 4951498053124096, 0, 1015423886506852352, 0, 246921480190207983616, 0]
    for i in range(len(tab)):
        assert(gftan(i) == tab[i])

main()
