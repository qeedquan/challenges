#!/usr/bin/env python3

from sympy import fibonacci

# https://oeis.org/A152891
def seq(n):
    if n < 0:
        return 0
    return fibonacci(2*n + 1) - n - 1

def solve(n):
    mod = 987654321
    if n < 6 or n%2 != 0:
        return 0
    return seq(n//2 - 2) % mod

def main():
    tab = [
        0, 2, 9, 29, 83, 226, 602, 1588, 4171, 10935, 28645, 75012, 196404,
        514214, 1346253, 3524561, 9227447, 24157798, 63245966, 165580120,
        433494415, 1134903147, 2971215049, 7778742024, 20365011048, 53316291146,
        139583862417
    ]

    assert(solve(8) == 2)
    assert(solve(9) == 0)
    assert(solve(10) == 9)

    for i in range(len(tab)):
        assert(seq(i + 1) == tab[i])

main()

