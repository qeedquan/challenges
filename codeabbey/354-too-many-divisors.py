#!/usr/bin/env python3

"""

Some integer numbers have more divisors than others. The number 36 has 9 divisors (1, 2, 3, 4, 6, 9, 12, 18, 36) while 17 has only 2 divisors (1, 17). The number 1 has only the single divisor 1. Consider the range of numbers from 32 to 40. Their divisors are summarised below:

32: [1, 2, 4, 8, 16, 32]            6 divisors
33: [1, 3, 11, 33]                  4 divisors
34: [1, 2, 17, 34]                  4 divisors
35: [1, 5, 7, 35]                   4 divisors
36: [1, 2, 3, 4, 6, 9, 12, 18, 36]  9 divisors
37: [1, 37]                         2 divisors
38: [1, 2, 19, 38]                  4 divisors
39: [1, 3, 13, 39]                  4 divisors
40: [1, 2, 4, 5, 8, 10, 20, 40]     8 divisors
It can be seen that the total number of divisors for all of the numbers in this range is 45. In this problem you will be given several ranges of numbers. For each range you are to find the total of the number of divisors for every number in the range.

It is fairly easy to devise a fast O(N) algorithm to solve this problem. Unfortunately it is not fast enough to deal with some of the bigger number ranges. Some careful thought should lead to an O(sqrt(N)) algorithm, which is certainly fast enough to solve the problem. This can be derived from a modification of the O(N) algorithm. There is also an approach based on a mathematical result, which is marginally faster, but still O(sqrt(N)).

Input/Output description:
The first line of the input data will contain a single integer N, the number of ranges to process.
N lines will follow. Each line contains two numbers n1 and n2, separated by a space. Find the total number of divisors for all numbers in the range from n1 to n2 inclusive. Combine all answers into a single string, separated by spaces.

Example:

input:
4
32 40
94 724
7620 84210
322280 2271330

answer:
45 4443 898757 29456310

"""

# https://oeis.org/A006218
def divisors_sum(n):
    r = 0
    i = 1
    while i <= n:
        x = n // i
        p = n // x
        r += x * (p - i + 1)
        i = p + 1
    return r

def solve(n1, n2):
    if n1 < 1 or n1 > n2:
        return 0
    return divisors_sum(n2) - divisors_sum(n1 - 1)

def main():
    tab = [
        0, 1, 3, 5, 8, 10, 14, 16, 20, 23, 27, 29, 35, 37, 41, 45, 50, 52, 58,
        60, 66, 70, 74, 76, 84, 87, 91, 95, 101, 103, 111, 113, 119, 123, 127,
        131, 140, 142, 146, 150, 158, 160, 168, 170, 176, 182, 186, 188, 198,
        201, 207, 211, 217, 219, 227, 231, 239, 243, 247, 249
    ]

    for i in range(len(tab)):
        assert(divisors_sum(i) == tab[i])

    assert(solve(32, 40) == 45)
    assert(solve(94, 724) == 4443)
    assert(solve(7620, 84210) == 898757)
    assert(solve(322280, 2271330) == 29456310)

main()
