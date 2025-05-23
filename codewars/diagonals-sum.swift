/*

Create a function that receives a (square) matrix and calculates the sum of both diagonals (main and secondary)

Matrix = array of n length whose elements are n length arrays of integers.

3x3 example:

diagonals( [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
] );

returns -> 30 // 1 + 5 + 9 + 3 + 5 + 7

*/

func sum(_ matrix: [[Int]]) -> Int {
    var total = 0
    for index in 0..<matrix.count {
        total += matrix[index][index] + matrix[index][matrix.count - 1 - index]
    }
    return total
}

assert(sum([[1, 2, 3], [4, 5, 6], [7, 8, 9]]) == 30)
