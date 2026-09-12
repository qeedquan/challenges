#!/usr/bin/env python3

"""

Determine the area of the largest square that can fit inside a circle with radius r.

"""

# https://oeis.org/A001105
def area(r):
    return 2*r*r

def main():
    tab = [
        0, 2, 8, 18, 32, 50, 72, 98, 128, 162, 200, 242, 288, 338, 392, 450,
        512, 578, 648, 722, 800, 882, 968, 1058, 1152, 1250, 1352, 1458, 1568,
        1682, 1800, 1922, 2048, 2178, 2312, 2450, 2592, 2738, 2888, 3042, 3200,
        3362, 3528, 3698, 3872, 4050, 4232, 4418
    ]

    for i in range(len(tab)):
        assert(area(i) == tab[i])

main()
