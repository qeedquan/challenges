#!/usr/bin/env python3

"""

Task
Given an integer matrix M and a modulus m, find an inverse of M modulo m. If the matrix M is not invertible modulo m, the behaviour is left unspecified.

Matrix inverse
If M is a square matrix, its inverse exists if and only if its determinant is not 0. Similarly, when we are talking about matrices modulo m, the inverse of M will exist if and only of the determinant of M is invertible modulo m, which happens when the determinant is coprime with m.

The inverse of M is a square matrix inv(M) such that M*inv(M) = inv(M)*M = I, where

I = Identity(M)

has the same shape of M and is called the identity matrix. As an example, consider the first test case, where [[22, 43], [29, 37]] is the inverse of [[26, 16], [38, 41]] mod 45:

[26 16] * [22 43] = [1036 1710] = [1 0] mod 45
[38 41]   [29 37]   [2025 3151]   [0 1]

Input
A square matrix M with integer values between 0 and m-1, inclusive, and a positive integer m > 1. The matrix may be given in any sensible format, including

a list of lists, where the inner lists encode the rows, like M = [[1, 2], [3, 4]], or a flattened version, like M = [1, 2, 3, 4]
a list of lists, where the inner lists encode the columns, like M = [[1, 3], [2, 4]], or a flattened version, like M = [1, 3, 2, 4]
where these encode the matrix

[1 2]
[3 4]

The integer m giving the modulus.

You may also accept the size of the matrix as input.

The inputs can be given in any order.

Output
A matrix representing the inverse of M modulo m. You may assume such an inverse exists. Preferable format is for each matrix entry ai,j to satisfy 0≤ai,j<m but this is just to make it easier to compare with the test cases.

Test cases
45, [[26, 16], [38, 41]] -> [[22, 43], [29, 37]]

39, [[29, 50], [29, 1]] -> [[16, 19], [4, 35]]

35, [[24, 14], [48, 45]] -> [[5, 7], [4, 33]]

53, [[43, 20], [15, 8]] -> [[5, 14], [37, 7]]

49, [[15, 11, 30], [20, 12, 40], [33, 25, 2]] -> [[33, 28, 23], [25, 18, 0], [25, 48, 13]]

37, [[8, 9, 22, 17], [24, 30, 30, 19], [39, 8, 45, 23], [5, 30, 22, 33]] -> [[18, 17, 26, 20], [29, 36, 23, 1], [19, 0, 9, 3], [30, 23, 14, 21]]
This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

This is the fourth challenge of the RGS Golfing Showdown. If you want to participate in the competition, you have 96 hours to submit your eligible answers. Remember there is still 300 reputation in prizes! (See 6 of the rules)

Also, as per section 4 of the rules in the linked meta post, the "restricted languages" for this third challenge are only Jelly, V (vim) and 05AB1E so submissions in these languages are not eligible for the final prize. But they can still be posted!!

Otherwise, this is still a regular code-golf challenge, so enjoy!

"""

from sympy import Matrix

def invmod(M, n):
    return M.inv_mod(n)

def main():
    assert(invmod(Matrix([[26, 16], [38, 41]]), 45) == Matrix([[22, 43], [29, 37]]))
    assert(invmod(Matrix([[29, 50], [29, 1]]), 39) == Matrix([[16, 19], [4, 35]]))
    assert(invmod(Matrix([[24, 14], [48, 45]]), 35) == Matrix([[5, 7], [4, 33]]))
    assert(invmod(Matrix([[43, 20], [15, 8]]), 53) == Matrix([[5, 14], [37, 7]]))
    assert(invmod(Matrix([[15, 11, 30], [20, 12, 40], [33, 25, 2]]), 49) == Matrix([[33, 28, 23], [25, 18, 0], [25, 48, 13]]))
    assert(invmod(Matrix([[8, 9, 22, 17], [24, 30, 30, 19], [39, 8, 45, 23], [5, 30, 22, 33]]), 37) == Matrix([[18, 17, 26, 20], [29, 36, 23, 1], [19, 0, 9, 3], [30, 23, 14, 21]]))

main()
