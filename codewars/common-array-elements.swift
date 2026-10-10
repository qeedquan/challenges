/*

Given three arrays of integers, return the sum of elements that are common in all three arrays.

For example:

common([1,2,3],[5,3,2],[7,3,2]) = 5 because 2 & 3 are common in all 3 arrays
common([1,2,2,3],[5,3,2,2],[7,3,2,2]) = 7 because 2,2 & 3 are common in the 3 arrays
More examples in the test cases.

Good luck!

*/

func mark(_ array: [Int], _ count: inout [Int: Int], _ seen: inout [Int: Int], _ bit: Int) {
    for number in array {
        count[number] = (count[number] ?? 0) + 1
        seen[number] = (seen[number] ?? 0) | bit
    }
}

func common(_ array1: [Int], _ array2: [Int], _ array3: [Int]) -> Int {
    var count1 = [Int: Int]()
    var count2 = [Int: Int]()
    var count3 = [Int: Int]()
    var seen = [Int: Int]()

    mark(array1, &count1, &seen, 0x1)
    mark(array2, &count2, &seen, 0x2)
    mark(array3, &count3, &seen, 0x4)

    var sum = 0
    for number in seen {
        if number.value != 0x7 {
            continue
        }

        let value1 = count1[number.key] ?? 0
        let value2 = count2[number.key] ?? 0
        let value3 = count3[number.key] ?? 0
        sum += number.key * min(value1, value2, value3)
    }

    return sum
}

assert(common([1, 2, 3], [5, 3, 2], [7, 3, 2]) == 5)
assert(common([1, 2, 2, 3], [5, 3, 2, 2], [7, 3, 2, 2]) == 7)
assert(common([1], [1], [1]) == 1)
assert(common([1], [1], [2]) == 0)
