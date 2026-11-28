#!/usr/bin/env python3

"""

Define a function that takes in two non-negative integers a and b and returns the last decimal digit of a^b.
Note that a and b may be very large!

For example, the last decimal digit of 9^7 is 9, since 9^7 = 4782969.
The last decimal digit of (2^200)^(2^300), which has over 10^92 digits is 6, also please take 0^0 to be 1.

You may assume that the input will always be valid.

Examples
last_digit(4, 1)                # returns 4
last_digit(4, 2)                # returns 6
last_digit(9, 7)                # returns 9
last_digit(10, 10 ** 10)        # returns 0
last_digit(2 ** 200, 2 ** 300)  # returns 6

"""

"""

https://www.geeksforgeeks.org/find-last-digit-of-ab-for-large-numbers/
https://brilliant.org/wiki/finding-the-last-digit-of-a-power/

Number  |  Last digits that repeat in cycle
  1     |  1
  2     |  4, 8, 6, 2
  3     |  9, 7, 1, 3
  4     |  6, 4
  5     |  5
  6     |  6
  7     |  9, 3, 1, 7
  8     |  4, 2, 6, 8
  9     |  1, 9

In the given table, we can see that maximum length for cycle repetition is 4.
Example: 2*2 = 4*2 = 8*2 = 16*2 = 32 last digit in 32 is 2 that means after multiplying 4 times digit repeat itself. So the algorithm is very simple.

Algorithm :
 
1. Take last digit in base a.
2. Now calculate b%4. Here b is very large. 
3. If b%4==0 that means b is completely divisible by 4, so our exponent now will be exp = 4 because by multiplying number 4 times, we get the last digit according to cycle table in above diagram.
4. If b%4!=0 that means b is not completely divisible by 4, so our exponent now will be exp=b%4 because by multiplying number exponent times, we get the last digit according to cycle table in above diagram.
5. Now calculate ldigit = pow( last_digit_in_base, exp ).
6. Last digit of a^b will be ldigit%10.

"""

def lastdigit(a, b):
    if a == 0 and b == 0:
        return 1
      
    if b == 0:
        return 1
      
    if a == 0:
        return 0
      
    r = b % 4
    if r == 0:
        r = 4
        
    return pow(a, r) % 10

def main():
    assert(lastdigit(4, 1) == 4)
    assert(lastdigit(4, 2) == 6)
    assert(lastdigit(9, 7) == 9)
    assert(lastdigit(10, 10**10) == 0)
    assert(lastdigit(2**200, 2**300) == 6)
    assert(lastdigit(0, 0) == 1)

main()
