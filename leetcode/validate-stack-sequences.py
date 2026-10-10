#!/usr/bin/env python3

"""

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.


Constraints:

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.

"""

def validate(pushed, popped):
    stack = []
    npush = 0
    npop = 0
    while True:
        while len(stack) > 0 and npop < len(popped) and stack[-1] == popped[npop]:
            stack.pop()
            npop += 1
        
        if npush >= len(pushed):
            return npop >= len(popped)

        stack.append(pushed[npush])
        npush += 1

def main():
    assert(validate([1, 2, 3, 4, 5], [4, 5, 3, 2, 1]) == True)
    assert(validate([1, 2, 3, 4, 5], [4, 3, 5, 1, 2]) == False)
    assert(validate([1, 2, 3, 4, 5], [5, 4, 3, 2]) == True)
    assert(validate([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]) == True)
    assert(validate([1, 2, 3, 4, 5], [2, 1, 4, 3, 5]) == True)

main()
