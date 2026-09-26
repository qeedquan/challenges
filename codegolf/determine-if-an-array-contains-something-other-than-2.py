#!/usr/bin/env python3

"""

Take an array which consists of positive integers or arrays, output if it only contains 2s.

Output should be a truthy or falsey value (Sorry if this destroys answers)

Truthy Test Cases
[2]
[2,2]
[[2],[2,2],2]
[]
[[],[]]
Falsey Test Cases
[1]
[22]
[2,2,2,1]
[[1,2],2]
Standard Loopholes Are forbidden.

Default IO rules apply.

Code-golf, Fewest bytes wins!

"""

def f(l):
    if isinstance(l, int):
        return l == 2
    if len(l) == 0:
        return True
    return all(map(f, l))

def main():
    assert(f([2]) == True)
    assert(f([2, 2]) == True)
    assert(f([[2],[2, 2], 2]) == True)
    assert(f([]) == True)
    assert(f([[], []]) == True)

    assert(f([1]) == False)
    assert(f([22]) == False)
    assert(f([2, 2, 2, 1]) == False)
    assert(f([[1, 2], 2]) == False)

main()
