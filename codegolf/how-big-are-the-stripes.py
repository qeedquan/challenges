#!/usr/bin/env python3

"""

Challenge
Consider this infinite sequence:

... 111111 000000 111111 000000 111111 ...
      n      n      n      n      n

An  n-stripey integer is an integer whose binary representation is any “slice” out of this sequence.
For instance, 57,825 is 4-stripey because its binary representation is 1110000111100001:

... 0000 1111 0000 1111 0000 1111 0000 ...
     4    4    4    4    4    4    4

Given a positive integer, return any n for which it is n-stripey. You do not have to handle inputs with no valid outputs.

Test Cases
 Input: 57825
Binary: 1110000111100001
Output: 4

 Input: 2
Binary: 10
Output: 1 (or any number greater than 1)

 Input: 9
Binary: 1001
Output: 2

 Input: 255
Binary: 11111111
Output: 8 (or any number greater than 8)

 Input: 7937
Binary: 1111100000001
Output: 7

 Input: 257
Binary: 100000001
Output: 7

 Input: 2730
Binary: 101010101010
Output: 1

Scoring
You may use a function or a full program.
Standard loopholes and I/O methods apply.
This is code-golf, so shortest code in bytes wins.

"""

"""

Ported from @Albert Lang solution

xors the argument with itself shifted by 1, so we only need to count consecutive 0's

"""

def solve(n):
    w = (n ^ (n << 1)) | 1
    t = f"{w:b}".split("1")
    return len(max(t)) + 1

def main():
    assert(solve(57825) == 4)
    assert(solve(2) == 1)
    assert(solve(9) == 2)
    assert(solve(255) == 8)
    assert(solve(7937) == 7)
    assert(solve(257) == 7)
    assert(solve(2730) == 1)

main()

