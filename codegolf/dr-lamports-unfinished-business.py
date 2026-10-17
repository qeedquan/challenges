#!/usr/bin/env python3

r"""

Introduction
Dr. Leslie Lamport, of the eponymous Lamport one-time signature scheme, is getting rather old. But he can't die until his most famous algorithm gets all the kinks ironed out!

In particular, that scheme had one internal component he was never satisfied with:

We hope that someone can find a more elegant method for constructing the function G

Challenge
Today, we're helping him prepare to leave by constructing a function R that takes the output of our one-way function φ (likely a hash function), and injectively uses it to select a subset of the user's private key, according to the following specifications:

Your function takes two arguments: the output of hash function φ (as a data blob, octet stream, or similar appropriate native datatype), and an ordered set (in your choice of appropriate native datatype).

If your language's standard library has a bitstring datatype [ex: Java; not Python], you may choose to take d as it with no penalty; if it does not, then unpacking the bytestring (or finding some clever way to avoid or vectorize the doing-of!) is your responsibility.
The nth bit of φ's output chooses whether the 2*nth element or the 2*n+1th element will be included in the subset. If φ outputs a 24-bit data blob, then 24 elements will be chosen.

FOR EXAMPLE: if the second bit of φ(m) is 1, then the fourth element of pk will be chosen. If this bit is, instead, 0, then the third element of pk will be chosen. (There are examples included below.)

Naturally, for 1-indexed languages, the nth bit chooses between the 2*n-1th and 2*nth elements.

behavior is totally undefined in the event that φ returns something with more bits than half the number of elements in pk; don't even consider this case.

Your function returns the thus-chosen subset of pk.

While the input set is ordered, the output set does not need to be ordered (and, if it is an ordered datatype, all possible orderings are allowed with no penalty). The function merely has to identify a subset of the ordered input set, so any ordering on its output would be redundant anyway.
This is a standard golfing challenge; shorter answers are better than longer answers.

Example Input and Output
For all examples,
N = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64

φ = MD5, with the digest truncated to the first 24 bits
m = [empty string]
φ(m) -> \xd4\x1d\x8c

R(φ(m), N) -> 2, 4, 5, 8, 9, 12, 13, 15, 17, 19, 21, 24, 26, 28, 29, 32, 34, 35, 37, 39, 42, 44, 45, 47
φ = CRC32
m = "Hello, World" (ASCII)
φ(m) -> \x26\x5b\x86\xc6

R(φ(m), N) -> 1, 3, 6, 7, 9, 12, 14, 15, 17, 20, 21, 24, 26, 27, 30, 32, 34, 35, 37, 39, 41, 44, 46, 47, 50, 52, 53, 55, 57, 60, 62, 63}
d = \x00\x00 = two bytes, with all bits "off"

R(d, N) -> 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31
d = \xFF = one byte, with all bits "on"

R(d, N) -> 2, 4, 6, 8, 10, 12, 14, 16
φ = Constant function returning the single byte \x1d
m = [any input]

R(φ(m), N) -> 1, 3, 5, 8, 10, 12, 13, 16
Python 3, 281 bytes:
(281 does not include comments, type hints, docstrings, or the example φ)

def _iterbits(data):
    yield from (((byte & (0b1 << k)) >> k) for byte in data for k in reversed(range(8)))

def R(digest: bytes, pk: OrderedSet | list | tuple) -> set:
    "Reference solution"
    included_indices = set(2 * n + bit for n, bit in enumerate(_iterbits(digest)))
    return set(k for i, k in enumerate(pk) if i in included_indices)

def φ(m):
    "Example hash function to help you run your own test cases\n\nReturns an MD5 digest truncated to 24 bits"
    return hashlib.md5(m).digest()[:3]

"""

import hashlib

def _iterbits(data):
    yield from (((byte & (0b1 << k)) >> k) for byte in data for k in reversed(range(8)))

def R(digest, pk):
    included_indices = set(2 * n + bit for n, bit in enumerate(_iterbits(digest)))
    return set(k for i, k in enumerate(pk) if i in included_indices)

def φ(m):
    return hashlib.md5(m).digest()[:3]

def main():
    print(R(φ(b"Hello, World"), range(48)))

main()
