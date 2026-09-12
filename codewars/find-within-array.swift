/*

We'll create a function that takes in two parameters:

a sequence (length and types of items are irrelevant)
a function (value, index) that will be called on members of the sequence and their index. The function will return either true or false.
Your function will iterate through the members of the sequence in order until the provided function returns true; at which point your function will return that item's index.

If the function given returns false for all members of the sequence, your function should return -1.

var trueIfEven = function(value, index) { return (value % 2 === 0) };
findInArray([1,3,5,6,7], trueIfEven) // should === 3

*/

func findInArray<T>(_ array: [T], _ predicate: (T, Int) -> Bool) -> Int {
    for index in 0..<array.count {
        if predicate(array[index], index) {
            return index
        }
    }
    return -1
}

func neverTrue(_ value: Int, _ index: Int) -> Bool {
    return false
}

func trueIfEven(_ value: Int, _ index: Int) -> Bool {
    return value % 2 == 0
}

func trueIfValueEqualsIndex(_ value: Int, _ index: Int) -> Bool {
    return value == index
}

func trueIfLengthEqualsIndex(_ value: String, _ index: Int) -> Bool {
    return value.count == index
}

assert(findInArray([], trueIfEven) == -1)
assert(findInArray([1, 3, 5, 6, 7], trueIfEven) == 3)
assert(findInArray([2, 4, 6, 8], trueIfEven) == 0)
assert(findInArray([2, 4, 6, 8], neverTrue) == -1)
assert(findInArray([13, 5, 3, 1, 4, 5], trueIfValueEqualsIndex) == 4)
assert(findInArray(["one", "two", "three", "four", "five", "six"], trueIfLengthEqualsIndex) == 4)
assert(findInArray(["bc", "af", "d", "e"], trueIfLengthEqualsIndex) == -1)
