#!/usr/bin/env python3

"""

Today's challenge is to determine if a number is a Kaprekar Number

Enjoy :)

"""

# https://oeis.org/A006886
def kaprekar(n):
    if n < 1:
        return False

    m = 1
    N = n**2
    for _ in str(N):
        m *= 10
        if n == sum(divmod(N, m)) and n != m:
            return True
    return False

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if kaprekar(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292,
        7272, 7777, 9999, 17344, 22222, 38962, 77778, 82656, 95121, 99999, 142857,
        148149, 181819, 187110, 208495, 318682, 329967, 351352, 356643, 390313,
        461539, 466830, 499500, 500500, 533170, 538461, 609687, 627615
    ]

    assert(gen(len(tab)) == tab)

main()
