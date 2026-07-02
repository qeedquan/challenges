#!/usr/bin/env python3

"""

Write the shortest code you can solving the following problem:

Input:

An integer X with 2 <= X and X <= 100

Output:

Total combinations of 2, 3, and 5 (repetition is allowed, order matters) whose sum is equal to X.

Examples:

Input: 8

Output: 6, because the valid combinations are:

3+5
5+3
2+2+2+2
2+3+3
3+2+3
3+3+2
Input: 11

Output: 16, because the valid combinations are

5+3+3
5+2+2+2
3+5+3
3+3+5
3+3+3+2
3+3+2+3
3+2+3+3
3+2+2+2+2
2+5+2+2
2+3+3+3
2+3+2+2+2
2+2+5+2
2+2+3+2+2
2+2+2+5
2+2+2+3+2
2+2+2+2+3
Input: 100

Output: 1127972743581281, because the valid combinations are ... many

Input and output can be of any reasonable form. The lowest byte count in each language wins. Standard code-golf rules apply.

"""

from functools import lru_cache

# https://oeis.org/A079973
@lru_cache(maxsize=None)
def scwr(n):
    if n < 0 or n == 1:
        return 0
    if n < 5:
        return 1
    return scwr(n - 2) + scwr(n - 3) + scwr(n - 5)

def main():
    tab = [1, 0, 1, 1, 1, 3, 2, 5, 6, 8, 14, 16, 27, 36, 51, 77, 103, 155, 216, 309, 448, 628, 912, 1292, 1849, 2652, 3769, 5413, 7713, 11031, 15778, 22513, 32222, 46004, 65766, 94004, 134283, 191992, 274291, 392041, 560287, 800615, 1144320, 1635193, 2336976]

    assert(scwr(8) == 6)
    assert(scwr(11) == 16)
    assert(scwr(100) == 1127972743581281)

    for i in range(len(tab)):
        assert(scwr(i) == tab[i])

main()
