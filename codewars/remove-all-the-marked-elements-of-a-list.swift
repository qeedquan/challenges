/*

Define a method/function that removes from a given array of integers all the values contained in a second array.

Examples (input -> output):
* [1, 1, 2, 3, 1, 2, 3, 4], [1, 3] -> [2, 2, 4]
* [1, 1, 2, 3, 1, 2, 3, 4, 4, 3, 5, 6, 7, 2, 8], [1, 3, 4, 2] -> [5, 6, 7, 8]
* [8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2, 3], [2, 4, 3] -> [8, 7, 6, 5, 1]

Enjoy it!!

*/

func remove(_ integers: [Int], _ values: [Int]) -> [Int] {
    var result = [Int]()
    for integer in integers {
        if !values.contains(integer) {
            result.append(integer)
        }
    }
    return result
}

assert(remove([1, 1, 2, 3, 1, 2, 3, 4], [1, 3]) == [2, 2, 4])
assert(remove([1, 1, 2, 3, 1, 2, 3, 4, 4, 3, 5, 6, 7, 2, 8], [1, 3, 4, 2]) == [5, 6, 7, 8])
assert(remove([8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2, 3], [2, 4, 3]) == [8, 7, 6, 5, 1])
