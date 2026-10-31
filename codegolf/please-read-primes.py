#!/usr/bin/env python3

"""

Do you know the book Murderous Maths, in the Horrible Science series? In the book, the Laplace Princess' "ridiculous" cipher might be interesting enough and simple enough to be a code-golf challenge.

Task
The original cipher looks like this:

Please read primes elephant help you me like cold

The nth word is only meaningful if it is a prime. So, the cipher becomes:

read primes help me

Your task is to write a program that inputs the cipher and outputs the plaintext.

Rules
You can take the input in any acceptable forms, e. g. an list of words.

The input will only consist of printable-ASCII characters.

You can use 0-based index or 1-based index.

A "Word" includes any punctuation. For example:

This is, "a" great test! I think.
should output

is, "a" test! think.

"""

from sympy import nextprime

def read_primes(text):
    tokens = text.split(' ')
    result = []
    index = 2
    while index <= len(tokens):
        result.append(tokens[index - 1])
        index = nextprime(index)
    return " ".join(result)

def main():
    print(read_primes('Please read primes elephant help you me like cold'))
    print(read_primes('This is, "a" great test! I think.'))

main()
