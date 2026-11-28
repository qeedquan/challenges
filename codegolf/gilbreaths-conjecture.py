#!/usr/bin/env python3

"""

Suppose we start with the infinite list of prime numbers:

[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, ...
Then, we take the absolute differences between each pair of numbers, repeatedly:

[1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, ...
[1, 0, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 0, 4, 4, 2, ...
[1, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 4, 0, 2, ...
[1, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 4, 2, ...
Notice that the leading number is 1 every time. Gilbreath's Conjecture is the prediction that this continues to be the case forever.

The only way the leading number would stop being a 1 is if the next number after it was neither a 0 nor a 2. The only way the second number wouldn't be a 0 or a 2 is if the number after that was neither a 0 nor a 2. And so on.

The index of the earliest number, other than the leading 1, which is neither a 0 nor a 2, can never go down by more than 1 between a consecutive pair of sequences. This fact has been used to put a very strong lower bound on when, if ever, a sequence might not have a 1 as the first element.

In this challenge, you will be given the index of a sequence, and you must output the index of the first number in that sequence which is not the leading 1, and is not a 0 or a 2.

For instance, in the 4th absolute difference sequence above:

[1, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 4, 2, ...
The first entry that's neither a zero or a two, other than the first entry, is the 15th position, 14 zero indexed. So if the input was 4, you would output 14.

For inputs from 1 to 30, the outputs should be:

[3, 8, 14, 14, 25, 24, 23, 22, 25, 59, 98, 97, 98, 97, 174, 176, 176, 176, 176, 291, 290, 289, 740, 874, 873, 872, 873, 872, 871, 870]

This is OEIS A000232.

This is assuming you have 1 indexed inputs and 0 indexed outputs. You may index your inputs and outputs starting at any constant integers, as long as you can accept the range of inputs corresponding to all sequences.

Requirements: Your solution must run in at most 1 minute on a input of up to 30. If it's close enough that it depends on the computer specs, it's allowed.

Shortest code wins.

"""

from functools import *
from sympy import *

# https://oeis.org/A036262
@lru_cache(maxsize=None)
def A036262(n, k):
    if n < 0:
        return 0
    if n == 0:
        return prime(k)
    return abs(A036262(n - 1, k + 1) - A036262(n - 1, k))

# https://oeis.org/A000232
def A000232(n):
    k = 1
    while True:
        if A036262(n, k) > 2:
            return k - 1
        k += 1
    return 0

def main():
    A036262tab = [2, 1, 3, 1, 2, 5, 1, 0, 2, 7, 1, 2, 2, 4, 11, 1, 2, 0, 2, 2, 13, 1, 2, 0, 0, 2, 4, 17, 1, 2, 0, 0, 0, 2, 2, 19, 1, 2, 0, 0, 0, 0, 2, 4, 23, 1, 2, 0, 0, 0, 0, 0, 2, 6, 29, 1, 0, 2, 2, 2, 2, 2, 2, 4, 2, 31, 1, 0, 0, 2, 0, 2, 0, 2, 0, 4, 6, 37, 1, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 4, 41, 1, 0, 0, 0, 0, 2, 0, 0, 0]

    A000232tab = [3, 8, 14, 14, 25, 24, 23, 22, 25, 59, 98, 97, 98, 97, 174, 176, 176, 176, 176, 291, 290, 289, 740, 874, 873, 872, 873, 872, 871, 870, 869, 868, 867, 866, 2180, 2179, 2178, 2177, 2771, 2770, 2769, 2768, 2767, 2766, 2765, 2764, 2763, 2763, 2763, 2763, 3366, 4208, 4207]

    k = 0
    f = False
    for i in range(1, len(A036262tab)):
        for j in range(1, i + 1):
            if k >= len(A036262tab):
                f = True
                break
            
            assert(A036262(i - j, j) == A036262tab[k])
            k += 1
        
        if f:
            break

    for i in range(len(A000232tab)):
        assert(A000232(i + 1) == A000232tab[i])

main()
