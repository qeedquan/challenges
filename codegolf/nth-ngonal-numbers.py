#!/usr/bin/env python3

"""

Most of us are probably familiar with the concept of triangular and square numbers. However, there are also pentagonal numbers, hexagonal numbers, septagonal numbers, octagonal numbers, etc. The Nth Nagonal number is defined as the Nth number of the sequence formed with a polygon of N sides. Obviously, N >= 3, as there are no 2 or 1 sided closed shapes. The first few Nth Ngonal numbers are 0, 1, 2, 6, 16, 35, 66, 112, 176, 261, 370, 506, 672, 871.... This is sequence A060354 in the OEIS.

Your Task:
Write a program or function that, when given an integer n as input, outputs/returns the Nth Nagonal number.

Input:
An integer N between 3 and 10^6.

Output:
The Nth Nagonal number where N is the input.

Test Case:
25 -> 6925
35 -> 19670
40 -> 29680
Scoring:
This is code-golf, lowest score in bytes wins!

"""

# https://oeis.org/A060354
def ngonal(n):
    return n*(n*n - 3*n + 4) // 2

def main():
    tab = [0, 1, 2, 6, 16, 35, 66, 112, 176, 261, 370, 506, 672, 871, 1106, 1380, 1696, 2057, 2466, 2926, 3440, 4011, 4642, 5336, 6096, 6925, 7826, 8802, 9856, 10991, 12210, 13516, 14912, 16401, 17986, 19670, 21456, 23347, 25346, 27456, 29680, 32021]

    for i in range(len(tab)):
        assert(ngonal(i) == tab[i])

main()
