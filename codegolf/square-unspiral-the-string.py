#!/usr/bin/env python3

"""

Given a string, first square it as follows:

First, write the string.

abcde
Next, write the string rotated one left.

abcde
bcdea
Keep doing this until you have written len(string) lines.

abcde
bcdea
cdeab
deabc
eabcd
Now, read from the string like this:

----+
+--+|
|+>||
|+-+|
+---+
Which gives:

abcdeabcdcbaedcbcdeabaede
Print this string.

Test cases
abcdef -> abcdefabcdedcbafedcbcdefabcbafedefaf
cena! -> cena!cenanec!anena!cec!a!
ppcg -> ppcgppcppgcpcgpg
abc -> abcabacbc
ab -> abab
a -> a
 ->
Please comment if a test case is incorrect.

Remember, this is code-golf, so the code with the smallest number of bytes wins.

"""

from math import *

"""

@ETHproductions

Explanation
This takes advantage of the fact that the output for e.g. a length 5 string can be represented as:

abcdeabcd cbaedcb cdeab aed e
012345678 7654321 23456 543 4
where each digit represents an index in the string (starting at 0), modulo the length of the string. In other words, if n is the length of the string, we increment the index 2n - 1 times, then decrement it 2(n - 1) - 1 times, then increment it 2(n - 2) - 1 times, etc. This can be simplified to the following algorithm:

Start the index i at -1.
For each integer x in the range [n2..1]:
If floor(sqrt(x)) is of the same parity (even/odd) as n, increment i.
Otherwise, decrement i.
Add the character at index i mod n to the output.
This works because floor(sqrt(x)) switches parities after 2n - 1 iterations, then 2(n - 1) - 1 iterations, etc.

"""

def unspiral(s):
    n = len(s)
    i = -1
    r = ""
    for x in range(n*n, 0, -1):
        p = int(n - sqrt(x))
        if p&1 == 0:
            i += 1
        else:
            i -= 1
        r += s[i % n]
    return r

def main():
    assert(unspiral("abcde") == "abcdeabcdcbaedcbcdeabaede")
    assert(unspiral("abcdef") == "abcdefabcdedcbafedcbcdefabcbafedefaf")
    assert(unspiral("cena!") == "cena!cenanec!anena!cec!a!")
    assert(unspiral("ppcg") == "ppcgppcppgcpcgpg")
    assert(unspiral("abc") == "abcabacbc")
    assert(unspiral("ab") == "abab")
    assert(unspiral("a") == "a")
    assert(unspiral("") == "")

main()
