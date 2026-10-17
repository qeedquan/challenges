#!/usr/bin/env python3

r"""

An unrooted binary tree is an unrooted tree (a graph that has single connected component and contains no cycles) where each vertex has exactly one or three neighbors. It is used in bioinformatics to show evolutionary relationships between species.

If such a tree has n internal nodes, it necessarily has n+2 leaves. Therefore it always has an even number of vertices.

Challenge
Given a positive integer  n, compute the number of distinct unrooted, unlabeled binary trees having 2n vertices.
This is OEIS A000672.
You may take 2n as input instead, and in that case, you may assume the input is always even.

The shortest code in bytes wins.

Illustration
n=1 (2 nodes, 1 possible)

O-O

n=2 (4 nodes, 1 possible)

O
 \
  O-O
 /
O

n=3 (6 nodes, 1 possible)

O     O
 \   /
  O-O
 /   \
O     O

n=4 (8 nodes, 1 possible)

O     O
 \   /
  O-O
 /   \
O     O-O
     /
    O

n=5 (10 nodes, 2 possible)

                  C
                   \
A     B       C     O-C
 \   /         \   /
  O-O     A     O-O
 /   \   /     /   \
A     O-O     C     O-C
     /   \         /
    B     A       C

n=6 (12 nodes, 2 possible)
(branching from A)  (branching from B or C)
    O                    O
   /                      \
O-O     O            O     O-O
   \   /              \   /
    O-O     O          O-O     O
   /   \   /          /   \   /
  O     O-O          O     O-O
       /   \              /   \
      O     O            O     O
Test cases
The values for first 20 terms (for  n=1…20) are as follows:

1, 1, 1, 1, 2, 2, 4, 6, 11, 18,
37, 66, 135, 265, 552, 1132, 2410, 5098, 11020, 23846

"""

from math import comb

"""

https://oeis.org/A000672

ported from @Arnauld solution

"""

class Gen:
    def __init__(self):
        self.v = 0

    def g(self, n, i):
        if i < n/2:
            return self.B(i)*self.B(n-i) + self.g(n, i+1)
        return 0

    def B(self, n):
        if n%1 != 0:
            return 0
        if n < 0:
            return 0
        if n < 2:
            self.v = n
            return n
        self.v = self.g(n, 1) + (self.B(n/2)*(self.v+1))/2 
        return self.v

    def b(self, n):
        return int(self.B(n + 1))

    def calc(self, n):
        if n < 5:
            return 1

        r = 0
        r -= self.b(n)
        n -= 1
        r += self.b(n/2)
        r += 2 * self.b(n)
        n -= 1
        r -= 2 * comb(1 + self.b(n/3), 3)
        
        k0 = 0
        for i in range(1, int((n-1)/2) + 1):
            k0 += comb(self.b(i), 2) * self.b(n - 2*i)
        
        n1 = int(n/3)
        n2 = n
        k1 = 0
        for i in range(1, n1 + 1):
            k2 = 0
            n2 -= 1
            for j in range(i, int(n2/2) + 1):
                k2 += self.b(j) * self.b(n2 - j)
            k1 += self.b(i) * k2

        r -= k0
        r += k1

        return r

def main():
    tab = [1, 1, 1, 1, 2, 2, 4, 6, 11, 18, 37, 66, 135, 265, 552, 1132, 2410, 5098, 11020, 23846]
    
    g = Gen()
    for i in range(len(tab)):
        assert(g.calc(i + 1) == tab[i])

main()
