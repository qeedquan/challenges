#!/usr/bin/env python3

"""

Centered pentagonal number
Complete the function that takes an integer and calculates how many dots exist in a pentagonal shape around the center dot on the Nth iteration.

In the image below you can see the first iteration is only a single dot. On the second, there are 6 dots. On the third, there are 16 dots, and on the fourth there are 31 dots. The sequence is: 1, 6, 16, 31...

https://upload.wikimedia.org/wikipedia/commons/c/cd/Nombre_pentagon_cent.svg

If the input is equal to or less than 0, return -1

Examples
1  -->    1
2  -->    6
8  -->  141
0  -->   -1

Note:
In the tests cases n can reach 1358187913

"""

# https://oeis.org/A005891
def pentagonal(n):
    if n < 1:
        return -1
    n -= 1
    return (5*n**2 + 5*n + 2) // 2

def main():
    tab = [
        1, 6, 16, 31, 51, 76, 106, 141, 181, 226, 276, 331, 391, 456, 526, 601,
        681, 766, 856, 951, 1051, 1156, 1266, 1381, 1501, 1626, 1756, 1891, 2031,
        2176, 2326, 2481, 2641, 2806, 2976, 3151, 3331, 3516, 3706, 3901, 4101,
        4306, 4516, 4731, 4951, 5176, 5406
    ]

    for i in range(len(tab)):
        assert(pentagonal(i + 1) == tab[i])

    assert(pentagonal(0) == -1)
    assert(pentagonal(-1) == -1)
    assert(pentagonal(100) == 24751)
    assert(pentagonal(77686) == 15087592276)

main()
