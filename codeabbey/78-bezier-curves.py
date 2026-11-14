#!/usr/bin/env python3

"""

Bezier curves are shapes very popular in computer design. They could be found among instruments in almost any image editor, including Microsoft Paint presented with any version of Windows.

Initially they were invented by engineers working on design of car bodies at automobile industry. Now we will try to learn how to create such curves programmatically.

Algorithm

The curve is defined by starting, ending and several intermediate points. The example above have 4 points - i.e. only 2 intermediate.

At first step we draw a polyline between these points, from starting via all intermediate in order to the ending one. It is shown with thin grey line at the picture.

Now suppose we choose some parameter alpha in range 0 ... 1 and divide each segment of the polyline according to it, i.e. in ratio:

alpha : (1 - alpha)
For example, in the drawing above alpha = 0.333.

For polyline drawn between N points and consisting of N - 1 segments we get N - 1 new points - they are shown as small purple dots at the leftmost picture.

Let us link these new points with new polyline, consisting of N - 2 segments. It is shown as thin blue line at the central and right-most pictures.

Then we can divide these new segments with the same ratio alpha once more. So we build a third polyline (shown in green at the rightmost picture).

We will continue building polylines until we get the last one consisting of only one segment. When we divide it with the ratio alpha, we get a single point.

This last point is the point of the Bezier Curve corresponding to parameter alpha.

The remaining is simple - just repeat these steps for different values of alpha - for example:

alpha = 0.00, 0.01, 0.02, 0.03, ... , 0.98, 0.99, 1.00
So that for example with 101 value (from 0 to 1 with the step of 0.01) we get the same amount of points, placed closely enough to each other. Connecting them we get the smooth curve (thick grey line at the rightmost picture).

Please refer to wikipedia article for more examples and animated demo.

Input data will contain the number of initial points M and the number N of values for parameter alpha.
Next M lines will contain coordinates of one initial point each (X and Y).
Answer should contain N pairs of coordinates (also X and Y) for all calculated points lying on the given curve. Pairs and points in them should be separated simply by space. Coordinates should be rounded to nearest integer (because when we do graphics coordinates of pixels are of course integer).

Note: the values for alpha should be calculated by dividing the range 0.0 ... 1.0 into N - 1 equal steps.

Example:

input data:
4 10
0 180
90 0
180 120
270 60

answer:
0 180 30 130 60 99 90 82 120 76 150 75 180 78 210 79 240 74 270 60
Additional Exercise for your own amusement - try to draw the resulting curve by the points which you calculated using graphical instruments of your favorite programming language. Or you can do this loading these points into Microsoft Excel (Openoffice Calc) and drawing XY chart by them.

"""

from math import comb

def bezier_curve(points, N):
    M = len(points)
    degree = M - 1
    result = []
    for k in range(N):
        # alpha ranges from 0.0 to 1.0 inclusive across N points
        alpha = 0.0
        if N > 1:
            alpha = k / (N - 1)
            
        x = 0.0
        y = 0.0
        # Apply Bernstein polynomial weights
        for i in range(M):
            weight = comb(degree, i) * ((1 - alpha)**(degree-i)) * alpha**i
            x += weight * points[i][0]
            y += weight * points[i][1]
        x = round(x)
        y = round(y)
        
        result.append((x, y))
        
    return result

def main():
    assert(bezier_curve([[0, 180], [90, 0], [180, 120], [270, 60]], 10) == [
        (0, 180),
        (30, 130),
        (60, 99),
        (90, 82),
        (120, 76),
        (150, 75),
        (180, 78),
        (210, 79),
        (240, 74),
        (270, 60),
    ])

main()
