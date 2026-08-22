#!/usr/bin/env python3

"""

Task
Given a string s of lowercase letters ('a' - 'z'), get the maximum distance between two same letters, and return this distance along with the letter that formed it.

If there is more than one letter with the same maximum distance, return the one that appears in s first.

Input/Output
[input] string s
A string of lowercase Latin letters, where at least one letter appears twice.

[output] a string
The letter that formed the maximum distance and the distance itself.

Example
For s = "fffffahhhhhhaaahhhhbhhahhhhabxx", the output should be "a23".

The maximum distance is formed by the character 'a' from index 5 to index 27 (0-based). Therefore, the answer is "a23".

"""

def dsl(string):
    index0, index1 = {}, {}
    for index in range(len(string)):
        symbol = string[index]
        if string[index] not in index0:
            index0[symbol] = index
        else:
            index1[symbol] = index

    character, max_distance = 0, 0
    for key in index0:
        if key in index1:
            distance = index1[key] - index0[key] + 1
            if distance > max_distance:
                character, max_distance = key, distance
    return f"{character}{max_distance}"

def main():
    assert(dsl("fffffahhhhhhaaahhhhbhhahhhhabxx") == "a23")
    assert(dsl("ucabcabcabcdfxhuizfgrsuixacbcx") == "c28")
    assert(dsl("iaufzhaifxhuzofghabcbacdbuzoxih") == "i30")
    assert(dsl("axaxfaaiiiofizxuiox") == "x18")
    assert(dsl("fxfaufhacaaacaaabbbabaddb") == "a19")
    assert(dsl("haaafhahhhuuuiuuuuiiifxxx") == "f18")
    assert(dsl("fxauf") == "f5")

main()

