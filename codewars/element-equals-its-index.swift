/*

Given a sorted array of distinct integers, write a function indexEqualsValue that returns the lowest index for which array[index] == index.
Return -1 if there is no such index.

Your algorithm should be very performant.

[input] array of integers ( with 0-based nonnegative indexing )
[output] integer

Examples:
input: [-8,0,2,5]
output: 2 # since array[2] == 2

input: [-1,0,3,6]
output: -1 # since no index in array satisfies array[index] == index
Random Tests Constraints:
Array length: 200 000

Amount of tests: 1 000

Time limit: 150 ms

*/

func indexEqualsValue(_ array: [Int]) -> Int {
    var low = 0
    var high = array.count - 1
    var result = -1
    while low <= high {
        let middle = (low + high) / 2
        if array[middle] == middle {
            result = middle
        }

        if array[middle] < middle {
            low = middle + 1
        } else {
            high = middle - 1
        }
    }
    return result
}

assert(indexEqualsValue([-8, 0, 2, 5]) == 2)
assert(indexEqualsValue([-1, 0, 3, 6]) == -1)
assert(indexEqualsValue([-3, 0, 1, 3, 10]) == 3)
assert(indexEqualsValue([-5, 1, 2, 3, 4, 5, 7, 10, 15]) == 1)
assert(indexEqualsValue([9, 10, 11, 12, 13, 14]) == -1)
assert(indexEqualsValue([0]) == 0)
