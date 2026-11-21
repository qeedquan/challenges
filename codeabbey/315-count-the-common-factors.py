#!/usr/bin/env python3

"""

You are given two positive integers A and B. You take any positive integer N and add this to the integers A and B to get the integers C and D. So C = A + N and D = B + N.

We are interested in the common factors of C and D, i.e. the set of numbers which divide into both C and D.

For this problem you are to consider all possible values of N and the common factors of the corresponding values of C and D. Clearly some factors will occur for many different pairs of C and D. If we collect the combined set of common factors for all pairs of C and D, there will be many duplicates. We are interested in the number of distinct factors in this set.

For example, if we are given A = 34 and B = 40, the first few values of N lead to the following results:

N = 1 gives C = 35, D = 41; which have a single common factor of 1
N = 2 gives C = 36, D = 42; which have common factors of 1, 2, 3 and 6
N = 3 gives C = 37, D = 43; which have a single common factor of 1
N = 4 gives C = 38, D = 44; which have common factors of 1, and 2
N = 5 gives C = 39, D = 45; which have common factors of 1, and 3
If we continue this process indefinitely, adding all common factors to the set, we will not produce any common factors that have not already been found. The set of distinct common factors is {1, 2, 3, 6} and the number of distinct common factors is 4.

Input/Output description: The first line of the input data will contain a single integer N. N lines will follow. Each line contains two integers A and B. For each of these pairs you are to carry out the process described above to find the number of distinct common factors in the set. Give all answers on a single line, separated by single spaces.

Example:

input:
8
34 40
696 1620
8851 14186
83118 128714
631491 1445435
7065276 13814628
99871024 183503616
839641464 1644943036

answer:
4 24 8 6 16 32 20 12

"""

from sympy import divisors

def solve(a, b):
    return len(divisors(abs(a - b)))

def main():
    assert(solve(34, 40) == 4)
    assert(solve(696, 1620) == 24)
    assert(solve(8851, 14186) == 8)
    assert(solve(83118, 128714) == 6)
    assert(solve(631491, 1445435) == 16)
    assert(solve(7065276, 13814628) == 32)
    assert(solve(99871024, 183503616) == 20)
    assert(solve(839641464, 1644943036) == 12)

main()
