#!/usr/bin/env python3

"""

For example, how many adjacent swaps are at least needed to convert some string such as BVVKCV to one without any instances of VK?

Input-length of the string will be within the range 1 <= length <= 200.
VK will be hardcoded across all test cases.

Input string examples:

Input:  VKVKVVVKVOVKVQKKKVVK
Output: 8

Input:  VVKEVKK
Output: 3

Input:  JUSTIN
Output: 0

"""

# @hyperneutrino - Basic BFS
def novk(string):
    seen = {string}
    count = 0
    while all("VK" in chars for chars in seen):
        next = set()
        for chars in seen:
            for i in range(len(chars) - 1):
                next.add(chars[:i] + chars[i+1] + chars[i] + chars[i+2:])
        seen = next
        count += 1

    return count

def main():
    assert(novk("BVVKCV") == 1)
    assert(novk("VKVKVVVKVOVKVQKKKVVK") == 8)
    assert(novk("VVKEVKK") == 3)
    assert(novk("JUSTIN") == 0)

main()
