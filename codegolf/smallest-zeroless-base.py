#!/usr/bin/env python3

"""

Given a positive integer n, output the smallest base b >= 2 where the representation of n in base b with no leading zeroes does not contain a 0. You may assume that b <= 256 for all inputs.

Test Cases
1 -> 2 (1)
2 -> 3 (2)
3 -> 2 (11)
4 -> 3 (11)
5 -> 3 (12)
6 -> 4 (12)
7 -> 2 (111)
10 -> 4 (22)
17 -> 3 (122)
20 -> 6 (32)
50 -> 3 (1212)
100 -> 6 (244)
777 -> 6 (3333)
999 -> 4 (33213)
1000 -> 6 (4344)
1179360 -> 23 ([12, 9, 21, 4, 4])
232792560 -> 23 ([15, 12, 2, 20, 3, 13, 1])
2329089562800 -> 31 ([20, 3, 18, 2, 24, 9, 20, 22, 2])
69720375229712477164533808935312303556800 -> 101 ([37, 17, 10, 60, 39, 32, 21, 87, 80, 71, 82, 14, 68, 99, 95, 4, 53, 44, 10, 72, 5])
8337245403447921335829504

"""

# https://oeis.org/A106370
def szb(n):
    x = n
    b = 2
    while x > 0:
        z = 0
        if x%b == 0:
            z = 1
        b += z
        if z == 0:
            x //= b
        else:
            x = n
    return b

def main():
    tab = [
        2, 3, 2, 3, 3, 4, 2, 3, 4, 4, 4, 5, 3, 3, 2, 3, 3, 5, 5, 6, 4, 3, 3, 5,
        3, 3, 4, 6, 4, 4, 2, 5, 5, 5, 6, 5, 4, 4, 4, 3, 3, 4, 3, 3, 4, 4, 4, 5,
        3, 3, 6, 3, 3, 4, 4, 5, 4, 4, 4, 7, 4, 4, 2, 5, 6, 5, 3, 3, 5, 3, 3, 5,
        5, 5, 7, 3, 3, 7, 3, 3, 5, 5, 5, 5, 4, 4, 4, 5, 4, 4, 4, 5, 4, 4, 4, 5,
        5, 5, 5, 6, 4, 4, 4, 6, 4
    ]

    for i in range(len(tab)):
        assert(szb(i + 1) == tab[i])

    assert(szb(1) == 2)
    assert(szb(2) == 3)
    assert(szb(3) == 2)
    assert(szb(4) == 3)
    assert(szb(5) == 3)
    assert(szb(6) == 4)
    assert(szb(7) == 2)
    assert(szb(10) == 4)
    assert(szb(17) == 3)
    assert(szb(20) == 6)
    assert(szb(50) == 3)
    assert(szb(100) == 6)
    assert(szb(777) == 6)
    assert(szb(999) == 4)
    assert(szb(1000) == 6)
    assert(szb(1179360) == 23)
    assert(szb(232792560) == 23)
    assert(szb(2329089562800) == 31)
    assert(szb(69720375229712477164533808935312303556800) == 101)
    assert(szb(8337245403447921335829504375888192675135162254454825924977726845769444687965016467695833282339504042669808000) == 256)

main()
