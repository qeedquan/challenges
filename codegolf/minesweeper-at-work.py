#!/usr/bin/env python3

"""

Everyone knows the old minesweeper game that shipped with Windows XP. It's a simple grid with a 9x9 matrix of cells containing either a number (indicating how many mines are adjacent to it) or a mine.

https://i.sstatic.net/kpVkm.png

The challenge is to generate a random 9x9 grid with 10 bombs given any integer seed (up to whatever your machine/language's largest int is) with brownie points if you implement the PRNG yourself

example output: cells contain either numerals 0-8 or * for mines

*101*1000
110111000
123210000
1***10000
123210011
00000002*
00000114*
000112*3*
0001*2121
Shortest code in bytes wins.. standard rules etc, etc..

"""

from random import *

def display(m):
    for y in range(len(m)):
        for x in range(len(m[y])):
            print(m[y][x], end='')
        print()
    print()

def mark(m, x, y):
    if y < 0 or y >= len(m) or x < 0 or x >= len(m[y]) or m[y][x] == '*':
        return
    m[y][x] += 1

def minesweeper(n, s):
    if n < 1:
        return

    p = [i for i in range(n*n)]
    m = [[0]*n for _ in range(n)]
    s = min(n*n, s)

    shuffle(p)
    for i in range(s):
        x, y = p[i]%n, p[i]//n
        m[y][x] = '*'

    for y in range(n):
        for x in range(n):
            if m[y][x] != '*':
                continue
            mark(m, x-1, y-1)
            mark(m, x, y-1)
            mark(m, x+1, y-1)
            mark(m, x-1, y)
            mark(m, x+1, y)
            mark(m, x-1, y+1)
            mark(m, x, y+1)
            mark(m, x+1, y+1)

    return m

def main():
    display(minesweeper(9, 10))

main()
