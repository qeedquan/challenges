#!/usr/bin/env python3

"""

Given x distinguishable balls (say they have different colors), sample with replacement repeatedly until all the balls that have been sampled have been sampled at least twice.

Challenge
The input is the integer value x≥2.

The challenge is to compute the probability that you would have seen all the balls when you stop.
You can of course stop before then, if for example you sample the same ball the first two times and x>1.
You should output the probability as an exact fraction.
For languages that don't have easy fraction arithmetic, your code can output a sum of fractions instead (e.g. 1/3 - 23/83 + 14/17).

Examples
If x=2 then the only way to stop before seeing both balls is if you sample the same ball twice in a row. This happens with probability 1/2.

The probability for x=3 is 4/9.

Why is this? Let us compute the probability that we don't see all the balls.
There is a 1/3 probability that the same ball is chosen in the first two steps and then we stop.
If this doesn't happen, there is then 2/3 probability that we don't select the third ball straight away.
In this case we will have selected one ball twice and another one a single time.
So now we want to compute the probability that we stop before seeing the third ball.
We can write this as a recursive equation.
Let p be this probability.

p=1/3 + p/3.
Solving this gives us p=1/2.
Putting it all together we get 1/3 + 2/3(2/3 * 1/2) = 5/9.
To get the desired probability that we do see all the balls we need 1 - 5/9.

The probability for x=4 is 43/96.

"""

from fractions import *

# ported from @ovs solution
def probability(x, d=0):
    if x < 1:
        return Fraction(d > 0, 1)
    return Fraction(d*probability(x*(d > 1), d - 1) + x*probability(x - 1, d + 1), d + x)

def main():
    assert(probability(0) == Fraction(0, 1))
    assert(probability(1) == Fraction(1, 1))
    assert(probability(2) == Fraction(1, 2))
    assert(probability(3) == Fraction(4, 9))
    assert(probability(4) == Fraction(43, 96))
    assert(probability(5) == Fraction(3517, 7500))
    assert(probability(6) == Fraction(17851, 36000))
    assert(probability(7) == Fraction(23119331, 44118375))
    assert(probability(8) == Fraction(91078385011, 165219532800))
    assert(probability(9) == Fraction(6779451493668383, 11759522374656000))

main()
