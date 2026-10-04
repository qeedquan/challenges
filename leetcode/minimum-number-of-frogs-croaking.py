#!/usr/bin/env python3

"""

You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs,
that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially.
The frogs have to print all five letters to finish a croak.
If the given string is not a combination of a valid "croak" return -1.

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1
Explanation: One frog yelling "croak" twice.

Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2
Explanation: The minimum number of frogs is two.
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.


Constraints:

1 <= croakOfFrogs.length <= 10^5
croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.

Hint 1
keep the frequency of all characters from "croak" using a hashmap.

Hint 2
For each character in the given string, greedily match it to a possible "croak".

"""

def count(frogs):
    KEYWORD = "croak"

    if len(frogs) == 0:
        return -1

    lookup = [0] * len(KEYWORD)
    result = 0
    for symbol in frogs:
        index = KEYWORD.find(symbol)
        lookup[index] += 1
        if lookup[index - 1]:
            lookup[index - 1] -= 1
        elif index == 0:
            result += 1
        else:
            return -1

    if result != lookup[-1]:
        return -1
    return result

def main():
    assert(count("croakcroak") == 1)
    assert(count("crcoakroak") == 2)
    assert(count("croakcrook") == -1)

main()

