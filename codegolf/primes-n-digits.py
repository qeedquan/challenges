#!/usr/bin/env python3

"""

This has no practical purpose but it could be fun to golf.

Challenge
Given a number n,

Count the amount of each digit in n and add 1 to each count
Take the prime factorization of n
Count the amount of each digit in the prime factorization of n, without including duplicate primes
Create a new list by multiplying together the respective elements of the lists from steps 1 and 3
Return the sum of that list
For example, 121 has two 1s and a 2, so you would get the following list from step 1:

0 1 2 3 4 5 6 7 8 9
1 3 2 1 1 1 1 1 1 1
The prime factorization of 121 is 112, which gives the following list for step 3:

0 1 2 3 4 5 6 7 8 9
0 2 0 0 0 0 0 0 0 0
Note how we did not count the exponent. These multiply together to get:

0 1 2 3 4 5 6 7 8 9
0 6 0 0 0 0 0 0 0 0
And the sum of this list is 6.

Test cases
1 -> 0
2 -> 2
3 -> 2
4 -> 1
5 -> 2
10 -> 2
13 -> 4
121 -> 6
Notes
Standard loopholes are forbidden.
Input and output can be in any reasonable format.
You should leave ones (or zeros for step 3) in the list for digits that did not appear in the number.
This is code-golf, so the shortest solution in bytes wins.

"""

from sympy import factorint
from functools import reduce
import operator

def count(n):
    r = [0] * 10
    while n > 0:
        r[n % 10] += 1
        n //= 10
    return r

def primendigits(n):
    a = list(map(operator.add, count(n), [1] * 10))
    b = [0] * 10
    for x in factorint(n):
        b = list(map(operator.add, b, count(x)))
    r = list(map(operator.mul, a, b))
    return reduce(operator.add, r)

def main():
    assert(primendigits(1) == 0)
    assert(primendigits(2) == 2)
    assert(primendigits(3) == 2)
    assert(primendigits(4) == 1)
    assert(primendigits(5) == 2)
    assert(primendigits(10) == 2)
    assert(primendigits(13) == 4)
    assert(primendigits(121) == 6)

main()
