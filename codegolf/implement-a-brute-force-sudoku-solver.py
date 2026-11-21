#!/usr/bin/env python3

"""

Implement the shortest Sudoku solver using guessing. Since I have received a few request I have added this as an alternative question for those wishing to implement a brute force sudoku solver.

Sudoku Puzzle:

 | 1 2 3 | 4 5 6 | 7 8 9
-+-----------------------
A|   3   |     1 |
B|     6 |       |   5
C| 5     |       | 9 8 3
-+-----------------------
D|   8   |     6 | 3   2
E|       |   5   |
F| 9   3 | 8     |   6
-+-----------------------
G| 7 1 4 |       |     9
H|   2   |       | 8
I|       | 4     |   3
Answer:

 | 1 2 3 | 4 5 6 | 7 8 9
-+-----------------------
A| 8 3 2 | 5 9 1 | 6 7 4
B| 4 9 6 | 3 8 7 | 2 5 1
C| 5 7 1 | 2 6 4 | 9 8 3
-+-----------------------
D| 1 8 5 | 7 4 6 | 3 9 2
E| 2 6 7 | 9 5 3 | 4 1 8
F| 9 4 3 | 8 1 2 | 7 6 5
-+-----------------------
G| 7 1 4 | 6 3 8 | 5 2 9
H| 3 2 9 | 1 7 5 | 8 4 6
I| 6 5 8 | 4 2 9 | 1 3 7
Rules:

Assume all mazes are solvable by logic only.
All input will be 81 characters long. Missing characters will be 0.
Output the solution as a single string.
The "grid" may be stored internally however you wish.
The solution must be using a brute force guessing solution.
Solutions should solve within a reasonable time limit.
Example I/O:

>sudoku.py "030001000006000050500000983080006302000050000903800060714000009020000800000400030"
832591674496387251571264983185746392267953418943812765714638529329175846658429137

"""

# Ported from @Keith Randall solution
def solve(board):
    index = board.find("0")
    if index == -1:
        return board

    row, col = divmod(index, 9)
    for digit in "123456789":
        valid = True
        for i, value in enumerate(board):
            if value != digit:
                continue

            r, c = divmod(i, 9)
            same_box = r//3 == row//3 and c//3 == col//3
            if r == row or c == col or same_box:
                valid = False
                break

        if valid:
            solution = solve(board[:index] + digit + board[index + 1:])
            if solution != None:
                return solution
    return None

def main():
    assert(solve("030001000006000050500000983080006302000050000903800060714000009020000800000400030") == "832591674496387251571264983185746392267953418943812765714638529329175846658429137")

main()
