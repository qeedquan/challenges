/*

In this Kata, you will be given a multi-dimensional array containing 2 or more sub-arrays of integers. Your task is to find the maximum product that can be formed by taking any one element from each sub-array.

Examples:
solve( [[1, 2],[3, 4]] ) = 8. The max product is given by 2 * 4
solve( [[10,-15],[-1,-3]] ) = 45, given by (-15) * (-3)
solve( [[1,-1],[2,3],[10,-100]] ) = 300, given by (-1) * 3 * (-100)

More examples in test cases. Good luck!

*/

func solve(_ arrays: [[Int]]) -> Int {
    if arrays.count == 0 {
        return 0
    }

    var maximum = 1
    var minimum = 1
    for array in arrays {
        let local_maximum = array.max() ?? 0
        let local_minimum = array.min() ?? 0
        let values = [
            maximum * local_maximum,
            maximum * local_minimum,
            minimum * local_maximum,
            minimum * local_minimum,
        ]

        maximum = values.max()!
        minimum = values.min()!
    }
    return maximum
}

assert(solve([[1, 2], [3, 4]]) == 8)
assert(solve([[10, -15], [-1, -3]]) == 45)
assert(solve([[1, -1], [2, 3], [10, -100]]) == 300)
assert(solve([[-1, 2, -3, 4], [1, -2, 3, -4]]) ==  12)
assert(solve([[-11, -6], [-20, -20], [18, -4], [-20, 1]]) == 17600)
assert(solve([[14, 2], [0, -16], [-12, -16]]) == 3584)
assert(solve([[-3, -4], [1, 2, -3]]) == 12)
