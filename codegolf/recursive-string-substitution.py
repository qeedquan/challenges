#!/usr/bin/env python3

"""

The task
Write a program or function that given three strings A, B, C produces an output string where each instance of B in A has been recursively substituted with C. Recursively substituting means repeating a substitution where at each step all non-overlapping instances of B in A (chosen greedily from left to right) are replaced with C until B is no more contained in A.

Input/Output
You may use any of the default methods for I/O.
Strings will contain only printable ASCII characters (and may contain any of them) .
B will never be an empty string, while A and C might be.
Strings are to be considered plaintext, you can't for example treat B as a Regex pattern.
Some combinations of inputs will never terminate. Your program can do anything in those cases.
Test cases
These are in the format: A/B/C\nOutput

Hello, world!/world!/PPCG
Hello, PPCG

Uppercase is up/up/down
Uppercase is down

ababababa/aba/ccc
cccbcccba

delete/e/{empty string}
dlt

{empty string}/no/effect
{empty string}

llllrrrr/lr/rl
rrrrllll

+-+-+-+/+-+/+
+

ababababa/aba/bada
badabbadbada

abaaba/aba/ab
abb

((())())())/()/{empty string}
)

Examples that don't terminate:

grow/ow/oow

loop/lo/lo

"""

"""

@xnor

To reach a fixed point if one exists, it suffices to do replacements equal to the length of the original string.

"""

def replace(s):
    t = s.split('/')
    if len(t) != 3:
        return "/"
    
    a, b, c, d, f, n = t[0], t[1], t[2], t[0], t[0], len(t[0])
    for i in range(n):
        d, a = a, a.replace(b, c)
        if a == d:
            break
    
    if a != d or (a == f and f != ""):
        return "/"
    
    return a

def main():
    assert(replace("Hello, world!/world!/PPCG") == "Hello, PPCG")
    assert(replace("Uppercase is up/up/down") == "Uppercase is down")
    assert(replace("ababababa/aba/ccc") == "cccbcccba")
    assert(replace("delete/e/") == "dlt")
    assert(replace("/no/effect") == "")
    assert(replace("llllrrrr/lr/rl") == "rrrrllll")
    assert(replace("+-+-+-+/+-+/+") == "+")
    assert(replace("ababababa/aba/bada") == "badabbadbada")
    assert(replace("abaaba/aba/ab") == "abb")
    assert(replace("((())())())/()/") == ")")
    assert(replace("grow/ow/oow") == "/")
    assert(replace("loop/lo/lo") == "/")
    assert(replace("((())())())/()/") == ")")

main()
