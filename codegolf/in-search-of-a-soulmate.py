#!/usr/bin/env python3

"""

Given a nonempty finite list of integers, output a truthy value if there are exactly two equal entries and all other entries are distinct, and a falsey value otherwise.

Examples
truthy:
[1,1]
[1,2,1]
[1,6,3,4,4,7,9]

falsey:
[0]
[1,1,1]
[1,1,1,2]
[1,1,2,2]
[2,1,2,1,2]
[1,2,3,4,5]

"""

def soulmate(a):
    return len(set(a)) + 1 == len(a)

def main():
    assert(soulmate([1, 1]) == True)
    assert(soulmate([1, 2, 1]) == True)
    assert(soulmate([1, 6, 3, 4, 4, 7, 9]) == True)
    
    assert(soulmate([1, 3, 3, 3, 0]) == False)
    assert(soulmate([0]) == False)
    assert(soulmate([1, 1, 1]) == False)
    assert(soulmate([1, 1, 1, 2]) == False)
    assert(soulmate([1, 1, 2, 2]) == False)
    assert(soulmate([2, 1, 2, 1, 2]) == False)
    assert(soulmate([1, 2, 3, 4, 5]) == False)

main()
