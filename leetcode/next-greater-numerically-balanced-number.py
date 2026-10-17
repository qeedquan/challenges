#!/usr/bin/env python3

"""

An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.

Example 1:

Input: n = 1
Output: 22
Explanation:
22 is numerically balanced since:
- The digit 2 occurs 2 times.
It is also the smallest numerically balanced number strictly greater than 1.

Example 2:

Input: n = 1000
Output: 1333
Explanation:
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.

Example 3:

Input: n = 3000
Output: 3133
Explanation:
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.

Constraints:

0 <= n <= 10^6

Hint 1
How far away can the next greater numerically balanced number be from n?

Hint 2
With the given constraints, what is the largest numerically balanced number?

"""

# https://oeis.org/A108571
def beautiful(n):
    s = str(n)
    for d in set(s):
        if s.count(d) != int(d):
            return False
    return True

def next(n):
    i = n + 1
    while True:
        if beautiful(i):
            return i
        i += 1

def main():
    assert(next(1) == 22)
    assert(next(1000) == 1333)
    assert(next(3000) == 3133)

main()

