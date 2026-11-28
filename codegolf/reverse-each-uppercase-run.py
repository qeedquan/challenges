#!/usr/bin/env python3

"""

Input
Input may be a string or an array/list of single-character strings.

Output
The output should be a string or an array of characters in which each maximal consecutive run of uppercase English letters (A–Z) is reversed independently, while all other characters remain unchanged.

Example
Consider this input:

Hello NASA! HTTP://ABC-def
Here is maximal consecutive runs of uppercase characters:

Hello NASA! HTTP://ABC-def
      <-->  <-->   <->
Reversing each, we obtain this output:

Hello ASAN! PTTH://CBA-def
Rules and Scoring
The input is a nonempty string containing printable ASCII characters.
Only uppercase English letters (A–Z) belong to the sequences being reversed.
Each maximal consecutive sequence is reversed independently.
All other characters remain in their original positions.
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

Leaderboard
Here's a Stack Snippet to generate a leaderboard and list of winners by language. To make sure your answer shows up, start it with a header of the form

## Language, N bytes
You can keep old scores in the header by using the strikethrough tags: <s>61</s> will appear as 61. You need to also add length of used flags of interpreter to your code length. For example if your flags are -E, then you need to add your score by 2.

"""

def solve(s):
    r = ""
    n = len(s)
    i = 0
    while i < n:
        if not s[i].isupper():
            r += s[i]
            i += 1
            continue
        
        j = i + 1
        while j < n and s[j].isupper():
            j += 1
        r += s[i:j][::-1]
        i = j
    return r

def main():
    assert(solve("Hello NASA! HTTP://ABC-def") == "Hello ASAN! PTTH://CBA-def")

main()
