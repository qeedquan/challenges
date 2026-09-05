#!/usr/bin/env python3

"""

The split-complex numbers, also known as "perplex numbers" are similar to the complex numbers. Instead of i^2 = -1, however, we have j^2 = 1; j != +/-1. Each number takes the form of z = x + j*y.

In one attempt to limit the complexity of this challenge, I will use the symbol - to represent negation, as there will not be any subtraction.

Here are some examples for your viewing pleasure:

6 * 9 = 54            // real numbers still act normally
5 + -7 = -2
j*1 + j*1 = j*2           // two `j`s added together make a j*2
7 * j*1 = j*7           // multiplication is commutative & associative
j*1 + 2 = 2+j*1           // like oil and water, "combine" to form a split-complex number
j*1 + j*-3 = j*-2          // seems okay so far
j*j*1 = j*-1*j*-1 = 1     // kinda sketchy, but such is its inherent nature
j*j*-1 = j*-1*j*1 = -1
(2+j*3)+(4+j*7) = 6+j*10  // combine like terms
7 * (2+j*3) = 14+j*21 // distributive property
j * (2+j*3) = (j*2) + (j*j*3) = 3+j*2   // since j^2 = 1, multiplying my j "swaps" the coefficients
(2+j*3)*(4+j*7) = (2*4)+(2*j*7)+(j*3*4)+(j*3*j*7) = 8+j*14+j*12+21 = 29+j*26 // a complete multiplication

Challenge
The goal of this challenge is to evaluate an expression with split-complex numbers.

This is code-golf, the fewest bytes wins.

Input

Input will be a single line containing only the symbols +*()-, the digits 0123456789, and the letter j, with an optional newline. This string represents an expression, using infix notation and operator precedence (multiplication before addition, with parenthesis grouping).

The symbol - will always represent negation, never subtraction. If you so desire, you can replace - with either _ or ~ for ease of I/O.
Parenthesis can be nested up to three times to denote grouping: (1+(1+(1)))
The letter j will never be directly prefixed with negation, and will always be followed by *.
Parentheses will not be preceded by negation -(7), but instead like -1*(j*5+2)
There will never be implicit operations. All multiplication will be expressed as (7)*7 instead of (7)7, and as j*5 instead of j5.
No leading zeros.
Output

Output will be in the form of X+j*Y, where X and Y can be any integer. If an integer is negative, it should be prefixed with the negation sign.

Additional Restrictions
Although I am not aware of any language with native support, built-ins that deal with split-complex numbers are forbidden. Regular complex numbers are fair game.

Test Cases
Similar to the above examples, but tidied up. Input on one line and output the line beneath.

(2+j*3)+(4+j*7)
6+j*10

(2+j*3)*(4+j*7)
29+j*26

(-5+j*1+j*2+2)*(4+j*7)
9+j*-9

(1+j*-1)*(1+j*1)
0+j*0 // this is why division does not exist.

j*((j*-1)+2)
-1+j*2

(2+(5+-1*(j*1))+2)
9+j*-1

"""

from sympy import *
from sympy.abc import *

def perplexeval(eq):
    eq = expand(eq)
    return eq.subs(j**2, 1)

def main():
    assert(perplexeval((2 + j*3) + (4 + j*7)) == 6 + j*10)
    assert(perplexeval((2 + j*3) * (4 + j*7)) == 29 + j*26)
    assert(perplexeval((-5 + j*1 + j*2 + 2) * (4 + j*7)) == 9 + j*-9)
    assert(perplexeval((1 + j*-1) * (1 + j*1)) == 0 + j*0)
    assert(perplexeval(j * ((j*-1) + 2)) == -1 + j*2)
    assert(perplexeval((2 + (5 + -1*(j*1)) + 2)) == 9 + j*-1)

main()
