#!/usr/bin/env python3

"""

Your friend has discovered an old machine that performs simple mathematical operations. The machine has only two buttons:

+1 — adds one to the current number.

x2 — multiplies the current number by two.

The machine starts with the number 1.
Now, your friend wants to know how many different ways it is possible to obtain a given number n using these buttons.
Help them write a program that calculates this number.

Constraint: 1 ≤ n ≤ 10**6

"""

# https://oeis.org/A018819
def ways(n):
    if n < 0:
        return 0

    f = {0: 1, 1: 1}
    for i in range(2, n + 1):
        f[i] = f[i - 1]
        if i%2 == 0:
            f[i] += f[i//2]
    return f[n]

def main():
    tab = [
        1, 1, 2, 2, 4, 4, 6, 6, 10, 10, 14, 14, 20, 20, 26, 26, 36, 36, 46, 46,
        60, 60, 74, 74, 94, 94, 114, 114, 140, 140, 166, 166, 202, 202, 238,
        238, 284, 284, 330, 330, 390, 390, 450, 450, 524, 524, 598, 598, 692,
        692, 786, 786, 900, 900, 1014, 1014, 1154, 1154, 1294, 1294
    ]

    for i in range(len(tab)):
        assert(ways(i) == tab[i])

main()

