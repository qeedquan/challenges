#!/usr/bin/env python3

"""

Take a positive integer X. This number is part of the sequence we are interested in if the sum of all digits of X is a divisor of X, and if the product of all digits of X is a divisor of X.

For example, 135 is such a number because 1 + 3 + 5 = 9 which divides 135 = 9 * 15 and 1 * 3 * 5 = 15 which also divides 135.

This is sequence A038186 in the OEIS.

Your task: given an integer N, output the Nth positive integer with such properties.

Inputs and outputs
Numbers may be 0-indexed or 1-indexed; please indicate which one your answer use.

The input may be taken through STDIN, as a function argument, or anything similar.

The output may be printed to STDOUT, returned from a function, or anything similar.

Test cases
The test cases below are 1-indexed.

Input        Output

1            1
5            5
10           12
20           312
42           6912
50           11313

Scoring
This is code-golf, so the shortest answer in bytes wins.

"""

from math import prod

# https://oeis.org/A038186
def ndsp(n):
    s = sum(map(int, str(n)))
    p = prod(map(int, str(n)))
    return n%s == 0 and p and n%p == 0

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if ndsp(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 24, 36, 111, 112, 132, 135, 144, 216, 224, 312, 315, 432, 612, 624, 735, 1116, 1212, 1296, 1332, 1344, 1416, 2112, 2232, 2916, 3132, 3168, 3276, 3312, 4112, 4224, 6624, 6912, 8112, 9612, 11112, 11115, 11133, 11172, 11232, 11313]
    
    assert(gen(len(tab)) == tab)

main()
