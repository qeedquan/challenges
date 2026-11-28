#!/usr/bin/env python3

"""

There is an infinite chessboard. Two bishops are there. (Bishop means the chess piece that moves diagonally).

Now you are given the position of the two bishops. You have to find the minimum chess moves to take one to another. With a chess move, a bishop can be moved to a long distance (along the diagonal lines) with just one move.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains four integers r1 c1 r2 c2 denoting the positions of the bishops. Each of the integers will be positive and not greater than 10^9. You can also assume that the positions will be distinct.

Output
For each case, print the case number and the minimum moves required to take one bishop to the other. Print impossible if it's not possible.

Sample
Input	Output
3
1 1 10 10
1 1 10 11
1 1 5 3

Case 1: 1
Case 2: impossible
Case 3: 2

"""

def solve(r1, c1, r2, c2):
    c = abs(c1 - c2)
    r = abs(r1 - r2)
    if c == r:
        return 1
    if c%2 == r%2:
        return 2
    return "impossible"

def main():
    assert(solve(1, 1, 10, 10) == 1)
    assert(solve(1, 1, 10, 11) == "impossible")
    assert(solve(1, 1, 5, 3) == 2)

main()
