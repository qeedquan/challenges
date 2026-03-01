#!/usr/bin/env python3

"""

The Home Prime of an integer n is the value obtained by repeatedly factoring and concatenating n's prime factors (in ascending order, including repeats) until reaching a fixed point (a prime).
For example, the Home Prime (HP(n)) of 10 is 773 as:

10 = 2x5 -> 25
25 = 5x5 -> 55
55 = 5x11 -> 511
511 = 7x73 -> 773

There are two equivalent ways to consider when the sequence ends:

It ends at a prime
It reaches a fixed point, as the prime factors of a prime p is just p
Note that the Home Prime of some numbers is currently unknown (e.g. 49 or 77).

You are to take a positive integer n≥2 as input through any convenient method or format and output the Home Prime of n.
You may assume that you don't have to handle any input that would exceed the integer limit in your language at any step, and you may assume that the input will already have a known Home Prime (so 49 won't be an input).

Make sure you program handles all inputs correctly, not just those that are only semiprimes:

HP(24)=331319:
24 = 2x2x2x3 = 2223
2223 = 3x3x13x19 = 331319

This is code-golf so the shortest code in bytes wins!

Test cases
These are the results for each 2≤n≤100, excluding n=49,77,80,96 which don't terminate on TIO in my example program.

  2                                  2
  3                                  3
  4                                211
  5                                  5
  6                                 23
  7                                  7
  8                3331113965338635107
  9                                311
 10                                773
 11                                 11
 12                                223
 13                                 13
 14                              13367
 15                               1129
 16                           31636373
 17                                 17
 18                                233
 19                                 19
 20                3318308475676071413
 21                                 37
 22                                211
 23                                 23
 24                             331319
 25                                773
 26                               3251
 27                              13367
 28                                227
 29                                 29
 30                                547
 31                                 31
 32                             241271
 33                                311
 34                              31397
 35                               1129
 36                              71129
 37                                 37
 38                                373
 39                                313
 40                      3314192745739
 41                                 41
 42                                379
 43                                 43
 44                        22815088913
 45                            3411949
 46                                223
 47                                 47
 48             6161791591356884791277
 50                               3517
 51                                317
 52                               2213
 53                                 53
 54                               2333
 55                                773
 56                              37463
 57                               1129
 58                                229
 59                                 59
 60                              35149
 61                                 61
 62                              31237
 63                                337
 64                      1272505013723
 65 1381321118321175157763339900357651
 66                               2311
 67                                 67
 68                               3739
 69                              33191
 70                                257
 71                                 71
 72                            1119179
 73                                 73
 74                                379
 75                                571
 76                             333271
 78                         3129706267
 79                                 79
 81                    193089459713411
 82                                241
 83                                 83
 84                               2237
 85                               3137
 86          6012903280474189529884459
 87         41431881512748629379008933
 88                             719167
 89                                 89
 90                              71171
 91                          236122171
 92                             331319
 93                                331
 94                               1319
 95                              36389
 97                                 97
 98                                277
 99                              71143
100                             317047

"""

from sympy import *

def nextfactors(n):
    return int("".join(str(p)*e for p, e in factorint(n).items()))

# https://oeis.org/A037274
def homeprime(n):
    if n < 1:
        return 0
    if n == 1:
        return 1

    fn = n
    while not isprime(fn):
        fn = nextfactors(fn)
    return fn

def main():
    tab = [1, 2, 3, 211, 5, 23, 7, 3331113965338635107, 311, 773, 11, 223, 13, 13367, 1129, 31636373, 17, 233, 19, 3318308475676071413, 37, 211, 23, 331319, 773, 3251, 13367, 227, 29, 547, 31, 241271, 311, 31397, 1129, 71129, 37, 373, 313]

    for i in range(len(tab)):
        assert(homeprime(i + 1) == tab[i])

main()
