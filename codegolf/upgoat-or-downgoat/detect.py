#!/usr/bin/env python3

"""

Given an image of a goat, your program should best try to identify whether the goat is upside down, or not.

Examples
These are examples of what the input may be. Not actual inputs

Input:
https://i.sstatic.net/p5yj4.jpg

Output: Downgoat

Spec
Your program should be at most 30,000 bytes

The input will contain the full goat
The picture will always contain a goat
If the goat is upside down, output Downgoat, otherwise Upgoat
Input will be however you can take an image as an input (file name, base64 of the image, etc.)

Don't rely on the image name or other metadata for containing "Upgoat" or "Downgoat" as the gist file names are just for reference.

Please don't hardcode. It's boring, I can't enforce it completely but I can ask nicely.

Test Cases
Gist with images. images beginning with downgoat have Downgoat output and images beginning with upgoat have Upgoat output.

Second Batch of Test Cases Make sure to test your images on all the test cases. These images are a jpgs. The image sizes do vary but not by that much.

Note: A few test cases may be added before accepting an answer to avoid answers which hardcode and to check the general performance of the program.

Bonus points for getting my avatar correct :P

Scoring
Score is a percent which can be calculated by: (number_correct / total) * 100

"""

"""

Ported from @qwr solution

My original idea was to detect the vertical lines of the goat's legs and determine its vertical position relative to the body and horizon.

As it turns out, in all the images, the ground is extremely noisy, making lots of Canny edge detection output and corresponding detected lines from the Hough transform. My strategy was then to determine whether the horizontal lines lie in the upper or lower half of the image, which was enough to solve the problem.

Addendum
It turns out median blur and adaptive Gaussian thresholding before the Hough Transform works much better than Canny edge detection, mostly since median blur is good in noisy areas. However the problems of my original approach immediately are clear: prominent background lines are detected, as well as the goat's face in some pictures.

"""

import cv2
import numpy as np

def is_upgoat(path):
    img = cv2.imread(path)
    height, width, channels = img.shape
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    edges = cv2.Canny(gray, 100, 200, apertureSize=3)

    lines = cv2.HoughLines(edges, 1, np.pi/180, 200, None, 0, 0, np.pi/2-0.5, np.pi/2+0.5)
    rho_small = 0

    for line in lines:
        rho, theta = line[0]
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a*rho
        y0 = b*rho
        x1 = int(x0 + 5000*(-b))
        y1 = int(y0 + 5000*(a))
        x2 = int(x0 - 5000*(-b))
        y2 = int(y0 - 5000*(a))

        if rho/height < 1/2: rho_small += 1
        cv2.line(img,(x1,y1),(x2,y2),(0,0,255),1, cv2.LINE_AA)

    return rho_small/len(lines) < 1/2

def is_upgoat2(path):
    img = cv2.imread(path)
    #height, width, channels = img.shape
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.medianBlur(gray, 19)
    thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                                   cv2.THRESH_BINARY_INV, 11, 2)

    lines = cv2.HoughLinesP(thresh, 1, np.pi / 180, threshold=100,
                            minLineLength=50, maxLineGap=10)

    vert_y = []
    horiz_y = []
    for line in lines:
        x1, y1, x2, y2 = line[0]
        # Vertical lines
        if x1 == x2 or abs((y2-y1)/(x2-x1)) > 3:
            vert_y.append((y1+y2)/2)
            cv2.line(img, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # Horizontal lines
        if x1 != x2 and abs((y2-y1)/(x2-x1)) < 1/3:
            horiz_y.append((y1+y2)/2)
            cv2.line(img, (x1, y1), (x2, y2), (0, 0, 255), 2)


    print(np.median(vert_y), np.median(horiz_y))

def main():
    for i in range(1, 10):
        downgoat_path = "downgoat" + str(i) + ".jpg"
        print(downgoat_path, is_upgoat(downgoat_path))

    for i in range(1, 10):
        upgoat_path = "upgoat" + str(i) + ".jpg"
        print(upgoat_path, is_upgoat(upgoat_path))

main()

