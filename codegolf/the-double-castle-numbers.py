#!/usr/bin/env python3

"""

Introduction
A double-castle number™ is a positive integer number that has a pattern of

a...a b a...a b a...a b a...a b a...a b a...a
 m a     m a     m a     n a     n a     n a

Where m>0, n>0 and a-b=1 are all non-negative integers, when represented in an integer base B where B≥2. It is so named because a bar chart representing the base-B digits of such a number resembles two castles of the same height place- side by side.

For example, 7029* is a double-castle number because when represented in base 2 it becomes 1101101110101_2, which can be split into 11011011 and 10101.

https://i.stack.imgur.com/WwmC1.png

This is the case when m=2, n=1, a=1, b=0 and B=2.
305421994212is also a double-castle number because when represented in base 8 it becomes 43434443443448, which can be split into 43434 and 44344344.

https://i.stack.imgur.com/MIhKU.png

This is the case when m=1, n=2, a=4, b=3 and B=8.

For a>=10, a should be treated as a single base-B "digit" with the value of a in base-10. 206247763570426655730674346 is a double-castle number in base-16, whose representation in base-16 is AA9AA9AAAAAA9AAAA9AAAA16.
Here, a=10 but is treated as a single digit (10)16=A16.

https://i.stack.imgur.com/6xXmK.png

This is the case when m=2, n=4, a=10, b=9 and B=16.

Challenge
Write a program or function that, given integers m>0, n>0, 1≤a<B and B≥2, calculate the corresponding double-castle number™ and output it in base-10.

Test Cases
The input below are in base-10, but in the case say when a=11 and B=12 the input should be understood as B12.

m, n, a,  B  => Output
1, 1, 1,  2  => 693
2, 1, 1,  2  => 7029
1, 2, 3,  4  => 62651375
1, 2, 4,  8  => 305421994212
1, 4, 7,  10 => 7676777776777767777
2, 4, 8,  16 => 164983095594247313234036872
2, 4, 10, 16 => 206247763570426655730674346

Winning Condition
This is a code-golf challenge, the shortest submission in each language wins. No standard loopholes allowed.

"""

# @Surculose Sputum
# Calculate aaaa...aaa in base B, then subtract 1 at the appropriate digits.
def dbc(m, n, a, B):
    r = 0
    for s in (n, m + n, m, m):
        r += B**n
        n -= -(s + 1)
    return a*(B**n - 1)//(B - 1) - r

def main():
    assert(dbc(1, 1, 1, 2) == 693)
    assert(dbc(2, 1, 1, 2) == 7029)
    assert(dbc(1, 2, 3, 4) == 62651375)
    assert(dbc(1, 2, 4, 8) == 305421994212)
    assert(dbc(1, 4, 7, 10) == 7676777776777767777)
    assert(dbc(2, 4, 8, 16) == 164983095594247313234036872)
    assert(dbc(2, 4, 10, 16) == 206247763570426655730674346)

main()
