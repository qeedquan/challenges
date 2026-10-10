#!/usr/bin/env python3

"""

Given a large number (in base 10), such as 1234567891011121314151617, find prime "subnumbers" in it.
A prime "subnumber" is a consecutive sequence of digits (taken from the input), which represents a prime number (in base 10).

Input: A number (either a string, a file, or whatever you like).
Output: All prime subnumbers separated somehow (either in a list, a file, comma-separated strings...) If the result is empty, you can take any convention you like (hardcoded string, empty string, gibberish, but program should not crash.

Example
1234 -> 2, 3, 23
6542 -> 5, 2
14 -> [.. empty output]
This is code-golf. The shortest program wins!
[edit] : additional rule, program must be explained! Not everybody is fluent in Jelly :)

"""

from sympy import isprime

def find(n):
    m = {}
    r = []
    s = str(n)
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            p = int(s[i:j])
            if p not in m and isprime(p):
                r.append(p)
                m[p] = True
    return sorted(r)

def main():
    print(find(1234))
    print(find(6542))
    print(find(14))
    print(find(1234567891011121314151617))

main()
