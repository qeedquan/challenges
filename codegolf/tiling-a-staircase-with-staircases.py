#!/usr/bin/env python3

"""

Background
A staircase polyomino is a polyomino made of unit squares whose shape resembles a staircase. More formally, a staircase polyomino of size n
 is defined as follows:

A staircase polyomino of size 1 is a single unit square.
A staircase polyomino of size n is the same as that of size n−1 with a horizontal bar of length n attached to the bottom, left-aligned.
Let's call them just staircases for brevity.

For example, here are the staircases of size 1 to 4:

#

#
##

#
##
###

#
##
###
####
Challenge
Given a positive integer n, calculate the number of ways the staircase of size n can be tiled with one or more staircases.

Multiple staircases of same size can be used in a tiling, and the staircases can be rotated. So the following are valid tilings for n=4:

A
BC
DEF
GHIJ

A
AA
AAA
AAAA

A
AA
BBC
BDCC
Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
Generated using this Python 3 reference solution.
def f(n):
 coords = {(x,y) for x in range(n) for y in range(n) if x <= y}
 pieces = []
 for size in range(1,n+1):
  base = {(x,y) for x in range(size) for y in range(size) if x <= y}
  rot1 = {(x,size-1-y) for x,y in base}
  rot2 = {(size-1-x,y) for x,y in base}
  rot3 = {(size-1-x,size-1-y) for x,y in base}
  bases = [base] if size == 1 else [base, rot1, rot2, rot3]
  pieces += [{(x+ox, y+oy) for x,y in b} for b in bases for ox in range(n) for oy in range(n)]
 pieces = [p for p in pieces if p <= coords]
 pieces.sort(key=min)
 #print(pieces)
 def recurse(grid, candidates, depth='*'):
  #print(depth, grid, candidates)
  if not grid: return 1
  if not candidates: return 0
  hd, tl = candidates[0], candidates[1:]
  if min(grid) != min(hd): return 0
  if hd <= grid: return recurse(grid - hd, [t for t in tl if not (hd & t)], depth+'*') + recurse(grid, tl, depth+'*')
  return recurse(grid, tl, depth+'*')
 return recurse(coords, pieces)
for i in range(1,8):
 print(i, '->', f(i))

1 -> 1
2 -> 2
3 -> 8
4 -> 57
5 -> 806
6 -> 20840
7 -> 1038266

"""

# https://oeis.org/A334617
def f(n):
    coords = {(x, y) for x in range(n) for y in range(n) if x <= y}
    pieces = []
    for size in range(1, n + 1):
        base = {(x, y) for x in range(size) for y in range(size) if x <= y}
        rot1 = {(x, size - 1 - y) for x, y in base}
        rot2 = {(size - 1 - x, y) for x, y in base}
        rot3 = {(size - 1 - x, size - 1 - y) for x, y in base}
        bases = [base] if size == 1 else [base, rot1, rot2, rot3]
        pieces += [
            {(x + ox, y + oy) for x, y in b}
            for b in bases
            for ox in range(n)
            for oy in range(n)
        ]
    pieces = [p for p in pieces if p <= coords]
    pieces.sort(key=min)
    
    def recurse(grid, candidates, depth="*"):
        if not grid:
            return 1
        if not candidates:
            return 0
        hd, tl = candidates[0], candidates[1:]
        if min(grid) != min(hd):
            return 0
        if hd <= grid:
            return recurse(
                grid - hd, [t for t in tl if not (hd & t)], depth + "*"
            ) + recurse(grid, tl, depth + "*")
        return recurse(grid, tl, depth + "*")

    return recurse(coords, pieces)

def main():
    tab = [1, 2, 8, 57, 806, 20840, 1038266]

    for i in range(len(tab)):
        assert(f(i + 1) == tab[i])

main()
