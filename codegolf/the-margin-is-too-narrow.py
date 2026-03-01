#!/usr/bin/env python3

"""

Around the year 1637, Pierre de Fermat wrote in the margins of his copy of the Arithmetica:

It is impossible to separate a cube into two cubes, or a fourth power
into two fourth powers, or in general, any power higher than the
second, into two like powers. I have discovered a truly marvelous
proof of this, which this margin is too narrow to contain.
Unfortunately for us, the margin is still too narrow to contain the proof. Today, we are going to write into the margins a simple program that confirms the proof for arbitrary inputs.

The Challenge
We want a program for function that given a power, separates it into two pairs of two powers that are as close to the power as possible. We want the program that does this to be as small as possible so it can fit into the margins.

Input
The power and the power number: c, x

Constraints: c > 2 and x > 2

Input can be through program arguments, function arguments, or from the user.

Output
This exact string: "a^x + b^x < c^x" with a, b, c, and x replaced with their literal integer values. a and b must be chosen so that a^x + b^x < c^x and no other values of a or b would make it closer to c^x. Also: a>=b>0

Output can be through function return value, stdout, saved to a file, or displayed on screen.

Examples:

> 3 3
2^3 + 2^3 < 3^3
> 4 3
3^3 + 3^3 < 4^3
> 5 3
4^3 + 3^3 < 5^3
> 6 3
5^3 + 4^3 < 6^3
> 7 3
6^3 + 5^3 < 7^3
> 8 3
7^3 + 5^3 < 8^3
Due to Fermat's average writing skills, unprintable characters are not allowed. The program with the least number of characters wins.

"""

"""

@Toby Speight

Explanation
This is an iterative solution that zigzags the line defined by a^x + b^x = c^x. We start with a=c and b=1. Obviously, that puts us on the wrong side of the line, because c^x + 1 > c^x. We decrement a until we cross the line. When we're below the line, we increment b until we cross it in the other direction. Repeat until b meets a, remembering the best solution in A and B as we go. Then print it.

p is a simple recursive implementation of a^x (for x>0) since C provides no operator for exponentiation.

In pseudo-code:

a=c
b=1
M = c^x

while a >= b
do
   m = c^x - a^x - b^x
   if m < 0
      a -= 1
   else // (m > 0, by Fermat's Last Theorem)
      if m < M
         A,B,M = a,b,m
      b += 1
done
return A,B

"""
def solve(c, x):
    A, B = 0, 0
    a, b, M = c, 1, c**x
    while a >= b:
        m = c**x - a**x - b**x
        if m < 0:
            a -= 1
        else:
            if m < M:
                A, B, M = a, b, m
            b += 1
    return (A, B)

def main():
    assert(solve(3, 3) == (2, 2))
    assert(solve(4, 3) == (3, 3))
    assert(solve(5, 3) == (4, 3))
    assert(solve(6, 3) == (5, 4))
    assert(solve(7, 3) == (6, 5))
    assert(solve(8, 3) == (7, 5))

main()
