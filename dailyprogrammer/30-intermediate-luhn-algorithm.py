#!/usr/bin/env python3

"""

Most credit card numbers, and many other identification numbers including the Canadian Social Insurance Number, can be validated by an algorithm developed by Hans Peter Luhn of IBM, described in U. S. Patent 2950048 in 1954 (software patents are nothing new!), and now in the public domain. The Luhn algorithm will detect almost any single-digit error, almost all transpositions of adjacent digits except 09 and 90, and many other errors.

The Luhn algorithm works from right-to-left, with the right-most digit being the check digit. Alternate digits, starting with the first digit to left of the check digit, are doubled. Then the digit-sums of all the numbers, both undoubled and doubled, are added. The number is valid if the sum is divisible by ten.

For example, the number 49927398716 is valid according to the Luhn algorithm. Starting from the right, the sum is 6 + (2) + 7 + (1 + 6) + 9 + (6) + 7 + (4) + 9 + (1 + 8) + 4 = 70, which is divisible by 10; the digit-sums of the doubled digits have been shown in parentheses.

Your task is to write two functions, one that adds a check digit to a identifying number and one that tests if an identifying number is valid.

source: programmingpraxis.com

"""

# ported from @Cosmologicon solution
dig = lambda d, a: d + a*(d + d//5)
luhn = lambda n, a: n and luhn(n // 10, 1 - a) + dig(n % 10, a)
isvalid = lambda n: luhn(n, 0)%10 == 0
checkdigit = lambda n: -luhn(n, 1) % 10

def main():
    assert(isvalid(49927398716) == True)
    assert(checkdigit(4992739871) == 6)

main()
