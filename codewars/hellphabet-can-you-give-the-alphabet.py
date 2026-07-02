#!/usr/bin/env python3

"""

Define a variable ALPHABET that contains the (english) alphabet in lowercase.


Too simple? Well, you can only use the following characters set:

 abcdefghijklmnopqrstuvwxyz().

(space included)


You code must starts with ALPHABET =  then respects the charset limitation.

Ofc you wouldn't cheat by importing the string module or using eval/exec...

"""

ALPHABET = str().join(sorted(set(c for c in str().join(dir(str)) if c.islower()).union(set(c for c in str().join(dir(dict)) if c.islower()))))

print(ALPHABET)
