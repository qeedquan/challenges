#!/usr/bin/env python3

"""

Almost all digital camera sensors are organized in a grid of photosensors. Each photo sensor is sensitive for one of the primary colors: red, green and blue. The way those photo sensors are organized is called the Bayer filter, after its inventor, Bryce Bayer of Eastman Kodak. After an image is taken, four photo sensors compose the RGB value of one pixel in the resulting image. Your task is to reverse that process and colorize the resulting pixels according to their filter color. For the sake of simplicity, we will ignore gamma correction.

For example: the "normal" forward Bayer filter steps are:

a lightray with a Pantone Beeswax color hits the sensor;
the BGGR (Blue - Green / Green - Red) filter decomposes this into four rays.
The four rays hit the sensor, which reads: 81 - 168 / 168 - 235 (sensor values range from 0 - 255);
The Bayer filter translates this to one RGB pixel with color (235, 168, 81).
The reverse Bayer filter steps are:

RGB pixel with color (235, 168, 81) is split into four pixels with RGB values: (0,0,81) - (0,168,0) / (0,168,0) - (235,0,0).
Challenge
You should write the shortest possible function or program that does the following:

Take a filename as in input and output the DeBayered image.
The output may be written to a file or displayed on the screen.
The output must be twice the width and twice the height of the original image.
Each pixel of the input image must be mapped according to the BGGR (Blue - Green / Green - Red) Bayer filter pattern as explained graphically in the following picture:

Bayer Filter - BGGR - graphical explanation

We'll assume that both green photosensors receive the same signal, so both the G values in the Bayer matrix are equal to the G value in the RGB image.

You may not return an array representation of the resulting image. The output must be an image or a file (in any suitable image format) that can be displayed as an image.
Example
Given this file as an input:

Mona Lisa
https://i.stack.imgur.com/9PrQc.jpg

The resulting image should be:

DeBayered Mona Lisa
https://i.imgur.com/UYTi1uB.png

Reference python implementation:
from PIL import Image
import np
import sys

if len(sys.argv) == 1:
    print "Usage: python DeByer.py <<image_filename>>"
    sys.exit()

# Open image and put it in a np array
srcArray = np.array(Image.open(sys.argv[1]), dtype=np.uint8)
w, h, _ = srcArray.shape

# Create target array, twice the size of the original image
resArray = np.zeros((2*w, 2*h, 3), dtype=np.uint8)

# Map the RGB values in the original picture according to the BGGR pattern#

# Blue
resArray[::2, ::2, 2] = srcArray[:, :, 2]

# Green (top row of the Bayer matrix)
resArray[1::2, ::2, 1] = srcArray[:, :, 1]

# Green (bottom row of the Bayer matrix)
resArray[::2, 1::2, 1] = srcArray[:, :, 1]

# Red
resArray[1::2, 1::2, 0] = srcArray[:, :, 0]

# Save the imgage
Image.fromarray(resArray, "RGB").save("output.png")
Remember: this is a code-golf, so shortest code wins!

"""

from PIL import Image
import numpy as np
import sys

def usage():
    print("usage: <input> <output>")
    sys.exit(2)

def main():
    if len(sys.argv) != 3:
        usage()

    src = np.array(Image.open(sys.argv[1]), dtype=np.uint8)
    width, height, _ = src.shape

    dst = np.zeros((2*width, 2*height, 3), dtype=np.uint8)
    dst[::2, ::2, 2] = src[:, :, 2]
    dst[1::2, ::2, 1] = src[:, :, 1]
    dst[::2, 1::2, 1] = src[:, :, 1]
    dst[1::2, 1::2, 0] = src[:, :, 0]

    img = Image.fromarray(dst, "RGB")
    img.save(sys.argv[2])

main()

