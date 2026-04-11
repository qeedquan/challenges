#!/usr/bin/env python3

"""

You can see a (4 × 4) grid below. Can you tell me how many squares and rectangles are hidden there?
You can assume that squares are not rectangles. Perhaps one can count it by hand but can you count
it for a (100 × 100) grid or a (10000 × 10000) grid. Can you do it for higher dimensions? That is can
you count how many cubes or boxes of different size are there in a (10 × 10 × 10) sized cube or how
many hyper-cubes or hyper-boxes of different size are there in a four-dimensional (5 × 5 × 5 × 5) sized
hypercube. Remember that your program needs to be very efficient. You can assume that squares are
not rectangles, cubes are not boxes and hyper-cubes are not hyper-boxes

Input
The input contains one integer N (0 ≤ N ≤ 100) in each line, which is the length of one side of the
grid or cube or hypercube. As for the example above the value of N is 4. There may be as many as 100 lines of input.

Output
For each line of input, output six integers S2, R2, S3, R3, S4, R4 in a single line where S2 means no of
squares of different size in (N × N) two-dimensional grid, R2 means no of rectangles of different size
in (N × N) two-dimensional grid. S3, R3, S4, R4 means similar cases in higher dimensions as described
before.

Sample Input
1
2
3

Sample Output
1 0 1 0 1 0
5 4 9 18 17 64
14 22 36 180 98 1198

"""

from functools import lru_cache

def triangular(n):
    return (n * (n + 1)) // 2

@lru_cache(maxsize=None)
def solve(n):
    if n < 1:
        return (0, 0, 0, 0, 0, 0)

    s2, r2, s3, r3, s4, r4 = solve(n - 1)

    s2 += n**2
    s3 += n**3
    s4 += n**4
    r2 = triangular(n)**2 - s2
    r3 = triangular(n)**3 - s3
    r4 = triangular(n)**4 - s4
    
    return (s2, r2, s3, r3, s4, r4)

def main():
    assert(solve(1) == (1, 0, 1, 0, 1, 0))
    assert(solve(2) == (5, 4, 9, 18, 17, 64))
    assert(solve(3) == (14, 22, 36, 180, 98, 1198))

main()

