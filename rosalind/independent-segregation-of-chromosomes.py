#!/usr/bin/env python3

"""

Problem
Consider a collection of coin flips. One of the most natural questions we can ask is if we flip a coin 92 times, what is the probability of obtaining 51 "heads", vs. 27 "heads", vs. 92 "heads"?

Each coin flip can be modeled by a uniform random variable in which each of the two outcomes ("heads" and "tails") has probability equal to 1/2.
We may assume that these random variables are independent (see “Independent Alleles”); in layman's terms, the outcomes of the two coin flips do not influence each other.

A binomial random variable X takes a value of k if n consecutive "coin flips" result in k total "heads" and n-k total "tails." We write that X∈Bin(n,1/2).

Given: A positive integer n≤50.

Return: An array A of length 2n in which A[k] represents the common logarithm of the probability that two diploid siblings share at least k of their 2n chromosomes (we do not consider recombination for now).

Sample Dataset
5
Sample Output
0.000 -0.004 -0.024 -0.082 -0.206 -0.424 -0.765 -1.262 -1.969 -3.010

"""

from math import comb, log10

def solve(n):
    r = []
    I = 0
    p = 0.5
    for i in range(2*n, 0, -1):
        x = comb(2*n, 2*n - i) * p**i * (1-p)**(2*n - i)
        I += x
        r.append(round(log10(I), 3))
    return r[::-1]

def main():
    print(solve(5))

main()

