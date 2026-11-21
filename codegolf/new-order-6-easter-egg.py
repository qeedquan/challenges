#!/usr/bin/env python3

"""

Introduction (may be ignored)
Putting all positive integers in its regular order (1, 2, 3, ...) is a bit boring, isn't it? So here is a series of challenges around permutations (reshuffelings) of all positive integers. This is the sixth challenge in this series (links to the first, second, third, fourth and fifth challenge).

This challenge has a mild Easter theme (because it's Easter). I took my inspiration from this highly decorated (and in my personal opinion rather ugly) goose egg.

Decorated goose egg

It reminded me of the Ulam spiral, where all positive integers are placed in a counter-clockwise spiral. This spiral has some interesting features related to prime numbers, but that's not relevant for this challenge.

Ulam spiral

We get to this challenge's permutation of positive integers if we take the numbers in the Ulam spiral and trace all integers in a clockwise turning spiral, starting at 1. This way, we get:

1, 6, 5, 4, 3, 2, 9, 8, 7, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 25, 24, 23, etc.
If you would draw both of the spirals, you'd get some sort of an infinite mesh of (egg shell) spirals (note the New Order reference there).

This sequence is present in the OEIS under number A090861. Since this is a "pure sequence" challenge,
the task is to output a(n) for a given n as input, where a(n) is A090861.

Task
Given an integer input n, output a(n) in integer format, where a(n) is A090861.

Note: 1-based indexing is assumed here; you may use 0-based indexing, so a(0)=1;a(1)=6 , etc.
Please mention this in your answer if you choose to use this.

Test cases
Input | Output
---------------
1     |  1
5     |  3
20    |  10
50    |  72
78    |  76
123   |  155
1234  |  1324
3000  |  2996
9999  |  9903
29890 |  29796

Rules
Input and output are integers.
Your program should at least support input in the range of 1 up to 32767).
Invalid input (0, floats, strings, negative values, etc.) may lead to unpredicted output, errors or (un)defined behaviour.
Default I/O rules apply.
Default loopholes are forbidden.
This is code-golf, so the shortest answers in bytes wins

"""

from math import isqrt

# https://oeis.org/A090861
def spiral(n):
    if n < 1:
        return 0

    x = (isqrt(n - 1) + 1) // 2
    y = 6
    if n <= 4*x**2 + 2*x:
        y = -2
    return 8*x**2 + x*y + 2 - n

def main():
    tab = [
        1, 6, 5, 4, 3, 2, 9, 8, 7, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
        25, 24, 23, 22, 21, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
        29, 28, 27, 26, 49, 48, 47, 46, 45, 44, 43, 72, 71, 70, 69, 68, 67, 66,
        65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50
    ]
    
    assert(spiral(1) == 1)
    assert(spiral(5) == 3)
    assert(spiral(20) == 10)
    assert(spiral(50) == 72)
    assert(spiral(78) == 76)
    assert(spiral(123) == 155)
    assert(spiral(1234) == 1324)
    assert(spiral(3000) == 2996)
    assert(spiral(9999) == 9903)
    assert(spiral(29890) == 29796)

    for i in range(len(tab)):
        assert(spiral(i + 1) == tab[i])

main()
