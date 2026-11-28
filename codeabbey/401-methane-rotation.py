#!/usr/bin/env python3

"""

After solving their contamination issues due to your clever work in Methane Identification, the Methane Factory has decided to reinvest their new profits into research and development.

The engineers on the R&D team have determined that the first step to performing research is the ability to re-orient the molecule in any direction. To achieve this, they have built a machine which aims a laser at the central carbon atom then rotates the molecule around the axis of the laser, clockwise from the perspective of the laser's origin.

At least, the R&D team thinks they have built such a machine. They record the initial coordinates of the hydrogen atoms using the "Hydrogen Detector" from the previous problem, fire the laser from a known direction, rotate the molecule by a known angle, and re-measure the coordinates of the result. However, they're not sure exactly what the "correct" final coordinates are supposed to be, in order to check if their machine is accurate! They turn to you to write a program to provide the expected final coordinates after a rotation.

For simplicity, the 4 points will always have the following initial XYZ coordinates:

(0, 0, 109)
(109 * sqrt(8/9), 0, -109/3)
(-109 * sqrt(2/9), 109 * sqrt(2/3), -109/3)
(-109 * sqrt(2/9), -109 * sqrt(2/3), -109/3)
The laser beam will be fired from the coordinates (Lx, Ly, Lz), aimed directly at the coordinate (0, 0, 0). The 4 points will then rotate Theta degrees around the axis of the laser, clockwise when viewed along the path of the laser.

Problem Statement
Input data will consist of 4 integer values: Lx, Ly, Lz, and Theta.

Answer should be a string of 12 space-separated decimal values corresponding to the coordinates of the 4 points after the indicated rotation, given in the format

x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4
Precision of 1e-7 should be enough. Please maintain the order of the vertices (provided above).

Example

input data:
925093 -215223 312858 133

answer:
70.219302 61.401284 -56.392658
    54.434182 -78.396264 52.64927
    -71.767539 -45.265074 -68.42144
    -52.885945 62.260055 72.164828

"""

import numpy as np
from math import sqrt

def rotate_around_axis(vectors, axis, angle_degrees):
    theta = np.radians(angle_degrees)
    # Normalize axis
    k = axis / np.linalg.norm(axis)
    
    # Rodrigues's formula
    cos_t = np.cos(theta)
    sin_t = np.sin(theta)
    rotated = (vectors * cos_t + 
               np.cross(k, vectors) * sin_t + 
               np.outer(np.dot(vectors, k), k) * (1 - cos_t))
    return rotated

def solve(laser_position, angle_degrees):
    points = np.array([
        [0, 0, 109],
        [109 * sqrt(8/9), 0, -109/3],
        [-109 * sqrt(2/9), 109 * sqrt(2/3), -109/3],
        [-109 * sqrt(2/9), -109 * sqrt(2/3), -109/3]
    ])
    axis = -laser_position
    for point in rotate_around_axis(points, axis, angle_degrees):
        print(point)

def main():
    solve(np.array([925093, -215223, 312858]), 133)

main()
