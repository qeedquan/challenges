#!/usr/bin/env python3

"""

When I was in grade 3, we were taught how to solve a very simple math problem. It was equaling the denominators of two or more fractions.

Let's take two proper fractions : 1/2, 2/3

First we will take the Least Common Multiple of the denominators of the two fractions, the LCM of 2,3 are 6.
Then we divide the LCM (6) by the denominators of both fractions (6) and we get 3,2 and serially multiply them with the numerators of the both fractions and get 36,46 And that's the result.

Challenge
Take two or more fractions, and equalize their denominators.

I/O format
You can take an array/list of (numerator,denominator) pairs. Pre-defining them in TIO header is allowed. You can take in other better ways too.

Input: ((1,2),(2,3)) or
        1,2 2,3
        1/2 2/3
Output: (3,6),(4,6) or
        3,6 4,6
        3/6 4/6
Input:  ((1, 8), (5, 12))
       1,8 5,12
       1/8 5/12
Output: ((3, 24), (10, 24))
         3,24 10,24
         3/24 10/24
Input: ((1, 2),(2, 3),(4, 6))
Output: 3/6 4/6 4/6

Rules
Standard loopholes are forbidden. (except use of TIO headers to pre-define input)
Trailing whitespace in output is allowed.
If possible, please link to an online interpreter (e.g. TIO) to run your program on.
Please explain your answer. This is not necessary, but it makes it easier for others to understand.
Languages newer than the question are allowed. This means you could create your own language where it would be trivial to do this, but don't expect any upvotes.
This is code-golf, so shortest code in bytes wins!

"""

from math import *

def equalize(a):
    l = 1
    for n, d in a:
        l = lcm(l, d)
    
    r = []
    for n, d in a:
        r.append((l*n//d, l))
    
    return r

def main():
    assert(equalize([(1, 2), (2, 3)]) == [(3, 6), (4, 6)])
    assert(equalize([(1, 8), (5, 12)]) == [(3, 24), (10, 24)])
    assert(equalize([(1, 2), (2, 3), (4, 6)]) == [(3, 6), (4, 6), (4, 6)])

main()
