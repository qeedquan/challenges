#!/usr/bin/env python3

"""

Calculate the sum of the first n terms of the sequence shown in the image:

1/2 + 2/3 + 3/4 + 4/5 + 5/6 + ...

Input
A natural number n, where 1≤n≤100.

Output
Print the sum of the first n terms of the sequence, rounded to three decimal places.

Examples
Input #1
3

Answer #1
1.917

"""

from scipy.special import polygamma

def solve(n):
    gamma = 0.57721566490153286060651209008240243104215933593992
    return 1 - gamma + n - polygamma(0, 2 + n)

def solvebf(n):
    r = 0
    for i in range(1, n + 1):
        r += i / (i + 1)
    return r

def main():
    print(solve(3))

    for i in range(1000):
        assert(abs(solve(i) - solvebf(i)) < 1e-12)

main()
