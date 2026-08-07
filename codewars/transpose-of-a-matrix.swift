/*

Transpose means is to interchange rows and columns of a two-dimensional array matrix.

[AT]ij=[A]ji

ie: Formally, the i th row, j th column element of AT is the j th row, i th column element of A:

https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/Matrix_transpose.gif/200px-Matrix_transpose.gif

Example :

[[1,2,3],[4,5,6]].transpose() //should return [[1,4],[2,5],[3,6]]
Write a prototype transpose to array in JS or add a .transpose method in Ruby or create a transpose function in Python so that any matrix of order ixj 2-D array returns transposed Matrix of jxi .

*/

func transpose(_ m: [[Int]]) -> [[Int]] {
    if m.count == 0 || m[0].count == 0 {
        return []
    }
    let (w, h) = (m[0].count, m.count)

    var r = [[Int]](repeating: [Int](repeating: 0, count: h), count: w)
    for y in 0..<h {
        for x in 0..<w {
            r[x][y] = m[y][x]
        }
    }
    return r
}

assert(transpose([[1]]) == [[1]])
assert(transpose([[0, 1]]) == [[0], [1]])
assert(transpose([[1, 2, 3], [4, 5, 6]]) == [[1, 4], [2, 5], [3, 6]])
