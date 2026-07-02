#!/usr/bin/env python3

"""

Write a function that removes every lone 9 that is inbetween 7s.

"79712312" --> "7712312"
"79797"    --> "777"

"""

def eat(s):
    r = ""
    for i in range(len(s)):
        if not (i > 0 and s[i-1:i+2] == "797"):
            r += s[i]
    return r

def main():
    assert(eat("79712312") == "7712312")
    assert(eat("79797") == "777")

main()
