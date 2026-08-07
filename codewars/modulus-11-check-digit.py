#!/usr/bin/env python3

"""

Check Digits
Some numbers are more important to get right during data entry than others: a common example is product codes.

To reduce the possibility of mistakes, product codes can be crafted in such a way that simple errors are detected. This is done by calculating a single-digit value based on the product number, and then appending that digit to the product number to arrive at the product code.

When the product code is checked, the check digit value is stripped off and recalculated. If the supplied value does not match the recalculated value, the product code is rejected.

A simple scheme for generating self-check digits, described here, is called Modulus 11 Self-Check.

Calculation method
Each digit in the product number is assigned a multiplication factor. The factors are assigned from right to left, starting at 2 and counting up. For numbers longer than six digits, the factors restart at 2 after 7 is reached. The product of each digit and its factor is calculated, and the products summed. For example:

digit     :  1    6    7    7    0    3    6    2    5
factor    :  4    3    2    7    6    5    4    3    2
           ---  ---  ---  ---  ---  ---  ---  ---  ---
             4 + 18 + 14 + 49 +  0 + 15 + 24 +  6 + 10 = 140
Then the sum of the products is divided by the prime number 11. The remainder is inspected, and:

if the remainder is 0, the check digit is also 0
if the remainder is 1, the check digit is replaced by an uppercase X
for all others, the remainder is subtracted from 11
The result is the check digit.

Your task
Your task is to implement this algorithm and return the input number with the correct check digit appended.

Examples
input: "036532"

product sum = 2*2 + 3*3 + 5*4 + 6*5 + 3*6 + 0*7 = 81
remainder   = 81 mod 11 = 4
check digit = 11 - 4 = 7

output: "0365327"

"""

def add_check_digit(s):
    n = len(s)
    v = 0
    m = 2
    for i in range(n - 1, -1, -1):
        v += (ord(s[i]) - ord('0')) * m
        m += 1
        if m > 7:
            m = 2
    v %= 11
    
    t = str(v)
    if v == 1:
        t = "X"
    elif v > 1:
        t = str(11 - v)
    return s + t

def main():
    assert(add_check_digit("036532") == "0365327")
    assert(add_check_digit("12388878") == "123888782")
    assert(add_check_digit("111111111") == "1111111118")
    assert(add_check_digit("9735597355") == "97355973550")
    assert(add_check_digit("2356") == "23566")
    assert(add_check_digit("6789") == "6789X")

main()
