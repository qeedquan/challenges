/*

In this kata you're given an n x n array and you're expected to traverse the elements diagonally from the bottom right to the top left.

Example

  1 6 7
  7 2 4
  3 5 9

your solution should return elements in the following order

9
4 5
7 2 3
6 7
1
//=> [9, 4, 5, 7, 2, 3, 6, 7, 1]

Your task is to write the function diagonal() that returns the array elements in the above manner.

Another Example

arr = [
 [4, 5, 7],
 [3, 9, 1],
 [7, 6, 2]
]

diagonal(arr) //=> [2, 1, 6, 7, 9, 7, 5, 3, 4]

You can assume the test cases are well formed.

*/

func traverse(_ m: [[Int]]) -> [Int] {
    let N = m.count
    var X = N - 1
    var Y = N - 1
    var r: [Int] = []
    while X >= 0 && Y >= 0 {
        var (x, y) = (X, Y)
        while x >= 0 && y < N {
            r.append(m[y][x])
            x -= 1
            y += 1
        }

        if Y > 0 {
            Y -= 1
        } else {
            X -= 1
        }
    }
    return r
}

assert(traverse([]) == [])
assert(traverse([[7]]) == [7])
assert(traverse([[1, 2], [3, 4]]) == [4, 2, 3, 1])
assert(traverse([[1, 6, 7], [7, 2, 4], [3, 5, 9]]) == [9, 4, 5, 7, 2, 3, 6, 7, 1])
assert(traverse([[4, 5, 7], [3, 9, 1], [7, 6, 2]]) == [2, 1, 6, 7, 9, 7, 5, 3, 4])
