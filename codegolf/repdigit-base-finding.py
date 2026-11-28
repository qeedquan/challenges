#!/usr/bin/env python3

"""

A repdigit is a natural number that can be written solely by repeating the same digit. For example, 777 is a repdigit, since it's solely composed of the digit 7 repeated three times.

This isn't limited to simply decimal (base 10) numbers, however:

Every Mersenne number (of the form Mn = 2n-1) is a repdigit when written in binary (base 2).
Every number is trivially a repdigit when written in unary (base 1).
Every number n can also trivially be written as the repdigit 11 in base n-1 (for example, 17 when written in hexadecimal (base 16) is 11, and 3 when written in binary (base 2) is also 11).
The challenge here is to find other bases where the input number may be a repdigit.

Input
A positive integer x > 3, in any convenient format.

Output
A positive integer b with (x-1) > b > 1 where the representation of x in base b is a repdigit.

If no such b exists, output 0 or some falsey value.
If multiple such b exist, you can output any or all of them.
Rules
The (x-1) > b > 1 restriction is to prevent the trivial conversions to unary or the "subtract one" base. The output number can be written in unary or any convenient base, but the base itself must not be one of the trivial conversions.
Input/output can be via any suitable method.
Standard loophole restrictions apply.
Examples
In --> Out
11 --> 0            (or other falsey value)
23 --> 0            (or other falsey value)
55 --> 10           (since 55 is 55 in base 10)
90 --> 14           (since 90 is 66 in base 14 ... 17, 29, 44 also allowed)
91 --> 9            (since 91 is 111 in base 9 ... 12 also allowed)

"""

"""

Ported from @Dennis solution

Idea
Any repdigit x of base b > 1 and digit d < b satisfies the following.

condition

Since d < b, the map (b, d) ↦ cb + d is injective.

Also, since b, x > 1, we have c < x, so cb + d < cb + b = (c + 1)b ≤ xb.

This means that, to find suitable values for c and d for a given base b, we can iterate through all i in [0, …, bx) and check whether (b - 1)x == (i % b)(bi / b - 1).

Code
The named lambda f test whether (b - 1)x is in the set {(i % b)(bi / b - 1) | 0 ≤ i < bx}, beginning with the value b = 2.

If the test was successful, we return b.

Else, we call f again, with the same x and b incremented by 1.

Since b may eventually reach x - 1, we take the final result modulo x - 1 to return 0 in this case. Note that this will not happen if b = 2 satisfies the condition, since it is returned without recursing. However, the question guarantees that b = 2 < x - 1 in this case.

"""
def solve(number, base=2):
    target = (base - 1) * number
    for index in range(base * number):
        value = (index % base) * (base ** (index//base) - 1)
        if value == target:
            return base
    return solve(number, base + 1) % (number - 1)

def main():
    assert(solve(11) == 0)
    assert(solve(23) == 0)
    assert(solve(55) == 10)
    assert(solve(90) == 14)
    assert(solve(91) == 9)

main()
