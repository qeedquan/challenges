#!/usr/bin/env python3

"""

Write a function centroid(c) to calculate the centroid of 3D coordinates.

Return the results as a list of floats. Round the values to two decimal places.

"""

def centroid(a):
    c = [0, 0, 0]
    for p in a:
        for i in range(len(p)):
            c[i] += p[i]
    for i in range(len(p)):
        c[i] /= len(p)
    return c

def main():
    print(centroid([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

main()
