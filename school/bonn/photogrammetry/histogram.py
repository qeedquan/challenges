#!/usr/bin/env python3

"""

Histogram shows the frequencies of each color channel, it can also be used binning method where if the bins are smaller than the range of the output, they will get put in the closest bin

Histogram equalization is a technique to spread out the histogram (makes it more into a uniform distribution):
This makes the image have better contrast

H(i) = Histogram value at point i
H'(i) = Sum[0 <= j < i] H(j)
equalized(x, y) = H'(src(x, y))

"""

import numpy as np
import cv2
import sys
from matplotlib import pyplot as plt

def histogram(filename):
    img = cv2.imread(filename)
    assert(img is not None)

    for i, col in enumerate(('b', 'g', 'r')):
        histr = cv2.calcHist([img], [i], None, [256], [0, 256])
        plt.plot(histr, color = col)
        plt.xlim([0, 256])

    plt.show()

def equalize(filename):
    img = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
    assert(img is not None)
    equ = cv2.equalizeHist(img)
    cv2.imshow("Original", img)
    cv2.imshow("Equalized", equ)
    cv2.waitKey()
    cv2.destroyAllWindows()

def main():
    if len(sys.argv) < 2:
        print("usage: <image>")
        sys.exit(2)

    histogram(sys.argv[1])
    equalize(sys.argv[1])

main()
