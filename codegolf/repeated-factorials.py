#!/usr/bin/env python3

"""

Not to be confused with Find the factorial!

Introduction
The factorial of an integer n can be calculated by

n! = n * (n-1) * (n-2) ... * 2 * 1

This is relatively easy and nothing new. However, factorials can be extended to double factorials, such that

n!! = n * (n - 2) * (n - 4) ... * 4 * 2

for even numbers, and

n!! = n * (n - 2) * (n - 4) ... *  3 * 1

for odd numbers. But we're not limited to double factorials. For example

n!!! = n * (n - 3) * (n - 6) * ... 6 * 3

or

n!!! = n * (n - 3) * (n - 6) * ... 5 * 2

or

n!!! = n * (n - 3) * (n - 6) * ... * 4 * 1

depending on the starting value.

In summary:

n!(k) = 1              if n = 0
        n              if 0 < n <= k
        n*((n-k)!(k)) if n > k

where n!(k) = n!...n!
                 k

Or, in plain English: Subtract the factorial count from the base number repeatedly and multiply all resulting positive integers.

The Challenge
Write a function that will calculate any kind of repeated factorial for any non-negative integer.

Input
Either

A string containing a non-negative base-ten integer, followed by 1 or more exclamation marks. E.g. "6!" or "9!!" or "40!!!!!!!!!!!!!!!!!!!!".
or

The same values represented by two integers: one non-negative base value and one positive value representing the factorial count. This can be done according to any format from the default I/O rules.
Output
The result of said calculation.

Challenge remarks
0! equals 1 by definition. Your code must account for this.
The factorial count is limited by
0<factorial count≤base value
 
outside this range, you are free to output whatever. Aside from 0!, which is the only exception to this rule.
Examples
Input                              Output

3!!!                               3
0!                                 1
6!                                 720
9!!                                945
10!!!!!!!!                         20
40!!!!!!!!!!!!!!!!!!!!             800
420!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  41697106428257280000000000000000
Try it with an ungolfed Python implementation: Try it online!

inp    = input()
value  = int(inp.strip('!'))
n      = inp.count('!') or value
result = 1

for i in range(value,0,-n):
     result *= i

print(result)

General remarks
This is code-golf, so the answer using the fewest bytes in each language wins.
Standard rules, I/O rules and loophole rules apply.
Please include a Try it Online-link to demonstrate your code working.
Please motivate your answer with an explanation of your code.

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n, b):
    if n < 1:
        return 1
    return n*f(n-b, b)

def main():
    assert(f(3, 3) == 3)
    assert(f(0, 1) == 1)
    assert(f(6, 1) == 720)
    assert(f(9, 2) == 945)
    assert(f(10, 8) == 20)
    assert(f(40, 20) == 800)
    assert(f(420, 30) == 41697106428257280000000000000000)

main()
