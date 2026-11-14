#!/usr/bin/env python3

"""

This kata is the part two version of the Find X ( https://www.codewars.com/kata/find-x ) kata, if you haven't solved it you should try solving it, it's pretty easy.

In this version you're given the following function

def find_x(n):
      if n == 0: return 0
      x = 0
      for i in range(1, n+1):
            x += find_x(i-1) + 3*i
      return x

Since this computation is exponential, it gets very slow quickly as n increases, your task is to optimize the function so it works well for large numbers.

find_x(2) #=> 12
find_x(3) #=> 33
find_x(5) #=> 171

The result gets pretty large even for small inputs, so you should return the result % (109+7)

Input Range
1 <= n <= 10^6

"""

from functools import lru_cache

def find_x(n):
    mod = 1000000007
    if n < 0:
        return 0
    return (3 * (pow(2, n+1, mod) - n - 2)) % mod

@lru_cache(maxsize=None)
def find_x_bf(n):
    mod = 1000000007
    if n < 0:
        return 0
 
    x = 0
    for i in range(1, n+1):
        x += find_x_bf(i-1) + 3*i
    return x % mod

def main():
    assert(find_x(2) == 12)
    assert(find_x(3) == 33)
    assert(find_x(5) == 171)

    for i in range(1000):
        assert(find_x(i) == find_x_bf(i))

main()

