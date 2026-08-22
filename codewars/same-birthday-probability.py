#!/usr/bin/env python3

"""

Given n number of people in a room, calculate the probability that any two people in that room have the same birthday (assume 365 days every year = ignore leap year). Answers should be two decimals unless whole (0 or 1) eg 0.05

"""

def prob(n):
    p = 1
    for i in range(1, n):
        p *= 1 - i/365
    return 1 - p

def main():
    for i in range(51):
        print("%d %.02f" % (i, prob(i)))

main()
