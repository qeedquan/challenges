#!/usr/bin/env python3

"""

The Padovan sequence is the sequence of integers defined by the initial values

P(0) = P(1) = P(2) = 1
and the recurrence relation

P(n) = P(n-2) + P(n-3)
The first few values of P(n) are:

1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86, 114, 151, 200, 265, ...
Task
Your task is to write a method that returns nth Padovan number

"""

"""

https://oeis.org/A000931
https://oeis.org/A060006
https://en.wikipedia.org/wiki/Plastic_ratio

"""

def padovan(n):
    p = 1.324717957244746
    return round(p**5/(2*p + 3) * p**n)

def main():
    tab = [
        1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86, 114, 151,
        200, 265, 351, 465, 616, 816, 1081, 1432, 1897, 2513, 3329, 4410, 5842,
        7739, 10252, 13581, 17991, 23833, 31572, 41824, 55405, 73396, 97229,
        128801, 170625
    ]

    for i in range(len(tab)):
        assert(padovan(i) == tab[i])

main()

