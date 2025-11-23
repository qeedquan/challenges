#!/usr/bin/env python3

"""

Given a string of integers, count how many times that integer repeats itself, then return a string showing the count and the integer.

Example: countMe('1123') (count_me in Ruby)

Here 1 comes twice so <count><integer> will be "21"
then 2 comes once so <count><integer> will be "12"
then 3 comes once so <count><integer> will be "13"

hence output string will be "211213".

Similarly countMe('211213') will return '1221121113' (1 time 2, 2 times 1, 1 time 2, 1 time 1, 1 time 3)

Return "" for empty, nil or non numeric strings

"""

def countme(s):
    r = ""
    n = len(s)
    i = 0
    while i < n:
        if not s[i].isdigit():
            return ""

        j = i + 1
        while j < n and s[i] == s[j]:
            j += 1
        r += str(j - i) + s[i]
        i = j
    return r

def main():
    assert(countme("1123") == "211213")
    assert(countme("1") == "11")
    assert(countme("211213") == "1221121113")
    assert(countme("a123") == "")

main()
