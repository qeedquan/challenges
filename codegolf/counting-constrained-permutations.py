#!/usr/bin/env python3

"""

Challenge: Write a program or function that, given positive integers n, t, b, c, counts permutations of 1..n where:

Exactly t numbers are in their original position
Exactly b numbers are higher than their original position
Exactly c numbers are lower than their original position
Input: Four non-negative integers n, t, b, c in any reasonable format.

Output: The count of valid permutations satisfying all conditions.

Constraints:

t, b, c ≥ 0
t + b + c = n (you may assume inputs satisfy this)
Test cases:

n=3, t=1, b=1, c=1 → 3 
n=2, t=2, b=0, c=0 → 1  
n=3, t=0, b=2, c=1 → 1  
n=4, t=1, b=2, c=1 → 4
Example explanation for n=3, t=1, b=1, c=1:
The three valid permutations are:

[1,3,2]: 1 fixed, 3 higher, 2 lower
[2,1,3]: 3 fixed, 2 higher, 1 lower
[3,2,1]: 2 fixed, 1 lower, 3 higher
This is code-golf, so shortest solution in bytes wins!

"""

from itertools import permutations

def count_permutations(size, fixed, below, above):
    result = 0
    target = ([-1]*below + [0]*fixed + [1]*above)
    for permutation in permutations(range(size)):
        group = []
        for index, value in enumerate(permutation):
            group.append((value > index) - (value < index))
        if sorted(group) == target:
            result += 1
    return result

def main():
    assert(count_permutations(3, 1, 1, 1) == 3)
    assert(count_permutations(2, 2, 0, 0) == 1)
    assert(count_permutations(3, 0, 2, 1) == 1)
    assert(count_permutations(4, 1, 2, 1) == 4)
    assert(count_permutations(6, 1, 3, 2) == 126)

main()
