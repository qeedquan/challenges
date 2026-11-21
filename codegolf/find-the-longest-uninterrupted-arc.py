#!/usr/bin/env python3

"""

The challenge here is to find the longest uninterruped arc around a unit circle with a random amount of points
distributed in random positions around it.
Here is a diagram to assist my explanation:

https://i.sstatic.net/bScM5.png

The red line indicates the largest arc between any two points that is not interrupted by any other points. The challenge is to find the two points on either end of the red line. The green line is simply the straight line distance.

A clarification about what interrupted means: When drawing an arc around the edge of the circle (the red line), this arc should not be intersected by any other point.

Here is a template for the function in C#:

int[] FindPair(double[][] points)
{
     return new[]{ 0, 1}; //Find the indices of the two points
}
The function should return two integers, the indices of the two points on either end of the green line.

Assumptions:

The Length of the points array is arbitrary but more than two. In the example we have:
points[40][]
Each element of the points array contains the x, y position of the point, for example:
points[i] = {x, y}
You can assume that the distance of any given point to the origin at the centre of the circle is always 1.
Notes:

The answer with the smallest Big O algorithm complexity wins. In case of a tie, shorter code wins.
Bonus points for the solution to have the ability to work in more dimensions than two.
I do have a solution, but it is very computationally expensive and only produces the correct answer around 99% of the time.
I am not sure if the problem has a name in mathematics, or a generally accepted solution. If anyone knows of a better name for this problem so that I can have a better title, that would be helpful.
Test case 1:
https://i.sstatic.net/ekAQW.png

Points: {
  { -0.71997 , -0.69400 },
  { 0.88564 , 0.46437 },
  { 0.78145 , -0.62397 },
  { 0.98409 , -0.17765 },
  { 0.88220 , 0.47087 },
  { 0.69938 , 0.71475 },
  { -0.89036 , -0.45526 },
  { -0.70588 , -0.70833 },
  { 0.70507 , 0.70914 },
  { -0.34971 , 0.93686 }
}

Solution:
{6, 9}

Test case 2:
https://i.sstatic.net/14ip4.png

Points: {
  { -0.71038 , 0.70382 },
  { 0.04882 , 0.99881 },
  { -0.53250 , -0.84643 },
  { -0.86814 , -0.49632 },
  { 0.97588 , -0.21829 },
  { 0.73581 , -0.67719 },
  { 0.88413 , -0.46724 },
  { -0.28739 , -0.95781 },
  { -0.68325 , 0.73019 },
  { 0.91879 , 0.39475 },
  { 0.65335 , 0.75706 },
  { -0.21009 , -0.97768 },
  { -0.94542 , -0.32585 },
  { 0.83207 , -0.55467 },
  { 0.99482 , 0.10170 },
  { 0.86228 , 0.50643 },
  { 0.98017 , 0.19817 },
  { 0.67520 , 0.73763 },
  { -0.03982 , -0.99921 },
  { -0.57624 , -0.81728 }
}

Solution: {0, 12}

Invalid example:
https://i.sstatic.net/8RO79.png

This is invalid, because when drawing an arc around the edge of the circle (the red line)
between the two points connected by the green line, this arc is intersected by another point.

"""

from math import *

"""

Ported from @ovs solution

1. convert coords to angle (radians)
2. sort by angle
3. calculate the difference between two adjacent points
4. where is the maximum delta?
5. where were these two points in the original list?

"""

def longest_arc(points):
    angles = [atan2(x, y) for x, y in points]
    sorted_angles = sorted(angles)
    gaps = [
        following - current
        for current, following in zip(sorted_angles, sorted_angles[1:])
    ]

    gaps.append(2*pi - sorted_angles[-1] + sorted_angles[0])

    largest_gap_start = gaps.index(max(gaps))
    endpoints = (sorted_angles * 2)[largest_gap_start : largest_gap_start + 2]
    return sorted(list(map(angles.index, endpoints)))

def main():
    assert(longest_arc([
        [-0.71997, -0.69400],
        [0.88564, 0.46437],
        [0.78145, -0.62397],
        [0.98409, -0.17765],
        [0.88220, 0.47087],
        [0.69938, 0.71475],
        [-0.89036, -0.45526],
        [-0.70588, -0.70833],
        [0.70507, 0.70914],
        [-0.34971, 0.93686],
    ]) == [6, 9])

    assert(longest_arc([
        [-0.71038, 0.70382],
        [0.04882, 0.99881],
        [-0.53250, -0.84643],
        [-0.86814, -0.49632],
        [0.97588, -0.21829],
        [0.73581, -0.67719],
        [0.88413, -0.46724],
        [-0.28739, -0.95781],
        [-0.68325, 0.73019],
        [0.91879, 0.39475],
        [0.65335, 0.75706],
        [-0.21009, -0.97768],
        [-0.94542, -0.32585],
        [0.83207, -0.55467],
        [0.99482, 0.10170],
        [0.86228, 0.50643],
        [0.98017, 0.19817],
        [0.67520, 0.73763],
        [-0.03982, -0.99921],
        [-0.57624, -0.81728],
    ]) == [0, 12])

main()
