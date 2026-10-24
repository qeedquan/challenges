#!/usr/bin/env python3

"""

Randomness is fun. Challenges with no point are fun.

Write a function that, given integer input n, will output a set (unordered, unique) of exactly n random integers between 1 and n^2 (inclusive) such that the sum of all integers is equal to n^2.

Randomness does not have to be uniform, provided each valid set has a non-zero chance to occur.

Shortest answer in bytes (per each language) wins.

Examples
Input (n) = 1, Target (n^2) = 1
Sample of possible outputs:
1

Input = 2, Target = 4
Sample of possible outputs:
3, 1
1, 3

Input = 3, Target = 9
Sample of possible outputs:
6, 1, 2
3, 5, 1
4, 3, 2

Input = 4, Target = 16
Sample of possible outputs:
1, 3, 5, 7
2, 4, 1, 9
8, 3, 1, 4

Input = 5, Target = 25
Sample of possible outputs:
11, 4, 7, 1, 2
2, 3, 1, 11, 8
6, 1, 3, 7, 8

Input = 8, Target = 64
Sample of possible outputs:
10, 3, 9, 7, 6, 19, 8, 2
7, 16, 2, 3, 9, 4, 13, 10
7, 9, 21, 2, 5, 13, 6, 1

Bonus Task: Is there a formula to calculate the number of valid permutations for a given n?

"""

from functools import lru_cache

def recurse(n, t, x):
    if len(x) > n:
        return 0

    if len(x) == n:
        s = sum(x)
        if s > t:
            return 0
        if s == t:
            print(x)
            return 1

    c = 0
    for i in range(1, t + 1):
        if i not in x:
            x.append(i)
            c += recurse(n, t, x)
            x.pop()
    return c

def solve(n):
    print("n=%d" % (n))
    c = recurse(n, n**2, [])
    print("Found %d solutions" % (c))
    print()

# https://oeis.org/A107379
@lru_cache(maxsize=None)
def partition(n, k):
    if n == 0 and k == 0:
        return 1
    if n <= 0 or n < k:
        return 0
    if (n+k)%2 == 1:
        return 0
    if k == 1:
        return 1
    return partition(n - 1, k - 1) + partition(n - 2*k, k)

def main():
    tab = [1, 1, 1, 3, 9, 30, 110, 436, 1801, 7657, 33401, 148847, 674585, 3100410, 14422567, 67792847, 321546251, 1537241148, 7400926549, 35854579015, 174677578889, 855312650751, 4207291811538, 20782253017825, 103048079556241, 512753419159803, 2559639388956793]

    for i in range(len(tab)):
        assert(partition(i**2, i) == tab[i])

    for i in range(1, 5):
        solve(i)

main()
