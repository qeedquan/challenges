#!/usr/bin/env python3

"""

In Gödel, Escher, Bach, Douglas Hofstadter introduces an integer sequence which is commonly referred to as the figure-figure sequence:

2, 4, 5, 6, 8, 9, 10, 11, 13, 14, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, ...
You may enjoy working out the definition of the sequence yourself as part of the challenge, but if you can't or don't want to figure it out you can find it on OEIS as sequence A030124 and a slightly clearer definition on Wikipedia.

Write a program or function which, given n via STDIN, ARGV or function argument, prints a list of the first n numbers of the sequence to STDOUT in any reasonable list format.

This is code golf, the shortest solution in bytes wins.

"""

"""

Ported from @matsjoyce solution

https://oeis.org/A030124

"""

def generate(n):
    result = []
    current = 1
    stack = list(range(2, n*n))
    for _ in range(n):
        value = stack.pop(0)
        current += value
        result.append(value)
        stack.remove(current)
    return result

def main():
    table = [
         2, 4, 5, 6, 8, 9, 10, 11, 13, 14, 15, 16, 17, 19, 20, 21, 22, 23, 24,
         25, 27, 28, 29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 44,
         46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 62, 63, 64,
         65, 66, 67, 68, 70, 71, 72, 73, 74, 75, 76, 77, 78
    ]

    assert(generate(len(table)) == table)

main()
