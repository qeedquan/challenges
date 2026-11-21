#!/usr/bin/env python3

"""

The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.

Given a positive integer N, return true if and only if it is an Armstrong number.

Example 1:

Input: 153
Output: true
Explanation:
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
Example 2:

Input: 123
Output: false
Explanation:
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.

Note:

1 <= N <= 10^8

"""

def digits(n):
    d = []
    while n > 0:
        d.append(n % 10)
        n //= 10
    return d

# https://oeis.org/A005188
def armstrong(n):
    if n < 0:
        return False

    d = digits(n)
    r = 0
    for v in d:
        r += v**len(d)
    return r == n

def main():
    tab = [
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748,
        92727, 93084, 548834, 1741725, 4210818, 9800817, 9926315, 24678050,
        24678051, 88593477, 146511208, 472335975, 534494836, 912985153,
        4679307774, 32164049650, 32164049651
    ]

    assert(armstrong(153) == True)
    assert(armstrong(123) == False)
    for v in tab:
        assert(armstrong(v) == True)

main()
