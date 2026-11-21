#!/usr/bin/env python3

"""

Write a function or program that outputs the number of each type of element (vertex, edge, face, etc.) of an N-dimensional hypercube.

As an example, the 3 dimensional cube has 1 cell (i.e. 1 3-dimensional cube), 6 faces (i.e. 6 2-dimensional cubes), 12 edges (i.e. 12 2-dimensional cubes) and 8 vertices (i.e. 8 0-dimensional cubes).

More details about Hypercube elements can be found here

You can as well take a look at the following OEIS sequence.

Input
Your code will take as input (via STDIN or a function parameter or similar things) an integer greater or equal to 0, which is the dimension of the hypercube.

Your code has to theoretically work for any input >= 0, disregarding memory and time issues (that is, speed and potential stack overflows are not a problem for your answer if the input is big). Inputs given as test cases will not be above 12.

Output
You will ouput a list of all elements of the hypercube, starting with the "highest dimension" element. For example, for a cube (input = 3), you will output the list [1,6,12,8] (1 cell, 6 faces, 12 edges, 8 vertices).

The format of the list in the output is relatively free, as long as it looks like a list.

You can output the result to STDOUT or return it from a function.

Test cases
Input = 0
Output = [1]

Input = 1
Output = [1,2]

Input = 3
Output = [1,6,12,8]

Input = 10
Output = [1, 20, 180, 960, 3360, 8064, 13440, 15360, 11520, 5120, 1024]

Input = 12
Output = [1, 24, 264, 1760, 7920, 25344, 59136, 101376, 126720, 112640, 67584, 24576, 4096]
Scoring
This is code-golf, so the shortest answer in bytes wins.

"""

from math import *

# https://oeis.org/A013609
def hypercube(n):
    r = []
    for k in range(n + 1):
        r.append(2**k * comb(n, k))
    return r

def main():
    assert(hypercube(0) == [1])
    assert(hypercube(1) == [1, 2])
    assert(hypercube(2) == [1, 4, 4])
    assert(hypercube(3) == [1, 6, 12, 8])
    assert(hypercube(10) == [1, 20, 180, 960, 3360, 8064, 13440, 15360, 11520, 5120, 1024])
    assert(hypercube(12) == [1, 24, 264, 1760, 7920, 25344, 59136, 101376, 126720, 112640, 67584, 24576, 4096])

main()
