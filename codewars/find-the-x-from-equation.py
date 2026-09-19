#!/usr/bin/env python3

"""

Given String s in the form of equation.
Your task is to parse the s string and find the "X" value from string.

Example:
For s = "99X=1(mod 8)", the output should be
findIt(s) = 3.

s = "99X=1(mod 8)".
To solve this equation, first you must reduce the left side.
Make it as small as possible without being negative by decreasing it by mod.
So,for example 99X would reduce to 3x.

Now your expression should look like this:
3X=1(mod 8).
Now that the left side is done, we switch focus to the right side.
If we mod by 8, we can safely add or subtract 8 to get the same answer, so we add 8 to the number on the right until we get a number evenly divisible by the left number.
So 3X=1(mod 8), goes to 3x=9(mod 8).

9 is evenly divided by 3, so we stop there. Our final step is to isolate X, so we divide 9 by 3 leaving us with X=3.

If there no result, return -1 instead.

s = "145X=1(mod 10)" We take the 145X, 145 can be reduced to 5, so your equation form now is 5X=1(mod 10).
but, there no valid equation because 1+10 = 11 + 10 = 21 + 10 = 31... etc, we will not get number that can be divide by 5.

"""

import re
from sympy import mod_inverse

def findit(s):
    try:
        t = re.findall(r'\d+', s)
        x = [int(v) for v in t]
        if len(x) != 3 or x[1] != 1:
            return -1
        return mod_inverse(x[0], x[2])
    except:
        return -1

def main():
    assert(findit("99X=1(mod 8)") == 3);
    assert(findit("72X=1(mod 11)") == 2);
    assert(findit("88X=1(mod 9)") == 4);
    assert(findit("28X=1(mod 5)") == 2);
    assert(findit("493X=1(mod 3)") == 1);
    assert(findit("6336X=1(mod 5)") == 1);
    assert(findit("16X=1(mod 9)") == 4);
    assert(findit("145X=1(mod 10)") == -1)

main()
