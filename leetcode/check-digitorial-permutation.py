#!/usr/bin/env python3

"""

You are given an integer n.

A number is called digitorial if the sum of the factorials of its digits is equal to the number itself.

Determine whether any permutation of n (including the original order) forms a digitorial number.

Return true if such a permutation exists, otherwise return false.

Note:

The factorial of a non-negative integer x, denoted as x!, is the product of all positive integers less than or equal to x, and 0! = 1.
A permutation is a rearrangement of all the digits of a number that does not start with zero. Any arrangement starting with zero is invalid.


Example 1:

Input: n = 145

Output: true

Explanation:

The number 145 itself is digitorial since 1! + 4! + 5! = 1 + 24 + 120 = 145. Thus, the answer is true.

Example 2:

Input: n = 10

Output: false

Explanation:

10 is not digitorial since 1! + 0! = 2 is not equal to 10, and the permutation "01" is invalid because it starts with zero.

Constraints:

1 <= n <= 10^9

Hint 1
Precompute the factorial of digits 0 to 9 and compute the sum of factorials of the digits.

Hint 2
Check whether the digits of this sum can be formed using exactly the digits of n (no leading zero allowed).

"""

from math import factorial

def digitorial(n):
    x, y = 0, n
    while y > 0:
        x += factorial(y % 10)
        y //= 10
    return sorted(str(x)) == sorted(str(n))

def main():
    assert(digitorial(145) == True)
    assert(digitorial(10) == False)

main()

