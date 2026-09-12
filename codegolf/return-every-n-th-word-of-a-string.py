#!/usr/bin/env python3

"""

Your goal is to write a program that, given a number N and a string as input, will return a string containing every Nth word of the original string, starting from the first word.

Sample inputs/outputs:

N = 2, str = "This is a sentence"

"This a"
--
N = 2, str = "The quick brown fox jumped over the lazy dog."

"The brown jumped the dog."
--
N = 7, str = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa."

"Lorem elit. massa."
You're allowed to assume that the input will always contain at least N+1 words, and that words will always be delimited by the space character &#32;.

This is code-golf, so the shortest answer in bytes wins.

"""

def nthword(n, s):
    return ' '.join(s.split()[::n])

def main():
    print(nthword(2, "This is a sentence"))
    print(nthword(2, "The quick brown fox jumped over the lazy dog."))
    print(nthword(7, "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa."))

main()
