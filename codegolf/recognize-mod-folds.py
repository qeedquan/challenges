#!/usr/bin/env python3

"""

Ported from @feersum solution

The answer to what characterizes a mod-foldable series turns out to be less interesting than it seems at first.
It is a series of the form 0, 1, ..., M - 1, 0, 1, ... x1, 0, 1, ..., x2, ... such that for all i, 0 <= xi < M.
Such a sequence can be produced by the mod chain of all the (0-based) indices of the zeroes in the array, excluding the first.

"""

def f(a, i=0):
    if len(a) == 0:
        return False

    if i//len(a) != 0:
        return True
    
    r = 0
    j = i <= max(a)
    if a[i] in [a[i-1] + 1, i, 0][j::2]:
        r = 1
    return r * f(a, i + 1)

def main():
    assert(f([0, 1, 2, 3, 4, 5]) == True)
    assert(f([1]) == False)
    assert(f([0, 0, 0]) == True)
    assert(f([0, 1, 2, 0, 1, 2, 0, 0, 1, 2]) == True)
    assert(f([0, 0, 1]) == False)
    assert(f([0, 1, 2, 3, 4, 5, 6, 0, 0, 1, 2]) == True)
    assert(f([0, 1, 2, 0, 1, 2, 0, 1, 2, 3]) == False)
    assert(f([0, 2, 1, 0, 2, 1, 0, 2, 1]) == False)
    assert(f([0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1]) == True)

main()
