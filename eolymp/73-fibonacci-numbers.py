#!/usr/bin/env python3

"""

Which is the largest Fibonacci number that can be constructed using the available set of digits C0,C1,C2,…,C9,
where C0 is the number of digit 0s, C1 is the number of digit 1s, ..., C9 is the number of digit 9s?

Input
A single line contains 10 integers, each representing the number of times the corresponding digit appears in the set. All input numbers do not exceed 100.

Output
Output the index of the largest Fibonacci number that can be constructed, or −1 if it is impossible to construct such a number using the given digits.

Examples
Input #1
1 2 3 0 0 0 0 0 0 0

Answer #1
8

"""

from sympy import fibonacci

def tally(number):
    digits = [0] * 10
    while True:
        digits[number % 10] += 1
        number //= 10
        if number == 0:
            break
    return digits

def subset(slots, digits):
    for index in range(len(slots)):
        if digits[index] > slots[index]:
            return False
    return True

def solve(slots):
    maximum = sum(slots)
    result = -1
    index = 0
    while True:
        digits = tally(fibonacci(index))
        if sum(digits) > maximum:
            break
        if subset(slots, digits):
            result = index
        index += 1
    return result

def main():
    assert(solve([1, 2, 3, 0, 0, 0, 0, 0, 0, 0]) == 8)

main()
