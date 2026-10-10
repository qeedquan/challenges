#!/usr/bin/env python3

"""

A very common need in algorithms classes and computer science in general is to iterate 4-directionally over a grid or matrix (such as in BFS or DFS). This seems to often result in a lot of clunky and verbose code with a lot of arithmetic and comparisons within loops. I've seen many different approaches to this, but I can't shake the feeling that there's a more concise way to do this.

The challenge is to write a pure function that, given the width and height of a finite plane n, m originating at point (0,0), and coordinates (x,y) that can represent any valid point within that plane, returns an iterable object of all points within the plane that are 4-directionally adjacent to (x,y).

The goal is to define that function in as few bytes as possible.

Some examples to help illustrate valid input/output:

n = 5 (y-axis), m = 3 (x-axis) (zero-based)

matrix = [
    [A, B, C],
    [D, E, F],
    [G, H, I],
    [J, K, L],
    [M, N, O],
]

(x, y) => [valid iterable points]

E: (1, 1) => [(1, 0), (2, 1), (1, 2), (0, 1)]
A: (0, 0) => [(1, 0), (0, 1)]
L: (2, 3) => [(2, 2), (2, 4), (1, 3)]
N: (1, 4) => [(1, 3), (2, 4), (0, 4)]
n = 1 (y-axis), m = 1 (x-axis) (zero-based)

matrix = [
    [A],
]

(x, y) => [valid iterable points]

A: (0, 0) => []
n = 2 (y-axis), m = 1 (x-axis) (zero-based)

matrix = [
    [A],
    [B],
]

(x, y) => [valid iterable points]

A: (0, 0) => [(0, 1)]
B: (0, 1) => [(0, 0)]
And here's an example (this one in Python) of a function that satisfies the conditions:

def four_directions(x, y, n, m):
    valid_coordinates = []
    for xd, yd in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        nx, ny = x + xd, y + yd
        if 0 <= nx < m and 0 <= ny < n:
            valid_coordinates.append((nx, ny))
    return valid_coordinates
The example above defined a named function, but anonymous functions are also acceptable.

The inputs n, m, x, y are all unsigned 32-bit integers within the following ranges:

n > 0
m > 0
0 <= x < m
0 <= y < n
The output must take the form of an iterable (however your language of choice defines that) of (x, y) pairs.

Additional clarifications:

Complex numbers (and other representations/serializations) are OK as long as the consumer of the iterable can access x and y as integers knowing only their location.

Non-zero-based indexes are acceptable, but only if the language of choice is a non-zero-indexed language. If the language uses a mix of numbering systems, default to the numbering system of the data structure most commonly used to represent a matrix. If these are still all foreign concepts in the given language, any starting index is acceptable.

"""

def four_directions(x, y, n, m):
    valid_coordinates = []
    for xd, yd in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        nx, ny = x + xd, y + yd
        if 0 <= nx < m and 0 <= ny < n:
            valid_coordinates.append((nx, ny))
    return valid_coordinates

print(four_directions(1, 1, 3, 5))
print(four_directions(0, 0, 3, 5))
print(four_directions(3, 2, 3, 5))
print(four_directions(4, 1, 3, 5))
print(four_directions(0, 0, 2, 1))
