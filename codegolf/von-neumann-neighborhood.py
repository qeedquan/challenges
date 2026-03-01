#!/usr/bin/env python3

"""

Your goal is to make a function that takes the coordinates of a cell in 2D space and a distance r and
returns the coordinates of all cells in the input coordinate's von Neumann neighborhood of radius r.
That is, all cells at most r away in Manhattan distance. For example, given the following cell coordinates and radius pairs:

[1, 1], 1 -> [0, 1], [1, 0], [1, 1], [1, 2], [2, 1]
[2, 2], 2 -> [0, 2], [1, 1], [1, 2], [1, 3], [2, 0], [2, 1], [2, 2], [2, 3], [2, 4], [3, 1], [3, 2], [3, 3], [4, 2]

This is what the von Neumann neighborhood looks like:

https://i.sstatic.net/crQOO.png

More information about the von Neumann neighborhood can be found here.
https://en.wikipedia.org/wiki/Von_Neumann_neighborhood

This is code-golf, so shortest amount of bytes wins!

"""

def neighborhood(x, y, d):
    r = []
    for i in range(-d, d + 1):
        for j in range(abs(i)-d, d+1-abs(i)):
            r.append((x+i, y+j))
    return r

def main():
    print(neighborhood(0, 0, 1))
    print(neighborhood(0, 0, 2))
    print(neighborhood(0, 0, 3))
    print(neighborhood(1, 1, 1))
    print(neighborhood(2, 2, 2))

main()
