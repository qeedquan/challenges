#!/usr/bin/env python3

"""

In convolutional neural networks, one of the main types of layers usually implemented is called the Pooling Layer.
Sometimes, the input image is big (and therefore time consuming especially if you have a big input set) or there is sparse data.
In these cases, the objective of the Pooling Layers is to reduce the spatial dimension of the input matrix (even though you would be sacrificing some information that could be gathered from it).

A Max-Pooling Layer slides a window of a given size k over the input matrix with a given stride s and get the max value in the scanned submatrix.
An example of a max-pooling operation is shown below:

https://i.stack.imgur.com/6WbWu.png

In the example above, we have an input matrix of dimension 4 x 4, a window of size k=2 and a stride of s=2.

Task
Given the stride and the input matrix, output the resulting matrix.

Specs
Both the input matrix and the window will always be square.
The stride and the window size will always be equal, so s=k.
The stride is the same for the horizontal and the vertical direction
The stride s will always be a nonzero natural number that divides the dimension of the input matrix. This guarantees that all values are scanned by the window exactly once.
Input is flexible, read it however you see fit for you.
Standard loopholes are not allowed.

Test Cases

Format:
s, input, output

2, [[2, 9, 3, 8], [0, 1, 5, 5], [5, 7, 2, 6], [8, 8, 3, 6]] --> [[9,8], [8,6]]
1, [[1, 2, 3], [4, 5, 6], [7, 8, 9]] --> [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
4, [[12, 20, 30, 0], [8, 12, 2, 0], [34, 70, 37, 4], [112, 100, 25, 12]] --> [[112]]
3, [[0, 1, 2, 3, 4, 5, 6, 7, 8], [9, 10, 11, 12, 13, 14, 15, 16, 17], [18, 19, 20, 21, 22, 23, 24, 25, 26], [27, 28, 29, 30, 31, 32, 33, 34, 35], [36, 37, 38, 39, 40, 41, 42, 43, 44], [45, 46, 47, 48, 49, 50, 51, 52, 53], [54, 55, 56, 57, 58, 59, 60, 61, 62], [63, 64, 65, 66, 67, 68, 69, 70, 71], [72, 73, 74, 75, 76, 77, 78, 79, 80]] --> [[20, 23, 26], [47, 50, 53], [74, 77, 80]]

This is code-golf, so shortest answers in bytes wins!

"""

import numpy as np

# https://stackoverflow.com/questions/42463172/how-to-perform-max-mean-pooling-on-a-2d-array-using-numpy
def maxpool(m, s):
    w, h = m.shape
    w, h = w//s, h//s
    
    p = m[:w*s, :h*s]
    p = p.reshape(w, s, h, s)
    p = p.max(axis=(1, 3))

    return p

def test(m, s, r):
    p = maxpool(np.array(m), s)
    print(p)
    assert(np.allclose(p, r))

def main():
    test([[2, 9, 3, 8], [0, 1, 5, 5], [5, 7, 2, 6], [8, 8, 3, 6]], 2, [[9, 8], [8, 6]])
    test([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1, [[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    test([[12, 20, 30, 0], [8, 12, 2, 0], [34, 70, 37, 4], [112, 100, 25, 12]], 4, [[112]])
    test([[0, 1, 2, 3, 4, 5, 6, 7, 8], [9, 10, 11, 12, 13, 14, 15, 16, 17], [18, 19, 20, 21, 22, 23, 24, 25, 26], [27, 28, 29, 30, 31, 32, 33, 34, 35], [36, 37, 38, 39, 40, 41, 42, 43, 44], [45, 46, 47, 48, 49, 50, 51, 52, 53], [54, 55, 56, 57, 58, 59, 60, 61, 62], [63, 64, 65, 66, 67, 68, 69, 70, 71], [72, 73, 74, 75, 76, 77, 78, 79, 80]], 3, [[20, 23, 26], [47, 50, 53], [74, 77, 80]])

main()
