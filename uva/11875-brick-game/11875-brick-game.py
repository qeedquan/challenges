#!/usr/bin/env python3

def solve(numbers):
    numbers.sort()
    return numbers[len(numbers)//2]

def main():
    assert(solve([19, 17, 16, 14, 12]) == 16)
    assert(solve([12, 14, 16, 17, 18]) == 16)

main()

