#!/usr/bin/env python3

"""

You have to create a function namedone_two (oneTwo for Java or Preloaded.OneTwo for C#) that returns 1 or 2 with equal probabilities. one_two is already defined in a global scope and can be called everywhere.

Your goal is to create a function named one_two_three (oneTwoThree for Java or OneTwoThree for C#) that returns 1, 2 or 3 with equal probabilities using only the one_two function.

Do not try to cheat returning repeating non-random sequences. There is a randomness test especially for this case.

"""

from random import randint

def rand123():
    while True:
        x = randint(1, 2)
        y = randint(1, 2)
        if x > 1:
            return y
        if y > 1:
            return 3
    return -1

def sim(n):
    m = [0, 0, 0]
    for _ in range(n):
        m[rand123() - 1] += 1
    print(m)

def main():
    sim(100000)

main()
