/*

Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements with the same value next to each other and preserving the original order of elements.

For example:

uniqueInOrder('AAAABBBCCDAABBB') == ['A', 'B', 'C', 'D', 'A', 'B']
uniqueInOrder('ABBCcAD')         == ['A', 'B', 'C', 'c', 'A', 'D']
uniqueInOrder([1,2,2,3,3])       == [1,2,3]

*/

func uniqueInOrder<T: Equatable>(_ array: [T]) -> [T] {
    var result: [T] = []
    var index0 = 0
    while index0 < array.count {
        var index1 = index0 + 1
        while index1 < array.count && array[index0] == array[index1] {
            index1 += 1
        }
        result.append(array[index0])
        index0 = index1
    }
    return result
}

assert(uniqueInOrder(["A", "A", "A", "A", "B", "B", "B", "C", "C", "D", "A", "A", "B", "B", "B"]) == ["A", "B", "C", "D", "A", "B"])
assert(uniqueInOrder(["A", "B", "B", "C", "c", "A", "D"]) == ["A", "B", "C", "c", "A", "D"])
assert(uniqueInOrder([1, 2, 2, 3, 3]) == [1, 2, 3])
