#!/usr/bin/env python3

"""

https://codeabbey.github.io/data/convex_hull.gif

After farmer John had bought a new field, he decided to errect a fence around it so it could be used as pasture. Most toilsome part of building a fence is driving posts into the ground. So John called farmer Semyon - his neighbor and good friend - for assistance.

It is well known that any labor could be made more cheerful if proper medicine is applied. So John took few bottles of whiskey with him. Semyon was of the same mood and fetched a gallon of vodka from his home. Surely the job was done in most cheerful and speedy way - and at the end of the day two friends returned from the field together very tired, very happy and singing very loudly.

However we know that alcohol affects people in unpredictable manner (that is why we do not recommend drinking while coding!) - the next morning John was surprised to see that:

they with Semyon planted far more posts than it was needed;
posts were placed not by circumference of the field, but rather chaotically.
After some consideration John decided that he can still use few outermost posts for fence while others could remain for some future needs.

Look at the picture above. Green dots here represent posts errected by John and Semyon. Now John wants the fence to be such a polygon that:

it surrounds all posts (so no area is wasted);
it is convex (for otherwise its length would be longer than necessary);
its has corners only on the posts (for making fence corner without a post is tricky).
Problem Statement
You are given coordinates of the posts. Please output indexes of the posts which should be used for fence. Start with the post with maximum value of Y coordinate (uppermost at the picture) and continue in clockwise direction. That is the order in which result should be represented - since, of course, it whould be easier to use for John.

Input data have N - the number of posts in the first line.
Next N lines contain a pair of integers Xi and Yi - coordinates of the posts.
Answer should specify indexes (0-based) of the posts to be choosen for fence, in the order described above.

Example:

input data:
17
113 44
87 101
64 38
52 161
108 28
27 40
145 103
161 89
96 26
83 163
69 11
15 74
50 132
48 107
134 135
37 27
3 88

answer:
9 14 7 4 10 15 5 16 3

"""

import numpy as np
import cv2

def rotate_left(array, amount):
    length = len(array)
    amount = amount % length
    return array[amount:] + array[:amount]

def solve(points):
    points = np.array(points)
    if len(points) < 1:
        return []

    hull = cv2.convexHull(points, clockwise=True, returnPoints=False)
    
    result = []
    start = 0
    for index in range(len(hull)):
        location = hull[index][0]
        if points[location][1] > points[start][1]:
            start = index
        result.append(location) 
    result = rotate_left(result, start - 1)
    
    return list(result)

def main():
    assert(solve([
        [113, 44],
        [87, 101],
        [64, 38],
        [52, 161],
        [108, 28],
        [27, 40],
        [145, 103],
        [161, 89],
        [96, 26],
        [83, 163],
        [69, 11],
        [15, 74],
        [50, 132],
        [48, 107],
        [134, 135],
        [37, 27],
        [3, 88],
    ]) == [9, 14, 7, 4, 10, 15, 5, 16, 3])

main()
