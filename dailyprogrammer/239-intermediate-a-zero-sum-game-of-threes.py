#!/usr/bin/env python3

"""

Description
Let's pursue Monday's Game of Threes further!

To make it more fun (and make it a 1-player instead of a 0-player game), let's change the rules a bit: You can now add any of [-2, -1, 1, 2] to reach a multiple of 3. This gives you two options at each step, instead of the original single option.

With this modified rule, find a Threes sequence to get to 1, with this extra condition: The sum of all the numbers that were added must equal 0. If there is no possible correct solution, print Impossible.

Sample Input:
929
Sample Output:
929 1
310 -1
103 -1
34 2
12 0
4 -1
1
Since 1 - 1 - 1 + 2 - 1 == 0, this is a correct solution.

Bonus points
Make your solution work (and run reasonably fast) for numbers up to your operating system's maximum long int value, or its equivalent. For some concrete test cases, try:

18446744073709551615

18446744073709551614

"""

import sys

def main():
    solve(929)
    solve(18446744073709551615)
    solve(18446744073709551614)

# ported from @turbana solution
def solve(n):
    if 0 in balances(n):
        show_path(n)
    else:
        print("Impossible")
    print()

def balances(n, cache={}):
    if n not in cache:
        cache[n] = find_balances(n)
    return cache[n]

def find_balances(n):
    if n < 1:
        return {}
    if n == 1:
        return {0: 1}
    return {
        dir + bal: (n + dir) // 3
        for dir in next_dirs(n)
        for bal in balances((n + dir) // 3)
    }

def next_dirs(n):
    return (d for d in [-2, -1, 0, 1, 2] if (n + d) % 3 == 0)

def show_path(n):
    bal = 0
    while n > 1:
        m = balances(n)[-bal]
        dir = m*3 - n
        print(n, dir)
        bal += dir
        n = m
    print(1)

main()
