#!/usr/bin/env python3

"""

In honor of how much rep I had several hours ago, when I first thought of this challenge:

https://i.sstatic.net/HftMG.png

Numbers like this that are made up of a single digit repeating are called repdigits. Repdigits are fun! Every body would be more happy if the amount of rep they had was a repdigit¹, but I am impatient, so you need to help me find out the fastest way to get to a repdigit.

Here is your challenge:

Given a positive integers representing reputation, output the minimum amount of rep they need to gain to get to a repdigit. For example, at the time of writing this challenge, user Martin Ender had 102,856 rep. The nearest rep-digit is 111,111, so he would need to gain: 8255 rep to be at a repdigit.

Since people dislike losing rep, we will only consider non-negative changes. This means that, for example, if someone is at 12 rep, rather than losing 1 rep, the solution is to gain 10 rep. This allows '0' to be a valid output, since anyone who has 111 rep is already at a repdigit.

Input and output can be in any reasonable format, and since it is impossible to have less than 1 rep on any Stack Exchange site, you can assume no inputs will be less than 1.

One cornercase to note:

If a user has less than 10 rep, they are already at a repdigit, and so they also need '0'.

Test IO:
#Input      #Ouput
8           0
100         11
113         109
87654321    1234567
42          2
20000       2222
11132       11090
Standard loopholes apply, and the shortest solution in bytes wins!

"""

"""

@Dennis

How it works
For input 10**len(`n`) rounds n up to the nearest power of 10. Afterwards, we divide the result by 9. This returns the repdigit 1…1 that has as many digits as n. We save the result in r. For example, if n = 87654321, then r = 11111111.

The desired repdigit will be a multiple or r. To decide which, we perform ceiling division of n by r. Since Python 2's division operator / floors, this can be achieved with -n/r, which will yield the correct absolute value, with negative sign. For example, if n = 87654321, this will return -8.

Finally, we multiply the computed quotient by -r to repeat the quotient once for each digit in n. For example, if n = 87654321, this returns 88888888, which is the desired repdigit.

Finally, to calculate the required increment, we subtract n from the previous result. For our example n = 87654321, this returns 1234567, as desired.

"""
def repdigit(n):
    r = 10**len(str(n))//9
    return -n//r * -r - n

def main():
    assert(repdigit(8) == 0)
    assert(repdigit(100) == 11)
    assert(repdigit(113) == 109)
    assert(repdigit(87654321) == 1234567)
    assert(repdigit(42) == 2)
    assert(repdigit(20000) == 2222)
    assert(repdigit(11132) == 11090)

main()
