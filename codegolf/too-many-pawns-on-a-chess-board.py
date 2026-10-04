#!/usr/bin/env python3

"""

Given an integer 2n, find the number of possible ways in which 2n² black pawns and 2n² white pawns can be arranged on a 2n by 2n chess board such that no pawn attack another.

A black pawn can attack only a white pawn, and vice versa.
The usual chess rules of attacking follow, i.e, white pawns attack squares immediately diagonally in front, and the black pawns attack squares immediately diagonally backward (as seen by the white observer).
All rotation, reflections count as distinct.
The program that can output all possible configurations for the highest value of 2n in 120 seconds wins. (All programs are welcome, though)

For example, Alice's program can deal with upto n=16 within 120 seconds while Bob's can deal with upto n=20 within the same time. Bob wins.

Platform: Linux 2.7GHz @ 4 CPUs

"""

"""

https://oeis.org/A294240

@feersum

This currently uses a dynamic programming scheme taking O(n^4) operations to calculate the ways to place p pawns on the squares of one color for 0 <= p <= n^2.
I think it should be possible to do this much more efficiently.

Explanation
In a valid solution, the lowermost white pawns in each column must form a zigzagging line like this:

https://i.sstatic.net/dwbdc.png

That is, the height of the line in column c must be +/- 1 from its position in column c - 1. The line can also go onto two imaginary rows above the top of the board.

We can use dynamic programming to find the number of ways to draw a line on the first c columns that includes p pawns on those columns,
is at height h on the cth column, using the results for column c - 1, heights h +/- 1, and number of pawns p - h.

"""

def count(n):
    a0 = []
    a1 = []
    for _ in range(n + 1):
        a0.append([0] * (n*n + 1))
        a1.append([0] * (n*n + 1))

    for h in range(n + 1):
        a0[h][0] = 1 - (h % 2)

    for c in range(1, 2*n + 1):
        minp = 0
        for h in range(n + 1):
            for i in range(len(a1[h])):
                a1[h][i] = 0
            
            if h > 0:
                minp += min(2*h - c%2, c)

            maxp = min(n*(c - 1) + h, n*n)
            for p in range(minp, maxp + 1):
                v = a0[h][p-h]
                if c%2 == 1 and h > 0:
                    v += a0[h-1][p-h]
                elif c%2 == 0 and h < n:
                    v += a0[h+1][p-h]
                a1[h][p] = v
        a0, a1 = a1, a0

    s = [0] * (n*n + 1)
    for p in range(n*n + 1):
        for h in range(n + 1):
            s[p] += a0[h][p]

    r = 0
    for p in range(n*n):
        r += s[p]**2
    return 2*r + s[n*n]**2

def main():
    tab = [
    	1, 3, 30, 410, 6148, 96120, 1526700, 24425026, 392143828, 6306613690,
        101505099104, 1634209596410, 26311180850268, 423567557239604,
        6817440328754244, 109703307312544664, 1764863031686159684,
        28385338557467333804, 456426743658724223028, 7337464027218416593362
    ]

    for i in range(len(tab)):
        assert(count(i) == tab[i])
    
    assert(count(87) == 62688341832480765224168252369740581641682638216282495398959252035334029997073369148728772291668336432168)

main()
