#!/usr/bin/env python3

"""

Consider these 10 images of various amounts of uncooked grains of white rice.
THESE ARE ONLY THUMBNAILS. Click an image to view it at full size.

A: https://i.sstatic.net/8T6W2.jpg
B: https://i.sstatic.net/pgWt1.jpg
C: https://i.sstatic.net/M0K5w.jpg
D: https://i.sstatic.net/eUFNo.jpg
E: https://i.sstatic.net/2TFdi.jpg
F: https://i.sstatic.net/wX48v.jpg
G: https://i.sstatic.net/eXCGt.jpg
H: https://i.sstatic.net/9na4J.jpg
I: https://i.sstatic.net/UMP9V.jpg
J: https://i.sstatic.net/nP3Hr.jpg

Grain Counts: A: 3, B: 5, C: 12, D: 25, E: 50, F: 83, G: 120, H:150, I: 151, J: 200

Notice that...

The grains may touch each other but they never overlap. The layout of grains is never more than one grain high.
The images have different dimensions but the scale of the rice in all of them is consistent because the camera and background were stationary.
The grains never go out of bounds or touch the image boundaries.
The background is always the same consistent shade of yellowish-white.
Small and large grains are counted alike as one grain each.
These 5 points are guarantees for all images of this sort.

Challenge
Write a program that takes in such images and, as accurately as possible, counts the number of grains of rice.

Your program should take the filename of the image and print the number of grains it calculates. Your program must work for at least one of these image file formats: JPEG, Bitmap, PNG, GIF, TIFF (right now the images are all JPEGs).

You may use image processing and computer vision libraries.

You may not hardcode the outputs of the 10 example images. Your algorithm should be applicable to all similar rice-grain images. It should be able to run in less than 5 minutes on a decent modern computer if the image area is less than 2000*2000 pixels and there are fewer than 300 grains of rice.

Scoring
For each of the 10 images take the absolute value of the actual number of grains minus the number of grains your program predicts. Sum these absolute values to get your score. The lowest score wins. A score of 0 is perfect.

In case of ties the highest voted answer wins. I may test your program on additional images to verify its validity and accuracy.

"""

import sys
from PIL import Image

"""

Ported from @Ell solution

This solution, like Falko's one, is based on measuring the "foreground" area and dividing it by the average grain area.

In fact, what this program tries to detect is the background, not so much as the foreground.
Using the fact that rice grains never touch the image boundary, the program starts by flood-filling white at the top-left corner.
The flood-fill algorithm paints adjacent pixels if the difference between theirs and the current pixel's brightness is within a certain threshold, thus adjusting to gradual change in the background color.

Finally, the area of each continuous foreground (i.e. non-white) region is divided by the average, precalculated, grain area,
giving us an estimate of the grain count in the said region.
The sum of these quantities is the result.
Initially, we did the same thing for the entire foreground area as a whole, but this approach is, literally, more fine-grained.

"""

def detect(name):
    I = Image.open(name)
    W, H = I.size
    A = W * H
    D = [sum(c) for c in I.getdata()]
    Bh = [0] * H
    Ch = [0] * H
    Bv = [0] * W
    Cv = [0] * W

    # Flood-fill
    Background = 3*255 + 1
    S = [0]
    while S:
        i = S.pop()
        c = D[i]
        if c != Background:
            D[i] = Background
            Bh[i // W] += c
            Ch[i // W] += 1
            Bv[i % W] += c
            Cv[i % W] += 1
            S += [(i + o) % A for o in [1, -1, W, -W] if abs(D[(i + o) % A] - c) < 10]

    # Eliminate "trapped" areas
    for i in range(H):
        Bh[i] /= float(max(Ch[i], 1))

    for i in range(W):
        Bv[i] /= float(max(Cv[i], 1))

    for i in range(A):
        a = (Bh[i // W] + Bv[i % W]) / 2
        if D[i] >= a:
            D[i] = Background

    # Estimate grain count
    Foreground = -1
    avg_grain_area = 3038.38
    grain_count = 0
    for i in range(A):
        if Foreground < D[i] < Background:
            S = [i]
            area = 0
            while S:
                j = S.pop() % A
                if Foreground < D[j] < Background:
                    D[j] = Foreground
                    area += 1
                    S += [j - 1, j + 1, j - W, j + W]
            grain_count += int(round(area / avg_grain_area))

    return grain_count

def main():
    if len(sys.argv) < 2:
        print("usage: <image>")
        exit(2)
    
    print(detect(sys.argv[1]))

main()
