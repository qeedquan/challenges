/*

DESCRIPTION:

Complete the sort function so that it returns the items passed into it in alphanumerical order. Conveniently enough, the standard array sort method has been disabled for you so that you are forced to create your own.

Example:

sort([1,3,2]) // should return [1,2,3]

*/

func sort<T: Comparable>(_ items: [T]) -> [T] {
    return items.sorted()
}

assert(sort([1, 3, 2]) == [1, 2, 3])
assert(sort([1, 3, 2, 3, 4, 1]) == [1, 1, 2, 3, 3, 4])
assert(sort([4, 1, 3, 2, 2, 3, 4, 1]) == [1, 1, 2, 2, 3, 3, 4, 4])
assert(sort([1]) == [1])
assert(sort([10, 11, 9]) == [9, 10, 11])
assert(sort(["abc", "adc", "acc"]) == ["abc", "acc", "adc"])
