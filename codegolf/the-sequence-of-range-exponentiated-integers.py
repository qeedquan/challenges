#!/usr/bin/env python3

"""

Consider a triangle where the Nth row (1-indexed) is the array of the first N positive integer powers of N. Here are the first few rows:

N | Triangle

1 | 1
2 | 2 4
3 | 3 9 27
4 | 4 16 64 256
5 | 5 25 125 625 3125
...
Now if we concatenate those powers into a single sequence, we get OEIS A075363:

1, 2, 4, 3, 9, 27, 4, 16, 64, 256, 5, 25, 125, 625, 3125, 6, 36, 216, 1296, 7776, 46656 ...
Given an integer N, your task is to return the Nth term of this sequence. You can choose either 0 or 1-indexing.

Test cases
1-indexed:

N  -> Output

1  -> 1
2  -> 2
3  -> 4
5  -> 9
10 -> 256
12 -> 25
15 -> 3125
0-indexed:

N  -> Output

0  -> 1
1  -> 2
2  -> 4
4  -> 9
9  -> 256
11 -> 25
14 -> 3125
Note that these loopholes are forbidden by default. This is code-golf, thus the shortest valid submission in each language wins!

"""

from math import *

# https://oeis.org/A002260
def A002260(n):
    x = int(sqrt(8*n) + 1)
    return n - comb(x//2, 2)

# https://oeis.org/A002024
def A002024(n):
     return int(sqrt(2*n) + 0.5)

# https://oeis.org/A075363
def A075363(n):
    return A002024(n)**A002260(n)

def main():
    A002260tab = [1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

    A002024tab = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13]

    A075363tab = [1, 2, 4, 3, 9, 27, 4, 16, 64, 256, 5, 25, 125, 625, 3125, 6, 36, 216, 1296, 7776, 46656, 7, 49, 343, 2401, 16807, 117649, 823543, 8, 64, 512, 4096, 32768, 262144, 2097152, 16777216, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000]

    for i in range(len(A002260tab)):
        assert(A002260(i + 1) == A002260tab[i])

    for i in range(len(A002024tab)):
        assert(A002024(i + 1) == A002024tab[i])

    for i in range(len(A075363tab)):
        assert(A075363(i + 1) == A075363tab[i])

main()
