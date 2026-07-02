#!/usr/bin/env python3

"""

The rundown
Create a program that generates an array of random length with random numbers, then apply a series of rules that alter the array. After the rules have been applied, print the sum of the array unless specified otherwise

Array setup
The array must be a random length between 5 and 10 inclusive, with random integers between 1 and 20 inclusive. Each array length should have equal probability of happening and each integer should have an equal probability of being picked per element.

The 7 rules
The rules should act as if they were applied in sequence (eg: rule 1 acts before rule 2) and are only applied once. For proof of rule application, the array must be printed to console after each rule application and once before any rules are applied.

If the array contains a 7, subtract 1 from every element
If rule 1 is applied and the array now contains a 0, add 1 to each element
If the array contains a 13, exclude the 13, and all elements that follow, from the array
If the array contains a 2, exclude all odd numbers
If the array contains a 20, and the third element is even, return 20 as the sum then terminate. If a 20 is present and the third element is odd, return 20 times the length of the array as the sum then terminate.
If the sum is greater than 50, remove the last element repeatedly until it is less than or equal to 50
If the array contains a 16, print the sum in both decimal and hexadecimal.
Example
Here is an initial array,

[20, 2, 5, 7, 14, 8]
Rule 1 can be applied:

[19, 1, 4, 6, 13, 7]
Rule 3 is applied next:

[19, 1, 4, 6]
No other rules are needed, so the program returns 30 as the sum.

Notes
I'm not an experienced code golfer, although I can say my personal record is in Python 3 with 369 bytes.
The rules don't have to actually be applied in order, but have to act as if they did.

"""

def rule_1_2(array):
    if 7 not in array:
        return (array, False, False, 0)

    array = list(map(lambda x: x-1, array))
    if 0 in array:
        array = list(map(lambda x: x+1, array))
    return (array, True, False, 0)

def rule_3(array):
    applied = False
    try:
        i = array.index(13)
        array = array[:i]
        applied = True
    except:
        pass
    return (array, applied, False, 0)

def rule_4(array):
    applied = False
    if 2 in array:
        array = list(filter(lambda x: x%2 == 0, array))
        applied = True
    return (array, applied, False, 0)

def rule_5(array):
    if 20 not in array or len(array) < 3:
        return (array, False, False, 0)
    
    value = 20 * (len(array) * array[2]&1)
    return (array, True, True, value)

def rule_6(array):
    applied = False
    while sum(array) > 50:
        array = array[:len(array)-1]
        applied = True
    return (array, applied, False, 0)

def rule_7(array):
    applied = False
    if 16 in array:
        print(array)
        applied = True
    return (array, applied, False, 0)

def apply(array):
    rules = [rule_1_2, rule_3, rule_4, rule_5, rule_6, rule_7]
    while True:
        finished = True
        for rule in rules:
            array, applied, early_exit, value = rule(array)
            if early_exit:
                return value

            if applied:
                finished = False 
        
        if finished:
            break

    return sum(array)

def main():
    assert(apply([20, 2, 5, 7, 14, 8]) == 30)

main()
