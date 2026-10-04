"""

Imagine you took all the numbers between 0 and n and concatenated them together into a long string.
How many digits are there between 0 and n? Write a function that can calculate this.

There are 0 digits between 0 and 1, there are 9 digits between 0 and 10 and there are 189 digits between 0 and 100.

Examples

digits(1) ➞ 0

digits(10) ➞ 9

digits(100) ➞ 189

digits(2020) ➞ 6969

Notes

The numbers are going to be rather big so creating that string won't be practical.

"""

from math import *

# https://oeis.org/A058183
def digits(n):
    if n <= 1:
        return 0
    n = n - 1
    d = floor(log10(n) + 1)
    return (n+1)*d - (10**d-1)//9

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
        33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67,
        69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101,
        103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125
    ]

    assert(digits(1) == 0)
    assert(digits(10) == 9)
    assert(digits(100) == 189)
    assert(digits(2020) == 6969)
    assert(digits(103496754) == 820359675)
    assert(digits(3248979384) == 31378682729)
    assert(digits(122398758003456) == 1724870258940729)
    assert(digits(58473029386609125789) == 1158349476621071404669)

    for i in range(len(tab)):
        assert(digits(i + 2) == tab[i])

main()
