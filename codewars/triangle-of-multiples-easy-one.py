#!/usr/bin/env python3

"""

See the following triangle:

____________________________________
 1
 2   4   2
 3   6   9   6   3
 4   8   12  16  12  8   4
 5   10  15  20  25  20  15  10  5
 ___________________________________

The total sum of the numbers in the triangle, up to the 5th line included, is 225, part of it, 144, corresponds to the total sum of the even terms and 81 to the total sum of the odd terms.

Create a function that may output an array with three results for each value of n.

triang_mult(n)  ----> [total_sum, total_even_sum, total_odd_sum]
Our example will be:

triang_mult(5) ----> [225, 144, 81]
Features of the random tests:

number of tests = 100
49 < n < 5000
Enjoy it! This kata will be translated in another languages soon

"""

def even_sums(n):
    r = 0
    for i in range(1, n + 1):
        s = i**2
        for j in range(i, s, i):
            if j%2 == 0:
                r += j * 2
        if s%2 == 0:
            r += s
    return r

"""

https://oeis.org/A000537
https://oeis.org/A000583

"""

def mult_triangle(n):
    r0 = (n * (n + 1) // 2)**2
    r1 = even_sums(n)
    r2 = ((n + 1) // 2)**4
    return [r0, r1, r2]

def main():
    assert(mult_triangle(1) == [1, 0, 1])
    assert(mult_triangle(2) == [9, 8, 1])
    assert(mult_triangle(3) == [36, 20, 16])
    assert(mult_triangle(4) == [100, 84, 16])
    assert(mult_triangle(5) == [225, 144, 81])
    assert(mult_triangle(10) == [3025, 2400, 625])
    assert(mult_triangle(50) == [1625625, 1235000, 390625])

main()
