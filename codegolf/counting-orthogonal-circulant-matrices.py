#!/usr/bin/env python3

"""

Two rows of a matrix are orthogonal if their inner product equals zero. Call a matrix with all rows pairwise orthogonal an orthogonal matrix. A circulant matrix is one where each row vector is rotated one element to the right relative to the preceding row vector. We will only be interested in matrices where the entries are either -1 or 1.

Task

Write code to count as many different n/2 by n orthogonal, circulant matrices as possible in 2 minutes (for even n).

Input

The code has no input. It can try any even values of n it likes. For example, the code could try all n that are multiplies of 4 starting from the smallest and also try n = 2.

Output

The number of orthogonal circulant matrices you have found. There should also be a simple switch in your code to enable it to output the matrices themselves.

Score

The number of circulant matrices you have found.

Hints

Orthogonal n/2 by n circulant matrices only exist when n is a multiple of 4 or n is less than 4.

An example orthogonal circulant matrix is:

-1  1 -1 -1
-1 -1  1 -1
Tips for a naive approach

The most naive approach is just to iterate over all possible matrices. This can be sped up using the following two observations.

To test orthogonality of a circulant matrix we need only compare each row to the first one. This is implemented in the sample code.

We can iterate over Lyndon words and then if we find an orthogonal matrix multiply by the number of possible rotations. This is idea as yet untested so may be buggy.

Sample code

This is a very simple and naive python answer. I ran it using timeout 120.

import itertools
def check_orthogonal(row):
    for i in xrange(1,int(n/2)):
        if (sum(row[j]*row[(j+i) % n] for j in xrange(n)) != 0):
            return False
    return True

counter = 0
for n in xrange(4,33,4):
    for row in itertools.product([-1,1],repeat = n):
        if check_orthogonal(row):
            counter +=1
            print "Counter is ", counter, ". n = ", n
Correctness tests

For n = 4,8,12,16,20,24,28, the number of distinct matrices you should get is 12,40,144,128,80,192,560, respectively.

"""

import itertools

def check_orthogonal(row, n):
    for i in range(1, n//2):
        if (sum(row[j]*row[(j+i) % n] for j in range(n)) != 0):
            return False
    return True

def count(n):
    c = 0
    for row in itertools.product([-1, 1], repeat = n):
        if check_orthogonal(row, n):
            c += 1
    return c

def main():
    assert(count(4) == 12)
    assert(count(8) == 40)
    assert(count(12) == 144)
    assert(count(16) == 128)
    assert(count(20) == 80)

main()
