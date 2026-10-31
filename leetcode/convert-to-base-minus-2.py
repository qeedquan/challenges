#!/usr/bin/env python3

"""

Given an integer n, return a binary string representing its representation in base -2.

Note that the returned string should not have leading zeros unless the string is "0".

Example 1:

Input: n = 2
Output: "110"
Explantion: (-2)2 + (-2)1 = 2
Example 2:

Input: n = 3
Output: "111"
Explantion: (-2)2 + (-2)1 + (-2)0 = 3
Example 3:

Input: n = 4
Output: "100"
Explantion: (-2)2 = 4


Constraints:

0 <= n <= 10^9

"""

# https://oeis.org/A039724
# https://stackoverflow.com/questions/9330946/how-to-convert-a-decimal-base-10-to-a-negabinary-base-2
def dec2neg(n):
    if n == 0:
        return '0'
    
    d = []
    while n != 0:
        n, r = divmod(n, -2)
        if r < 0:
            n, r = n + 1, r + 2
        d.append(str(r))
    
    return ''.join(d[::-1])

def main():
    assert(dec2neg(2) == "110")
    assert(dec2neg(3) == "111")
    assert(dec2neg(4) == "100")

main()
