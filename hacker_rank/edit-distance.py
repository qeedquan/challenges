#!/usr/bin/env python3

"""

"Edit distance" (also known as Levenshtein distance) measures the minimum the number of simple changes to move from one string to another.
Possible changes include the insertion of a single character, the deletion of a single character, or the substitution from one character to another.
Your program must calculate edit distance between pairs of strings.

Input Format

A value N on a line by itself indicating the number of test cases.
Each test case is presented on subsequent pairs of lines with a string on each line.
Strings will consist of non-whitespace printable characters.

Output Format

The edit distance of each test case should be output, one value per line.

Sample Input

1
ABCDE
ABDE

Sample Output

1

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def lev(a, b):
    if len(b) == 0:
        return len(a)
    
    if len(a) == 0:
        return len(b)

    if a[0] == b[0]:
        return lev(a[1:], b[1:])

    x = lev(a[1:], b)
    y = lev(a, b[1:])
    z = lev(a[1:], b[1:])
    return 1 + min(x, y, z)

def main():
    assert(lev("ABCDE", "ABDE") == 1)
    assert(lev("atoll", "bowl") == 3)
    assert(lev("tar", "tarp") == 1)
    assert(lev("turing", "tarpit") == 4)
    assert(lev("antidisestablishmentarianism", "bulb") == 27)
    assert(lev("kitten", "sitting") == 3)

main()
