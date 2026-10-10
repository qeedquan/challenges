#!/usr/bin/env python3

"""

Write a program to determine if a periodic sequence of positive integers has the property that, for every integer n occurring in the sequence, there are never more than n other integers between two consecutive occurrences of n.

For example, 2, 3, 5, 2, 3, 6, 2, 3, 5, 2, 3, 6, ... does have this property: every pair of consecutive occurrences of 2 have at most two integers between them (such as 2, 3, 5, 2 and 2, 3, 6, 2; every pair of consecutive occurrences of 3 have at most three integers between them; and the same for 5 and 6.

However, 2, 3, 5, 2, 3, 4, 2, 3, 5, 2, 3, 4, ... does not have this property: two consecutive occurrences of 4, namely 4, 2, 3, 5, 2, 3, 4, have more than four integers between them.

Input: a reasonable representation of a periodic sequence of positive integers. For example, a finite list such as {2, 3, 5, 2, 3, 6} can represent the first infinite sequence 2, 3, 5, 2, 3, 6, 2, 3, 5, 2, 3, 6, ... above. (For that matter, the problem could be stated for finite lists that wrap around instead of for infinite periodic lists.)

Output: a truthy/falsy value.

Truthy examples:

{1}
{8, 9}
{2, 3, 4}
{5, 5, 3, 3, 6}
{2, 3, 5, 2, 3, 6}
{6, 7, 3, 5, 3, 7}
{9, 4, 6, 7, 4, 5}
{1, 1, 1, 1, 1, 100, 1}
{1, 9, 1, 8, 1, 7, 1, 11}

Falsy examples:

{1, 2, 3}
{2, 3, 9, 5}
{3, 5, 4, 4, 6}
{2, 3, 5, 2, 3, 4}
{3, 5, 7, 5, 9, 3, 7}
{5, 6, 7, 8, 9, 10, 11}
{1, 9, 1, 8, 1, 6, 1, 11}
This is codegolf, so the shortest code wins. Answers in all languages are encouraged.

"""

def solve(values):
    doubled = values + values
    for index, value in enumerate(values, start=1):
        if value not in doubled[index:index + value + 1]:
            return False
    return True

def main():
    assert(solve([1]) == True)
    assert(solve([8, 9]) == True)
    assert(solve([2, 3, 4]) == True)
    assert(solve([5, 5, 3, 3, 6]) == True)
    assert(solve([2, 3, 5, 2, 3, 6]) == True)
    assert(solve([6, 7, 3, 5, 3, 7]) == True)
    assert(solve([9, 4, 6, 7, 4, 5]) == True)
    assert(solve([1, 1, 1, 1, 1, 100, 1]) == True)
    assert(solve([1, 9, 1, 8, 1, 7, 1, 11]) == True)
    
    assert(solve([1, 2, 3]) == False)
    assert(solve([2, 3, 9, 5]) == False)
    assert(solve([3, 5, 4, 4, 6]) == False)
    assert(solve([2, 3, 5, 2, 3, 4]) == False)
    assert(solve([3, 5, 7, 5, 9, 3, 7]) == False)
    assert(solve([5, 6, 7, 8, 9, 10, 11]) == False)
    assert(solve([1, 9, 1, 8, 1, 6, 1, 11]) == False)

main()
