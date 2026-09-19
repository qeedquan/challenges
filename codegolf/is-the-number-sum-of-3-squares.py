#!/usr/bin/env python3

"""

Challenge
Write a program (function) that given a nonnegative integer input, output whether the number can be represented as the sum of 3 square numbers.
That is, the program should, given nonnegative integer input N, determine whether N=a^2+b^2+c^2 where a,b,c are all nonnegative integers.

Here, "nonnegative integers" means 0 is included alongside all natural numbers. The three square numbers a,b,c need not be all distinct.

Rules
As usual, standard loopholes are forbidden.

The algorithm used should also theoretically produce the correct output for all valid inputs regardless of size (e.g. the program, without restrictions from memory or underlying type implementations, should work even with a trillion-digit input). You can assume that the program only receives valid inputs as stated above.

This is a code golf, so shortest code for every language wins.

Sample input/output
Per convention, True and False below can be replaced by any 2 distinguishable and consistent values, such as 1 and 0.

Input: 0                         # 0^2 + 0^2 + 0^2. Squares can repeat and be 0
Output: True

Input: 6                         # 1^2 + 1^2 + 2^2. Need not be all distinct
Output: True

Input: 7                         # 7 can't be represented as the sum of 3 squares. So do 15, 23, 28, ...
Output: False

Input: 8                         # 2^2 + 2^2 (+ 0^2). Need not be all non-zero
Output: True

Input: 9                         # 3^2 (+ 0^2 + 0^2). Same as above
Output: True

Input: 1145141919810             # 1070113^2 + 295^2 + 4^2
Output: True

Input: 245657627368729           # 15384573^2 + 2995420^2 (+ 0^2). Representable as the sum of 2 squares
Output: True

Input: 12345678987654321         # 111111111^2 (+ 0^2 + 0^2). Itself is a square number
Output: True

Input: 185724285729475816451975  # A large number not representable as the sum of 3 squares
Output: False
Similar challenges
Challenges below are related but this challenge is no duplicate to them - this has extremely short algorithms that works.

How many ways to write numbers as sums of squares? - Counts the number of ways instead. Also not limited to sum of 3 squares

Four Squares Together - Finds one representation as sum of at most 4 squares explicitly

■ or ■+■ or ■+■+■ or ■+■+■+■ - Duplicate of above

finally posting challenges after years of hiatus

"""

def valuation(n, b):
    v = 0
    while n > 1 and n%b == 0:
        n //= b
        v += 1
    return v

# https://oeis.org/A000378
def sum_of_3_squares(n):
    return (n//4**valuation(n, 4))%8 != 7

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if sum_of_3_squares(i):
            r.append(i)
        i += 1
    return r
        

def main():
    tab = [
        0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 19, 20, 21,
        22, 24, 25, 26, 27, 29, 30, 32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43,
        44, 45, 46, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 61, 62, 64, 65,
        66, 67, 68, 69, 70, 72, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83
    ]

    assert(gen(len(tab)) == tab)

    assert(sum_of_3_squares(0) == True)
    assert(sum_of_3_squares(6) == True)
    assert(sum_of_3_squares(7) == False)
    assert(sum_of_3_squares(8) == True)
    assert(sum_of_3_squares(9) == True)
    assert(sum_of_3_squares(1145141919810) == True)
    assert(sum_of_3_squares(245657627368729) == True)
    assert(sum_of_3_squares(12345678987654321) == True)
    assert(sum_of_3_squares(185724285729475816451975) == False)

main()
