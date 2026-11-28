/*

Given a non-empty array of integers, return the result of multiplying the values together in order. Example:

[1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24

*/

func grow(_ array: [Int]) -> Int {
    return array.reduce(1, { x, y in x * y })
}

assert(grow([1, 2, 3, 4]) == 24)
