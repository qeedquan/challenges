#!/usr/bin/env python3

"""

The Seidel Triangle is a mathematical construction similar to Pascal's Triangle, and is known for it's connection to the Bernoulli numbers.

The first few rows are:

      1
      1  1
   2  2  1
   2  4  5  5
16 16 14 10 5
16 32 46 56 61 61
Each row is generated as follows:

If the row number is even (1-indexed):

Bring down the first item of the previous row

Every next item is the sum of the previous item and the item above it

Duplicate the last item

If the row number is odd:

Bring down the last item of the previous row

Going backwards, each item is the sum of the previous item and the item above it

Duplicate what is now the first item.

Basically, we construct the triangle in a zig-zag pattern:

    1
    v
    1 > 1
        v
2 < 2 < 1
v
2 > 4 > 5 > 5
For more information, see the Wikipedia page on Bernoulli numbers.

The Challenge:
Given n, either as a function argument or from STDIN, print or return either the nth row of the Seidel triangle or the first n rows. You may use either 0 or 1 indexing.

You do not need to handle negative or non-integer input (nor 0, if 1-indexed). You do not have to handle outputs larger than 2147483647 = 2^31 - 1

As this is code-golf, do this in as few bytes as possible.

Examples:
In these examples the return value is the nth row, 0-indexed.

Input   ->  Output

0           1
1           1 1
2           2 2 1
6           272 272 256 224 178 122 61
13          22368256 44736512 66750976 88057856 108311296 127181312 144361456 159575936 172585936 183194912 191252686 196658216 199360981 199360981

"""

# https://oeis.org/A008280
def seidel(n):
    if n < 0:
        return []

    n += 2
    A = {-1: 0, 0: 1}
    k = 0
    e = 1
    r = []
    for i in range(n + 1):
        Am = 0
        A[k + e] = 0
        e = -e
        for j in range(i):
            Am += A[k]
            A[k] = Am
            k += e

    r = []
    for z in range(-n//2, n//2 + 1):
        if A[z] != 0:
            r.append(A[z])
    return r

def main():
    assert(seidel(0) == [1])
    assert(seidel(1) == [1, 1])
    assert(seidel(2) == [2, 2, 1])
    assert(seidel(3) == [2, 4, 5, 5])
    assert(seidel(4) == [16, 16, 14, 10, 5])
    assert(seidel(5) == [16, 32, 46, 56, 61, 61])
    assert(seidel(6) == [272, 272, 256, 224, 178, 122, 61])
    assert(seidel(13) == [22368256, 44736512, 66750976, 88057856, 108311296, 127181312, 144361456, 159575936, 172585936, 183194912, 191252686, 196658216, 199360981, 199360981])

main()
