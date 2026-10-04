/*

#Task Given a sorted array of integer numbers A and another integer number sum, write a function that returns true if there are two (distinct) numbers in A that add up to sum. Return false otherwise.

#Input

A: The array is guaranteed to be sorted and has at least two elements. All elements are integers.
sum: An integer.
#Example

A = [1,2,3,4], sum = 7 returns true, since 3+4=7.
A = [-1,2,7,15], sum = 12 returns false, since any combination of two integers in the array doesn't add up to 12.
A = [1,3,3], sum = 2 returns false. You cannot use 1 twice.
#Notes

Some arrays will have many elements (>100000). Therefore, please optimize your code.

*/

func hasPair(_ array: [Int], _ target: Int) -> Bool {
    var (left, right) = (0, array.count - 1)
    while left < right {
        let sum = array[left] + array[right]
        if sum == target {
            return true
        } else if sum < target {
            left += 1
        } else {
            right -= 1
        }
    }
    return false
}

assert(hasPair([1, 2, 3, 4], 7) == true)
assert(hasPair([-1, 2, 7, 15], 12) == false)
assert(hasPair([1, 3, 3], 2) == false)
assert(hasPair([1, 5, 6, 9, 10, 14, 16, 20, 27, 30], 3) == false)
assert(hasPair([1, 5, 6, 9, 10, 14, 16, 20, 27, 30], 36) == true)
