/*

Find the number with the most digits.

If two numbers in the argument array have the same number of digits, return the first one in the array.

*/

func findLongest(_ array: [Int]) -> Int {
    var longest = 0
    var result = 0
    for value in array {
        let string = String(abs(value))
        if longest < string.count {
            longest = string.count
            result = value
        }
    }
    return result
}

assert(findLongest([1, 10, 100]) == 100)
assert(findLongest([9000, 8, 800]) == 9000)
assert(findLongest([8, 900, 500]) == 900)
assert(findLongest([3, 40000, 100]) == 40000)
assert(findLongest([1, 200, 100000]) == 100000)
assert(findLongest([-10, 1, 0, 1, 10]) == -10)
