#!/usr/bin/env python3

"""

John D. Cook's web page includes a section which plots the "exponential sum of the day". This is defined as follows:
https://www.johndcook.com/expsum/

Given the month m (from 1 to 12), the day of the month d (from 1 to 31) and the last two digits of the year y (from 1 to 99),
draw straight lines between the consecutive partial sums of

Sum[n=0, N] exp(2*pi*i*(n/m + n^2/d + n^3/y))

where i is the imaginary unit and N is computed as 2*lcm(m,d,y)+1, with lcm denoting the least common multiple.

The challenge
Given m, d and y, produce the plot as defined above.

The graph should include all values corresponding to the partial sums. Note that the bounding box is in general a rectangle (not necessarily a square).

Additional rules
Input can be taken in any reasonable format and order.

Output must be graphical.

The scales of the horizontal and vertical axes should be the same. Axis labels, grid lines and similar elements are optional.

Any of the standard means for outputting images can be used. If raster output (as opposed to vector graphics) is used, the resolution should be at least 300 pixels for the shortest side of the graph.

Floating-point numerical errors are acceptable when computing the values.

Shortest code in bytes wins.

Test cases
Input is shown in the order m, d, y:

12, 17, 01 (click link for better resolution):
https://i.sstatic.net/61qZKXBMl.png

12, 24, 25 (click link for better resolution):
https://i.sstatic.net/EDboTbMZl.png

12, 25, 25 (click link for better resolution):
https://i.sstatic.net/QBhQRanZl.png

12, 26, 25 (click link for better resolution):
https://i.sstatic.net/cW4oiRsgl.png

12, 27, 25 (click link for better resolution):
https://i.sstatic.net/v8bkCu2ol.png

"""

import matplotlib.pyplot as plt
import numpy as np

# Ported from @Truls Henriksson solution 
def expsum(m, d, y):
    n = np.arange(2*np.lcm(np.lcm(m, d), y) + 2)
    z = np.cumsum(np.exp(2j*np.pi*n*(1/m + n/d + n*n/y)))
    plt.cla()
    plt.subplot(aspect=1).plot(z.real, z.imag)
    plt.savefig("expsum_%d_%d_%d.png" % (m, d, y))

def main():
    params = [[12, 17, 1], [12, 24, 25], [12, 25, 25], [12, 26, 25], [12, 27, 25]]
    for [m, d, y] in params:
        expsum(m, d, y)

main()
