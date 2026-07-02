#!/usr/bin/env python3

"""

https://static.e-olymp.com/content/18/18c821993fa58ab22648395d443febc847a44b04.gif

In one of the Buddhist monasteries, monks have been rearranging discs for a thousand years.
They have three pegs with discs of different sizes.
Initially a certain number of disks are put on the first peg and ordered by size
- from smallest to largest from top to bottom.Monks must move all discs from the first peg to the third one, satisfying the only condition
- any disc cannot be placed on a smaller disc.

All three pegs can be used for moves.
The monks move one disc in one second.
Once they finish their work, the world will come to an end.

Well, is it like a monk to bring the end of the world closer? Wrong monks ... :)

Therefore, we will not be interested in the answer to a question somehow related to the apocalypse,
but will be interested in the answer to a more familiar question in our everyday life:
What is the least number of moves in which the monks will be able to complete their work, provided that they move the disks optimally?

Input
Number of discs n (0≤n≤64) available to monks.
By a strange coincidence, the number of disks in this problem does not exceed the number of cells on an ordinary chessboard.

Output
Print the smallest number of moves for which the monks can complete their work.

Examples

Input #1
3

Answer #1
7

Input #2
1

Answer #2
1

"""

def solve(n):
    if n < 0:
        return 0
    return (1 << n) - 1

def main():
    assert(solve(3) == 7)
    assert(solve(1) == 1)

main()
