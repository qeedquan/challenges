#!/usr/bin/env python3

"""

Pancake number p[n] represents the maximal number of pieces in which a circle can be divided into by n linear cuts.
In other words, pancake numbers are numbers of the form (n²+n+2)/2 where n is an integer. (Illustration needed)

A "Pancake-only product" is a positive integer that can be expressed as a product of (not necessarily distinct) pancake numbers.

Task
Given a positive integer n, determine if it can be expressed as a product of pancake numbers.

This is code-golf, so the shortest code in bytes wins.

This is also a decision-problem so you may use your language's convention for truthy/falsy (swapping truthy and falsy is allowed),
or use two distinct, fixed values to represent true or false.

Test cases
input	result	note
1	truthy	1
2	truthy	2
3	falsy	(3)
4	truthy	4 = 2×2
8	truthy	2×4 = 2×2×2
23	falsy	(23)
46	truthy	46
49	truthy	7×7
301	truthy	301 = 7×(43)
506	truthy	11×46 = 22×(23)
2438	falsy	(2438) = 46×(53) = (23)×106 = 2×(1219) = 2×(23)×(53)
9653	truthy	7×1379
12167	falsy	(12167) = (23)×529 = (23)×(23)×(23)
12943	falsy	(12943) = 7×(1849) = (43)×301 = 7×(43)×(43)
94220	falsy	It is easy to see that no pancake numbers are divisible by 5.
297892	falsy	It may take a human some time to prove that no pancake numbers are divisible by 10639.

"""

def pancakable(number):
    if number < 3:
        return True

    total = 0
    for i in range(1, number):
        divisor = i * (i + 1) // 2 + 1
        if number % divisor == 0:
            total += pancakable(number // divisor)
    return total != 0

def main():
    assert(pancakable(1) == True)
    assert(pancakable(2) == True)
    assert(pancakable(3) == False)
    assert(pancakable(4) == True)
    assert(pancakable(8) == True)
    assert(pancakable(23) == False)
    assert(pancakable(46) == True)
    assert(pancakable(49) == True)
    assert(pancakable(301) == True)
    assert(pancakable(506) == True)
    assert(pancakable(2438) == False)
    assert(pancakable(9653) == True)
    assert(pancakable(12167) == False)
    assert(pancakable(12943) == False)
    assert(pancakable(94220) == False)
    assert(pancakable(297892) == False)

main()
