#!/usr/bin/env python3

"""

Given a list of indices and zero or more lists of integers, output the lists of integers, sorted in ascending order, with the key priority from the first input.

Example
Let the keys input be [1, 0, 2], and the lists input be [[5, 3, 4], [6, 2, 1], [5, 2, 1]]. Those lists need to be sorted by their second element, then first element, then third element, in ascending order:

First, we sort by the values at index 1: [[6, 2, 1], [5, 2, 1], [5, 3, 4]]
Next, we break any ties from the first sort using the values at index 0: [[5, 2, 1], [6, 2, 1], [5, 3, 4]]
Finally, we break any remaining ties with the vlues at index 2 (this doesn't actually change anything, because there are no ties remaining).
Details
Sorting is stable: if two elements compare equal with respect to the given sort keys, they must remain in the same relative order in the output. For example, if A and B are equal under the given sort keys, and the input was [..., A, ..., B, ...], A must be placed before B in the output.
A sort key will never reference a non-existant element in one of the input lists.
No sort key will be repeated. Thus, [1, 2, 1] is not a valid list of sort keys.
Any elements not referenced by the sort keys do not factor into the sorting order. Only the initial relative order and the values of the elements referenced by the sort keys determine the output order.
You may choose whether the sort keys are zero-indexed or one-indexed.
There will be no negative values in the sort keys. If you choose to use one-indexing, there will be no zeroes in the sort keys either.
Integer values will not exceed your language's natively-representable range. If your chosen language is natively capable of arbitrary-precision integers (like Python), then any integer value can be present in the input, subject to memory constraints.
Reference Implementation (Python 2)
#!/usr/bin/env python3

keys = input()
lists = input()

print sorted(lists, key=lambda l:[l[x] for x in keys])
Try it online

Test Cases
Format: keys lists -> output. All sort keys are zero-indexed.

[1, 0, 2] [[5, 3, 4], [6, 2, 1], [5, 2, 1]] -> [[5, 2, 1], [6, 2, 1], [5, 3, 4]]
[1, 2] [[5, 3, 4], [6, 2, 1], [5, 2, 1]] -> [[6, 2, 1], [5, 2, 1], [5, 3, 4]]
[0, 1] [[1, 2], [2, 1]] -> [[1, 2], [2, 1]]
[1, 0] [[1, 2], [2, 1]] -> [[2, 1], [1, 2]]
[0] [[4], [10, 11, -88], [-2, 7]] -> [[-2, 7], [4], [10, 11, -88]]
[2] [[-1, -5, 8, -1, -4, -10, -5, 4, 4, 6, -8, 4, 2], [-7, 6, 2, -8, -7, 7, -3, 3, 0, -6, 1], [-9, 8, -5, -1, -7, -8, -5, -6, 5, -6, 6]] -> [[-9, 8, -5, -1, -7, -8, -5, -6, 5, -6, 6], [-7, 6, 2, -8, -7, 7, -3, 3, 0, -6, 1], [-1, -5, 8, -1, -4, -10, -5, 4, 4, 6, -8, 4, 2]]
[2, 1] [[9, 2, -2, -10, -6], [3, -4, -2]] -> [[3, -4, -2], [9, 2, -2, -10, -6]]
[2, 4, 8] [[5, -3, 4, -6, -1, -2, -2, -4, 5], [-2, -3, 6, -4, -1, -4, -4, -5, 8, 9, 9, -3, 3, -9, -3], [2, 0, 10, -10, -1, 2, -1, 5, -1, 10, -5], [-7, -8, -6, 7, 3, 8, 6, -7, -2, 0, -6, -4, 4, -3, 2, -3]] -> [[-7, -8, -6, 7, 3, 8, 6, -7, -2, 0, -6, -4, 4, -3, 2, -3], [5, -3, 4, -6, -1, -2, -2, -4, 5], [-2, -3, 6, -4, -1, -4, -4, -5, 8, 9, 9, -3, 3, -9, -3], [2, 0, 10, -10, -1, 2, -1, 5, -1, 10, -5]]
[1, 2, 3, 4, 5] [[-7, 3, -8, 3, 5, -1, 6, -6, 9, 8], [-9, -1, -7, -9, -10, -2, -8, -10, -10, -3], [5, 3, -6, -5, -4, -4, -8, 2], [9, -4, 1, -1, -3, -2], [-6, -10, 4, -10, 6, 6, -1, 3, 0, 0], [1, -2, -7, -6, -7, -7, -1, 0, -4, 3, 3], [7, -1, -7, 2, -2, 9, 7, 5, -6, -8], [1, -5, -3, -10, -7, 9, -8, -5, -1], [-9, 4, -1, -1, 2, 4]] -> [[-6, -10, 4, -10, 6, 6, -1, 3, 0, 0], [1, -5, -3, -10, -7, 9, -8, -5, -1], [9, -4, 1, -1, -3, -2], [1, -2, -7, -6, -7, -7, -1, 0, -4, 3, 3], [-9, -1, -7, -9, -10, -2, -8, -10, -10, -3], [7, -1, -7, 2, -2, 9, 7, 5, -6, -8], [-7, 3, -8, 3, 5, -1, 6, -6, 9, 8], [5, 3, -6, -5, -4, -4, -8, 2], [-9, 4, -1, -1, 2, 4]]
[8, 7, 3, 2, 4, 9, 1] [[8, -5, 1, -6, -1, -4, 6, 10, 10, 6, 9, 5], [4, -8, 6, -10, -2, -3, 2, -6, 9, 5, 4, 10, 2, 3], [10, -1, 3, 0, -4, 1, -5, -4, -1, -7, 9, -9, -1, -5, 7, 8, 9, 6, -3], [0, -9, -7, -2, 2, -5, 7, 4, 6, -4, 1, 8, -7, 10], [5, 6, -9, 0, -1, 5, 4, 7, 5, 10, 2, 5, 7, -9]] -> [[10, -1, 3, 0, -4, 1, -5, -4, -1, -7, 9, -9, -1, -5, 7, 8, 9, 6, -3], [5, 6, -9, 0, -1, 5, 4, 7, 5, 10, 2, 5, 7, -9], [0, -9, -7, -2, 2, -5, 7, 4, 6, -4, 1, 8, -7, 10], [4, -8, 6, -10, -2, -3, 2, -6, 9, 5, 4, 10, 2, 3], [8, -5, 1, -6, -1, -4, 6, 10, 10, 6, 9, 5]]

"""

def keysort(keys, array):
    return sorted(array, key=lambda l:[l[x] for x in keys])

def main():
    assert(keysort([1, 0, 2], [[5, 3, 4], [6, 2, 1], [5, 2, 1]]) == [[5, 2, 1], [6, 2, 1], [5, 3, 4]])
    assert(keysort([1, 2], [[5, 3, 4], [6, 2, 1], [5, 2, 1]]) == [[6, 2, 1], [5, 2, 1], [5, 3, 4]])
    assert(keysort([0, 1], [[1, 2], [2, 1]]) == [[1, 2], [2, 1]])
    assert(keysort([1, 0], [[1, 2], [2, 1]]) == [[2, 1], [1, 2]])
    assert(keysort([0], [[4], [10, 11, -88], [-2, 7]]) == [[-2, 7], [4], [10, 11, -88]])
    assert(keysort([2], [[-1, -5, 8, -1, -4, -10, -5, 4, 4, 6, -8, 4, 2], [-7, 6, 2, -8, -7, 7, -3, 3, 0, -6, 1], [-9, 8, -5, -1, -7, -8, -5, -6, 5, -6, 6]]) == [[-9, 8, -5, -1, -7, -8, -5, -6, 5, -6, 6], [-7, 6, 2, -8, -7, 7, -3, 3, 0, -6, 1], [-1, -5, 8, -1, -4, -10, -5, 4, 4, 6, -8, 4, 2]])
    assert(keysort([2, 1], [[9, 2, -2, -10, -6], [3, -4, -2]]) == [[3, -4, -2], [9, 2, -2, -10, -6]])
    assert(keysort([2, 4, 8], [[5, -3, 4, -6, -1, -2, -2, -4, 5], [-2, -3, 6, -4, -1, -4, -4, -5, 8, 9, 9, -3, 3, -9, -3], [2, 0, 10, -10, -1, 2, -1, 5, -1, 10, -5], [-7, -8, -6, 7, 3, 8, 6, -7, -2, 0, -6, -4, 4, -3, 2, -3]]) == [[-7, -8, -6, 7, 3, 8, 6, -7, -2, 0, -6, -4, 4, -3, 2, -3], [5, -3, 4, -6, -1, -2, -2, -4, 5], [-2, -3, 6, -4, -1, -4, -4, -5, 8, 9, 9, -3, 3, -9, -3], [2, 0, 10, -10, -1, 2, -1, 5, -1, 10, -5]])
    assert(keysort([1, 2, 3, 4, 5], [[-7, 3, -8, 3, 5, -1, 6, -6, 9, 8], [-9, -1, -7, -9, -10, -2, -8, -10, -10, -3], [5, 3, -6, -5, -4, -4, -8, 2], [9, -4, 1, -1, -3, -2], [-6, -10, 4, -10, 6, 6, -1, 3, 0, 0], [1, -2, -7, -6, -7, -7, -1, 0, -4, 3, 3], [7, -1, -7, 2, -2, 9, 7, 5, -6, -8], [1, -5, -3, -10, -7, 9, -8, -5, -1], [-9, 4, -1, -1, 2, 4]]) == [[-6, -10, 4, -10, 6, 6, -1, 3, 0, 0], [1, -5, -3, -10, -7, 9, -8, -5, -1], [9, -4, 1, -1, -3, -2], [1, -2, -7, -6, -7, -7, -1, 0, -4, 3, 3], [-9, -1, -7, -9, -10, -2, -8, -10, -10, -3], [7, -1, -7, 2, -2, 9, 7, 5, -6, -8], [-7, 3, -8, 3, 5, -1, 6, -6, 9, 8], [5, 3, -6, -5, -4, -4, -8, 2], [-9, 4, -1, -1, 2, 4]])
    assert(keysort([8, 7, 3, 2, 4, 9, 1], [[8, -5, 1, -6, -1, -4, 6, 10, 10, 6, 9, 5], [4, -8, 6, -10, -2, -3, 2, -6, 9, 5, 4, 10, 2, 3], [10, -1, 3, 0, -4, 1, -5, -4, -1, -7, 9, -9, -1, -5, 7, 8, 9, 6, -3], [0, -9, -7, -2, 2, -5, 7, 4, 6, -4, 1, 8, -7, 10], [5, 6, -9, 0, -1, 5, 4, 7, 5, 10, 2, 5, 7, -9]]) == [[10, -1, 3, 0, -4, 1, -5, -4, -1, -7, 9, -9, -1, -5, 7, 8, 9, 6, -3], [5, 6, -9, 0, -1, 5, 4, 7, 5, 10, 2, 5, 7, -9], [0, -9, -7, -2, 2, -5, 7, 4, 6, -4, 1, 8, -7, 10], [4, -8, 6, -10, -2, -3, 2, -6, 9, 5, 4, 10, 2, 3], [8, -5, 1, -6, -1, -4, 6, 10, 10, 6, 9, 5]])

main()
