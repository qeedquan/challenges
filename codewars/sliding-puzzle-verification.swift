/*

Given a board of NxN, distributed with tiles labeled 0 to N² - 1(inclusive):

A solved grid will have the tiles in order of label, left to right, top to bottom.

Return true if the board state is currently solved, and false if the board state is unsolved.

Input will always be a square 2d array.

For example, a 2x2 solved grid:

[ [0, 1],
  [2, 3] ]

A 2x2 unsolved grid:

[ [2, 1],
  [0, 3] ]

*/

func solved(_ m: [[Int]]) -> Bool {
    let n = m.count
    for i in 0..<n {
        for j in 0..<n {
            if m[i][j] != (i * n) + j {
                return false
            }
        }
    }
    return true
}

assert(solved([[0, 1], [2, 3]]) == true)
assert(solved([[2, 1], [0, 3]]) == false)
assert(solved([[1, 0], [3, 2]]) == false)

