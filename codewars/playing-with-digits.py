#!/usr/bin/env python3

"""

Some numbers have funny properties. For example:

> 89 --> 8¹ + 9² = 89 * 1

> 695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2

> 46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p
- we want to find a positive integer k, if it exists, such as the sum of the digits of n taken to the successive powers of p is equal to k * n.

In other words:


> Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

If it is the case we will return k, if not return -1.

**Note**: n and p will always be given as strictly positive integers.


digPow(89, 1) should return 1 since 8¹ + 9² = 89 = 89 * 1
digPow(92, 1) should return -1 since there is no k such as 9¹ + 2² equals 92 * k
digPow(695, 2) should return 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2
digPow(46288, 3) should return 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

"""

def binsearch(n, f):
    i, j = 0, n
    while i < j:
        h = (i + j) // 2
        if not f(h):
            i = h + 1
        else:
            j = h
    return i

def digspc(n, p):
    r = 0
    for c in str(n):
        r += int(c)**p
        p += 1
    return r

def digpow(n, p):
    if n < 1 or p < 1:
        return -1

    x = digspc(n, p)
    k = binsearch(x, lambda i: n*i >= x)
    if n*k != x:
        return -1
    return k

def main():
    assert(digpow(89, 1) == 1)
    assert(digpow(92, 1) == -1)
    assert(digpow(695, 2) == 2)
    assert(digpow(46288, 3) == 51)

main()
