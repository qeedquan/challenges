#!/usr/bin/env python3

"""

Stepan returned from the International Olympiad in Informatics (IOI) and brought with him n colored stones as souvenirs.
Stepan is not a greedy boy, so he decided to share the stones with his friends.
Stepan gave each friend exactly one stone.
It turned out that Stepan now also has only one stone left.
Determine how many friends Stepan has.

Input
One number n (1≤n≤100).

Output
Print the number of Stepan's friends.

Examples

Input #1
2

Answer #1
1

Note
Stepan brought 2 stones, one of which he kept for himself. So the second stone he gave to his one friend.

"""

def solve(n):
    return n - 1

def main():
    assert(solve(2) == 1)

main()
