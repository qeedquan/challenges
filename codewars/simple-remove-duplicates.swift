/*

Remove the duplicates from a list of integers, keeping the last ( rightmost ) occurrence of each element.

Example:
For input: [3, 4, 4, 3, 6, 3]

remove the 3 at index 0
remove the 4 at index 1
remove the 3 at index 3
Expected output: [4, 6, 3]

More examples can be found in the test cases.

Good luck!

*/

func solve(_ array: [Int]) -> [Int] {
    var count = [Int: Int]()
    for value in array {
        count[value] = (count[value] ?? 0) + 1
    }

    var result: [Int] = []
    for value in array {
        if count[value]! > 1 {
            count[value]! -= 1
        } else {
            result.append(value)
        }
    }
    return result
}

assert(solve([3, 4, 4, 3, 6, 3]) == [4, 6, 3])
assert(solve([1, 2, 1, 2, 1, 2, 3]) == [1, 2, 3])
assert(solve([1, 2, 3, 4]) == [1, 2, 3, 4])
assert(solve([1, 1, 4, 5, 1, 2, 1]) == [4, 5, 2, 1])
