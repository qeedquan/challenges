#!/usr/bin/env python3

"""

This kata aims to show the vulnerabilities of hashing functions for short messages.

When provided with a SHA-256 hash, return the value that was hashed. You are also given the characters that make the expected value, but in alphabetical order.

The returned value is less than 10 characters long. Return nil for Ruby and Crystal, None for Python, null for for Java and Javascript when the hash cannot be cracked with the given characters.

Example:
Example arguments: '5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b', 'cdeo'
Correct output: 'code'

"""

from itertools import permutations
from hashlib import sha256

def crack(checksum, letters):
    for order in permutations(letters):
        word = ''.join(order)
        digest = sha256(bytes(word, 'utf-8')).hexdigest()
        if digest == checksum:
            return word
    return None

def main():
    assert(crack("5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b", "cdeo") == "code")

main()
