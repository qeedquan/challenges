/*

A non-empty array a of length n is called an array of all possibilities if it contains all numbers between 0 and a.length - 1 (both inclusive).

Write a function that accepts an integer array and returns true if the array is an array of all possibilities, else false.

Examples:

[1,2,0,3] => True
# Includes all numbers between 0 and a.length - 1 (4 - 1 = 3)

[0,1,2,2,3] => False
# Doesn't include all numbers between 0 and a.length - 1 (5 - 1 = 4)

[0] => True
# Includes all numbers between 0 and a.length - 1 (1 - 1 = 0).

*/

func isAllPossibilities(_ array: [Int]) -> Bool {
    if array.count == 0 {
        return false
    }

    var array = array
    array.sort()
    for index in 0..<array.count {
        if array[index] != index {
            return false
        }
    }
    return true
}

assert(isAllPossibilities([1, 2, 0, 3]) == true)
assert(isAllPossibilities([0, 1, 2, 2, 3]) == false)
assert(isAllPossibilities([0, 2, 19, 4, 4]) == false)
assert(isAllPossibilities([3, 2, 1, 0]) == true)
assert(isAllPossibilities([0, 1, 2, 3]) == true)
assert(isAllPossibilities([1, 2, 3, 4]) == false)
assert(isAllPossibilities([0, 2, 3]) == false)
assert(isAllPossibilities([0]) == true)
assert(isAllPossibilities([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]) == true)
assert(isAllPossibilities([0, 1, 3, -2, 5, 4]) == false)
assert(isAllPossibilities([1, -1, 2, -2, 3, -3, 6]) == false)
