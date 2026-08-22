#!/usr/bin/env python3

"""

Given two integers A and B written in an unusual format: the numbers are grouped in threes, starting from the units digit, and separated by commas.
Your task is to find their sum and output the result in the usual decimal form.

Input
The input consists of multiple data sets. Each test case is given on a separate line and contains two integers A and B, where ∣A∣,∣B∣<10^9, separated by a space.

Output
For each test case, output the sum in the usual decimal format on a separate line.

Examples
Input #1
-234,567,890 123,456,789
1,234 2,345,678

Answer #1
-111111101
2346912

"""

def solve(a, b):
    a = a.replace(",", "")
    b = b.replace(",", "")
    return int(a) + int(b)

def main():
    assert(solve("-234,567,890", "123,456,789") == -111111101)
    assert(solve("1,234", "2,345,678") == 2346912)

main()
