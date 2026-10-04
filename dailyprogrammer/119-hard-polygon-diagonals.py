#!/usr/bin/env python3

"""

In how many distinct ways can you divide a regular N-sided polygon into N-2 triangles using N-3 non-intersecting diagonals?

For instance, there are 3 ways to do divide a regular hexagon (6-sided polygon) into 4 triangles using 3 non-intersecting diagonals, as shown here: http://i.imgur.com/gEQHq.gif

A diagonal of a regular polygon is a line joining two non-adjacent vertices. Two diagonals are non-intersecting if they don't cross within the interior of the polygon. Two ways are distinct if one cannot be rotated and/or reflected to become the other.

What's the largest N that your program can handle in a reasonable amount of time? Post the solution for N = 23 if you can get it.

Author: skeeto

Formal Inputs & Outputs
Input Description
Number of polygon sides N

Output Description
Number of distinct ways to divide the N-gon into N-2 triangles using N-3 non-intersecting diagonals.

Sample Inputs & Outputs
Sample Input
6

Sample Output
3

Challenge Input
11

Challenge Input Solution
228

Note
None

"""

import math

def catalan(n):
    if n < 1:
        return 0
    return math.comb(2*n, n) // (n + 1)

# https://oeis.org/A000207
def polygon_diagonals(n):
    if n < 0:
        return 0
    if n == 1:
        return 1

    k = n//2 + 2
    if n%2 != 0:
        k = (n + 3) // 2

    r = catalan(n) / (2*n + 4)
    r += catalan(k - 2) / 2
    if n%2 == 0:
        r += catalan(n // 2) / 4
    if (n+2)%3 == 0:
        r += catalan((n - 1) // 3) / 3

    return int(r)

def solve(n):
    return polygon_diagonals(n - 2)

def main():
    tab = [
        1, 1, 1, 3, 4, 12, 27, 82, 228, 733, 2282, 7528, 24834, 83898, 285357,
        983244, 3412420, 11944614, 42080170, 149197152, 531883768, 1905930975,
        6861221666, 24806004996, 90036148954, 327989004892, 1198854697588,
        4395801203290, 16165198379984, 59609171366326, 220373278174641
    ]

    for i in range(len(tab)):
        assert(polygon_diagonals(i + 1) == tab[i])

    assert(solve(6) == 3)
    assert(solve(11) == 228)

main()
