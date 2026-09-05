#!/usr/bin/env python3

"""

Inspired by an old manual...

The challenge
I define the ath suffix vector of b as the boolean list of length a with b trailing truthy values.

Write a program or function that, given a and b by any means, returns the ath suffix vector of b by any means.

Now this may seem trivial, but here is the catch: Your score is the byte count plus the earliest year your solution would have worked.

Rules
All standard rules apply, except that languages and language versions that were released after this challenge, may also be used.

Output using whatever representation of boolean values that your language uses, e.g. 1/0, True/False, TRUE/FALSE, "True"/"False", etc.

Output using whatever representation of lists that your language uses, e.g. 0 0 1, [False,False,True], (FALSE;FALSE;TRUE), {"False","False","True"}, etc.

You may assume that a ≥ b is always true and that they are of an appropriate data type.

Test cases
Given a = 7 and b = 3, return 0 0 0 0 1 1 1

Given a = 4 and b = 4, return [True,True,True,True]

Given a = 2 and b = 0, return (FALSE;FALSE)

Given a = 0 and b = 0, return {}

Example solution and scoring
I might want to submit the solution {⌽⍺↑⍵⍴1} using Dyalog APL. That would be a bytecount of 8. This is a dynamic function, which works from version 8.1 of Dyalog APL, released in 1998, so my total score is 2006. My submitted answer should look something like:

# Dyalog APL 8.1, 1998 + 8 = 2006
    {⌽⍺↑⍵⍴1}

Optional explanation...
Recommended: Link to documentation showing when the features you used were released.
Lowest score wins!

"""

def f(a, b):
    return [0]*(a - b) + [1]*b

def main():
    assert(f(7, 3) == [0, 0, 0, 0, 1, 1, 1])
    assert(f(4, 4) == [1, 1, 1, 1])
    assert(f(2, 0) == [0, 0])
    assert(f(0, 0) == [])

main()

