#!/usr/bin/env python3

"""

Given an integer array of at least two elements, output the Matrix-Vector (defined below) of the array.

To compute the Matrix-Vector, first rotate through the size-n input array to create a matrix of size n x n, with the first element of the array following the main diagonal.
This forms the matrix portion. For the vector, flip the input array vertically. Then perform normal matrix multiplication. The output vector is the result.

For example,

a = [1, 2, 3]
First, rotate the array two times to the right, to obtain [3, 1, 2] and [2, 3, 1], then stack them to form a 3x3 matrix

[[1, 2, 3]
 [3, 1, 2]
 [2, 3, 1]]
Next, flip the array vertically to form the vector

[[1, 2, 3]    [[1]
 [3, 1, 2]  x  [2]
 [2, 3, 1]]    [3]]
Perform usual matrix multiplication

[[1, 2, 3]    [[1]    [[1+4+9]    [[14]
 [3, 1, 2]  x  [2]  =  [3+2+6]  =  [11]
 [2, 3, 1]]    [3]]    [2+6+3]]    [11]]
And the output is [14, 11, 11] or [[14], [11], [11]] (your choice of whether it's flattened or not).

Example #2
a = [2, 5, 8, 3]

[[2, 5, 8, 3]    [[2]    [[4+25+64+9]     [[102]
 [3, 2, 5, 8]  x  [5]  =  [6+10+40+24]  =  [80]
 [8, 3, 2, 5]     [8]     [16+15+16+15]    [62]
 [5, 8, 3, 2]]    [3]]    [10+40+24+6]]    [80]]

[102, 80, 62, 80]

Rules
The input and output can be assumed to fit in your language's native integer type.
The input and output can be given in any convenient format.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

import numpy as np

def mvmul(a):
    m = []
    for i in range(len(a)):
        m.append(np.roll(a, i))
    return np.dot(m, np.array(a))

def main():
    assert(np.array_equal(mvmul([1, 2, 3]), np.array([14, 11, 11])))
    assert(np.array_equal(mvmul([2, 5, 8, 3]), np.array([102, 80, 62, 80])))

main()
