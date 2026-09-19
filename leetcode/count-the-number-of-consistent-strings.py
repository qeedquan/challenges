#!/usr/bin/env python3

"""

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.


Constraints:

1 <= words.length <= 10^4
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

"""

def contains(chars, word):
    for ch in word:
        if ch not in chars:
            return False
    return True

def consistent(allowed, words):
    count = 0
    chars = set(allowed)
    for word in words:
        if contains(chars, word):
            count += 1
    return count

def main():
    assert(consistent("ab", ["ad", "bd", "aaab", "baa", "badab"]) == 2)
    assert(consistent("abc", ["a", "b", "c", "ab", "ac", "bc", "abc"]) == 7)
    assert(consistent("cad", ["cc", "acd", "b", "ba", "bac", "bad", "ac", "d"]) == 4)

main()
