#!/usr/bin/env python3

"""

Given an integer N as input, output the Nth permutapalindromic number.

A permutapalindromic number is a strictly positive integer such that there is at least one permutation of its digits that results in a palindrome (i.e. a number that is its own reverse).

For example, 117 is a permutapalindromic number since its digits can be permuted into 171, which is a palindrome.

We consider that numbers like 10 are not permutapalindromic numbers, even though 01 = 1 is a palindrome. We impose that the palindromic permutation must not have a leading zero (as such, 0 itself is not permutapalindromic).

Numbers that are already palindromes are also permutapalindromic, since permuting nothing is valid.

Inputs and outputs
N may be either 0-indexed or 1-indexed. Please indicate which of the two your answer uses.
The input can be taken through STDIN, as a function argument, or anything similar in your language of choice. The output can be written to STDOUT, returned from a function, or anything similar in your language of choice.
The input and output must be in the decimal base.
Test cases
The following test cases are 1-indexed. Your program must be able to pass any of the test cases presented here in at most 1 minute.

N      Output

1      1
2      2
3      3
4      4
5      5
6      6
7      7
8      8
9      9
10     11
42     181
100    404
128    511
256    994
270    1166

Scoring
This is code-golf, so the shortest answer in bytes wins.

"""

from itertools import permutations

def permutapalindromic(n):
    count = n
    found = []
    candidate = 2
    while len(found) < count:
        for number in range(1, candidate):
            digits = str(number)
            can_form_palindrome = any(
                arrangement == arrangement[::-1] and arrangement[0] != "0"
                for arrangement in permutations(digits)
            )
            if can_form_palindrome and number not in found:
                found.append(number)
        candidate += 1
    return found[-1]

def main():
    assert(permutapalindromic(1) == 1)
    assert(permutapalindromic(2) == 2)
    assert(permutapalindromic(3) == 3)
    assert(permutapalindromic(4) == 4)
    assert(permutapalindromic(5) == 5)
    assert(permutapalindromic(6) == 6)
    assert(permutapalindromic(7) == 7)
    assert(permutapalindromic(8) == 8)
    assert(permutapalindromic(9) == 9)
    assert(permutapalindromic(10) == 11)
    assert(permutapalindromic(42) == 181)
    assert(permutapalindromic(100) == 404)
    assert(permutapalindromic(128) == 511)
    assert(permutapalindromic(256) == 994)
    assert(permutapalindromic(270) == 1166)

main()
