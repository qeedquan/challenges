#!/usr/bin/env python3

"""

In this challenge, an infinitely proportional sequence is defined as a infinite sequence of positive integers such that:

All positive integers are contained infinitely many times within the sequence.
As more and more terms are added to the sequence, for all positive integers n, the ratio of the number of ns to the number of n+1 s in the sequence must grow arbitrarily large.
An example of such a sequence is the following function taking an index and returning a value:

S(n) = S(sqrt(n)) + 1   if n is a perfect square > 1
       1                otherwise

This results in a sequence [1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3 ..., and it's fairly easy to see why this list satisfies the given properties. The first 4 occurs at index 2^8=256, the first 5 at index 2^16=65536, and so on, with each positive integer occuring infinitely many more times than the previous.

An example of an invalid sequence is this:

S(n) = S(n/2) + 1    if n is even
                     1 otherwise

This sequence goes [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5, ...], and while it does contain every positive integer infinitely many times, and contains each positive integer more than the previous, it does not contain each integer infinitely many more than the previous. In the limiting case, the sequence contains twice as many 1s as 2s, twice as many 2s as 3s, and so on.

Your challenge is to output any infinitely proportional sequence. Standard sequence rules apply - you may output as a function that takes n
 and outputs the n
th or first n
 terms, or output an infinite sequence in some form. You may use 0-indexing, 1-indexing or 2-indexing (taking the first term as f(2))

This is code-golf, shortest wins!

"""

from math import *

def S(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    
    s = int(sqrt(n))
    if s*s == n:
        return S(s) + 1
    return 1

def main():
    tab = [1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3]
    
    for i in range(len(tab)):
        assert(S(i + 1) == tab[i])

main()
