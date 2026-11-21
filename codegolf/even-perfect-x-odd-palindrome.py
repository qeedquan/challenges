#!/usr/bin/env python3

"""

We already have a challenge about perfect numbers, and another one about palindrome numbers. How about combining them into one?

Perfect number is a positive integer, that is equal to the sum of all its divisors, except itself.
So 6 is perfect number, since 1 + 2 + 3 = 6.
On the other hand 12 is not, because 1 + 2 + 3 + 4 + 6 = 16 != 12.

A palindromic number is a number the remains the same upon digit reversal. In this task, we are determining whether a number can be expressed as a product of two numbers, of which one is an even perfect number and the other is an odd palindromic number.

Here is a list of all the "Even Perfect × Odd Palindrome" numbers less than 5000:

6 18 28 30 42 54 66 84 140 196 198 252 308 330 462 496 594 606 666 726 786 846 906 924 966 1026 1086 1146 1488 1540 1818 1878 1938 1998 2058 2118 2156 2178 2238 2298 2358 2480 2772 2828 3030 3090 3108 3150 3210 3270 3330 3388 3390 3450 3472 3510 3570 3668 3948 4228 4242 4302 4362 4422 4464 4482 4508 4542 4602 4662 4722 4782 4788
This sequence is not yet in the OEIS.

Task
Given a positive integer n, determine whether or not it can be expressed as the product of an even perfect number and an odd palindromic number.

This is code-golf, so the shortest code in bytes wins.

This is also a decision-problem so you may use your language's convention for truthy/falsy (swapping truthy and falsy is allowed), or use two distinct, fixed values to represent true or false.

Test cases
input	result	factors
1	falsy	
3	falsy	
4	falsy	
6	truthy	6×1
8	falsy	
12	falsy	(6×2)
18	truthy	6×3
66	truthy	6×11
132	falsy	(6×22)
198	truthy	6×33
1512	falsy	(6×252) = (28×54)
3388	truthy	28×121
4242	truthy	6×707
4782	truthy	6×797
4788	truthy	(6×798) = 28×171
6776	falsy	(28×242)
94220	falsy	(28×3365)
140140	truthy	28×5005
250480	truthy	496×505
297899	falsy	
998284	truthy	28×35653
1064768	truthy	8128×131
10480640	falsy	(2096128×5) (Note that 2096128 is not a perfect number)
100651008	truthy	(6×16775168) = 33550336×3

"""

from sympy import divisors

# Ported from @spears0fgungnir solution
def solve(n):
    for d in divisors(n):
        if all((
            d % 2 < 1,
            sum(divisors(d)[:-1]) == d,
            (n / d) % 2,
            str(n//d) == str(n//d)[::-1],
        )):
            return True
    return False

def main():
    assert(solve(1) == False)
    assert(solve(3) == False)
    assert(solve(4) == False)
    assert(solve(6) == True)
    assert(solve(8) == False)
    assert(solve(12) == False)
    assert(solve(18) == True)
    assert(solve(66) == True)
    assert(solve(132) == False)
    assert(solve(198) == True)
    assert(solve(1512) == False)
    assert(solve(3388) == True)
    assert(solve(4242) == True)
    assert(solve(4782) == True)
    assert(solve(4788) == True)
    assert(solve(6776) == False)
    assert(solve(94220) == False)
    assert(solve(140140) == True)
    assert(solve(250480) == True)
    assert(solve(297899) == False)
    assert(solve(998284) == True)
    assert(solve(1064768) == True)
    assert(solve(10480640) == False)
    assert(solve(100651008) == True)

main()
