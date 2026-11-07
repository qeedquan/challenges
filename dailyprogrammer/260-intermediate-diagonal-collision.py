#!/usr/bin/env python3

"""

Description
You have one rectangle composed of X*Y squares, with X being the width and Y being the height. You want to know how many squares you are going to collide if you were to draw a diagonal, meaning a line between the bottom-left edge and the top-right edge.

Input Description
2 unsigned integers X and Y

Output Description
Number of squares that collide with the diagonal.

Sample Inputs
Sample Input 1 : 5 2 Sample Input 2 : 3 9

Sample Outputs
For this first case, the squares marked as X would collide with the diagonal :

..XXX
XXX..
meaning the Sample Output 1 is 6

Sample Output 2 : 9

Challenge Input
Input 0 : 3 9 Input 1 : 21 2 Input 2 : 168 189 Input 3 : 100 101 Input 4 : 123456789 987654321

Bonus
For small numbers, you can output on the standard output which squares would collide, like so :

..XXX
XXX..
Credit
This challenge was suggested by u/Cobrand. Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas.

"""

from math import *

"""

@dan-the-space-man

If x and y are coprime (i.e. gcd(x, y) = 1), that means there are no intersections with the vertices of any square. Now, define a crossing to be a place where the line intersects with a horizontal boundary. For example:

...XX

XXX..

|

|-> crossing

Now, if we assume x => y (the rectangle is wider than it's higher), a crossing will only ever have 2 squares in it. You see, graphically, the line can be represented as y = (y0/x0)x, where x0 and y0 are just x and y, to prevent naming conflicts.

A crossing only occurs on x = k if and only if there exists an integer n such that

(y0/x0)k < n < (y0/x0)(k + 1)

That is, you have a horizontal boundary sandwiched between 2 consecutive x values. Those 2 values can only differ by a maximum of y0/x0. Since x0 >= y0, which means y0/x0 <= 1, you could also say they only differ by a maximum of 1. That means a value can't leap through a maximum of one horizontal line, which means you can't have a crossing with 3, 4, etc. squares. And that means you can only have 1 or 2 squares in a column.

Given that, the solution to this problem is

x + (number of crossings).

But how do we find (number of crossings)?

Return to the graphical representation: y = (y0/x0)x.

To reach the line y = y0 (the upper boundary of the rectangle), the line has to move through y0 - 1 horizontal lines: y = 1, y = 2, y = 3 until y = y0 - 1. And since the line can only move through a horizontal line on a crossing, that means there are y0 - 1 crossings.

That means, assuming x and y are coprime, the answer is x + y - 1.

But what if they're not?

Divide up the X*Y rectangles into rectangles of side length x/gcd(x, y) and y/gcd(x, y). That means gcd(x, y) rectangles with coprime side lengths. The number of squares intersecting the line in each of those rectangles is x/gcd(x, y) + y/gcd(x, y) - 1. Since those rectangles are all the same, the total solution is

gcd(x, y)[x/gcd(x, y) + y/gcd(x, y) - 1]

Expanding, the denominator in the first 2 terms cancel out, leaving

x + y - gcd(x, y).

"""
def solve(X, Y):
    return X + Y - gcd(X, Y)

def main():
    assert(solve(5, 2) == 6)
    assert(solve(3, 9) == 9)
    assert(solve(21, 2) == 22)
    assert(solve(168, 189) == 336)
    assert(solve(100, 101) == 200)
    assert(solve(8, 2) == 8)
    assert(solve(123456789, 987654321) == 1111111101)

main()
