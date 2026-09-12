#!/usr/bin/env python3

"""

This challenge was originally posted on codidact.
https://codegolf.codidact.com/posts/288535

You are a low-level censor working for the Ministry of Media Accuracy. Part of your job is to make sure that certain words don't appear in publications. Every morning you get a fresh stack of next week's newspapers and its your job to comb through them and fix any of the words that were mistakenly included. A naive censor might simply remove the entire word completely, but you know that if you remove part of the word that still prevents the word from appearing in print. So for you it is a point of pride to remove as little of the offending word as possible while still ensuring it does not appear in print.

Task
Given non-empty strings X and Y output the longest substring of X which does not contain Y as a contiguous substring

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
For each input output pair a possible correct output is given, your output should always be the same length, but it is not necessary to reproduce these outputs exactly.

chat, cat -> chat
escathe, cat -> esathe
homology, o -> hmlgy
ccatt, cat -> cctt
aababbabab, abab -> aaabbbab
ababab, abab -> abbab
aaaaaaaa, aaa -> aa
a, a ->

"""

# Based on @SuperStormer solution
def censor(s, t):
    if t not in s:
        return s

    r = []
    for i in range(len(s)):
        r.append(censor(s[:i] + s[i+1:], t))
    return max(r, key=len)

def main():
    assert(censor("chat", "cat") == "chat")
    assert(censor("escathe", "cat") == "esathe")
    assert(censor("homology", "o") == "hmlgy")
    assert(censor("ccatt", "cat") == "cctt")
    assert(censor("aababbabab", "abab") == "aaabbbab")
    assert(censor("ababab", "abab") == "abbab")
    assert(censor("aaaaaaaa", "aaa") == "aa")
    assert(censor("a", "a") == "")

main()
