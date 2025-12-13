/*

There are two lists, possibly of different lengths. The first one consists of keys, the second one consists of values. Write a function createDict(keys, values) that returns a dictionary created from keys and values. If there are not enough values, the rest of keys should have a None (JS null)value. If there not enough keys, just ignore the rest of values.

Example 1:

keys = ['a', 'b', 'c', 'd']
values = [1, 2, 3]
createDict(keys, values) // returns {'a': 1, 'b': 2, 'c': 3, 'd': null}
Example 2:

keys = ['a', 'b', 'c']
values = [1, 2, 3, 4]
createDict(keys, values) // returns {'a': 1, 'b': 2, 'c': 3}

*/

func dictionary(_ keys: [String], _ values: [Int]) -> [String: Int?] {
    var result = [String: Int?]()
    for index in 0..<keys.count {
        if index >= values.count {
            result[keys[index]] = Int?(nil)
        } else {
            result[keys[index]] = values[index]
        }
    }
    return result
}

print(dictionary(["a", "b", "c", "d"], [1, 2, 3]))
print(dictionary(["a", "b", "c"], [1, 2, 3, 4]))
