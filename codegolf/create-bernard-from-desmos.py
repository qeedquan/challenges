#!/usr/bin/env python3

"""

Background
In the online graphing calculator Desmos, there is a certain shape that appears in the lower left portion of the graph in many high detail graphs, which the Desmos community has dubbed "Bernard". You can see an example of it in this graph and an isolated version of it in this graph. This shape is a consequence of the quadtree algorithm which Desmos utilizes to actually graph equations. I barely comprehend how it all works, but by descending into "deeper", or more detailed, quadrants, a more detailed Bernard can be created.

(Don't take my word for how Bernard is formed, I barely understand how it works myself.)

A screenshot of what Bernard looks like for posterity:

https://i.sstatic.net/bgYpp.png

In this challenge, you will write code that will print out a 2d array version of a depth-n Bernard.

How to create Bernard?
Given a positive integer n, create a 2^n×2^n grid of 1's and 0's.

If n=1, then fill in the 2×2 grid like so:

0 1
1 1

That is your output.

If n>1, then recursively fill in the grid in the following way:

Split the grid into 16 blocks of size (2^n-2)×(2^n-2).

Fill in the square regions according to the below diagram, and recurse on the region labelled R:
0 0 1 1
0 0 0 R
1 1 1 1
1 1 1 1

If the region R is a 1×1 or a 2×2 region, then finish this step and output the resulting array.
If the region R is a 1×1 region, then fill its only entry with 1.
If R is a 2×2 region, then fill it in the following way:
0 1
1 1
If step 3 does not apply, then repeat steps 1-4 but on region R.

Worked example: n=4
n is 4, so we will have a 16×16 grid. Following step 1, we fill the grid in the following way (with R denoting the region we will recurse on):

0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 R R R R
0 0 0 0 0 0 0 0 0 0 0 0 R R R R
0 0 0 0 0 0 0 0 0 0 0 0 R R R R
0 0 0 0 0 0 0 0 0 0 0 0 R R R R
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
The region R is 4×4, so we recurse. The region R should now look like this, with the new R inside the grid denoting where to recurse:

0 0 1 1
0 0 0 R
1 1 1 1
1 1 1 1
Because R is now 1×1, we fill it in, so it becomes:

0 0 1 1
0 0 0 1
1 1 1 1
1 1 1 1
Placing this back into the original 16×16 grid, we obtain the desired output:

0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Task
Given a positive integer n as input, return a 2^n×2^n 2d array which represents the depth-n Bernard.

Test Cases
n=1
0 1
1 1

n=2
0 0 1 1
0 0 0 1
1 1 1 1
1 1 1 1

n=3
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

n=4
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

This is code-golf, so shortest code in bytes wins!

"""

import numpy as np

def recurse(n):
    return n < np.eye(1) or np.kron(np.c_[:4:2, 1:3], recurse(n - 1)[::-1] + 1) > 1

"""

ported from @m90 solution

n<eye(1) produces [[True]] for n=0, the base case, and [[False]] for positive n, causing the expression after it to be used.

c_[:4:2,1:3] produces [[0 1] [2 2]], and is 1 byte shorter than the direct way of writing that matrix.

The grid for n-1 is recursively obtained and flipped vertically, and then 1 is added, making it consist of 1s and 2s. kron then produces a copy of it in the top-right quadrant (>1 where the pre–+1 version had a 1), a doubled copy of it in each bottom quadrant (always >1), and zero in the top-left quadrant (never >1).

"""

def bernard(n):
    r = recurse(n)
    return r.astype(int)

def main():
    for i in range(5):
        print(i)
        print(bernard(i))
        print()

main()
