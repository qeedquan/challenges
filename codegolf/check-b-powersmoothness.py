#!/usr/bin/env python3

"""

from Wikipedia, a number is called B-powersmooth if all prime powers p^v that divide the number satisfy pv≤B.
B-powersmoothness is important, for example, for Pollard's p-1 factorization algorithm.

Task
your task is to get two numbers, n and B, and output if n is B-powersmooth.

Rules
You may take the input in any reasonable format
Since this is code-golf, the shortest code wins.
You can output a truthy/false value, or any two different values for true/false.
You can assume  1<B,n.
Test cases
n, b -> answer
3, 2 -> 0
10, 7 -> 1
123, 40 -> 0
123, 41 -> 1
64, 2 -> 0
64, 32 -> 0
64, 65 -> 1
720, 5 -> 0
720, 15 -> 0
720, 16 -> 1
20, 5 -> 1

"""

from sympy import factorint

def bsmooth(n, B):
    f = factorint(n)
    for p in f:
        if p**f[p] > B:
            return 0
    return 1

def main():
    assert(bsmooth(3, 2) == 0)
    assert(bsmooth(10, 7) == 1)
    assert(bsmooth(123, 40) == 0)
    assert(bsmooth(123, 41) == 1)
    assert(bsmooth(64, 2) == 0)
    assert(bsmooth(64, 32) == 0)
    assert(bsmooth(64, 65) == 1)
    assert(bsmooth(720, 5) == 0)
    assert(bsmooth(720, 15) == 0)
    assert(bsmooth(720, 16) == 1)
    assert(bsmooth(20, 5) == 1)

main()
