#!/usr/bin/env python3

"""

Indeed, the army of the Dark Lord Sauron is countless—it contains n orcs! (According to some sources, it even numbers 10^100.)
However, not so long ago, there was an annoying case of desertion—one of the orcs, whose name is Shagrath, decided that it was time to retire.
He went away to the west of Middle-earth, acquired a little garden there, and began to cultivate leeks.
It would be interesting to know how many orcs remain in the army now.

Input
The initial number of orcs in the army n (1≤n≤10^100).

Output
the number of orcs remaining in the army after Shagrath's departure.

Examples

Input #1
1

Answer #1
0

Input #2
2

Answer #2
1

"""

def solve(n):
    return n - 1

def main():
    assert(solve(1) == 0)
    assert(solve(2) == 1)

main()
