#!/usr/bin/env python3

"""

Using Algodoo and Paint I made these six 300×300 monochromatic images of four convenient shapes:

This class of images has the following properties:

https://i.stack.imgur.com/Oa2O1.png
https://i.stack.imgur.com/C6IKR.png
https://i.stack.imgur.com/YZfc6.png
https://i.stack.imgur.com/F1ZDM.png
https://i.stack.imgur.com/chJFi.png
https://i.stack.imgur.com/DLM3y.png

They are always 300×300 pixels, monochromatic (black and white only), and have exactly four white regions that correspond to a square, a circle, a triangle, and a gear.
The shapes never overlap or touch each other, nor do they touch the image border or go out of bounds.
The shapes always have the same size, but they may be rotated and positioned in any way.
(The shapes also have equal areas, though when rastered like this their pixel counts are unlikely to be exactly equivalent.)

Challenge
Write the shortest program or function possible that takes in the filename of such an image and turns all the white pixels...

red (255, 0, 0) if they are in the square.
blue (0, 0, 255) if they are in the circle.
green (0, 255, 0) if they are in the triangle.
yellow (255, 255, 0) if they are in the gear.
e.g.

https://i.stack.imgur.com/EIRiN.png

Details
Your program should work for effectively all possible input images. (Only valid 300×300 monochromatic images will be input.) The six images I have provided are merely examples, you may not hardcode their output into your program.

You may not use computer vision libraries or functions, built-in or external. The point is to do this using your own pixel-level operations. You may use image libraries that simply let you open and modify images (e.g. PIL for Python).

You may use any common lossless image file formats for input and output as long as you stick to the color scheme.

You can take in the image filename as a function argument, from stdin, or from the command line. The output image can be saved to a new file, the same file, or simply displayed.

Scoring
The submission with the fewest bytes wins. I may test submissions with additional images to determine their validity.

"""

import cv2
import sys

def main():
    if len(sys.argv) != 2:
        print("usage: file")
        sys.exit(2)

    image = cv2.imread(sys.argv[1])
    gray = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
    if image is None or gray is None:
        print("Could not load image")
        sys.exit(1)

    # The idea for detecting the shapes is to get the contours of the shapes, which is an approximation to the outline of the shape using polylines
    # The number of polylines vertices gives a rough idea of what shape it is
    contours, _ = cv2.findContours(gray, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
    for contour in contours:
        approx = cv2.approxPolyDP(contour, 0.005*cv2.arcLength(contour, True), True)
        
        shape = "Unknown"
        col = (255, 255, 255)
        if len(approx) == 3:
            shape = "Triangle"
            col = (0, 255, 0)
        elif len(approx) == 4:
            shape = "Square"
            col = (255, 0, 0)
        elif len(approx) < 20:
            shape = "Circle"
            col = (0, 0, 255)
        else:
            shape = "Gear"
            col = (255, 255, 0)

        cv2.drawContours(image, [approx], -1, col[::-1], thickness=cv2.FILLED)

        print(shape, len(approx))
    
    cv2.imshow("Shape Detector", image)
    cv2.waitKey()
    cv2.destroyAllWindows()

main()
