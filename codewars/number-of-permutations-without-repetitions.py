#!/usr/bin/env python3

"""

Write a function that takes a number or a string and gives back the number of permutations without repetitions that can generated using all of its element.; more on permutations here.

For example, starting with:

1
45
115
"abc"
You could respectively generate:

1
45,54
115,151,511
"abc","acb","bac","bca","cab","cba"
So you should have, in turn:

perms(1)==1
perms(45)==2
perms(115)==3
perms("abc")==6

"""

from collections import Counter
from math import factorial

def perms(value):
    string = str(value)
    counter = Counter(string)
    result = factorial(len(string))
    for index in counter:
        result //= factorial(counter[index])
    return result

def main():
    assert(perms(1) == 1)
    assert(perms(45) == 2)
    assert(perms(115) == 3)
    assert(perms(2) == 1)
    assert(perms(25) == 2)
    assert(perms(342) == 6)
    assert(perms(1397) == 24)
    assert(perms(76853) == 120)
    assert(perms("a") == 1)
    assert(perms("ab") == 2)
    assert(perms("abc") == 6)
    assert(perms(737) == 3)
    assert(perms(66666) == 1)

main()
