#!/usr/bin/env python3

"""

Write Number in Expanded Form
You will be given a number and you will need to return it as a string in Expanded Form. For example:

   12 --> "10 + 2"
   45 --> "40 + 5"
70304 --> "70000 + 300 + 4"
NOTE: All numbers will be whole numbers greater than 0.

If you liked this kata, check out part 2!!

"""

def expand(n):
    if n == 0:
        return "0"

    p = '+'
    if n < 0:
        p = '-'

    r = ""
    s = str(abs(n))
    l = len(s)
    for i in range(l):
        if s[i] == '0':
            continue

        if i == 0 and p == '-':
            r += "%c" % (p)
        r += "%c%s" % (s[i], '0'*(l - i - 1))   
        if i + 1 < l:
            r += " %c " % (p)
    
    return r

def main():
    assert(expand(12) == "10 + 2")
    assert(expand(45) == "40 + 5")
    assert(expand(70304) == "70000 + 300 + 4")
    assert(expand(-24) == "-20 - 4")

main()
