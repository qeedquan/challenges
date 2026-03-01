#!/usr/bin/env python3

"""

Definition
Jumping number is the number that All adjacent digits in it differ by 1.

Task
Given a number, Find if it is Jumping or not.

Notes
Number passed is always Positive .

Return the result as String .

The difference between ‘9’ and ‘0’ is not considered as 1 .

All single digit numbers are considered as Jumping numbers.

Input >> Output Examples
jumpingNumber(9) ==> return "Jumping!!"

Explanation:
It's single-digit number
jumpingNumber(79) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(23) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1
jumpingNumber(556847) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(4343456) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1
jumpingNumber(89098) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(32) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1

"""

# https://oeis.org/A033075
def isjumping(n):
    if n < 1:
        return False

    x, n = n % 10, n // 10
    while n > 0:
        y = n % 10
        if abs(x - y) != 1:
            return False
        x, n = y, n // 10
    return True

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65,
        67, 76, 78, 87, 89, 98, 101, 121, 123, 210, 212, 232, 234, 321, 323,
        343, 345, 432, 434, 454, 456, 543, 545, 565, 567, 654, 656, 676, 678,
        765, 767, 787, 789, 876
    ]

    for i in range(max(tab) + 1):
        if i in tab:
            assert(isjumping(i) == True)
        else:
            assert(isjumping(i) == False)

    assert(isjumping(8987) == True)
    assert(isjumping(4343456) == True)
    assert(isjumping(98789876) == True)

main()
