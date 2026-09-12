#!/usr/bin/env python3

"""

Input:
A positive integer n consisting of digits in the range 0-9.

Challenge:
If d is the highest digit in the integer, assume the base of the number is d+1. E.g. if the integer is 1256 then you shall assume it's in base-7, if it's 10110 then you shall assume it's base-2 (binary), and if it's 159 then it's decimal.

Now, do the following until you either, 1: reach a base-10 integer, or 2: reach a single digit integer.

Convert the integer from base-(d+1) to base-10
Find the base of this new integer (again, base-(d+1) where d is the highest digit in the new number)
Go to step 1.
Examples:
Assume the input is n = 413574. The highest digit d=7, so this is base-8 (octal). Convert this to decimal and get 137084. The highest digit d=8, so this is base-9. Convert this to decimal and get 83911. The highest digit is 9, so this is a decimal number and we stop. The output shall be 83911.

Assume the input is n = 13552. The highest digit is d=5, so this is base-6. Convert this to decimal and get 2156. The highest digit d=6, so this is base-7. Convert this to decimal and get 776. The highest digit is d=7, so this is base-8. Convert this to decimal and get 510. The highest digit is d=5 so this is base-6. Convert this to decimal and get 186. The highest digit is 8, so this is base-9. Convert this to decimal and get 159. The highest digit is 9, so this is a decimal number and we stop. The output shall be 159.

Assume the input is n=17. This will give us 15, then 11, then 3, which we will output since it's a single digit.

Test cases:
5
5

17
3

999
999

87654321  (base-9 -> 42374116 in decimal -> base-7 -> 90419978 in decimal)
9041998

41253  (5505 -> 1265 -> 488 -> 404 -> 104 -> 29)
29

Notes:

Standard rules regarding I/O, loopholes etc. You may take the input as a string
Explanations are encouraged
You may use builtin base-conversion commands
Solutions that don't use the language's builtin base-conversion functions (if they exist) are welcome, even if they end up being much longer than the obvious approach using builtin functions.
Apparently, this is OEIS A091047.

"""

# https://oeis.org/A091047
def ib10(n):
    while n >= 10:
        s = str(n)
        b = int(max(s))
        if b == 9:
            break
        n = int(s, b + 1)
    return n

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 5, 7, 9, 3, 7, 3, 3, 19, 6, 7, 8, 3, 9, 3, 6, 3, 6, 29, 5, 7, 9, 3, 19, 3, 3, 7, 3, 39, 6, 7, 8, 3, 9, 29, 19, 39, 9, 49, 5, 7, 9, 3, 19, 3, 7, 39, 3, 59, 8, 3, 9, 29, 19, 39, 9, 3, 9, 69, 7, 39, 3, 59, 8, 3, 9, 29, 39, 79, 3, 59, 8, 3, 9, 29, 39, 79, 3, 89, 90, 91, 92]

    assert(ib10(413574) == 83911)
    assert(ib10(13552) == 159)
    assert(ib10(5) == 5)
    assert(ib10(17) == 3)
    assert(ib10(999) == 999)
    assert(ib10(87654321) == 9041998)
    assert(ib10(41253) == 29)

    for i in range(len(tab)):
        assert(ib10(i + 1) == tab[i])
    
main()
