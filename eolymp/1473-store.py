#!/usr/bin/env python3

"""

In one of the largest stores in our city, a New Year's promotion has been announced.
When you buy three items, you only pay for two, and the third one is free.
However, the key detail of this promotion, as always, is in the fine print: the items you pay for are not chosen by you, but by the cashier.
Naturally, the cashier will select the two most expensive items.
You have decided to take advantage of this promotion and buy some items.

Write a program that determines how much you will have to pay for the three selected items.

Input
A single line contains three non-negative integers — the prices of the selected items. Each number does not exceed 30000.

Output
Output a single integer — the maximum amount the cashier can charge for this purchase according to the promotion's rules.

Examples

Input #1
4 6 3

Answer #1
10

"""

def solve(p1, p2, p3):
    p = sorted([p1, p2, p3])
    return p[1] + p[2]

def main():
    assert(solve(4, 6, 3) == 10)

main()
