#!/usr/bin/env python3

"""

Challenge:
Given an array of non-negative whole numbers numbers in the range of 0 to Infinity, Check whether all of them are primes or not. (You can take input as a string too if you want)

Input:
Input: An array of numbers

Output: The array with every element replaced by one of these:

-1                 -----> If 0, 1
1                  -----> If it is a prime number greater than 1
the highest factor -----> If that number is not prime
Return either -1 (0, 1), 1 (for primes >= 2) or the highest factor of given number (for non-primes)

Examples:
[1, 2, 3, 4, 10, 11, 13]                        ---> [-1, 1, 1, 2, 5, 1, 1]
[100, 200, 231321, 12312, 0, 111381209, 123123] ---> [50, 100, 77107, 6156, -1, 1, 41041]
Note:
Input will always be valid, i.e it will consist only of numbers and decimals are not tested for. The array can be empty, if so, return the empty array.

Restriction:
This is code-golf so shortest code in bytes for each language wins.

"""

from sympy import divisors

def solve(a):
    r = []
    for x in a:
        if x < 2:
            r.append(-1)
        else:
            r.append(list(divisors(x))[-2])
    return r

def main():
    assert(solve([1, 2, 3, 4, 10, 11, 13]) == [-1, 1, 1, 2, 5, 1, 1])
    assert(solve([100, 200, 231321, 12312, 0, 111381209, 123123]) == [50, 100, 77107, 6156, -1, 1, 41041])

main()
