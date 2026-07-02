#!/usr/bin/env python3

"""

Challenge
Derivatives are very important mathematical tools that has been widely applied in physics, chemistry, biology, economics, psychology and more to handle all kinds of problems. Expressions with multiple variables are also very common.

In the scope of this challenge, a polynomial string ("polystr") is defined by the following BNF (Backus–Naur form):

<polystr> ::= <term> | <term><plusminus><polystr>

<plusminus> ::= "+" | "-"

<term> ::= <coeff> | <coeff><baseterm> | <baseterm>

<baseterm> ::= <variable> | <variable><exponent> | <baseterm><baseterm>

<coeff> ::= positive_integer

<exponent> ::= positive_integer

<variable> ::= lowercase_ASCII_letters
Where positive_integer and lowercase_ASCII_letters are quite self-explanatory.

For example, The string 3x2y-x3y-x2y+5 means 3*(x^2)*y-(x^3)*y-(x^2)*y+5. The terms given in the input may appear in any order, and the variables in each term also may appear in any order. So for example 5-yx2-x3y+y3x2 is also a valid input and is in fact the same as the previous example.

The rule for taking partial derivative is just doing it term by term. If the variable appears does not appear in the term, the derivative is zero. Otherwise, the coefficient of the term is multiplied by the exponent of that variable, and then the exponent of the variable is decreased by one. The exponents for other variables do not change. This is just following the definition in mathematics. In addition, if the resulting exponent is zero, remove the variable from the term.

For example, to take the partial derivative of 5z-z2y2-5w3y with respect to y. The following process is done (in accordance with the BNF defined above, the "coefficient" are all taken to be positive numbers, i.e. the signs are considered separately)

          5z          -   z2y2        - 5w3y

Coeff                 1->1*2=2      5->5*1=5
Expon                 2->2-1=1      1->1-1=0
Term                  -   2yz2         - 5w3
      (y is not here            (expon 0->y removed)
     so the term is 0)

The result is -2yz2-5w3y.

On the other hand, if the above expression is taken partial derivative with respect to a, the result is 0 because a is in none of the terms.

Your task is to write a function or a full program to calculate this derivative. It should take a polynomial string and a single character (the variable to take derivative with respect to), and return the derivative in the simplest form.

"Simplest form" means three things.

The number 0 (not the digit) should not appear in the output unless the output itself is just 0. So neither 0+10y nor 3-y0z will be valid output and should be transformed to 10y and 3-z, respectively.

The number 1 should not appear as an exponent or a coefficient, but can appear as a standalone term itself.

The terms with exactly the same set of variables and exponents should be merged, which means 3a2b5-4b5a2 is not a valid output, and it should be -a2b5 instead. More information about the input and output can be found in the "Specs" section.

Test Cases
Input
Output

2xy+4ax-5+7mx4-4-7x4m, x
2y+4a

4upv+5u2v3w4-4w4u2v3+qr-v,v
4up+3u2v2w4-1

12ux-7x2m3+ab5,q
0

-a+10ca11y-1nv3rt3d-poly, a
-1+110ca10y

1y+1x3y, y
1+x3
Specs
Input can be taken through standard forms. In other words, you can take input as a string, a list of characters, a nested array of coefficients, variables (possibly denoted by their ASCII value minus 'a' or something alike) and exponents, etc. You are also free to change the string to 2*x^3y^2 or alike instead of 2x3y2.
However, please do not use the input [2,0,0,0,1,0,0,3,0,0,...0] (an array of 27 elements) for the term 2dg, or any other verbose format that enumerates the 26 letters like this. Your input format should also be able to treat ab and ba as different inputs (so the 27-element array format is invalid due to this restriction as well).

Each variable (letter) will only appear once in each term of the input, that means xx will not appear and will always be presented as x2, nor will something like a3b4a2 appear.

To reiterate, the terms in the input may appear in any order.

You are also free to choose the output format provided that the verbose format mentioned above is avoided. The output should however always be in the simplest form as defined above. Just like the input, the terms in the output can appear in any order, and the variables in each term can also appear in any order and does not have to be consistent between terms. That means pu+2up2 is a valid output. The sign for the leading term can be either positive or negative and -y+3x and 3x-y are both valid, so is +3x-y.

The input are always given such that all the coefficients and exponents in the output will be less than 232-1, or the largest integer your language can handle, whichever is smaller. Claiming that the largest integer your language can handle is unreasonably small and trivializing the challenge falls into the category of default loopholes.

This is code-golf, the lowest number of bytes wins.

As usual, default loopholes apply here.

Edit: Since most of the answers so far turn out to be internals that do the whole challenge, and despite knowing there are builtins I don't have the intention to ban such internals from the very beginning, nor do I have now. I will make the winning criteria one that is based on a per-language basis, i.e. the submission with the least bytes in each language wins in that language. I will add a standard snippet for a catalogue if there are enough submissions. Feel free to go on submitting builtins to showcase the power of your language but please do not hesitate to submit your non-builtin answers even if it's way longer and your language does not have a builtin. Happy code golfing in your favorite language!

"""

from sympy import *
from sympy.abc import *

def main():
    assert(diff(2*x*y + 4*a*x - 5 + 7*m*x**4 - 4 - 7*x**4*m, x) == (2*y + 4*a))
    assert(diff(4*u*p*v + 5*u**2*v**3*w**4 - 4*w**4*u**2*v**3 + q*r - v, v) == (4*u*p + 3*u**2*v**2*w**4 - 1))
    assert(diff(12*u*x - 7*x**2*m**3 + a*b**5, q) == 0)
    assert(diff(-a + 10*c*a**11*y - 1*n*v**3*r*t*3*d - p*o*l*y, a) == (-1 + 110*c*a**10*y))
    assert(diff(1*y + 1*x**3*y, y) == (1 + x**3))

main()
