#!/usr/bin/env python3

"""

The Challenge
Implement the Sundaram sieve for finding prime numbers below n. Take an input integer, n, and output the prime numbers below n. You can assume that n will always be less than or equal to one million.

Sieve
Start with a list of the integers from 1 to n.

Remove all numbers that are in the form i + j + 2ij where:

i and j are less than n. j is always greater than or equal to i, which is greater than or equal to 1.
i + j + 2ij is less than or equal to n

Multiply the remaining numbers by 2, and add 1.

This will yield all the prime numbers (except 2, which should be included in your output) less than 2n + 2.

Here is an animation of the sieve being used to find primes below 202.

Output
Your output should be every prime integer ≤ n (in ascending order) followed by a newline:

2
3
5
Where n is 5.

Examples
> 10
2
3
5
7

> 30
2
3
5
7
11
13
17
19
23
29
Inputs are denoted by >.

"""

def sundaram(n):
    k = (n - 2) // 2
    p = [0]*(k+1)
    for i in range(1, k+1):
        j = i
        while i+j+2*i*j <= k:
            p[i+j+2*i*j] = 1
            j += 1

    r = []
    if n > 2:
        r.append(2)
    for i in range(1, k+1):
        if p[i] == 0:
            r.append(2*i + 1)
    return r

def main():
    print(sundaram(10))
    print(sundaram(30))
    print(sundaram(1000))

main()
