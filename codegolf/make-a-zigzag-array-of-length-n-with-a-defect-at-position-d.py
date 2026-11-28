#!/usr/bin/env python3

"""

In the fewest bytes, in any language, write a function, zigzagdefect(n, d) that takes as input integers n and d < n. The function should return a list of length n containing integers alternating 1 and -1 such that there is a 'defect' that begins at position d, where the entry at position d is duplicated. That is to say:

zigzagdefect(6,3) -> [1, -1, 1, 1, -1, 1]
zigzagdefect(8,2) -> [1, -1, -1, 1, -1, 1, -1, 1]
zigzagdefect(7,6) -> [1, -1, 1, -1, 1, -1, -1].
Note that 0 < d < n. I've been dumb and 1-indexed my list, which isn't ideal, but now that I've written the problem it seems too late to change.

"""

def zigzag_defect(n, d):
    l = [-1, 1] * n
    return l[1:d+1] + l[d:n]

def main():
    assert(zigzag_defect(6, 3) == [1, -1, 1, 1, -1, 1])
    assert(zigzag_defect(8, 2) == [1, -1, -1, 1, -1, 1, -1, 1])
    assert(zigzag_defect(7, 6) == [1, -1, 1, -1, 1, -1, -1])

main()
