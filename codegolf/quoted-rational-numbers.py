#!/usr/bin/env python3

"""

Quote notation is a way of expressing rational numbers based on the concept of p-adic numbers, written in the form x′y.

The quote indicates that the number to it's left (x) is "repeated" infinitely to the left, then prefixed to the number on the right (y).
For example 3′=...3333 and 764′31=...76476431. We can then consider the geometric series:

... + 10^(3*k) + 10^(2*k) + 10^k + 10^0 = 1 / (1 - 10^k)

By setting k to be equal to the number of digits of x, we can transform this "infinite" number into a value which converges:

3' = ...333
   = ... + 3*10^3 + 3*10^2 + 3*10^1 + 3*10^0
   = 3 * (1 / (1 - 10))
   = 3 / -9
   = -1 / 3

Note that 9′0≠9′ as the first equals -10 and the second -1.
Additionally, note that leading zeros on y do affect the output: 81′09 = -80111≠911 = 81′9
Therefore, a value after the ′(y) may be omitted in the input.

You are to take, in any reasonable format, up to 2 non-negative integers x and y, and output the fraction a/b represented by x′y.
Reasonable formats include:

A string, delimited by a non-digit character, such as ', e.g. 9' or 9'0. The string will always begin with a digit; if there is no x value, it will be a 0 (e.g. 0'3)
A list of either 1 or 2 non-negative integers, represented as strings or lists of digits. If there is only 1, it represents x′. 2 integers represent x′y.
A list of 2 elements. The last element may be either a non-negative integer (as a string or digit list), or a consistent value that is not a non-negative integer (e.g. null or None or -1 etc.)
that indicates that there is no y value. The first value will always be a non-negative integer.

This is not an exhaustive list, if you have another method, feel free to ask.

You may output the two integers a and b instead of the fraction a/b. The fraction must be exact, and fully simplified (i.e. a and b are coprime).
If b is 1, outputting just a is acceptable. For negative outputs, if outputting a and b separately, either may have the negative sign, but not both.

You may input and output in any convenient method. This is code-golf so the shortest code in bytes wins.

Modified from the linked Wikipedia page:

Let x and y be sequences of digits, as in x′y

Let z be the digit 1 followed by a sequence of zeros of the same length as y.

Let w be a sequence of 9s of the same length as x.

Then the number represented by x′y is given by y - x*z/w

Test cases
x'y    = a / b
31'491 = 17609 / 99
844'80 = -4480 / 999
4'128  = -2848 / 9
247'0  = -2470 / 999
0'716  = 716 / 1
592'   = -16 / 27
3'45   = 35 / 3
9'7    = -3 / 1
9'     = -1 / 1
3'0    = -10 / 3
764'31 = -45431 / 999
81'09  = -801 / 11
81'9   = 9 / 11
123456' = -41152 / 333333

"""

from fractions import Fraction

"""

@Bubbler

How it works
Uses the formula at the end of the challenge. If we define #x as the number of digits of x,

z=10^#y,w=10^(#x−1), x′y = -z/w*x + y,

and observe that the result is the same as the 2-vector [x,y] evaluated in base -z/w.

"""

def solve(X, Y):
    x, y = 0, 0
    try:
        x = int(X)
        y = int(Y)
    except:
        pass

    z = 10**len(Y)
    w = 10**len(X) - 1
    return Fraction(-z*x, w) + Fraction(y, 1)

def main():
    assert(solve("31", "491") == Fraction(17609, 99))
    assert(solve("844", "80") == Fraction(-4480, 999))
    assert(solve("4", "128") == Fraction(-2848, 9))
    assert(solve("247", "0") == Fraction(-2470, 999))
    assert(solve("0", "716") == Fraction(716, 1))
    assert(solve("592", "") == Fraction(-16, 27))
    assert(solve("3", "45") == Fraction(35, 3))
    assert(solve("9", "7") == Fraction(-3, 1))
    assert(solve("9", "") == Fraction(-1, 1))
    assert(solve("3", "0") == Fraction(-10, 3))
    assert(solve("764", "31") == Fraction(-45431, 999))
    assert(solve("81", "09") == Fraction(-801, 11))
    assert(solve("81", "9") == Fraction(9, 11))
    assert(solve("123456", "") == Fraction(-41152, 333333))

main()
