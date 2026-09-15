#!/usr/bin/env python3

"""

There are N doors and K monkeys. Initially, all the doors are closed.

Round 1: The 1st monkey visits every door and toggles the door (if the door is closed, it gets opened it; if it is open, it gets closed).

Round 2: The 1st monkey visits every door and toggles the door. Then The 2nd monkey visits every 2nd door and toggles the door.

. . .

. . .

Round k: The 1st monkey visits every door and toggles the door . . . . . . . . . . The kth monkey visits every kth door and toggles the door.

Input : N K (separated by a single space)

Output: Door numbers which are open, each separated by a single space.

Example:

Input: 3 3

Output: 1 2

Constraints:

0 < N < 101

0 <= K <= N

Note:

    Assume N doors are numbered from 1 to N and K monkeys are numbered from 1 to K

    The one with the shortest code wins. Also, display output for N=23, K=21

"""

"""

Ported from @Reinstate Monica solution

If a monkey appears in an even number of rounds, that's no change at all. If a monkey appears in an even number of times, that's the same as in exactly one round.

Thus some monkeys can be left out, and the others just have to switch doors once.

"""

def door(n, k):
    s = set()
    while k > 0:
        s ^= set(range(k, n + 1, k))
        k -= 2
    return list(s)

def main():
    assert(door(3, 3) == [1, 2])
    assert(door(23, 21) == [1, 2, 4, 8, 9, 16, 18, 23])

main()

