#!/usr/bin/env python3

"""

Write a function that takes as input a set of integers (can be a list, array or any other container with distinct numbers), and outputs the list of all its permutations.

Python (95 chars):

p=lambda s:s and sum(map(lambda e:map(lambda p:[e]+p,p(filter(lambda x:x!=e,s))),s),[]) or [[]]
It'd be nice to be beaten in the same language, but implementations in other languages are more than welcome!

"""

# Ported from @feersum solution
def permutation(a):
    return [p + [x] for x in a for p in permutation(a - {x})] or [[]]

def main():
    print(permutation({1, 2, 3}))
    print(permutation({1, 2, 3, 4}))

main()
