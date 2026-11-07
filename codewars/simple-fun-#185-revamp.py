#!/usr/bin/env python3

"""

Task
Consider a string of lowercase Latin letters and space characters (" ").

First, rearrange the letters in each word alphabetically.

And then rearrange the words in ascending order of the sum of their characters' ASCII values.

If two or more words have the same ASCII value, rearrange them by their length in ascending order; If their length still equals to each other, rearrange them alphabetically.

Finally, return the result.

Example
For s = "batman is bruce wayne", the result should be "is bceru aenwy aamntb".

After rearranging the letters the string turns into "aamntb is bceru aenwy". The ASCII values of each word are: [627, 220, 529, 548]. After sorting the words the following string is obtained: "is bceru aenwy aamntb" (with ASCII values of [220, 529, 548, 627]).

For s = "peter parker is spiderman", the result should be "is eeprt aekprr adeimnprs"

(ASCII values: [220, 554, 645, 963])

Input/Output
[input] string s
A string of lowercase words. Each word is separated by exactly one space character.

[output] a string

"""

from functools import cmp_to_key

def cmp(a, b):
    x = y = 0
    for c in a:
        x += ord(c)
    for c in b:
        y += ord(c)
    return x - y 

def revamp(s):
    w = s.split(" ")
    for i in range(len(w)):
        w[i] = sorted(w[i])
    w = sorted(w, key=cmp_to_key(cmp))
    return ' '.join([''.join(x) for x in w])

def main():
    assert(revamp("batman is bruce wayne") == "is bceru aenwy aabmnt")
    assert(revamp("peter parker is spiderman") == "is eeprt aekprr adeimnprs")
    assert(revamp("codewars is great") == "is aegrt acdeorsw")
    assert(revamp("airplanes in the night sky") == "in eht ksy ghint aaeilnprs")

main()

