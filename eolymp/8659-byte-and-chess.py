#!/usr/bin/env python3

"""

While rushing to class, Baytik noticed a chessboard in the game room.
He began to wonder how many different squares of side length k (1≤k≤n) can fit on a chessboard of size n.

Input
A natural number n (n≤10000), representing the size of the chessboard.

Output
A single number indicating the total number of different squares that can be placed on the chessboard.

Examples
Input #1
3

Answer #1
14

"""

# https://oeis.org/A000330
def solve(n):
    return n*(n+1)*(2*n + 1) // 6

"""

The total number of squares is (n - k + 1)^2.
This formula counts a kxk square inside an nxn chessboard.

Sum [k=1 to n] gives the square pyramidal numbers above

"""
def solvebf(n):
    r = 0
    for k in range(1, n + 1):
        r += (n - k + 1)**2
    return r

def main():
    assert(solve(3) == 14)
    for i in range(1000):
        assert(solve(i) == solvebf(i))

main()
