#!/usr/bin/env python3

"""

Your job is to convert decimals back into the sum of the square roots of integers. The result has to have an accuracy of at least 6 significant decimal digits.

Input:

A number indicating the number of square roots and a decimal indicating the number to approximate.

Example input:

2 3.414213562373095
Output: Integers separated by spaces that, when square rooted and added, are approximately the original decimal accurate to at least 6 significant decimal digits.

Zeros are not allowed in the solution.

If there are multiple solutions, you only have to print one.

Example output (in any order):

4 2
This works because Math.sqrt(4) + Math.sqrt(2) == 3.414213562373095.

This is code golf. Shortest code (with optional bonus) wins!

There is always going to be a solution but -10 if your program prints "No" when there is no solution with integers. In addition, -10 if your program prints all solutions (separated by newlines or semicolons or whatever) instead of just one.

Test cases:

3 7.923668178593959 --> 6 7 8
2 2.8284271247461903 --> 2 2
5 5.0 --> 1 1 1 1 1
5 13.0 --> 4 4 9 9 9 --> 81 1 1 1 1 --> 36 9 4 1 1 etc. [print any, but print all for the "all solutions bonus"]
And yes, your program has to finish in finite time using finite memory on any reasonable machine. It can't just work "in theory," you have to be able to actually test it.

"""

def recurse(N, x, p, i):
    if abs(x) < 1e-6 and N == 0:
        print(p)

    while i < x*x + 0.1:
        recurse(N - 1, x - i**0.5, p + [i], 1)
        i += 1

"""

Ported from @Sp3000 solution

Proof of correctness
In order to end up in an infinite loop, we must hit some point where x < 0 and 0.1 + x2 > 1. This is satisfied by x < -0.948....

But note that we start from positive x and x is always decreasing,
so in order to hit x < -0.948... we must have had x' - i0.5 < -0.948... for some x' > -0.948... before x and positive integer i.
For the while loop to run, we must also have had 0.1 + x'2 > i.

Rearranging we get x'2 + 1.897x' + 0.948 < i < 0.1 + x'2, the outer parts implying that x' < -0.447.
But if -0.948 < x' < -0.447, then no positive integer i can fit the gap in the above inequality.

Hence we'll never end up in an infinite loop.

"""

def solve(N, x):
    recurse(N, x, [], 1)
    print()

def main():
    solve(3, 7.923668178593959)
    solve(2, 2.8284271247461903)
    solve(5, 5.0)
    solve(5, 13.0)

main()
