#!/usr/bin/env python3

"""

Your challenge today is to take an array, split it into chunks, and add those chunks.

Here's how this works: Your program or function will be given an array of integers a and a chunk size L. The array should be split into arrays of size L, if the array length is not divisible by L then the array should have 0's appended to it so that it is evenly divisible. Once the array is chunked, all chunks are to be added together element-wise. The resulting array is then output.

You can assume L is greater than 0, and that a is nonempty. You cannot make the assumption that a's contents are positive.

Here's an example:

[1,2,3,4,5,6,7,8], 3 => [1,2,3]+[4,5,6]+[7,8,0] =>  [1+4+7,2+5+8,3+6+0] => [12,15,9]
Test cases:

Array                           Length   Output
[1]                             1        [1]
[1]                             3        [1,0,0]
[0]                             3        [0,0,0]
[1,2]                           3        [1,2,0]
[1,2]                           1        [3]
[-1,1]                          2        [-1,1]
[-7,4,-12,1,5,-3,12,0,14,-2]    4        [12,-1,0,1]
[1,2,3,4,5,6,7,8,9]             3        [12,15,18]
This is code-golf, fewest bytes wins!

"""

def solve(array, length):
    return [sum(array[index::length]) for index in range(length)]

def main():
    assert(solve([1], 1) == [1])
    assert(solve([1], 3) == [1, 0, 0])
    assert(solve([0], 3) == [0, 0, 0])
    assert(solve([1, 2], 3) == [1, 2, 0])
    assert(solve([1, 2], 1) == [3])
    assert(solve([-1, 1], 2) == [-1, 1])
    assert(solve([-7, 4, -12, 1, 5, -3, 12, 0, 14, -2], 4) == [12, -1, 0, 1])
    assert(solve([1, 2, 3, 4, 5, 6, 7, 8, 9], 3) == [12, 15, 18])

main()
