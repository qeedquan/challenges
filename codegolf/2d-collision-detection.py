#!/usr/bin/env python3

"""

This challenge is based on actual collision detection I had to write for a simple game recently.

Write a program or function which, given two objects, returns a truthy or falsy value depending on whether the two objects are in collision (i.e. intersect) or not.

You need to support three types of objects:

Line segments: represented by 4 floats, indicating the two endpoints, i.e. (x1,y1) and (x2,y2). You may assume that the endpoints are not identical (so the line segment is not degenerate).
Discs: i.e. filled circles, represented by 3 floats, two for the centre (x,y) and one (positive) for the radius r.
Cavities: these are a disc's complement. That is, a cavity fills all of 2D space, except a circular region, specified by a centre and radius.
Your program or function will receive two such objects in the form of an identifying integer (of your choice) and their 3 or 4 floats. You can take input via STDIN, ARGV or function argument. You may represent the input in any convenient form that is not preprocessed, e.g. 8 to 10 individual numbers, two comma-separated list of values or two lists. The result can be returned or written to STDOUT.

You may assume that the objects are either at least 10-10 length units apart or intersect by that much, so you don't need to worry about the limitations of floating point types.

This is code golf, so the shortest answer (in bytes) wins.

Test Cases
Representing line segments with 0, discs with 1 and cavities with 2, using a list-based input format, the following should all produce a truthy output:

[0,[0,0],[2,2]], [0,[1,0],[2,4]]        # Crossing line segments
[0,[0.5,0],[-0.5,0]], [1,[0,0],1]       # Line contained in a disc
[0,[0.5,0],[1.5,0]], [1,[0,0],1]        # Line partially within disc
[0,[-1.5,0.5],[1.5,0.5]], [1,[0,0],1]   # Line cutting through disc
[0,[0.5,2],[-0.5,2]], [2,[0,0],1]       # Line outside cavity
[0,[0.5,0],[1.5,0]], [2,[0,0],1]        # Line partially outside cavity
[0,[-1.5,0.5],[1.5,0.5]], [2,[0,0],1]   # Line cutting through cavity
[1,[0,0],1], [1,[0,0],2]                # Disc contained within another
[1,[0,0],1.1], [1,[2,0],1.1]            # Intersecting discs
[1,[3,0],1], [2,[0,0],1]                # Disc outside cavity
[1,[1,0],0.1], [2,[0,0],1]              # Disc partially outside cavity
[1,[0,0],2], [2,[0,0],1]                # Disc encircling cavity
[2,[0,0],1], [2,[0,0],1]                # Any two cavities intersect
[2,[-1,0],1], [2,[1,0],1]               # Any two cavities intersect
while the following should all result in a falsy output

[0,[0,0],[1,0]], [0,[0,1],[1,1]]        # Parallel lines
[0,[-2,0],[-1,0]], [0,[1,0],[2,0]]      # Collinear non-overlapping lines
[0,[0,0],[2,0]], [0,[1,1],[1,2]]        # Intersection outside one segment
[0,[0,0],[1,0]], [0,[2,1],[2,3]]        # Intersection outside both segments
[0,[-1,2],[1,2]], [1,[0,0],1]           # Line passes outside disc
[0,[2,0],[3,0]], [1,[0,0],1]            # Circle lies outside segment
[0,[-0.5,0.5],[0.5,-0.5]], [2,[0,0],1]  # Line inside cavity
[1,[-1,0],1], [1,[1,1],0.5]             # Non-intersecting circles
[1,[0.5,0],0.1], [2,[0,0],1]            # Circle contained within cavity

"""

import math
import random

"""

Ported from @QuadmasterXLII solution

I'm using a pretty garbage algorithm compared to all these geometric tricks,
but it gets the right answers even though it takes a over a minute to get through the test cases.
The big advantage is that I only have to write the three scoring functions, and the hillclimbing takes care of all the edge cases.

"""

def norm(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def line_weight(a, b, p):
    l1 = norm(a, p)
    l2 = norm(b, p)
    return min(l1, l2, l1 + l2 - norm(a, b))

def circle_weight(a, r, p):
    return max(0, norm(a, p) - r)

def void_weight(a, r, p):
    return max(0, r - norm(a, p))

def weight(f1, f2, s1, s2, p):
    return f1(s1[1], s1[2], p) + f2(s2[1], s2[2], p)

def check_collision(s1, s2):
    a = [line_weight, circle_weight, void_weight]
    f1 = a[s1[0]]
    f2 = a[s2[0]]
    p = (0.0, 0.0)
    w = 0
    for i in a * 1000:
        w = weight(f1, f2, s1, s2, p)
        p2 = ((random.random() - 0.5) * w + p[0], (random.random() - 0.5) * w + p[1])
        if weight(f1, f2, s1, s2, p2) < w:
            p = p2
    if w < 0.0001:
        return True
    return False

tests = [
    [0, [0, 0], [2, 2]],
    [0, [1, 0], [2, 4]],  # Crossing line segments
    [0, [0.5, 0], [-0.5, 0]],
    [1, [0, 0], 1],  # Line contained in a disc
    [0, [0.5, 0], [1.5, 0]],
    [1, [0, 0], 1],  # Line partially within disc
    [0, [-1.5, 0.5], [1.5, 0.5]],
    [1, [0, 0], 1],  # Line cutting through disc
    [0, [0.5, 2], [-0.5, 2]],
    [2, [0, 0], 1],  # Line outside cavity
    [0, [0.5, 0], [1.5, 0]],
    [2, [0, 0], 1],  # Line partially outside cavity
    [0, [-1.5, 0.5], [1.5, 0.5]],
    [2, [0, 0], 1],  # Line cutting through cavity
    [1, [0, 0], 1],
    [1, [0, 0], 2],  # Disc contained within another
    [1, [0, 0], 1.1],
    [1, [2, 0], 1.1],  # Intersecting discs
    [1, [3, 0], 1],
    [2, [0, 0], 1],  # Disc outside cavity
    [1, [1, 0], 0.1],
    [2, [0, 0], 1],  # Disc partially outside cavity
    [1, [0, 0], 2],
    [2, [0, 0], 1],  # Disc encircling cavity
    [2, [0, 0], 1],
    [2, [0, 0], 1],  # Any two cavities intersect
    [2, [-1, 0], 1],
    [2, [1, 0], 1],  # Any two cavities intersect
    [0, [0, 0], [1, 0]],
    
    [0, [0, 1], [1, 1]],  # Parallel lines
    [0, [-2, 0], [-1, 0]],
    [0, [1, 0], [2, 0]],  # Collinear non-overlapping lines
    [0, [0, 0], [2, 0]],
    [0, [1, 1], [1, 2]],  # Intersection outside one segment
    [0, [0, 0], [1, 0]],
    [0, [2, 1], [2, 3]],  # Intersection outside both segments
    [0, [-1, 2], [1, 2]],
    [1, [0, 0], 1],  # Line passes outside disc
    [0, [2, 0], [3, 0]],
    [1, [0, 0], 1],  # Circle lies outside segment
    [0, [-0.5, 0.5], [0.5, -0.5]],
    [2, [0, 0], 1],  # Line inside cavity
    [1, [-1, 0], 1],
    [1, [1, 1], 0.5],  # Non-intersecting circles
    [1, [0.5, 0], 0.1],
    [2, [0, 0], 1],  # Circle contained within cavity
]

for a, b in zip(tests[0::2], tests[1::2]):
    print(check_collision(a, b))

