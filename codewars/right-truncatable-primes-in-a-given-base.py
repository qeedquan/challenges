#!/usr/bin/env python3

"""

A right truncatable prime is a prime with the property that, if you remove the rightmost digit, the result will be prime, and you can repeat this until the number is one digit (by definition, one-digit primes are right-truncatable). An example of this in base 10 is 37397: the number itself is a prime, as is 3739, 373, 37, and 3.

But who said we have to be in base 10?

This exact same process can happen in any other base, and the process is very similar: in the base-b representation of a number, a number is base-b right truncatable if you can repeat the process of removing the last digit of that number, and it remains prime until the last digit. An example in a nonstandard base is the number 211135 in base 8 (70237 in base 10). The process looks like: 211135 (70237) -> 21113 (8779) -> 2111 (1097) -> 211 (137) -> 21 (17) -> 2 (2) and you can check for yourself using the base 10 representations in parentheses that it is prime at every step.

For convenience, we will call each of these descending truncations a set of primes, and the largest prime in each set is called the head -- to clarify, an example of a set in base 10 is 37397, 3739, 373, 37, 3, and the head of that set is 37397; an example set in base 8 is 211135, 21113, 2111, 211, 21, 2, and the head of that set is 211135, which is 70237 in base 10.

Your task in this kata is to write a method get_right_truncatable_primes that takes a base to work in, and will output a list of every such head in the given base. They can be in any order, so long as they're all represented exactly once. Good luck!

Using external prime-checkers is allowed - for example gmpy2s is_prime (which has been provided in the solution setup).

Notes: your inputs are guaranteed to be bounded between 2 <= b <= 21, as beyond 21 the primes get so large that primality test I've included is no longer deterministic.

Hint: something to be mindful of is that a number is independent of its representation in its base; that is to say, if a number is prime in one base, it will be prime in every base, so there's no need to worry about converting between bases; what you want to do is figure out how the base affects the process of truncating a number, and simulating that process without, for example, translating the number to a base and appending the digit to it.from gmpy2 import is_prime

"""

from sympy import isprime

def get_right_truncatable_primes(base):
    heads = []
    current = [p for p in range(2, base) if isprime(p)]
    while current:
        next_level = []
        for num in current:
            children = [num * base + d for d in range(base) if isprime(num * base + d)]
            if children:
                next_level.extend(children)
            else:
                heads.append(num)
        current = next_level
    return heads

def main():
    for base in range(11):
        print(get_right_truncatable_primes(base))

main()
