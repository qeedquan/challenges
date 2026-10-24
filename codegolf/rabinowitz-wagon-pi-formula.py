#!/usr/bin/env python3

"""

In 1995, Stanley Rabinowitz and Stan Wagon found an interesting algorithm to generate the digits of π one by one without storing the previous results.
The algorithm is called the spigot algorithm. It is based on the following formula:

π = 2 * (1 + 1/3 * ( 1 + 2/5 * (1 + 3/7 * (1 + ... k/(2k + 1) * (1 + ...)))))

This formula can be derived from the Leibniz formula for π using the Euler's transformation.

(The formula was already well-known before the algorithm was found, but I can't find a name for it. So I call it the Rabinowitz-Wagon π formula as @aeh5040 suggested in a sandbox comment.)

Using this formula, we can approximate π by a sequence of fractions. The first few terms are:

2     = 2
8/3   = 2 * (1 + 1/3)
44/15 = 2 * (1 + 1/3 * (1 + 2/5))
64/21 = 2 * (1 + 1/3 * (1 + 2/5 * (1 + 3/7)))

Task
In this challenge, you need to output this sequence of fractions.

You can output a fraction a/b in any reasonable format, e.g. a built-in rational type, a pair of integers (a,b), or a string a/b. You don't need to simplify the fraction.
For example, you can output 83 as 4015.

As with standard sequence challenges, you may choose to:

Take an integer n as input and output the n
th term of the sequence.
Take an integer n as input and output the first n terms of the sequence.
Take no input and output the sequence indefinitely.
The indices can be 0-based or 1-based.

This is code-golf, so the shortest code in bytes in each language wins.

Test cases
0 -> 2
1 -> 8/3
2 -> 44/15
3 -> 64/21
4 -> 976/315
5 -> 10816/3465
6 -> 141088/45045
7 -> 47104/15015
8 -> 2404096/765765
9 -> 45693952/14549535
10 -> 45701632/14549535
11 -> 80863232/25741485
12 -> 5256312832/1673196525
13 -> 3153846272/1003917915
14 -> 457311809536/145568097675
15 -> 833925152768/265447707525
16 -> 4725585805312/1504203675975
17 -> 14176771899392/4512611027925
18 -> 524540820979712/166966608033225
19 -> 104908189597696/33393321606645

"""

from fractions import Fraction

def rwpi(n):
    if n < 0:
        return 0

    r = 1
    for k in range(n, 0, -1):
        x = Fraction(k, 2*k + 1)
        r = 1 + r*x
    r *= 2
    return r

def main():
    assert(rwpi(0) == Fraction(2, 1))
    assert(rwpi(1) == Fraction(8, 3))
    assert(rwpi(2) == Fraction(44, 15))
    assert(rwpi(3) == Fraction(64, 21))
    assert(rwpi(4) == Fraction(976, 315))
    assert(rwpi(5) == Fraction(10816, 3465))
    assert(rwpi(6) == Fraction(141088, 45045))
    assert(rwpi(7) == Fraction(47104, 15015))
    assert(rwpi(8) == Fraction(2404096, 765765))
    assert(rwpi(9) == Fraction(45693952, 14549535))
    assert(rwpi(10) == Fraction(45701632, 14549535))
    assert(rwpi(11) == Fraction(80863232, 25741485))
    assert(rwpi(12) == Fraction(5256312832, 1673196525))
    assert(rwpi(13) == Fraction(3153846272, 1003917915))
    assert(rwpi(14) == Fraction(457311809536, 145568097675))
    assert(rwpi(15) == Fraction(833925152768, 265447707525))
    assert(rwpi(16) == Fraction(4725585805312, 1504203675975))
    assert(rwpi(17) == Fraction(14176771899392, 4512611027925))
    assert(rwpi(18) == Fraction(524540820979712, 166966608033225))
    assert(rwpi(19) == Fraction(104908189597696, 33393321606645))

main()
