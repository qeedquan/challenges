#!/usr/bin/env python3

"""

Output a grid of characters visualizing the decomposition of a number into a sum of four perfect squares.

Challenge
Given a nonnegative integer 0≤n≤2^30, output a 2k×2k boolean matrix M such that f(M)=n, where f is defined such that:

f([0])=0
 
f([1])=1
 
If  M is larger than 1×1, then split it into submatrices A,B,C,D of equal size.
Then  f(M)=f(A)^2+f(B)^2+f(C)^2+f(D)^2.
Example 1:

1111
1000
1110
0000

   11      11      11      10
= (10)² + (00)² + (00)² + (00)²
= 3² + 2² + 2² + 1²
= 18
Example 2:

1111 = 2² + 2² = 8
0000
0000
0000

1010 = 1² + 1² + 1² = 3
0000
1000
0000

1010 = 1² + 1² = 2
0000
0000
0000

1000 = 1² = 1
0000
0000
0000

11111010 = 8² + 3² + 2² + 1² = 78
00000000
00001000
00000000
10101000
00000000
00000000
00000000
The output must be of minimal size and have the fewest number of ones for its size. For example, 1 must be represented as 1 and not 10;00, because the former grid is smaller than the latter.

9 must be represented as

1100
1000
0000
0000
and not

1111
0000
1000
0000
because the former has fewer ones.

4 must be represented as

11
11
and not

1100
0000
0000
0000
even though the latter grid has fewer ones, because the grid size takes precedence over the number of ones.

You may output the result as a matrix or as a nested list. Alternatively, you may output the values as a grid of two distinct characters of your choice, where each row of the output is separated by a newline; the output may contain a trailing newline.

Test cases
0 -> 0
1 -> 1
3 -> 11;10
4 -> 11;11
5 -> 1110;0000;0000;0000
9 -> 1100;1000;0000;0000
15 -> 1111;1000;1010;0000
67 -> 11111000;00000000;00000000;00000000;10001000;00000000;00000000;00000000
78 -> 11111010;00000000;00001000;00000000;10101000;00000000;00000000;00000000

"""

import numpy as np

def decompose_into_four_squares(n):
    for a in range(n, -1, -1):
        for b in range(a, -1, -1):
            for c in range(b, -1, -1):
                for d in range(c, -1, -1):
                    if a * a + b * b + c * c + d * d == n:
                        return a, b, c, d
    raise ValueError(f"Cannot decompose {n} into four squares")

def pad_to_size(matrix, size):
    old_size = matrix.shape[0]
    if old_size == size:
        return matrix

    factor = size // old_size
    if old_size * factor != size:
        raise ValueError("Target size must be a multiple of the matrix size")

    result = np.zeros((size, size), dtype=matrix.dtype)
    result[::factor, ::factor] = matrix
    return result

def build_matrix(n):
    if n < 2:
        return np.array([[n]])

    if n < 5:
        values = np.zeros(4, dtype=int)
        values[:n] = 1
        return values.reshape(2, 2)

    a, b, c, d = decompose_into_four_squares(n)
    blocks = [build_matrix(value) for value in (a, b, c, d)]
    size = max(block.shape[0] for block in blocks)
    a, b, c, d = [pad_to_size(block, size) for block in blocks]

    return np.block([[a, b], [c, d]])

# Ported from @Kolen Cheung solution
def encode(n):
    matrix = build_matrix(n)
    return ";".join(
        "".join(map(str, row))
        for row in matrix.astype(int)
    )

def main():
    for i in (0, 1, 3, 4, 5, 9, 15, 67, 78):
        print(i, encode(i), sep=" -> ")

main()
