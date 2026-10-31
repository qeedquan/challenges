#!/usr/bin/env python3

"""

https://imgur.com/MuyugjF

You have just started a job at a factory which produces high-purity Methane for industrial and laboratory uses. During your new-employee orientation, you learn a few things about Methane:

A Methane molecule consists of a single Carbon atom surrounded by four Hydrogen atoms.
The "bond length" between each Carbon-Hydrogen pair is a fixed distance of 109 picometers.
Each Hydrogen atom is positioned as far away from each other as possible, since they are all positively-charged and therefore repel each other.
Methane is the only molecule that satisfies these exact geometric properties. If any molecule has the above specific structure, we can be confident that it is Methane.

The factory has received some complaints about contamination in recent batches of Methane and so they have bought a "Hydrogen Detector" machine which will aid in identifying molecules, to determine if a batch may be contaminated with molecules other than Methane.

Unfortunately the machine is designed to be general-purpose, and so it doesn't identify Methane directly. Instead, it takes a given molecule and returns the XYZ coordinate positions (in picometer units) of the Hydrogen atoms in that molecule. It is your job to analyze these Hydrogen coordinate positions and determine if the molecule being examined is indeed Methane.

Problem Statement
Input data will contain the number of testcases in the first line.
The following lines will contain one testcase each, consisting of 12 decimal values corresponding to 4 sets of XYZ coordinates. Values will be ordered as x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4.

Answer should be a string of space-separated values: True if the corresponding testcase is evaluated as Methane and False otherwise.

Example

In this example each line with test-case is further sub-split into four lines (all except first indented) to simplify human reading. To feed these data to your program you may need remove these extra line breaks (depending on your chosen language and input method).

input data:
4
-510.134842 -321.599931 -376.903097
    -554.797813 -237.69143 -312.869955
    -557.183259 -313.151736 -331.771654
    -416.131227 -336.049727 -482.451894
795.762701 718.129006 -691.666904
    809.080133 717.904762 -670.999801
    695.835664 802.776936 -668.257661
    788.564752 696.315454 -583.30922
148.239367 474.968476 -207.042879
    163.248427 388.564664 -69.502184
    210.813323 528.010266 -117.618413
    244.304803 452.918487 -191.785573
-415.268144 -165.722105 -210.016587
    -372.878841 -170.513449 -382.825316
    -510.88644 -265.292058 -322.380427
    -521.299032 -87.757988 -329.856956

answer:
False False False True

"""

import numpy as np

def distance(x1, y1, z1, x2, y2, z2):
    return np.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)

# https://math.stackexchange.com/questions/2585392/equation-of-the-sphere-that-passes-through-4-points
def find_sphere_center(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4):
    A = np.zeros((3, 3))
    A[0][0] = 2*(x2 - x1)
    A[0][1] = 2*(y2 - y1)
    A[0][2] = 2*(z2 - z1)
    A[1][0] = 2*(x3 - x1)
    A[1][1] = 2*(y3 - y1)
    A[1][2] = 2*(z3 - z1)
    A[2][0] = 2*(x4 - x1)
    A[2][1] = 2*(y4 - y1)
    A[2][2] = 2*(z4 - z1)
    
    b = np.zeros((3, 1))
    b[0] = (x2**2 + y2**2 + z2**2) - (x1**2 + y1**2 + z1**2)
    b[1] = (x3**2 + y3**2 + z3**2) - (x1**2 + y1**2 + z1**2)
    b[2] = (x4**2 + y4**2 + z4**2) - (x1**2 + y1**2 + z1**2)

    c = np.dot(np.linalg.inv(A), b)
    return (c[0], c[1], c[2])

"""

All of the hydrogen molecules are equidistant from the carbon molecule.
This can be viewed geometrically as the carbon molecule being the center of a sphere
and all of the hydrogen molecules lying on the surface of that sphere.

Use the above fact to verify that it is a methane molecule:
1. Solve for the position of carbon (find the center of the sphere given 4 points)
2. Check that the center distance to all of the 4 points to be ~109 picometers

"""

def solve(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4):
    cx, cy, cz = find_sphere_center(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4)
    d1 = distance(cx, cy, cz, x1, y1, z1)
    d2 = distance(cx, cy, cz, x2, y2, z2)
    d3 = distance(cx, cy, cz, x3, y3, z3)
    d4 = distance(cx, cy, cz, x4, y4, z4)
    return np.allclose(np.array([d1, d2, d3, d4]), np.array([109]*4))

def main():
    assert(solve(
          -510.134842, -321.599931, -376.903097,
          -554.797813, -237.69143, -312.869955,
          -557.183259, -313.151736, -331.771654,
          -416.131227, -336.049727, -482.451894
    ) == False)

    assert(solve(
          795.762701, 718.129006, -691.666904,
          809.080133, 717.904762, -670.999801,
          695.835664, 802.776936, -668.257661,
          788.564752, 696.315454, -583.30922
    ) == False)

    assert(solve(
          148.239367, 474.968476, -207.042879,
          163.248427, 388.564664, -69.502184,
          210.813323, 528.010266, -117.618413,
          244.304803, 452.918487, -191.785573
    ) == False)

    assert(solve(
        -415.268144, -165.722105, -210.016587,
        -372.878841, -170.513449, -382.825316,
        -510.88644, -265.292058, -322.380427,
        -521.299032, -87.757988, -329.856956
    ) == True)

main()
