#!/usr/bin/env python3

"""

Consider the following probability puzzle.

We start with a string of bits all set to 0. At each step we choose a bit uniformly and independently at random and flip it. The value your code has to compute is the probability of getting to the all 1s bit string before you get back to the all 0s bit string.

Let n be the length of the starting bitstring.

Examples:

n=1. The output is 1.

n=2. The output is 1/2.

n=3. The output is 2/5.

The remaining outputs for n up to 20 are:

3/8,3/8,5/13,60/151,105/256,35/83,63/146,630/1433,1155/2588,6930/15341,12870/28211,24024/52235,9009/19456,9009/19345,17017/36362,306306/651745,2909907/6168632.

Your code should take n as the input and give the right output. The output must be exact, for example as a fraction. There is no need for the fraction to be fully reduced.

Your code must work for n up to at least 20 and run without timing out on TIO .

"""

from math import *

"""

@ZaMoC

n! / (Sum[k=0, n] k!*(n - k!))

"""
def probability(n):
    x = factorial(n)
    y = 0
    for k in range(n+1):
        y += factorial(k)*factorial(n - k)
    
    d = gcd(x, y)
    return (x//d, y//d)

def main():
    tab = [(1, 1), (1, 2), (2, 5), (3, 8), (3, 8), (5, 13), (60, 151), (105, 256), (35, 83), (63, 146), (630, 1433), (1155, 2588), (6930, 15341), (12870, 28211), (24024, 52235), (9009, 19456), (9009, 19345), (17017, 36362), (306306, 651745), (2909907, 6168632)]

    for i in range(len(tab)):
        assert(probability(i) == tab[i])

main()
