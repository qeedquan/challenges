#!/usr/bin/env python3

"""

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

http://i.imgur.com/EYcuB1wm.jpg

Hint:
See Fibonacci sequence

Ref:
http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216

"""

def mul(m1, m2):
    x = m1[0][0]*m2[0][0] + m1[0][1] * m2[1][0]
    y = m1[0][0]*m2[0][1] + m1[0][1] * m2[1][1]
    z = m1[1][0]*m2[0][0] + m1[1][1] * m2[1][0]
    w = m1[1][0]*m2[0][1] + m1[1][1] * m2[1][1]
    return [[x, y], [z, w]]

def fib(n):
    m = [[1, 0], [0, 1]]
    t = [[0, 1], [1, 1]]
    if n < 0:
        n, t = -n, [[-1, 1], [1, 0]]
    while n > 0:
        if n&1 != 0:
            m = mul(t, m)
        t = mul(t, t)
        n >>= 1
    return m[0][1]

# https://oeis.org/A000071
def fibsum(n):
    return fib(n + 1) - 1

def perimeter(n):
    return 4*fibsum(n + 2)

def main():
    assert(perimeter(5) == 80)
    assert(perimeter(7) == 216)
    assert(perimeter(20) == 114624)
    assert(perimeter(30) == 14098308)
    assert(perimeter(100) == 6002082144827584333104)

main()
