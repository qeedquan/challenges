#!/usr/bin/env python3

"""

Input: an array of length n containing integers in the range 0 to 2n.

For each integer x in the array, compute the number of integers that occur before x that are no larger than x.

As an example, if the array is

[3, 0, 1, 4, 3, 6]
the output should be equivalent to:

3: 0
0: 0
1: 1
4: 3
3: 3
6: 5

How quickly can you compute this as a function of n?

"""

import math

"""

Ported from @Command Master solution

O(n * log(n)/(log(log(n))))

Uses the approach from the paper "Optimal Algorithms for List Indexing and Subset Rank".
https://www.semanticscholar.org/paper/Optimal-Algorithms-for-List-Indexing-and-Subset-Dietz/f0e722bcd64611ff1b2ef4618c884bfa685696b1

The complexity of ShortSum's operations is amortized O(1) + a one-time o(n) for initialization of cache.
The cost of Tree.__init__ is the number of nodes, which is O(n).

The cost of Tree.inc and Tree.prefix each is the depth of the tree, which is log_sqrt(log(n)) log n = O(log(n) / log(log(n))).

They are run n times, so the total cost is O(n*log(n)/log(log(n)))

"""

def partial_sums(arr):
    for i in range(1, len(arr)):
        arr[i] += arr[i - 1]
    return [0] + arr

class ShortSum:
    cache = None

    def __init__(self, size):
        self.sz = size
        self.logsz = int(math.log2(size)) + 1
        if ShortSum.cache is None:
            ShortSum.cache = [partial_sums([(v >> (i * self.logsz)) & ((1 << self.logsz) - 1) for i in range(self.sz)])
                              for v in range(1 << (self.sz * self.logsz))]
        self.cnt = 0
        self.b = [0] * size
        self.c = 0

    def prefix(self, v):
        return self.b[v] + ShortSum.cache[self.c][v]

    def inc(self, v):
        self.c += 1 << (v * self.logsz)
        self.cnt += 1
        if self.cnt == self.sz:
            self.cnt = 0
            for i in range(self.sz):
                self.b[i] += ShortSum.cache[self.c][i]
            self.c = 0


class Tree:
    def __init__(self, l, r, branching_factor):
        self.sum = 0
        self.sons = []
        self.sons_sum = ShortSum(branching_factor)
        self.l = l
        self.r = r
        self.branching_factor = branching_factor
        if r - l > 1:
            for i in range(branching_factor):
                sl = l + (r - l) * i // branching_factor
                sr = l + (r - l) * (i + 1) // branching_factor
                self.sons.append(Tree(sl, sr, branching_factor))

    def count(self, ind):
        if self.l == self.r:
            return 0
        if self.l + 1 == self.r:
            return self.sum
        son_ind = ((ind - self.l + 1) * self.branching_factor - 1) // (self.r - self.l)
        return self.sons_sum.prefix(son_ind) + self.sons[son_ind].count(ind)

    def inc(self, ind):
        if self.l == self.r:
            return
        if self.l + 1 == self.r:
            self.sum += 1
            return
        son_ind = ((ind - self.l + 1) * self.branching_factor - 1) // (self.r - self.l)
        self.sons_sum.inc(son_ind)
        self.sons[son_ind].inc(ind)


def counts(L):
    N = len(L)
    logN = int(math.log2(N)) + 1
    sqrtlog = math.isqrt(logN) + 1
    ShortSum.cache = None
    t = Tree(0, 2 * N + 1, sqrtlog)
    ans = []
    for v in L:
        ans.append(t.count(v))
        t.inc(v)
    return ans

def main():
    assert(counts([3, 0, 1, 4, 3, 6]) == [0, 0, 1, 3, 3, 5])

main()
