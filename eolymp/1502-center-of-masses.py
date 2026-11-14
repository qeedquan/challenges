#!/usr/bin/env python3

"""

Find the center of mass of a convex polygon carved from wood.

Input
The input consists of multiple test cases. Each test case begins with the integer n (n≤100), the number of vertices of the polygon.
This is followed by n pairs of integers, each pair representing the x and y coordinates of a vertex (in any order).
The last polygon has n<3 vertices and should not be processed.

Output
For each polygon, output a single line containing the coordinates x and y of its center of mass, each rounded to three decimal places.

Examples

Input #1
4 0 1 1 1 0 0 1 0
3 1 2 1 0 0 0
7
-4 -4
-6 -3
-4 -10
-7 -12
-9 -8
-3 -6
-8 -3
1

Answer #1
0.500 0.500
0.667 0.667
-6.102 -7.089

"""

import numpy as np

def sort_counterclockwise(points):
    coords = np.array(points)
    cx, cy = np.mean(coords, axis=0)
    angles = np.arctan2(coords[:, 1] - cy, coords[:, 0] - cx)
    sorted_indices = np.argsort(angles)
    return coords[sorted_indices].tolist()

def centroid(points):
    points = sort_counterclockwise(points)
    center = [0, 0]
    area = 0
    for i in range(len(points)):
        j = (i + 1) % len(points)
        d = (points[i][0] * points[j][1]) - (points[j][0] * points[i][1])
        center[0] += (points[i][0] + points[j][0]) * d
        center[1] += (points[i][1] + points[j][1]) * d
        area += d
    area *= 0.5
    center[0] /= (6 * area)
    center[1] /= (6 * area)
    return (center[0], center[1])

def solve(points):
    return centroid(points)

def main():
    points_1 = [(0, 1), (1, 1), (0, 0), (1, 0)]
    points_2 = [(1, 2), (1, 0), (0, 0)]
    points_3 = [(-4, -4), (-6, -3), (-4, -10), (-7, -12), (-9, -8), (-3, -6), (-8, -3)]
    
    print(solve(points_1))
    print(solve(points_2))
    print(solve(points_3))

main()
