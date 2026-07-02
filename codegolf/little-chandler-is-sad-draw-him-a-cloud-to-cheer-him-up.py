#!/usr/bin/env python3

"""

Little Chandler is sad. Draw him a cloud to cheer him up.
Note: Drawing a cloud won't actually cheer him up.

A circle can be defined as a 3-tuple (x,y,r) where x is the x position of the circle on a Cartesian plane, y is the y position of the circle on a Cartesian plane, and r is the radius of the circle. x and y may be negative. r is always positive. The input is a list of circles in the form of space separated 3-tuples. For instance:

3,1,1 3,2,1.5 1,2,0.7 0.9,1.2,1.2 1,0,0.8
The 3,1,1 means "A circle with centre point at 3,1 with 1 radius. 3,2,1.5 means "A circle with centre point at 3,2 with 1.5 radius.

If we draw all of these circles of the input on a graph, it looks like this (I've included grid lines and labels for clarity only; they are not required):

https://i.sstatic.net/jyZzd.png

Notice how all the circles are cohesive. That is, they're all overlapped together such that it forms one large group without any small groups of circles separated from the rest. The input is guaranteed to be cohesive.

Suppose now we draw a line that travels around the "border" formed by these circles, without any of the other lines. It would be like drawing the border of the silhouette formed by all the circles. The resulting cloud would look something like this:

https://i.sstatic.net/zDuUa.png

So this cloud has been formed by drawing only the arcs of the circles in the input that form a border, resulting in a single shape. In other words, the cloud is formed by only drawing the arcs that are not within another circle. Your program will take in input in the form explained above, and output an image that displays the resulting cloud. The overall shape of the cloud must be correct, but the scale, colour, line thickness, and how it looks at vertexes is up to you. Note that the cloud must be visible, so you can't pull something like "This program draws a white cloud on a white background", "This program draws a cloud at a infinitesimally small scale", "This program draws a cloud with 0 line thickness", etc. Also note that the colour of the border must be different from the colour of the fill or background.

Another example. Input:

1,4,2 5,2,1 3,1,1 3.5,2,1.2 3,3,0.7 1,2,0.7
Output:

https://i.sstatic.net/mLzXk.png

If there is a "hole" in the cloud, you should draw the hole as well. Input:

0,5,4 3,4,4 4,3,4 5,0,4 4,-3,4 3,-4,4 0,-5,4 -3,-4,4 -4,-3,4 -5,0,4 -4,3,4 -3,4,4
Output:

https://i.sstatic.net/F5K2j.png

Here is an important rule: your program must draw only the lines that form the border. This means that you CANNOT simply draw the circles fully, and then draw the circles slightly smaller with a white fill -- because that method still draws lines that don't form a border, it just covers them up afterwards. The purpose of the rule was to prevent the "draw the circles, then draw the circles again with a white fill" implementations, or anything similar to that. The answer is expected to actually calculate where to draw things before drawing it.

This is code golf, so the shortest character count wins.

"""

import matplotlib.pyplot as plt
from shapely.geometry import *

def cloud(name, circles):
    region = Point()
    for x, y, radius in circles:
        point = Point(x, y)
        next_region = point.buffer(radius)
        region = region.union(next_region)

    plt.clf()
    plt.plot(*region.exterior.xy)
    for interior in region.interiors:
        plt.plot(*interior.xy)
    
    plt.savefig(name)

def main():
    cloud("clouds_1.png", [[3, 1, 1], [3, 2, 1.5], [1, 2, 0.7], [0.9, 1.2, 1.2], [1, 0, 0.8]])
    cloud("clouds_2.png", [[1, 4, 2], [5, 2, 1], [3, 1, 1], [3.5, 2, 1.2], [3, 3, 0.7], [1, 2, 0.7]])
    cloud("clouds_3.png", [[0, 5, 4], [3, 4, 4], [4, 3, 4], [5, 0, 4], [4, -3, 4], [3, -4, 4], [0, -5, 4], [-3, -4, 4], [-4, -3, 4], [-5, 0, 4], [-4, 3, 4], [-3, 4, 4]])

main()
