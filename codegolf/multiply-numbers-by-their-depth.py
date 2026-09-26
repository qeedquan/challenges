#!/usr/bin/env python3

"""

Given a ragged list, we can define an element's depth as the number of arrays above it, or the amount that it is nested.

For example, with the list [[1, 2], [3, [4, 5]]] the depth of the 2 is 2, as it is nested within two lists: The base list, and the list [1, 2]. The depth of the 4 is 3 as it is nested within three lists.

Your challenge is to, given a ragged list of positive integers, multiply them by their depths.

For example, given the list [[1, 2], [3, [4, 5]], 6]:

The depth of 1 is 2, so double it -> 2
The depth of 2 is also 2, so double it -> 4
The depth of 3 is 2, so double it -> 6
The depth of 4 is 3, so triple it -> 12
The depth of 5 is 3, so triple it -> 15
The depth of 6 is 1, so leave it alone -> 6
So, the result is [[2, 4], [6, [12, 15]], 6].

Another way of viewing it:

[[1, 2], [3, [4, 5 ]], 6]  - Original list
[[2, 2], [2, [3, 3 ]], 1]  - Depth map
[[2, 4], [6, [12,15]], 6]  - Vectorising product
You can assume the list won't contain empty lists.

This is code-golf, shortest wins!

Testcases
[[1, 2], [3, [4, 5]], 6] => [[2, 4], [6, [12, 15]], 6]
[[3, [2, 4]]] => [[6, [6, 12]]]
[[9, [[39], [4, [59]]]], 20] => [[18, [[156], [16, [295]]]], 20]
[2, [29]] => [2, [58]]
[[[[[[[[9]]]]]]]] => [[[[[[[[72]]]]]]]]

"""

def recurse(array, depth):
    if isinstance(array, int):
        return array * depth
    if isinstance(array, list):
        for index in range(len(array)):
            array[index] = recurse(array[index], depth + 1)
    return array

def solve(array):
    return recurse(array, 0)

def main():
    assert(solve([[1, 2], [3, [4, 5]], 6]) == [[2, 4], [6, [12, 15]], 6])
    assert(solve([[3, [2, 4]]]) == [[6, [6, 12]]])
    assert(solve([[9, [[39], [4, [59]]]], 20]) == [[18, [[156], [16, [295]]]], 20])
    assert(solve([2, [29]]) == [2, [58]])
    assert(solve([[[[[[[[9]]]]]]]]) == [[[[[[[[72]]]]]]]])

main()
