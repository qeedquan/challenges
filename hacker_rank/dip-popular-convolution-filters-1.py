#!/usr/bin/env python3

"""

You are provided with the kernels of six popular convolution filters. Which of these filters will blur an image?

Only enter the integer corresponding to the appropriate filter (1-6)  in the text box. Do not leave any leading or trailing spaces or newlines.

1

    0   0   0
    0   1   0
    0   0   0
2

    -1  -1  -1
    -1   8  -1
    -1  -1  -1
3

     0  -1   0
    -1   5  -1
     0  -1   0
4

    1/16    1/8     1/16
    1/8     1/4     1/8
    1/16    1/8     1/16
5

    -1  0   1
    -2  0   2
    -1  0   1
6

    -1  -2  -1
     0   0   0
     1   2   1

"""

import cv2
import numpy as np
import sys

def usage():
    print("usage: <image>")
    sys.exit(2)

def main():
    if len(sys.argv) != 2:
        usage()

    image = cv2.imread(sys.argv[1])
    if image is None:
        print("Could not read image")
        sys.exit(1)

    # kernel #4 blurs the image
    kernel1 = np.array([[0, 0, 0], [0, 1, 0], [0, 0, 0]])
    kernel2 = np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]])
    kernel3 = np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]])
    kernel4 = np.array([[1/16, 1/8, 1/16], [1/8, 1/4, 1/8], [1/16, 1/8, 1/16]])
    kernel5 = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    kernel6 = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])
    
    index = 1
    for kernel in [kernel1, kernel2, kernel3, kernel4, kernel5, kernel6]:
        output = cv2.filter2D(src=image, ddepth=-1, kernel=kernel)
        cv2.imwrite('kernel%d.jpg' % (index), output)
        index += 1
     
main()
