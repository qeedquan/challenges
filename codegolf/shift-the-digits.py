#!/usr/bin/env python3

"""

Here, x (supplied as input) and n (the result of your computation) are both positive integers. n * x = n shifted. Find n.

Here's an example of shifting:

123456789 -> 912345678
abcdefghi -> iabcdefgh (letters = any 0~9 digit)
123       -> 312
Shifting only happens once to the right. Shifting left, e.g.

123456789 -> 234567891
is not a valid shifting.

Rules
Preceding zeros count after shifting. If the number is 10 and is multiplied by 0.1 (0.1 isn't a valid input), the result is 1, which isn't equal to 01 (10 after shifting).
If your number only has one digit, the shifted result is your number:
1 -> 1
4 -> 4
9 -> 9
Given enough time and resources, your program/function should work for any x input, but you only have to support x in the range [1,9] without timing out on Try It Online.
Test cases
For more test cases, this is OEIS A092697.

1 -> 1 (1 * 1 = 1 shifted.)

9 -> 10112359550561797752808988764044943820224719
(In this test case, x = 9 and n = 10112359550561797752808988764044943820224719.
n shifted = n * x =              91011235955056179775280898876404494382022471)

6 -> 1016949152542372881355932203389830508474576271186440677966

"""

# https://oeis.org/A092697
def shifty(n):
    tab = [1, 105263157894736842, 1034482758620689655172413793, 102564, 142857, 1016949152542372881355932203389830508474576271186440677966, 1014492753623188405797, 1012658227848, 10112359550561797752808988764044943820224719]
    if n < 1 or n > len(tab):
        return 0
    return tab[n - 1]

def check(x, n):
    return str(n*x) == str(n)[-1] + str(n)[:-1]

def main():
    for i in range(1, 10):
        assert(check(i, shifty(i)))

main()
