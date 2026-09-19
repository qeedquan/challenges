#!/usr/bin/env python3

"""

I had this problem come up for me recently and I thought it would make a fun code-golf.

You will receive as input a list of positive integers. e.g.

[2,3,2,2,4,5,4,4,2]
We say a relabeling of the list is another list of positive integers such that the i
th element and the j
th element are equal in the relabeling if and only if the are equal in the original list. In other words it is the result of mapping a permutation of the positive integers over the list.

For example the following are relabelings of the above list:

[1,3,1,1,4,5,4,4,1]
[3,4,3,3,2,5,2,2,3]
[1,2,1,1,3,4,3,3,1]
But the following are not:

[2,3,2,2,4,5] -- Different length
[1,1,1,1,1,1,1,1,1] -- Values that were unequal have been made equal
[2,4,6,6,3,5,3,3,1] -- Values that were equal have been made unequal
Your program or function will be required to find the lexicographically earliest (i.e. the one which would appear first with dictionary ordering) relabeling of the input list.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test-cases
[] -> []
[9] -> [1]
[2,3,2,2,4,5,4,4,2] -> [1,2,1,1,3,4,3,3,1]
[3,4,2,1,1,1,1,1,1,1] -> [1,2,3,4,4,4,4,4,4,4]

"""

def relabel(numbers):
    mapping = {}
    index = 1
    result = []
    for number in numbers:
        if number not in mapping:
            mapping[number] = index
            index += 1
        result.append(mapping[number])
    return result

def main():
    assert relabel([]) == []
    assert relabel([9]) == [1]
    assert relabel([2, 3, 2, 2, 4, 5, 4, 4, 2]) == [1, 2, 1, 1, 3, 4, 3, 3, 1]
    assert relabel([3, 4, 2, 1, 1, 1, 1, 1, 1, 1]) == [1, 2, 3, 4, 4, 4, 4, 4, 4, 4]

main()

