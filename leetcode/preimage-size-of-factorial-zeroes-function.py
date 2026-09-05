#!/usr/bin/env python3

"""

Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.

For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
Given an integer k, return the number of non-negative integers x have the property that f(x) = k.

Example 1:

Input: k = 0
Output: 5
Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.

Example 2:

Input: k = 5
Output: 0
Explanation: There is no x such that x! ends in k = 5 zeroes.

Example 3:

Input: k = 3
Output: 5

"""

def digitsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def convb(n, b, p):
    if b <= 0:
        return 0
    
    r = 0
    d = []
    while n > 0:
        d.append(n % b)
        n //= b
    for i in range(len(d)-1, -1, -1):
        r = (r * p) + d[i]
    return r

# https://oeis.org/A027868
def trailingzeroes(n):
    return (n - digitsum(convb(n, 5, 10))) // 4

def psfzf(k):
    c = 0
    i = 0
    while True:
        z = trailingzeroes(i)
        if z > k:
            break
        if z == k:
            c += 1
        i += 1
    return c

def main():
    assert(psfzf(0) == 5)
    assert(psfzf(5) == 0)
    assert(psfzf(3) == 5)
    assert(psfzf(15) == 5)

main()
