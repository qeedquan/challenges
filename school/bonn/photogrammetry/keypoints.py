#!/usr/bin/env python3

"""

Keypoints and descriptor together define common visual features so we can use them to compare different images with each other

Keypoints defines the location in the image

Algorithms

Harris Corner Detector
Shi-Tomasi Corner Detector
Forstner operator
Difference of Gaussians

Generally looks for corner/blob structures due to gradients they have (different gradients in X/Y) so they can be localized precisely

Feature Descriptors for describing keypoints
SIFT   - Scale Invariant Feature Transform
BRIEF  - Binary robust Independent Elementary Features
ORB    - Oriented FAST Rotated BRIEF

"""


import numpy as np
import cv2
import sys

def main():
    if len(sys.argv) != 2:
        print("usage: <image>")
        sys.exit(2)

    image = cv2.imread(cv2.samples.findFile(sys.argv[1]), cv2.IMREAD_COLOR)
    if image is None:
        print('Could not open or find the image:', sys.argv[1])
        sys.exit(1)

    # Detect keypoints
    sift = cv2.SIFT_create()
    keypoints, _ = sift.detectAndCompute(image, None)

    # Draw keypoints
    image_keypoints = np.empty((image.shape[0], image.shape[1], 3), dtype=np.uint8)
    cv2.drawKeypoints(image, keypoints, image_keypoints)
    
    cv2.imshow('Keypoints', image_keypoints)
    cv2.waitKey()
    cv2.destroyAllWindows()

main()
