#!/usr/bin/env python3

"""

The generalised harmonic number of order m of n is

H[n,m] = Sum[k=1, n] 1/k^m

In this challenge, we'll be considering the generalised harmonic numbers of order 2:

H[n,m] = Sum[k=1, n] 1/k^2

This sequence begins 1, 5/4, 49/36, 205/144, ...and converges to π^2/6 as n->oo.

However, we will only be considering the numerators of this sequence, which forms another sequence known as the Wolstenholme numbers (A007406):

1, 5, 49, 205, 5269, 5369, 266681, 1077749, 9778141, ...
You are to take a positive integer x as input. x is guaranteed to be a Wolstenholme number.
You should output the next term in the sequence of Wolstenholme numbers, i.e. given the numerator of H[n,2], output the numerator of H[n+1,2]

You may input and output in any convenient format. Your program should not fail due to floating point errors, meaning that attempts that calculate via the generalised harmonic numbers will be invalid if not using rational numbers.
Your program should work theoretically for any valid input, but it is acceptable to fail for inputs that may be outside your language's integer maximum.

You may assume that no element is repeated in the sequence. If it turns out that there are any duplicate values in the Wolstenholme numbers sequence, any and all behaviour is acceptable when passed such values as input.

This is code-golf, so the shortest code in bytes wins

Test cases
        x ->       out
        1 ->         5
        5 ->        49
       49 ->       205
      205 ->      5269
     5269 ->      5369
     5369 ->    266681
   266681 ->   1077749
  1077749 ->   9778141
  9778141 ->   1968329
  1968329 -> 239437889
239437889 -> 240505109

"""

from sympy import *

# https://oeis.org/A007406
def wolstenholme(n):
    r = Rational(0, 1)
    for i in range(1, n + 1):
        r += Rational(1, i*i)
    x, _ = fraction(r)
    return x

def next_wolstenholme(n):
    for i in range(1, n + 2):
        if wolstenholme(i) == n:
            return wolstenholme(i + 1)
    return 0


def main():
    tab = [1, 5, 49, 205, 5269, 5369, 266681, 1077749, 9778141, 1968329, 239437889, 240505109, 40799043101, 40931552621, 205234915681, 822968714749, 238357395880861, 238820721143261, 86364397717734821, 17299975731542641, 353562301485889, 354019312583809, 187497409728228241]

    for i in range(len(tab)):
        assert(wolstenholme(i + 1) == tab[i])

    assert(next_wolstenholme(1) == 5)
    assert(next_wolstenholme(5) == 49)
    assert(next_wolstenholme(49) == 205)
    assert(next_wolstenholme(205) == 5269)
    assert(next_wolstenholme(5269) == 5369)
    assert(next_wolstenholme(5369) == 266681)
    assert(next_wolstenholme(266681) == 1077749)
    assert(next_wolstenholme(1077749) == 9778141)
    assert(next_wolstenholme(9778141) == 1968329)
    assert(next_wolstenholme(1968329) == 239437889)
    assert(next_wolstenholme(239437889) == 240505109)

main()
