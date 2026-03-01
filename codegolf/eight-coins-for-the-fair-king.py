#!/usr/bin/env python3

"""

This is a "counterpart" of another puzzle, Eight coins for the fair king on Puzzling.SE.

You can read the above puzzle for the background. The details about this puzzle are as follows.

A set of 8 kinds of coins of different values are created, the king wants you to find out the maximum N such that any number of price from 0 to N can be paid with a combination no more than 8 coins and without charges.

For example, (taken from Glorfindel's answer). If a set of coins of values 1, 2, 5, 13, 34, 89, 233, 610 are given, your program should output 1596, because every number between 0 and 1596 (inclusive) can be represented by the sum of no more than 8 numbers from the given list (numbers may repeat), while 1597 cannot be represented in that way.

In a mathematical way, if the input is a set S consisting of 8 positive integers, the desired output N satisfies that for any number n between 0 and N, there exists x1, x2, x3, ..., x8 such that

x1+x2+...+x8 = n and x1,x2,...,x8 ∈{0} ∪ S

Your goal is to write a program, a function, or a snippet that takes 8 numbers as input, and output the maximum N as described above.

Rules:

Flexible I/O allowed, so your program can take the input in any form that's best suitable. You may assume that the input numbers are sorted in the way that best suits your program.
Please state it in your answer if your program depends on input order
Input is a set of 8 different, positive integers (no zeros). The output is one non-negative integer.
In case there's no 1 in the input set, your program should output 0 because any number from 0 to 0 satisfies the requirement.
In the case of invalid input (the set contains zero, negative or duplicate numbers), your program can do anything.
Standard loopholes are forbidden.
Your program should run within a few minutes on a modern computer.
Test cases (mostly taken from the answers under the linked question on Puzzling):

[1, 2, 3, 4, 5, 6, 7, 8] => 64
[2, 3, 4, 5, 6, 7, 8, 9] => 0
[1, 3, 4, 5, 6, 7, 8, 9] => 72
[1, 2, 5, 13, 34, 89, 233, 610] => 1596
[1, 5, 16, 51, 130, 332, 471, 1082] => 2721
[1, 6, 20, 75, 175, 474, 756, 785] => 3356
This is a code-golf, so the shortest program or snippet in each language wins!

"""

# ported from @Mark answer
def eight_coins(c):
    x = set(c)
    if 1 not in x:
        return 0

    i = 0
    while i < 3:
        x |= {a + b for a in x for b in x}
        i += 1
    while {i + 1} & x:
        i += 1
    
    return i

def main():
    assert(eight_coins([1, 2, 3, 4, 5, 6, 7, 8]) == 64)
    assert(eight_coins([2, 3, 4, 5, 6, 7, 8, 9]) == 0)
    assert(eight_coins([1, 3, 4, 5, 6, 7, 8, 9]) == 72)
    assert(eight_coins([1, 2, 5, 13, 34, 89, 233, 610]) == 1596)
    assert(eight_coins([1, 5, 16, 51, 130, 332, 471, 1082]) == 2721)
    assert(eight_coins([1, 6, 20, 75, 175, 474, 756, 785]) == 3356)

main()
