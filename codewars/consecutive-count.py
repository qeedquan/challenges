#!/usr/bin/env python3

"""

I want to know the size of the longest consecutive elements of X in Y. You will receive two arguments: items and key. Return the length of the longest segment of consecutive keys in the given items.

Notes:

The items and the key will be either an integer or a string (consisting of letters only)
If the key does not appear in the items, return 0

Examples
90000, 0           -->  4
"abcdaaadse", "a"  -->  3
"abcdaaadse", "z"  -->  0

"""

def consecutive(items, key):
    items, key, count, result = str(items), str(key), 0, 0
    for item in items:
        if key == item:
            count += 1
            result = max(result, count)
        else:
            count = 0
    return result

def main():
    assert(consecutive(90000, 0) == 4)
    assert(consecutive("abcdaaadse", "a") == 3)
    assert(consecutive("abcdaaadse", "z") == 0)

main()
