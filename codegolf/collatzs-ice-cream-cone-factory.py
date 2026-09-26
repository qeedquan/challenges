#!/usr/bin/env python3

"""

The Collatz sequence
Given a positive integer a1, the Collatz sequence with starting value a1 is defined as

a[n+1] = a[n]/2     if a[n] is even
         3*a[n] + 1 if a[n] is odd

It is conjectured that, for any starting value, this sequence always reaches the number 1.
This challenge assumes that the conjecture is true.

The challenge
Given an integer a1>2, compute the Collatz sequence until 1 is reached for the first time.
Let N be the number of sequence terms (including a1 and aN=1).
From the sequence of numbers

a1,a2,a3,…,aN

form a sequence of points in the plane by taking all pairs of consecutive terms

(a1,a2),(a2,a3),…,(aN−1,aN)

and plot these points on a 2D graph, joining consecutive points by a line segment.

Example
For input 12 the Collatz sequence is (10 terms);
12,6,3,10,5,16,8,4,2,1.

The sequence of points is (9 points):
(12,6),(6,3),(3,10),(10,5),(5,16),(16,8),(8,4),(4,2),(2,1).

The plot contains 8 line segments, as shown in the following graph.
Note that some of the segments partially overlap.
For clarity, the plot includes markers at the 9 points.

https://i.sstatic.net/SXS7n.png

Additional rules
Graphical output is required, with output being flexible as usual.
Only the straight lines are required in the graph. Line width is flexible, as long as the plot can be seen reasonably well. Line color is also flexible, and may be different for each segment, as long as lines are distinguishable from the background.
Other elements in the graph are not required, but are allowed (point markers, grid lines, axis labels, ...).
Horizontal and vertical axis scales need not be the same. Axis limits are arbitrary, as long as the graph can be seen fully and clearly. The axes may be swapped, and each axis may be reversed.
The code should work for any input given unlimited resources. It is acceptable if in practice it fails for large inputs due to time, memory or data-type limitations.
If the input happens to be a counterexample for the Collatz conjecture the code can do anything, such as get stuck in an infinite loop or order a pizza.
Programs or functions are accepted. Standard loopholes are forbidden.
Shortest code in bytes wins.

Test cases

3 https://i.sstatic.net/u8p5i.png
4 https://i.sstatic.net/4DtDx.png
27 https://i.sstatic.net/xOUsN.png
649 https://i.sstatic.net/Mt3Fs.png
650 https://i.sstatic.net/5eSka.png
46720 https://i.sstatic.net/rL0ly.png
345435 https://i.sstatic.net/LUtDC.png
63728127 https://i.sstatic.net/xTgng.png

"""

from turtle import *
import sys

# ported from @ovs solution
def render(n, x=0):
    while n > 1:
        w = n
        m = [n//2, 3*n+1]
        n = m[n % 2]
        goto(w, n)
        if x < 1:
            clear()
        x = max(x, n)
        setworldcoordinates(0, 0, x, x)

def main():
    if len(sys.argv) != 2:
        print("usage: n")
        exit(2)

    n = int(sys.argv[1])
    title("Collatz Ice Cream (N=%d)" % n)
    bgcolor("gray")
    width(20)
    render(n)
    mainloop()

main()
