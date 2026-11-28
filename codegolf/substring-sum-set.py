#!/usr/bin/env python3

"""

Introduction

Let's observe this array: [3, 2, 4, 1, 1, 5, 1, 2].

Each element displays the length of the substring which must be summed up. Let's take a look at the first element of the above array:

[3, 2, 4, 1, 1, 5, 1, 2]
 ^
The element at the first index is 3, so we now take a substring of length three with the same index as the starting position:

[3, 2, 4]
When summed up, this results into 9, so the first element of the substring sum set is 9.

We do this for all the elements in the array:

3 -> [3, 2, 4]
2 -> [2, 4]
4 -> [4, 1, 1, 5]
1 -> [1]
1 -> [1]
5 -> [5, 1, 2]
1 -> [1]
2 -> [2]
You can see that the number 5 is a bit of a weird case. That number exceeds the length of the array:

[3, 2, 4, 1, 1, 5, 1, 2]
                ^  ^  ^  ^  ^
We'll ignore everything that exceeds the array, so we just use [5, 1, 2].

The last step is to sum everything up:

[3, 2, 4]     -> 9
[2, 4]        -> 6
[4, 1, 1, 5]  -> 11
[1]           -> 1
[1]           -> 1
[5, 1, 2]     -> 8
[1]           -> 1
[2]           -> 2
And that is the array that needs to be outputted:

[9, 6, 11, 1, 1, 8, 1, 2]
The Task
Given an non-empty array with positive (non-zero) integers, output the substring sum set. This is code-golf, so the submission with the smallest number of bytes wins!

Test cases
[1, 2, 3, 4, 5] -> [1, 5, 12, 9, 5]
[3, 3, 3, 3, 3, 3, 3, 3] -> [9, 9, 9, 9, 9, 9, 6, 3]
[5, 1, 2, 4, 1] -> [13, 1, 6, 5, 1]
[1] -> [1]

"""

# ported from @El'endia Starman solution
def substring_sum_set(x):
    return [sum(x[i:i+k]) for i, k in enumerate(x)]

def main():
    assert(substring_sum_set([3, 2, 4, 1, 1, 5, 1, 2]) == [9, 6, 11, 1, 1, 8, 1, 2])
    assert(substring_sum_set([1, 2, 3, 4, 5]) == [1, 5, 12, 9, 5])
    assert(substring_sum_set([3, 3, 3, 3, 3, 3, 3, 3]) == [9, 9, 9, 9, 9, 9, 6, 3])
    assert(substring_sum_set([5, 1, 2, 4, 1]) == [13, 1, 6, 5, 1])
    assert(substring_sum_set([1]) == [1])

main()
