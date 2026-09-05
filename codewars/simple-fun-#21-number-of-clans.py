#!/usr/bin/env python3

"""

Task
Let's call two integers A and B friends if each integer from the array divisors is either a divisor of both A and B or neither A nor B. If two integers are friends, they are said to be in the same clan. How many clans are the integers from 1 to k, inclusive, broken into?

Example
For divisors = [2, 3] and k = 6, the output should be 4

The numbers 1 and 5 are friends and form a clan, 2 and 4 are friends and form a clan, and 3 and 6 do not have friends and each is a clan by itself. So the numbers 1 through 6 are broken into 4 clans.

Input/Output
[input] integer array divisors

A non-empty array of positive integers.

Constraints: 2 ≤ divisors.length < 10, 1 ≤ divisors[i] ≤ 10.

[input] integer k

A positive integer.

Constraints: 5 ≤ k ≤ 50.

[output] an integer

"""

def clans(d, k):
    r = []
    for i in range(1, k + 1):
        p = []
        for j in d:
            if i%j == 0:
                p.append(j)
        
        if p not in r:
            r.append(p)
    
    return len(r)

def main():
    assert(clans([2, 3], 6) == 4)
    assert(clans([2, 3, 4], 6) == 5)
    assert(clans([1, 3], 10) == 2)
    assert(clans([6, 2, 2, 8, 9, 2, 2, 2, 2], 10) == 5)

main()
