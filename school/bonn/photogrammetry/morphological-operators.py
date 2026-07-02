#!/usr/bin/env python3

"""

Morphological operators are useful for preprocessing an image for other algorithms to do detection/classification.
They can enlarge/shrink/erode/enhance/fuzz/etc features of the image.

"""


import numpy as np
import cv2
import sys

def main():
    if len(sys.argv) != 2:
        print("usage: <image>")
        sys.exit(2)

    gray = cv2.imread(cv2.samples.findFile(sys.argv[1]), cv2.IMREAD_GRAYSCALE)
    if gray is None:
        print('Could not open or find the image:', sys.argv[1])
        sys.exit(1)

    iterations = 10
    for i in range(0, iterations):
        eroded = cv2.erode(gray.copy(), None, iterations=i+1)
        cv2.imwrite("eroded_%d.png" % (i), eroded)

        dilated = cv2.dilate(gray.copy(), None, iterations=i+1)
        cv2.imwrite("dilated_%d.png" % (i), dilated)

        kernel_size = (2*i + 1, 2*i + 1)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, kernel_size)

        opening = cv2.morphologyEx(gray, cv2.MORPH_OPEN, kernel)
        cv2.imwrite("opening_%d.png" % (i), opening)

        closing = cv2.morphologyEx(gray, cv2.MORPH_CLOSE, kernel)
        cv2.imwrite("closing_%d.png" % (i), closing)

        gradient = cv2.morphologyEx(gray, cv2.MORPH_GRADIENT, kernel)
        cv2.imwrite("gradient_%d.png" % (i), gradient)

        rect_kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (13*(i+1), 5*(i+1)))
        blackhat = cv2.morphologyEx(gray, cv2.MORPH_BLACKHAT, rect_kernel)
        tophat = cv2.morphologyEx(gray, cv2.MORPH_TOPHAT, rect_kernel)
        cv2.imwrite("blackhat_%d.png" % (i), blackhat)
        cv2.imwrite("tophat_%d.png" % (i), tophat)

main()
