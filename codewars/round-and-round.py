#!/usr/bin/env python3

"""

Since there are lots of katas requiring you to round numbers to 2 decimal places, you decided to extract the method to ease out the process.

And you can't even get this right!

Quick, fix the bug before everyone in CodeWars notices that you can't even round a number correctly!

"""

from decimal import *

def round_by_2_decimal_places(n):
    d = Decimal(n)
    d = d.quantize(Decimal('1e-2'), ROUND_HALF_UP)
    return d

def test(x, y):
    x = round_by_2_decimal_places(x)
    print(x)
    assert(x == y)

def main():
    test(round_by_2_decimal_places(Decimal('2')), Decimal('2'))
    test(round_by_2_decimal_places(Decimal('7.477')), Decimal('7.48'))
    test(round_by_2_decimal_places(Decimal('-4.999')), Decimal('-5'))
    test(round_by_2_decimal_places(Decimal('18.123')), Decimal('18.12'))
    test(round_by_2_decimal_places(Decimal('0')), Decimal('0'))
    test(round_by_2_decimal_places(Decimal('1.455')), Decimal('1.46'))
    test(round_by_2_decimal_places(Decimal('-1.455')), Decimal('-1.46'))
    test(round_by_2_decimal_places(Decimal('1.055')), Decimal('1.06'))
    test(round_by_2_decimal_places(Decimal('-1.055')), Decimal('-1.06'))
    test(round_by_2_decimal_places(Decimal('16.765')), Decimal('16.77'))
    test(round_by_2_decimal_places(Decimal('-16.765')), Decimal('-16.77'))
    test(round_by_2_decimal_places(Decimal('1.025')), Decimal('1.03'))
    test(round_by_2_decimal_places(Decimal('-1.025')), Decimal('-1.03'))
    test(round_by_2_decimal_places(Decimal('16.355')), Decimal('16.36'))
    test(round_by_2_decimal_places(Decimal('-16.345')), Decimal('-16.35'))
    test(round_by_2_decimal_places(Decimal('-1.1949999999999999999999999999')), Decimal('-1.19'))
    test(round_by_2_decimal_places(Decimal('-1.1950000000000000000000000001')), Decimal('-1.2'))
    test(round_by_2_decimal_places(Decimal('1.1949999999999999999999999999')), Decimal('1.19'))
    test(round_by_2_decimal_places(Decimal('1.1950000000000000000000000001')), Decimal('1.2'))
    test(round_by_2_decimal_places(Decimal('-1.1849999999999999999999999999')), Decimal('-1.18'))
    test(round_by_2_decimal_places(Decimal('-1.1850000000000000000000000001')), Decimal('-1.19'))
    test(round_by_2_decimal_places(Decimal('1.1849999999999999999999999999')), Decimal('1.18'))
    test(round_by_2_decimal_places(Decimal('1.1850000000000000000000000001')), Decimal('1.19'))

main()
