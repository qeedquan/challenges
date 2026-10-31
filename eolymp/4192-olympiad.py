#!/usr/bin/env python3

"""

n teams arrived to the Informatics Olympiad. Each team consists of ai boys and bi girls.
The participants can live in rooms with m places in each.
Find the minimum number of rooms needed to accommodate all the Olympiad participants, if the boys can't be settled with the girls.

Input
The first line contains the values of n and m. In the next n lines the pairs of numbers ai,bi (1≤i≤n) are given.
All numbers are non-negative integers not greater than 100.

Output
Print the minimum required number of rooms.

Examples

Input #1
2 3
2 1
3 2

Answer #1
3

"""

def solve(m, p):
    k = l = 0
    for a, b in p:
        k += a
        l += b
    return (k+m-1)//m + (l+m-1)//m

def main():
    assert(solve(3, [[2, 1], [3, 2]]) == 3)

main()
