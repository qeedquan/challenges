#!/usr/bin/env python3

"""

Let us consider the Bernoulli trial scheme.

There are n independent trials.
The probability of event A occurring in each trial is p.
Find the probability that in n independent trials, event A will occur exactly k times.

Input
The first line contains two integers: n (0<n≤15) and k (0≤k≤n).

The second line contains one real number p (0≤p≤1).

Output
Print the probability that in n independent trials, event A will occur exactly k times. Print the answer with at least 6 decimal places.

Examples

Input #1
8 2
0.3

Answer #1
0.296475

Input #2
10 3
0.5

Answer #2
0.117188

"""

from math import comb

def bernoulli(n, k, p):
    return comb(n, k) * p**k * (1 - p)**(n - k)

def main():
    print("%.6f" % bernoulli(8, 2, 0.3))
    print("%.6f" % bernoulli(10, 3, 0.5))

main()
