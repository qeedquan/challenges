#!/usr/bin/env python3

"""

Background
The special linear group SL2(Z) is a multiplicative group of 2×2 matrices whose elements are integers and determinant is 1.

It is known that every member of SL2(Z) is a product of some sequence of the following two matrices S and T (reference pdf):
https://kconrad.math.uconn.edu/blurbs/grouptheory/SL(2,Z).pdf

S = [[0, -1], [1, 0]]
T = [[1, 1], [0, 1]]

Note that S^-1 and T^-1 can also be expressed as a product of S and T:

S^-1 = S^3
T^-1 = S^3*T*S*T*S

Task
Given a 2×2 integer matrix whose determinant is 1, express it as the product of a sequence of S and T.

Note that there are infinitely many possible answers for any valid input. Your code needs to just output one answer for a valid input.

Example algorithm
Here is a sample algorithm to find a decomposition; you may use different algorithms to solve the task.

First, note that

M = [[a b] [c d]]
S^-1 * M = [[c d] [-a -b]]
T^-1 * M = [[a-c b-d] [c d]]

Using these two operations, we can use Euclidean-like algorithm to reduce the given matrix down to I, and then construct the chain backwards:

Assume M=(acbd).
Left-multiply S^-1 until both a and c are positive.
Repeat the following until we reach c=0:
Left-multiply T^-q where −c < a-qc <= 0.
Left-multiply S^-1 (exactly once). Now, a and c are positive again, and c is smaller than the original.
Then the result is [[1 b] [0 1]], which is simply T^b. (If b<0, we can use (SSSTSTS)^-b instead.) Now invert all the left-multiplications to get the representation for the original matrix.

Here is an example for
M = [[17 29] [7 12]]

T^-3 * M = [[-4 -7] [7 12]]
S^-1 * T^-3 * M = [[7 12] [4 7]]
T^-2 * S^-1 * T^-3 * M = [[-1 -2] [4 7]]
S^-1 * T^-2 * S^-1 * T^-3 * M = [[4 7] [1 2]]
T^-4 * S^-1 * T^-2 * S^-1 * T^-3 * M = [[0 -1] [1 2]]
S^-1 * T^-4 * S^-1 * T^-2 * S^-1 * T^-3 * M = [[1 2] [0 1]] = T^2
M = T^3 * S * T^2 * S * T^4 * S * T^2

Input and output
You can take the input matrix in any suitable way, e.g. a matrix, a 4-element vector, two complex numbers, etc. You can assume that the input is always valid, i.e. the four elements are integers and the determinant is 1.

The output is a sequence of two distinct values (or objects) that represent S and T respectively. All of the following are accepted (using an example output STTS):

"STTS"  # string
"0110"  # digit string
[0, 1, 1, 0]  # array of 0s and 1s
['S', 'T', 'T', 'S']  # array of characters
[(0,-1,1,0), (1,1,0,1), (1,1,0,1), (0,-1,1,0)]  # array of tuples
Also, by definition of empty product, an empty sequence (e.g. "" or []) is a valid answer when the input is I.

Scoring and winning criterion
Standard code-golf rules apply. Shortest code in bytes wins.

Example I/O
Note that every valid input has infinitely many correct answers, so your code's output may differ from the sample outputs shown here.

[[1 0]
 [0 1]] -> empty or SSSS or SSSTSTST or ...

[[0 -1]
 [1  0]] -> S

[[1 10]
 [0  1]] -> TTTTTTTTTT

[[17 29]
 [ 7 12]] -> TTTSTTSTTTTSTT

[[-1  -7]
 [-2 -15]] -> SSTSTTSTSSTTTTSSTTT

"""

import numpy as np

"""

@xnor

Given [[a b] [c d]]
we choose whether to apply S^-1 or T^-1 based on a simple condition: whether ac+bd>0. Repeating this enough times takes any matrix to the identity.

"""

def sl2dec(a, b, c, d):
    if (a, b, c, d) == (1, 0, 0, 1):
        return ""
    if a*c + b*d > 0:
        return "T" + sl2dec(a-c, b-d, c, d)
    return "S" + sl2dec(c, d, -a, -b)

def apply(s):
    M = [[1, 0], [0, 1]]
    S = [[0, -1], [1, 0]]
    T = [[1, 1], [0, 1]]
    for c in s:
        if c == 'S':
            M = np.dot(M, S)
        elif c == 'T':
            M = np.dot(M, T)
    return (M[0][0], M[0][1], M[1][0], M[1][1])

def test(a, b, c, d):
    s = sl2dec(a, b, c, d)
    assert((a, b, c, d) == apply(s))

def main():
    test(1, 0, 0, 1)
    test(0, -1, 1, 0)
    test(1, 10, 0, 1)
    test(17, 29, 7, 12)
    test(-1, -7, -2, -15)

main()
