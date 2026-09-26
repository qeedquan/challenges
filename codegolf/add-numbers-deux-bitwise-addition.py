#!/usr/bin/env python3

"""

Your job is to implement bitwise addition.

To ensure that this is done, you will compute and print the result of addition without carry (or bitwise XOR). Then, you will compute the carry of the addition (bitwise AND) and multiply it by two (bitwise left shift). If the carry is nonzero, then you add the carry and the previous result until the carry is zero, at which point you stop producing output. If all is done correctly, the final result printed should be the sum of the two integers that you received as input.

Here's an ungolfed reference implementation in C:

#include <stdio.h>

void print_add(unsigned a, unsigned b)
{
    unsigned carry;

    while(b)
    {
        carry = a & b;
        a ^= b;
        printf("%u\n", a);
        b = carry << 1;
    }
}
Input
Two positive integers in any convenient format.

Output
A list of positive integers in any convenient format representing each result of addition without carry. Leading/trailing whitespace/newlines are allowed.

Rules
This is code-golf. The answer with the least bytes in each language wins, which means that I will not accept an answer.
Standard loopholes are forbidden. This includes, but is not limited to, Abusing native number types to trivialize a problem.
Testcases
1, 1 -> 0, 2
3, 17 -> 18, 16, 20
6, 7 -> 1, 13
21, 19 -> 6, 36, 32, 40
10, 9 -> 3, 19
20, 20 -> 0, 40
Your code must work for at least all pairs of positive integers that your integer type can represent the sum of.

"""

def bitadd(a, b):
    r = []
    while b != 0:
        a, b = a ^ b, (a & b) << 1
        r.append(a)
    return r

def main():
    assert(bitadd(1, 1) == [0, 2])
    assert(bitadd(3, 17) == [18, 16, 20])
    assert(bitadd(6, 7) == [1, 13])
    assert(bitadd(21, 19) == [6, 36, 32, 40])
    assert(bitadd(10, 9) == [3, 19])
    assert(bitadd(20, 20) == [0, 40])

main()
