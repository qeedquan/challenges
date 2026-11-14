#!/usr/bin/env python3

"""

Task:
Your program is given a proper, positive simple fraction in the format <numerator>/<denominator>.

For this input, it must find two fractions.

A fraction that is less than the input.
A fraction that is greater than the input.
Both fractions must have a lower denominator than the input. Of all possible fractions, they should have the lowest difference to the input.

Output:
Your program's output must be:

A fraction that is smaller than the input, in the format <numerator>/<denominator>.
Followed by a space character (ASCII-code 32).
Followed by a fraction that is greater than the input, in the format <numerator>/<denominator>.
As follows:

«fraction that is < input» «fraction that is > input»

Rules:
All fractions outputted must be in lowest terms.
All fractions outputted must be proper fractions.
If there are no proper fractions possible that are allowed by the rules, you must output 0 instead of a fraction < input, and 1 instead of a fraction > input.
You can choose whether you want to receive the fraction as a command-line argument (e.g. yourprogram.exe 2/5) or prompt for user input.
You may assume your program won't receive invalid input.
The shortest code (in bytes, in any language) wins.
Any non-standard command-line arguments (arguments that aren't normally required to run a script) count towards the total character count.

What your program must not do:

Depend on any external resources.
Depend on having a specific file name.
Output anything other than the required output.
Take exceptionally long to run. If your program runs over a minute for fractions with a 6-digit numerator and denominator (e.g. 179565/987657) on an average home user's computer, it's invalid.
Output fractions with 0 as the denominator. You can't divide by zero.
Output fractions with 0 as the numerator. Your program must output 0 instead of a fraction.
Reduce an inputted fraction. If the fraction given as input is reducible, you must use the fraction as it is inputted.
Your program must not be written in a programming language for which there did not exist a publicly available compiler / interpreter before this challenge was posted.

Examples:
Input: 2/5
Output: 1/3 1/2

Input: 1/2
Output: 0 1

Input: 5/9
Output: 1/2 4/7

Input: 1/3
Output: 0 1/2

Input: 2/4
Output: 1/3 2/3

Input: 179565/987657
Output: 170496/937775 128779/708320

"""

from math import gcd

def find(p, n, d):
    a = d
    while (a*n + p)%d != 0:
        a -= 1
    return ((a*n + p)//d, a)

"""

Ported from @izzyg solution

I started with the obvious brute-force solution,
but I realized that since the OP wanted to be able to solve instances with six digit numerators and denominators in under a minute,
I need a better solution than trying a trillion possibilities.
I found a handy formula on the Wikipedia page for the Farey sequence: If a/b, c/d are neighbors in one of the Farey sequences, with a/b<c/d, then b*c-a*b=1.
The while loop inside f in my program extends this fact to non-reduced numbers, using the gcd, which the other while loop calculates.

"""

def solve(n, d):
    p = gcd(n, d)
    f1 = find(-p, n, d)
    f2 = find(p, n, d)
    return (f1, f2)

def main():
    assert(solve(2, 5) == ((1, 3), (1, 2)))
    assert(solve(1, 2) == ((0, 1), (1, 1)))
    assert(solve(5, 9) == ((1, 2), (4, 7)))
    assert(solve(1, 3) == ((0, 1), (1, 2)))
    assert(solve(2, 4) == ((1, 3), (2, 3)))
    assert(solve(179565, 987657) == ((170496, 937775), (128779, 708320)))

main()
