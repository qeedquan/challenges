#!/usr/bin/env python3

"""

Find the greatest gcd of the numbers (n^m) + k and  (n+1)^m + k for given m and k.

For example, for m=3, k=1 we have:

n = 1: gcd(1^3 + 1, 2^3 + 1) = 1
n = 2: gcd(2^3 + 1, 3^3 + 1) = 1
n = 5: gcd(5^3 + 1, 6^3 + 1) = 7 (max)
...
n -> oo

Input/Output
Input is L lines through file or stdin, EOF terminated. Each line contains two integers: m and k separated by a space.

Output is L integers separated by any pattern of whitespace characters (tabs, spaces, newlines etc).

Examples
Input

2 4
2 7
3 1
4 1
3 2
5 4
10 5
Output

17
29
7
17
109
810001
3282561
Update
I can't find a proof that the solution is bounded for all n given some m and k, so you only have to find the GGCD for n<10,000,000.

"""

from math import gcd

"""

@Ante

GGCD for given m and k is good defined.
https://math.stackexchange.com/questions/56120/number-of-solutions-for-pair-of-discrete-logarithm-like-equations

This is table of GGCD tested for n up to 500000.

m/k      1       2       3       4       5       6       7       8       9      10
2        5       9      13      17      21      25      29      33      37      41
3        7     109      61     433     169     973     331    1729     547    2701
4       17      33      49      65      81      97     113     129     145    2093
5      341   52501  258751  810001       1  131371       1       1  501311 2846591
6       65     129     193     257   21507     385     449   22059     577     641
7     3683  235747       1       1      71  438299  940507   33461     757  110503
8     4369     513     769   13325    1281  149089  202609    2049  975937  617201
9   359233  232537  202927  470983  123019  708589  241117 5601589  398581   19783
10   62525  514299  183757  807517 1094187 16856405  97477    8193  377897 25919971
For m==2 or 4 it looks quite good :-)

It seems that if p_in_i is gcd for some n, where p_i is a prime, than every combination of products of p_i's with exponents <= n_i is also gcd for some n. E.g. for m=8,k=2, 3^3 and 19 are gcd of type p_in_i, also 57, 171 and 513 are gcd's.

Some theory background: If g = gcd(n) > 1 for some n, and d > 1 and d divide g (it can be d=g) than d divide gcd(n±d). It is easy to prove. That means:

If you find some g = gcd(n) > 1 for some n, than gcd(n±d) > 1. So, it is enough to jump for found prime number of steps while iterating n.
If prime p divide some gcd() than there is n <= p where p divide gcd(n). Prime p will 'appear' in gcd(n) for some n <= p.
These properties can speed up search, but still there is a question is GGCD good defined.

"""

def ggcd(m, k):
    r = 0
    for n in range(1, 10000000):
        r = max(r, gcd(n**m + k, (n + 1)**m + k))
    return r

def main():
    assert(ggcd(2, 4) == 17)
    assert(ggcd(2, 7) == 29)
    assert(ggcd(3, 1) == 7)
    assert(ggcd(4, 1) == 17)
    assert(ggcd(3, 2) == 109)
    assert(ggcd(5, 4) == 810001)
    assert(ggcd(10, 5) == 3282561)

main()

