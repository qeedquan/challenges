#!/usr/bin/env python3

from sympy import fibonacci

# https://oeis.org/A001924
def solve(n):
    return fibonacci(n + 4) - n - 3

def main():
    tab = [
        0, 1, 3, 7, 14, 26, 46, 79, 133, 221, 364, 596, 972, 1581, 2567, 4163,
        6746, 10926, 17690, 28635, 46345, 75001, 121368, 196392, 317784, 514201,
        832011, 1346239, 2178278, 3524546, 5702854, 9227431, 14930317, 24157781,
        39088132, 63245948, 102334116, 165580101
    ]

    assert(solve(3) == 7)
    assert(solve(4) == 14)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()

