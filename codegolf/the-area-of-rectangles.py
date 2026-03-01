#!/usr/bin/env python3

"""

Getting the area covered by a rectangle is really easy; just multiply its height by its width. However in this challenge we will be getting the area covered by multiple rectangles. This is equally easy ... so long as the rectangles don't overlap.

If the rectangles don't overlap the total area covered is the sum of the areas of each individual rectangle. However if they do overlap this method will double count the area they intersect.

For example, in the following picture we have 2 rectangles: A rectangle with opposite corners at (3,7) and (9,3) and a rectangle with opposite corners at (8,10) and (14,4).
On their own they cover 24 and 36 square units respectively. However they have an overlap area of 3 units so the total area covered by the both of them is 24+36−3=57

2 Overlapping rectangles

Task
Your task is to take a list of positive integer rectangles as input and output the total area covered by those rectangles.

You may take a rectangle as a pair of pairs representing opposite corners, or as a flattened 4-tuple. You may assume a particular pair of corners in a certain order will be given if you please.

This is code-golf so answers will be scored in bytes with fewer bytes being the goal.

Test cases
[((3,7),(9,3))] -> 24
[((8,10),(14,4))] -> 36
[((3,7),(9,3)),((8,10),(14,4))] -> 57
[((8,10),(14,4)),((3,7),(9,3)),((5,8),(10,3))] -> 61
[((1,1),(8,8)),((2,3),(3,5))] -> 49

"""

def rectareas(a):
    m = {}
    for r in a:
        (x0, y0, x1, y1) = (r[0][0], r[0][1], r[1][0], r[1][1])

        x0, x1 = min(x0, x1), max(x0, x1)
        y0, y1 = min(y0, y1), max(y0, y1)
        for y in range(y0, y1):
            for x in range(x0, x1):
                m[(x, y)] = True
    
    return len(m)

def main():
    assert(rectareas([((3, 7), (9, 3))]) == 24)
    assert(rectareas([((8, 10), (14, 4))]) == 36)
    assert(rectareas([((3, 7), (9, 3)), ((8, 10), (14, 4))]) == 57)
    assert(rectareas([((8, 10), (14, 4)), ((3, 7), (9, 3)), ((5, 8), (10, 3))]) == 61)
    assert(rectareas([((1, 1), (8, 8)), ((2, 3), (3, 5))]) == 49)

main()
