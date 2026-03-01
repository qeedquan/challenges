#!/usr/bin/env python3

"""

Given three grids and the sum of rows and columns of each grid, your task is:

Grid 3×3: Fill the grid from 1 to 9, ensure no repeats within the grid.
Grid 4×4: Fill the grid from 1 to 16, ensure no repeats within the grid.
Grid 5×5: Fill the grid from 1 to 25, ensure no repeats within the grid.
Output ONLY one solution if many solutions exist. All solutions that meet the criteria are accepted.
Input ensures a solution exists.

Test Case
Format is flexible.

Input:
3×3 grid:
[[12, 18, 15], # sum of row 1 2 3
 [9, 18, 18]] # sum of column 1 2 3
4×4 grid:
[[33, 21, 43, 39], # sum of row 1 2 3 4
 [24, 36, 41, 35]] # sum of column 1 2 3 4
5×5 grid:
[[43, 79, 58, 60, 85], # sum of row 1 2 3 4 5
 [76, 66, 44, 70, 69]] # sum of column 1 2 3 4 5
One possible solution For 3×3, 4×4, 5×5 grid For the given Input:
[[1, 7, 4],
 [3, 9, 6],
 [5, 2, 8]]
[[1, 3, 15, 14],
 [6, 9, 2, 4],
 [12, 8, 13, 10],
 [5, 16, 11, 7]]
[[1, 9, 12, 6, 15],
 [24, 19, 3, 11, 22],
 [8, 20, 10, 16, 4],
 [18, 5, 2, 14, 21],
 [25, 13, 17, 23, 7]]

Criteria
The time measurement will be conducted with AMD Ryzen 9 7900X3D with 64GB RAM.
Only 1 core is utilized.
This is a competition per language.

Lowest runtime performance wins. If many code snippets have similar runtime, priority will be given to the snippet submitted first.

"""

from z3 import *

# ported from @dingledooper solution
def solve(rows, cols, n):
    grid = [Int(f'a{i}') for i in range(n * n)]

    s = Solver()
    s.add(Distinct(grid))
    for i in range(n * n):
        s.add(Or([grid[i] == j + 1 for j in range(n * n)]))
    
    for i in range(n):
        s.add(sum(grid[i*n:i*n+n]) == rows[i])
        s.add(sum(grid[i::n]) == cols[i])
    
    assert(s.check() == sat)
    model = s.model()

    sol = [model[g].as_long() for g in grid]
    return [sol[i*n:i*n+n] for i in range(n)]

def main():
    print(solve([12, 18, 15], [9, 18, 18], 3))
    print(solve([33, 21, 43, 39], [24, 36, 41, 35], 4))
    print(solve([43, 79, 58, 60, 85], [76, 66, 44, 70, 69], 5))

main()
