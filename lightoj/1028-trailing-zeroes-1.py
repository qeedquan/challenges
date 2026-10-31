#!/usr/bin/env python3

"""

We know what a base of a number is and what the properties are. For example, we use decimal number system, where the base is 10 and we use the symbols - {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}. But in different bases we use different symbols. For example in binary number system we use only 0 and 1.

Now in this problem, you are given an integer. You can convert it to any base you would want to. But the condition is that if you convert it to any base then the number in that base should have at least one trailing zero, that means a zero at the end.

For example, in decimal number system 2 doesn't have any trailing zero. But if we convert it to binary then 2 becomes (10)2 and it contains a trailing zero. Given this task, you have to find the number of bases where the given number contains at least one trailing zero. You can use any base from two to infinity.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains an integer N (1 ≤ N ≤ 10^12).

Output
For each case, print the case number and the number of possible bases where N contains at least one trailing zero.

Sample
Input	Output
3
9
5
2

Case 1: 2
Case 2: 1
Case 3: 1

Notes
For 9, the possible bases are: 3 and 9. Since in base 3; 9 is represented as 100, and in base 9; 9 is represented as 10. In both bases, 9 contains a trailing zero.

"""

from sympy import divisor_count

def solve(n):
    return divisor_count(n) - 1

def main():
    assert(solve(9) == 2)
    assert(solve(5) == 1)
    assert(solve(2) == 1)

main()
