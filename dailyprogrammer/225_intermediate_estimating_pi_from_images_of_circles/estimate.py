#!/usr/bin/env python3

"""

Description
In modern times, if we wish to calculate the value of pi to some precision, there are plenty of mathematical formulas that you can use to get the value. Leibniz formula for pi and the solution to the Basel problem are two of the most famous ones, though both converge very slowly. Modern day computers that attempt to set the world record for digits of pi generally use some variation on Ramanujan's formula, which converges very rapidly.

However, back in the good old days, we didn't know of these formulas. They all depend on analysis and infinite sums which mathematicians had no skill at manipulating. Back then, the way you estimated pi was less accurate but more straight-forward: you drew a circle, measured it, and calculated pi from that.

Today, we're going to honor those mathematicians of old. You will be given an image of a black circle on white background, and using the pixel data in the image, you are to come up with an estimate for pi.

For those of you who have forgotten your formulas for circles, the formula for the area of a circle is as follows:

A = pi * r^2
In other words, to calculate the area of a circle, multiply pi by the square of the radius.

Formal inputs & outputs
Inputs
As input, you will be given an image that contains a black circle on white background (those are the only two colors in the image, there's no anti-aliasing or anything). The image provided will be in PNG format, but if you find it difficult to import and analyze PNG images in your language, you're welcome to use a tool like ImageMagick to convert it to a format you prefer (the Netpbm family of formats are famously easy for a computers to parse).

Note that for challenge input 1, the height and width of the image itself is equal to the diameter of the circle, but that is not true for challenge input #2. It is highly encouraged (but not required) that you to try and write a program that works for both challenge inputs.

Outputs
You will output a single line containing your estimate of pi based on the image. It doesn't have to be very exact in all decimal places, just the closest value you can get by looking at the image provided.

Challenge inputs
Input 1
This image

Input 2
This image

Bonus
If you really want to test your test your skills, extract an estimate of pi from this image

Notes
As always, if you have a challenge suggestion, head on over to r/dailyprogrammer_ideas and suggest it!

Also, for you historians out there who are going to comment "that's not how Archimedes did it!": yes, I know that other methods were used, but lets just forget that for the purposes of this problem :)

"""

import cv2
import numpy as np

def detect(name, params):
    blursize = params["blursize"]
    mindist = params["mindist"]
    param1 = params["param1"]
    param2 = params["param2"]

    gray = cv2.imread(name, cv2.IMREAD_GRAYSCALE)
    gray = 255 - gray
    blur = cv2.blur(gray, (blursize, blursize))
    max_radius = max(gray.shape)

    areas = []
    radiuses = []
    circles = cv2.HoughCircles(blur, cv2.HOUGH_GRADIENT, 1, mindist, param1=param1, param2=param2, minRadius=1, maxRadius=max_radius)
    if circles is None:
        print("No circles detected")
        return

    for circle in circles:
        if len(circle) == 0:
                continue

        for x, y, r in circle:
            radiuses.append(r)

    contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        areas.append(cv2.contourArea(contour))

    if len(radiuses) != len(areas):
        print("Mismatch number of radiuses and areas detection: %d != %d" % (len(radiuses), len(areas)))
        return

    radiuses.sort()
    areas.sort()

    print("%s: Detected:" % name)
    for i in range(len(radiuses)):
        R, A = radiuses[i], areas[i]
        print("Radius: %f Area: %f PI: %f" % (R, A, A/R**2))
    print()

def main():
    params = { "blursize": 9, "mindist": 20, "param1": 300, "param2": 120 }
    detect("circle_1.png", params)
    detect("circle_2.png", params)
    detect("multiple_circles_1.png", params)

main()
