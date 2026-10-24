#!/usr/bin/env python3

"""

Suppose we define an infinite matrix M, on N^2 -> {0, 1} (where N starts from 1 instead of 0) in this manner:

M(1, 1) = 0.

For every x > 1, M(x, 1) = 1 if x is prime, and 0 otherwise.

For every y > 1, M(1, y) = the yth term in the Thue-Morse sequence.

For every x, y > 1, M(x, y) = M(x, y-1) + M(x-1, y) mod 2.

The top-left 16x16 section of this matrix looks like (with x being rows and y being columns):

0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
1 0 1 1 0 0 0 1 0 0 0 1 1 0 1 1
1 1 0 1 1 1 1 0 0 0 0 1 0 0 1 0
0 1 1 0 1 0 1 1 1 1 1 0 0 0 1 1
1 0 1 1 0 0 1 0 1 0 1 1 1 1 0 1
0 0 1 0 0 0 1 1 0 0 1 0 1 0 0 1
1 1 0 0 0 0 1 0 0 0 1 1 0 0 0 1
0 1 1 1 1 1 0 0 0 0 1 0 0 0 0 1
0 1 0 1 0 1 1 1 1 1 0 0 0 0 0 1
0 1 1 0 0 1 0 1 0 1 1 1 1 1 1 0
1 0 1 1 1 0 0 1 1 0 1 0 1 0 1 1
0 0 1 0 1 1 1 0 1 1 0 0 1 1 0 1
1 1 0 0 1 0 1 1 0 1 1 1 0 1 1 0
0 1 1 1 0 0 1 0 0 1 0 1 1 0 1 1
0 1 0 1 1 1 0 0 0 1 1 0 1 1 0 1
0 1 1 0 1 0 0 0 0 1 0 0 1 0 0 1

Your task is to build a program that will evaluate the value of an arbitrary entry in this matrix as accurately as possible.

Your program will take two integers x and y as input, in any form you choose, and return M(x, y), which will be either 0 or 1.

Your code may be written in any language, but must not exceed 64 kilobytes (65,536 bytes) of source code size or 2 MB (2,097,152 bytes) of total memory usage. Your program must start with empty memory (i.e. it cannot load data from somewhere else) and run independently for each input (that is, it may not store common data for multiple runs). Your program must also be able to evaluate all the entries in the top-left 8192x8192 square in a reasonable amount of time.

The program that evaluates the most entries correctly in the top-left 8192 x 8192 square will be the winner, with shorter code acting as a tie-breaker.

"""

# ported from @Aleksi Torhamo solution
def M(X, Y):
    X += 1
    c = [1] * X
    r = [0]
    
    while len(r) < Y:
        r += [i ^ 1 for i in r]
    
    for i in range(2, X):
        if c[i]:
            for j in range(i + i, X, i):
                c[j] = 0
        
        r[0] = c[i]
        
        for i in range(1, Y):
            r[i] ^= r[i - 1]
    
    return r[Y - 1]

def main():
    for x in range(1, 17):
        for y in range(1, 17):
            print(M(x, y), end=' ')
        print()

main()
