#!/usr/bin/env python3

"""

Your task is to write a function that takes an even-digit integer and compares the 2 halves of the integer. If the sum of the digits in the first half is greater than the sum of the digits in the second half, output a truthy value, otherwise, output falsey.

For example:

12345678
1234 5678
(1+2+3+4)>(5+6+7+8)
10>26

Output falsey

Input
A single integer.

This must be passed as a single whole integer in base 10, a single string, an array of integers, or an array of characters. Please specify which format your answer accepts
The input can be passed via Command Line Arguments, STDIN, or any other standard method of input supported by your language
Assume the input will always have an even digit count
Assume the input will always be positive and greater than 0
Assume the input will be within feasible number handling capacities for your language
The input will not contain leading zeroes

Output
A truthy value if the sum of the digits in the first half is greater than the sum of the digits in the second half.

A falsey value if the sum of the digits in the first half is less than or equal to the sum of the digits in the second half.

Test cases

Input > Output

12345678 > False
87654321 > True
12344321 > False
12 > False
214758392639543385 > False
1001 > False
100000 > True

Scoring
This is code-golf so fewest bytes wins.

"""

def digits(x):
    d = []
    while x > 0:
        d.append(x % 10)
        x //= 10
    return d

def significant(x):
    d = digits(x)
    n = len(d)
    
    a, b = 0, 0
    for i in range(n//2):
        a += d[i]
        b += d[n-i-1]
    return a < b

def main():
    assert(significant(12345678) == False)
    assert(significant(87654321) == True)
    assert(significant(12344321) == False)
    assert(significant(12) == False)
    assert(significant(214758392639543385) == False)
    assert(significant(1001) == False)
    assert(significant(100000) == True)

main()
