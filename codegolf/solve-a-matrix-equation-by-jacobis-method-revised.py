#!/usr/bin/env python3

"""

Mathematical Background

Let A be an N by N matrix of real numbers, b a vector of N real numbers and x a vector N unknown real numbers. A matrix equation is Ax = b.

Jacobi's method is as follows: decompose A = D + R, where D is the matrix of diagonals, and R is the remaining entries.

if you make an initial guess solution x0, an improved solution is x1 = inverse(D) * (b - Rx) where all multiplications are matrix-vector multiplication and inverse(D) is the matrix inverse.

Problem Specification

Input: Your complete program should accept as input the following data: the matrix A, the vector b, an initial guess x0, and an 'error' number e.
Output: The program must output the minimum number of iterations such that the latest solution differs by the true solution, by at most e. This means each component of the vectors in absolute magnitude differ by at most e. You must use Jacobi's method for iterations.
How the data is inputted is your choice; it could be your own syntax on a command line, you could take input from a file, whatever you choose.

How the data is outputted is your choice; it can be written to a file, displayed in the command line, written as ASCII art, anything, as long as it is readable by a human.

Further Details

You are not given the true solution: how you calculate the true solution is up to you entirely. You may solve it by Cramer's rule for example, or computing an inverse directly. What matters is that you have a true solution to be able to compare to iterations.

Precision is an issue; some people's 'exact solutions' for comparison may differ. For the purposes of this code golf the exact solution must be true to 10 decimal places.

To be absolutely clear, if even one component of your present iteration solution exceeds its corresponding component in the true solution by e, then you need to keep iterating.

The upper limit to N varies based on what hardware you're using and how much time you're willing to spend running the program. For the purposes of this code golf, assume maximum N = 50.

Preconditions

When your program is called, you are free to assume that the following holds at all times:

N > 1 and N < 51, i.e. you will never be given a scalar equation, always a matrix equation.
All inputs are over the field of real numbers, and will never be complex.
The matrix A is always such that the method converges to the true solution, such that you can always find a number of iterations to minimise the error (as defined above) below or equal to e.
A is never the zero matrix or the identity matrix, i.e. there is one solution.
Test Cases

A = ((9, -2), (1, 3)), b = (3,4), x0 = (1,1), e = 0.04
The true solution is (0.586, 1.138). The first iteration gives x1 = (5/9, 1), differing by more than 0.04 from the true solution, by at least one component. Taking another iteration we find, x2 = (0.555, 1.148) which differs by less than 0.04 from (0.586, 1.138). Thus the output is

2
A = ((2, 3), (1, 4)), b = (2, -1), x0 = (2.7, -0.7), e = 1.0
In this case the true solution is (2.2, -0.8) and the initial guess x0 already has error less than e = 1.0, thus we output 0. That is, whenever you do not need to make an iteration, you simply output

0
Submission Assessment

This is code golf, with all standard loopholes hereby disallowed. The shortest correct complete program (or function), i.e. lowest number of bytes wins. It is discouraged to use things like Mathematica which wrap up a lot of the necessary steps into one function, but use any language you want.

"""

import numpy as np

def solve(A, b, x, tolerance):
    A = np.asarray(A)
    b = np.asarray(b)
    x = np.asarray(x)

    diagonal = np.diag(np.diag(A))
    off_diagonal = A - diagonal
    exact_solution = np.linalg.solve(A, b)

    iterations = 0
    while np.linalg.norm(x - exact_solution) > tolerance:
        x = np.linalg.solve(diagonal, b - np.dot(off_diagonal, x))
        iterations += 1
    return iterations

def main():
    print(solve(np.array(((9, -2),(1, 3))), np.array((3,4)), np.array((1,1)), 0.04))
    print(solve(np.array(((2, 3),(1, 4))), np.array((2, -1)), np.array((2.7, -0.7)), 1.0))

main()
