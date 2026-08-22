#!/usr/bin/env python3

"""

Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 

Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 

Constraints:

1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
target is an integer from nums.
At most 10^4 calls will be made to pick.

"""

from random import *

class Chooser:
    def __init__(self, nums):
        self.index = {}
        for (i, n) in enumerate(nums):
            if n not in self.index:
                self.index[n] = []
            self.index[n].append(i) 
    
    def pick(self, target):
        if target not in self.index:
            return -1
        
        x = self.index[target]
        n = randint(0, len(x)-1)
        return x[n]

def main():
    c = Chooser([1, 2, 3, 3, 3])
    assert(c.pick(3) in [2, 3, 4])
    assert(c.pick(1) == 0)
    assert(c.pick(3) in [2, 3, 4])
    assert(c.pick(2) == 1)

main()
