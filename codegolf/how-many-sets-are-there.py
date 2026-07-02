#!/usr/bin/env python3

"""

This is similar in concept to this challenge, but that is pretty restrictive on input and output and I think opening up these restrictions would lead to a completely different set of solutions that would be interesting in their own right.

Background
Set is a card game in which players compete to construct sets of three cards from a collection based on certain rules. Each card has four attributes: number, shape, color, and pattern. For a set to be valid, the cards must all either match or differ in each of the attributes.

For example, three cards being 1 empty green diamond, 1 shaded red diamond, and 1 filled purple diamond would constitute a Set. An example of a non-set is 1 empty green diamond, 2 shaded red diamonds, and 3 filled green diamonds. This is not a valid Set because while the numbers are different, patterns different, and shape the same, two of them share a color that the third does not.

The Challenge
Your job is to write a function that takes a list of twelve cards as a parameter and outputs the number of valid Sets. The cards must consist of a collection of four values, each representing an attribute on the card. Each attribute may have its own set of values to represent the different states, but there are only three states, and your choice of representation must be consistent across cards and inputs. This is Code Golf, so the shortest solution wins.

Test Cases
In my test cases, cards are represented by a 4-tuple with each attribute being encoded by a number 0-2. The first column is the expected output, and the second column is the input.

0  | (0, 2, 1, 1), (0, 0, 0, 2), (0, 1, 0, 0), (1, 2, 1, 0), (1, 1, 2, 2), (0, 1, 2, 1), (0, 1, 1, 0), (1, 0, 2, 0), (1, 1, 0, 1), (2, 2, 0, 1), (1, 0, 2, 1), (2, 1, 1, 2)
1  | (0, 2, 0, 2), (0, 2, 0, 0), (2, 2, 2, 1), (2, 0, 0, 0), (1, 0, 2, 2), (2, 1, 2, 2), (0, 1, 2, 1), (2, 0, 1, 1), (1, 0, 1, 1), (1, 2, 2, 1), (0, 1, 2, 2), (2, 1, 0, 2)
2  | (2, 0, 1, 0), (1, 0, 1, 1), (0, 1, 0, 0), (2, 0, 1, 2), (2, 0, 0, 1), (2, 2, 2, 0), (0, 1, 2, 2), (1, 1, 0, 0), (0, 2, 2, 2), (1, 1, 1, 1), (0, 1, 0, 2), (0, 1, 0, 1)
3  | (2, 1, 0, 2), (1, 0, 2, 1), (2, 2, 1, 1), (2, 0, 1, 2), (1, 2, 1, 1), (1, 2, 2, 2), (0, 0, 1, 2), (0, 0, 2, 1), (2, 0, 0, 0), (2, 1, 2, 0), (0, 2, 2, 0), (0, 0, 1, 0)
4  | (1, 0, 1, 0), (2, 2, 0, 1), (2, 0, 1, 2), (0, 0, 2, 1), (1, 2, 0, 1), (2, 2, 1, 0), (2, 0, 2, 1), (1, 1, 0, 2), (2, 1, 0, 2), (0, 1, 2, 2), (1, 2, 2, 0), (1, 0, 1, 2)
5  | (2, 2, 1, 0), (1, 2, 1, 0), (2, 0, 0, 0), (0, 0, 1, 2), (0, 0, 0, 2), (0, 1, 2, 0), (0, 2, 0, 1), (2, 2, 2, 0), (1, 2, 1, 2), (0, 1, 1, 0), (2, 0, 1, 0), (2, 1, 2, 1)
6  | (2, 1, 1, 0), (0, 1, 0, 1), (1, 1, 0, 2), (0, 0, 2, 2), (1, 0, 2, 0), (2, 1, 0, 0), (2, 2, 2, 2), (2, 0, 1, 1), (1, 0, 2, 1), (2, 2, 0, 1), (2, 2, 1, 2), (0, 1, 0, 0)
7  | (1, 0, 1, 0), (1, 1, 0, 0), (2, 1, 2, 0), (2, 0, 1, 1), (0, 0, 2, 0), (0, 2, 1, 1), (0, 1, 1, 0), (0, 0, 1, 2), (1, 0, 0, 2), (0, 2, 2, 1), (1, 0, 2, 2), (0, 0, 0, 1)
8  | (1, 2, 0, 1), (2, 2, 2, 1), (1, 2, 2, 0), (0, 1, 2, 2), (1, 1, 0, 1), (0, 0, 1, 1), (0, 2, 2, 0), (2, 0, 2, 1), (2, 1, 0, 2), (0, 1, 0, 0), (1, 2, 1, 2), (2, 0, 0, 2)
9  | (0, 2, 2, 1), (0, 1, 0, 0), (2, 1, 1, 0), (2, 0, 1, 0), (2, 0, 0, 2), (2, 1, 2, 1), (2, 2, 1, 0), (0, 2, 1, 1), (1, 2, 0, 2), (0, 0, 1, 0), (0, 1, 0, 2), (1, 1, 1, 0)
10 | (0, 1, 2, 0), (1, 1, 2, 0), (1, 0, 1, 2), (2, 0, 2, 0), (1, 1, 1, 2), (1, 2, 1, 2), (0, 2, 2, 0), (1, 1, 0, 1), (2, 0, 0, 1), (2, 1, 0, 1), (0, 0, 0, 1), (2, 2, 1, 2)

"""

from itertools import *

"""

@dingledooper

Get all triplets combination and see which one has a sum(x) mod 3 less than 1

"""
def count(a):
    c = 0
    for x in combinations(a, 3):
        v = 1
        for y in zip(*x):
            if sum(y)%3 >= 1:
                v = 0
                break
        c += v
    return c

def main():
    assert(count(((0, 2, 1, 1), (0, 0, 0, 2), (0, 1, 0, 0), (1, 2, 1, 0), (1, 1, 2, 2), (0, 1, 2, 1), (0, 1, 1, 0), (1, 0, 2, 0), (1, 1, 0, 1), (2, 2, 0, 1), (1, 0, 2, 1), (2, 1, 1, 2))) == 0)
    assert(count(((0, 2, 0, 2), (0, 2, 0, 0), (2, 2, 2, 1), (2, 0, 0, 0), (1, 0, 2, 2), (2, 1, 2, 2), (0, 1, 2, 1), (2, 0, 1, 1), (1, 0, 1, 1), (1, 2, 2, 1), (0, 1, 2, 2), (2, 1, 0, 2))) == 1)
    assert(count(((2, 0, 1, 0), (1, 0, 1, 1), (0, 1, 0, 0), (2, 0, 1, 2), (2, 0, 0, 1), (2, 2, 2, 0), (0, 1, 2, 2), (1, 1, 0, 0), (0, 2, 2, 2), (1, 1, 1, 1), (0, 1, 0, 2), (0, 1, 0, 1))) == 2)
    assert(count(((2, 1, 0, 2), (1, 0, 2, 1), (2, 2, 1, 1), (2, 0, 1, 2), (1, 2, 1, 1), (1, 2, 2, 2), (0, 0, 1, 2), (0, 0, 2, 1), (2, 0, 0, 0), (2, 1, 2, 0), (0, 2, 2, 0), (0, 0, 1, 0))) == 3)
    assert(count(((1, 0, 1, 0), (2, 2, 0, 1), (2, 0, 1, 2), (0, 0, 2, 1), (1, 2, 0, 1), (2, 2, 1, 0), (2, 0, 2, 1), (1, 1, 0, 2), (2, 1, 0, 2), (0, 1, 2, 2), (1, 2, 2, 0), (1, 0, 1, 2))) == 4)
    assert(count(((2, 2, 1, 0), (1, 2, 1, 0), (2, 0, 0, 0), (0, 0, 1, 2), (0, 0, 0, 2), (0, 1, 2, 0), (0, 2, 0, 1), (2, 2, 2, 0), (1, 2, 1, 2), (0, 1, 1, 0), (2, 0, 1, 0), (2, 1, 2, 1))) == 5)
    assert(count(((2, 1, 1, 0), (0, 1, 0, 1), (1, 1, 0, 2), (0, 0, 2, 2), (1, 0, 2, 0), (2, 1, 0, 0), (2, 2, 2, 2), (2, 0, 1, 1), (1, 0, 2, 1), (2, 2, 0, 1), (2, 2, 1, 2), (0, 1, 0, 0))) == 6)
    assert(count(((1, 0, 1, 0), (1, 1, 0, 0), (2, 1, 2, 0), (2, 0, 1, 1), (0, 0, 2, 0), (0, 2, 1, 1), (0, 1, 1, 0), (0, 0, 1, 2), (1, 0, 0, 2), (0, 2, 2, 1), (1, 0, 2, 2), (0, 0, 0, 1))) == 7)
    assert(count(((1, 2, 0, 1), (2, 2, 2, 1), (1, 2, 2, 0), (0, 1, 2, 2), (1, 1, 0, 1), (0, 0, 1, 1), (0, 2, 2, 0), (2, 0, 2, 1), (2, 1, 0, 2), (0, 1, 0, 0), (1, 2, 1, 2), (2, 0, 0, 2))) == 8)
    assert(count(((0, 2, 2, 1), (0, 1, 0, 0), (2, 1, 1, 0), (2, 0, 1, 0), (2, 0, 0, 2), (2, 1, 2, 1), (2, 2, 1, 0), (0, 2, 1, 1), (1, 2, 0, 2), (0, 0, 1, 0), (0, 1, 0, 2), (1, 1, 1, 0))) == 9)
    assert(count(((0, 1, 2, 0), (1, 1, 2, 0), (1, 0, 1, 2), (2, 0, 2, 0), (1, 1, 1, 2), (1, 2, 1, 2), (0, 2, 2, 0), (1, 1, 0, 1), (2, 0, 0, 1), (2, 1, 0, 1), (0, 0, 0, 1), (2, 2, 1, 2))) == 10)

main()
