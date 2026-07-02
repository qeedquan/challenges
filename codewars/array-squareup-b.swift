/*

This is a question from codingbat

Given a non-negative integer n,
create and return an array with the following pattern:

squareUp(3) => [0, 0, 1, 0, 2, 1, 3, 2, 1]
squareUp(2) => [0, 1, 2, 1]
squareUp(4) => [0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1]
0 <= n <= 1 000

*/

func squareup(_ n: Int) -> [Int] {
    var r = [Int]()
    for y in 0..<n {
        for x in 0..<n {
            if x < n - y - 1 {
                r.append(0)
            } else {
                r.append(n - x)
            }
        }
    }
    return r
}

assert(squareup(2) == [0, 1, 2, 1])
assert(squareup(3) == [0, 0, 1, 0, 2, 1, 3, 2, 1])
assert(squareup(4) == [0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1])
assert(squareup(9) == [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 0, 0, 4, 3, 2, 1, 0, 0, 0, 0, 5, 4, 3, 2, 1, 0, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0, 7, 6, 5, 4, 3, 2, 1, 0, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1])
