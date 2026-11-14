#!/usr/bin/env python3

"""

If you solved the task about Neumann's Random Generator you are already aware that not all methods of generating pseudo-random sequences are good. Particularly, Neumann's method is not suitable for anything except programming exercises.

Here is the other method which is more widespread (it is implemented in most of programming languages and libraries) and still simple enough: let us start with some initial number and generate each new member Xnext of a sequence by the current Xcur using the following rule:

Xnext = (A * Xcur + C) % M
So we need three constants to define such a sequence (and an initial number). Not all combinations of constants are good (you may read details at Random Numbers), however, here are many good variants which allow to produce sequences with period of M, i.e. significantly long.

In this task we are going to build this algorithm to tell the value of n-th member of a sequence.

Input data will contain the number of test-cases in the first line.
Then test-cases will follow, each in separate line.
Test-case consists of five values: A, C, M, X0, N where first three are the same as in formula, while X0 is the initial member of a sequence and N is the number of a member which we want to calculate.
Answer should contain N-th member's value for each test-case, separated by spaces.

Example:

input data:
2
3 7 12 1 2
2 3 15 8 10

answer:
1 11

"""

import numpy as np

"""

https://www.nayuki.io/page/fast-skipping-in-a-linear-congruential-generator
https://jia.je/ctf-writeups/misc/lcg.html
https://en.wikipedia.org/wiki/Linear_congruential_generator

To determine x[n] for an LCG, the naive method is to iterate the generator O(N) times.
There is a faster way to do this in O(log(n)) using matrix exponentiation.
The LCG next state can be represented as a matrix as follows:

[x[n+1] = [a b] [x]
[  1  ]   [0 1] [1]

So to get the nth iteration we have:
               
[x[n+k] = [a b]^k [x]
[  1  ]   [0 1]   [1]

This can be done in O(log(n)) via exponentiation by squaring.
Apply the modulus each step during the squaring to keep the numbers from exploding.

If the matrix has an inverse modulo m (this is true iff a is coprime to m),
then we can do backward iteration as well to recover the previous values

"""
class LCG:
    def __init__(self, a, b, m, seed):
        self.a = a
        self.b = b
        self.m = m
        self.x = seed

    def skip(self, n):
        A = np.array([[self.a, self.b], [0, 1]])
        A = np.linalg.matrix_power(A, n)
        b = np.dot(A, np.array([self.x, 1]))
        self.x = b[0] % self.m
        return self.x

def test(a, c, m, x0, n, r):
    l = LCG(a, c, m, x0)
    x = l.skip(n)
    assert(x == r)

def main():
    test(3, 7, 12, 1, 2, 1)
    test(2, 3, 15, 8, 10, 11)

main()
