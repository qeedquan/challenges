#!/usr/bin/env python3

"""

This is a code golf challenge I thought of with a mathematical bent. The challenge is to write the shortest code possible such that it is an open question whether or not the code terminates. An example of what I mean could be the following piece of python code, adapted from an anwser to this cs stackexchange question.

def is_perfect(n):
    return sum(i for i in range(1, n) if n % i == 0) == n

n = 3
while not is_perfect(n):
    n = n + 2
Mathematicians conjecture that there are no odd perfect numbers, but it has never been proven, so no one knows if this piece of code will ever terminate. Can you come up with other pieces of code (perhaps relying on other open problems like the Collatz conjecture, or the twin primes conjecture) that are shorter, but for which it is unknown whether or not they terminate?

Edit: Some people have brought up a good additional rule - The solutions to the question should be deterministic. Although it might be even more interesting if you could find shorter solutions using nondeterminism. In this case, the rule would be to find a snippet for which the probability of termination is unknown.

"""

from itertools import count

# https://oeis.org/A000396
def perfect(n):
    return sum(i for i in range(1, n) if n%i == 0) == n

def main():
    n = 3
    while not perfect(n):
        n += 2 

main()
