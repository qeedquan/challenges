#!/usr/bin/env python3

"""

This is inspired by an 05AB1E answer by Magic Octupus Urn.

Given two arguments, a positive integer and a string/list of characters:

    Translate the number to base-n, where n is the length of the string.
    For each character, replace every appearance of the index of that character in the base-n number with that character.
    Print or return the new string.

Examples:

Input:
2740, ["|","_"]
2740 -> 101010110100 in base 2
     -> Replace 0s with "|" and 1s with "_"
Output: _|_|_|__|_||

Input:
698911, ["c","h","a","o"]
698911 ->  2222220133 in base 4
       ->  Replace 0s with "c", 1s with "h", 2s with "a", and 3s with "o"
Output -> "aaaaaachoo"

Input:
1928149325670647244912100789213626616560861130859431492905908574660758972167966, [" ","\n","|","_","-"]
Output:
    __   __
   |  |_|  |
___|       |___
-   -   -   -
 - - - - - - -
- - - - - - - -
_______________

Input: 3446503265645381015412, [':', '\n', '.', '_', '=', ' ', ')', '(', ',']
Output:
_===_
(.,.)
( : )
( : )

Rules:

    IO is flexible.
        You can take the number in any base, as long as it is consistent between inputs
        The list of characters has to be 0-indexed though, where 0 is the first character and n-1 is the last
    Possible characters can be any printable ASCII, along with whitespace such as tabs and newlines
    The given list of characters will have a length in the range 2-10 inclusive. That is, the smallest base is binary and the largest is decimal (no pesky letters here)
    Standard loopholes are forbidden
    Feel free to answer even if your language can't handle the larger test cases.

As this is code-golf, the shortest code for each language wins. (I know all you golfing languages have one byte built-ins ready to go ;)

"""

def uncompress(value, mapping):
    result = ""
    base = len(mapping)
    if base == 0:
        return result

    while value > 0:
        result += mapping[value % base]
        value //= base
    return result[::-1]

def main():
    print(uncompress(2740, ["|", "_"]))
    print(uncompress(698911, ["c", "h", "a", "o"]))
    print(uncompress(1928149325670647244912100789213626616560861130859431492905908574660758972167966, [" ","\n","|","_","-"]))
    print(uncompress(3446503265645381015412, [':', '\n', '.', '_', '=', ' ', ')', '(', ',']))

main()
