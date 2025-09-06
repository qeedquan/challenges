#!/usr/bin/env python3

"""

Introduction
The Babylonians had a clever method for finding square roots. To find the square root of a number N, you start with a guess, then refine it by repeatedly evaluating a line of computer code (or papyrus scroll equivalent):

guess = (guess + N/guess) / 2
If the guess is smaller than sqrt(N), N/guess must be larger than sqrt(N), so averaging these two terms should get you closer to the true answer. It turns out this method converges fairly quickly to the correct answer:

N = 7
guess = 1
guess = 4.0
guess = 2.875
guess = 2.65489
guess = 2.64577
guess = 2.64575
guess = 2.64575
Extension
Does an equivalent algorithm exist for matrices? Throwing all mathematical rigor aside, if we wish to find the 'square root' of a square matrix M, we may again start with a guess, then refine it by repeatedly evaluating a line of code:

guess = (guess + inverse(guess)*M) / 2
where inverse() is the matrix inverse function, and * is matrix multiplication. Instead of 1, our initial guess is an identity matrix of the appropriate size.

However, convergence is no longer guaranteed - the algorithm diverges for most (but not all) inputs. If M produces a convergent series, it is a Babylonian matrix. Furthermore, the converged value is actually the real square root of the matrix (i.e., guess*guess = M).

Example
Here's an example using a 2x2 matrix, showing convergence of the series:

M = [[7,2],[3,4]]
guess = [[1.,      0.      ], [0.,       1.     ]]  <-- 2x2 identity matrix
guess = [[4.,      1.      ], [1.5,      2.5    ]]
guess = [[2.85294, 0.558824], [0.838235, 2.01471]]
guess = [[2.60335, 0.449328], [0.673992, 1.92936]]
guess = [[2.58956, 0.443035], [0.664553, 1.92501]]
guess = [[2.58952, 0.443016], [0.664523, 1.92499]]
guess = [[2.58952, 0.443016], [0.664523, 1.92499]]
After only a few iterations, the series converges to within 1e-9. After a while, it grows unstable as rounding errors add up, but the initial stability is demonstrated, which is sufficient.

Task
Your job is to find a square matrix M, populated by the integers 1 through 9, which, when given an initial guess of an identity matrix of the proper size, converges successfully. Matrices should be submitted as comma-delimited text (or attached text files, if they are too large), with either brackets or newlines separating subsequent rows.

Rules
Even though the matrix M and starting guess use integers (mainly for display convenience), all arithmetic should be conducted using double-precision floating point. Integer-specific operators (such as 3/2 evaluating to 1) are prohibited.

Divide-by-zero errors, singular matrices, and over/underflows cannot be used to coerce a sequence into 'converging'. The values must be proper floating-point numbers at all times to be considered to have converged.

The algorithm is considered to have converged if an iteration produces no change larger than 1e-9, in any individual cell.

You may use external mathematics libraries for matrix inversion (no need to reinvent the wheel).

Win Condition
The winner is the largest submitted valid Babylonian matrix made of integers 1-9, after one week. You must also submit the code you used to find the matrix.

"""

import numpy as np

"""

@xnor

In general, the procedure converges for matrices with positive real eigenvalues.
This is because if we work in the basis of eigenvectors of the original matrix, it and all its iterates are diagonal matrices, and we can view the procedure as applying the Babylonian method to each individual diagonal entry.
The starting matrix is the still the identity in this basis.

Since the Babylonian method converges only if the original value was positive, the matrix version converges when every eigenvalue is real and positive.
I'm not sure what happens for complex eigenvalues.

I constructed the given matrix to have positive eigenvalues as follows. First, start with the matrix of all ones, which is rank-1, and so has a single eigenvalue (of n) and all others 0.
Then, add the identity, which shifts the eigenvalues up by 1 to get (n+1,1,1,...,1).
Iterating makes the eigenvalues converge to (sqrt(n+1),1,1,...,1). Note that the 1's are unchanged by each iteration.

"""

def gen(n):
    M = np.ones((n, n))
    for i in range(n):
        M[i][i] = 2
    return M

def check(M):
    tries = 1000000
    for i in range(tries):
        N = M
        M = (M + np.dot(np.linalg.inv(M), M)) * 0.5
        print(N)
        if np.allclose(N, M):
            break

def main():
    check(gen(2))

main()
