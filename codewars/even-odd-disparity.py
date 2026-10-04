#!/usr/bin/env python3

"""

Given an array, return the difference between the count of even numbers and the count of odd numbers. 0 will be considered an even number.

For example:
solve([0,1,2,3]) = 0 because there are two even numbers and two odd numbers. Even - Odd = 2 - 2 = 0.
Let's now add two letters to the last example:

solve([0,1,2,3,'a','b']) = 0. Again, Even - Odd = 2 - 2 = 0. Ignore letters.
The input will be an array of lowercase letters and numbers only.

In some languages (Haskell, C++, and others), input will be an array of strings:

solve ["0","1","2","3","a","b"] = 0
Good luck!

"""

def solve(a):
    c = [0, 0]
    for x in a:
        if isinstance(x, int):
            c[x & 1] += 1
    return c[0] - c[1]

def main():
    assert(solve([0, 1, 2, 3]) == 0)
    assert(solve([0, 1, 2, 3, 'a', 'b']) == 0)
    assert(solve(["0", "1", "2", "3"]) == 0)
    assert(solve(["0", "1", "2", "3", "a", "b"]) == 0)
    assert(solve(["0", "15", "z", "16", "m", "13", "14", "c", "9", "10", "13", "u", "4", "3"]) == 0)
    assert(solve([13, 6, 8, 15, 4, 8, 13]) == 1)
    assert(solve([1, 'a', 17, 8,'e', 3,'i', 12, 1]) == -2)

main()
