#!/usr/bin/env python3

"""

0. DEFINITIONS
A sequence is a list of numbers.
A series is the sum of a list of numbers.
The set of natural numbers contains all "non-negative integers greater than zero".
A divisor (in this context) of a natural number j is a natural number i, such that j÷i is also a natural number.

1. PREAMBLE
A couple of other questions on this site mention the concept of the aliquot, or the sequence of divisors of a natural number a which are less than a. Determining amicable numbers involves computing the sum of these divisors, called an aliquot sum or aliquot series. Every natural number has its own aliquot sum, although the value of a number's aliquot sum is not necessarily unique to that number. (Exempli gratia, every prime number has an aliquot sum of 1.)

2. CHALLENGE
Given a natural number n, return the nth digit of the sequence of aliquot sums. The first several series in the sequence, starting with the series for 1, are:

{0, 1, 1, 3, 1, 6, 1, 7, 4, 8, 1, 16, 1, 10, 9, 15, 1, 21, 1, 22, 11, 14, 1, 36, 6, 16, 13}
Concatenated, these look like:

0113161748116110915121122111413661613
Input may be zero-indexed or one-indexed, according to your preference. Solutions must be programs or functions capable of returning the 10,000th digit (input up to 9999 or 10000). The shortest working solution wins.

3. TEST CASES
Correct input-output pairs should include, but are not limited to, the following:

   0 or     1    ->    0
   4 or     5    ->    1
  12 or    13    ->    6
9999 or 10000    ->    7
The number preceding the "or" is 0-indexed; the number following is 1-indexed.
Additional test cases may be provided upon request.

4. REFERENCES
OEIS has a list of numbers and their aliquot sums.

"""

from sympy import *

# https://oeis.org/A001065
def aliquot(n):
    return divisor_sigma(n) - n

def seq(n):
    if n < 1:
        return 0

    s = ""
    for i in range(n + 1):
        s += str(aliquot(i + 1))
    return int(s[n])

def main():
    assert(seq(0) == 0)
    assert(seq(4) == 1)
    assert(seq(12) == 6)
    assert(seq(9999) == 7)

main()
