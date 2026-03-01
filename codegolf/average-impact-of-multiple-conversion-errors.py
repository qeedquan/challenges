#!/usr/bin/env python3

"""

Imagine four people stand in a line.
The first looks at a thermometer, and tells the temperature to the person on their right.
This continues down the line, until the last person writes the temperature on a sheet of paper.
Unfortunately, due to a miscommunication, every person in the line converts the temperature to their preferred unit, without knowing which it already was.

Let's say the people's preferred units are celsius, fahrenheit, fahrenheit, celsius.
The first reads the temperature as 20°C.
The second converts to fahrenheit, and determines that it is 68°F.
The third, not knowing they have received the temperature in °F already, determines that it is 154.4°F.
Finally, it is converted back to °C by the fourth person, who determines that it is 68°C.

Task:

You will be given two inputs: a temperature (t), and a number of people (n).
Your program (or function) should return the average difference between the original and resulting temperatures, for every possible assortment of n people.

There are two temperature units: °F and °C. To convert between them, you can use F=9/5*C+32 and C=5/9*(F−32).

You can choose whether your program receives the inputted temperature in °F or °C. The first person should always receive an accurate temperature, converted to their preferred unit only if necessary.

As an example, we'll use an inputted temperature of 41°F, and just 3 people. There are 8 temperature preferences possible:

FFF   41°F  ->  41.0  ->  105.8  ->  222.44  ->  222.44°F
FFC   41°F  ->  41.0  ->  105.8  ->   41.00  ->  105.80°F
FCF   41°F  ->  41.0  ->    5.0  ->   41.00  ->   41.00°F
FCC   41°F  ->  41.0  ->    5.0  ->  -15.00  ->    5.00°F
CFF   41°F  ->   5.0  ->   41.0  ->  105.80  ->  105.80°F
CFC   41°F  ->   5.0  ->   41.0  ->    5.0  ->    41.00°F
CCF   41°F  ->   5.0  ->  -15.0  ->    5.00  ->    5.00°F
CCC   41°F  ->   5.0  ->  -15.0  ->  -26.11  ->  -15.00°F
The average distance from 41°F is 54.88°F, which is the program's output.

I/O:

Temperature should be represented as a float, decimal, or fraction of some sort. The accuracy should be within reasonable bounds; for inputs less than ten people at low temperatures there shouldn't be floating point errors or imprecision noticeable in the first four decimal digits.

You may represent the temperatures inputted and outputted as either °F or °C, but must be consistent (although the input can output can be different units as long as they don't change). Temperatures can be negative. The number of people will never be less than two.

The output is referred to as a temperature above, although it's technically the arithmetic mean of multiple temperatures.

Test Cases:

Input unit is the same as output unit for all test cases.

41°F   2   ->  25.2
41°F   3   ->  54.88
41°F   4   ->  77.236444...
41°F   10  ->  295.4268...
20°C   4   ->  57.21218...
-1°C   2   ->  12.133...
-20°C  2   ->  6.2222...
-40°F  4   ->  0

Other:

This is code-golf, shortest answer in bytes per language wins!

"""

from math import comb

r"""

@Bubbler

I finally managed to derive the correct version of tsh's formula, though it turns out to be slightly longer than brute force.

(1 + r) * [Sum[p=-n+1, n-2] r^p * sgn(p + 1/2)] / 2**n =
(1 + r) * r^(-n + 1) * [Sum[p=0, 2*n-3] r^p * sgn(p - n - 1/2)] / 2**n =
(1 + r) * [Sum[p=-n+1, n-2] binomial(n-2, floor((p+n-1)/2)) * abs(r**p - 1)] / 2^n

In array terms, the first and second formula are equivalent to building a vector containing two copies of each binomial coefficient,
negating half of it, and multiplying each with suitable power of r.

The code above uses the third line of the formula.

The process of deriving the formula was essentially spotting two copies of Pascal's triangle in the
expansion of polynomial (r^0 + r^-1) * (r^1 + r^-1)^(n-2) * (r^1+r^0), defining an intermediate function ([x;y;z] denotes if x then y else z)

f+(n, r) = Sum[p=0, n-1] binomial(n-1, p) * r^(2*p - n) [2*p - n >= 0; 1; -1].

defining the sum of differences in terms of f+ as

g(n) = f+(n - 1, r) - f+(n - 1, r^-1) + r*f+(n - 1, r) - r^-1*f+(n - 1, r^-1)

and simplifying it over an entire sheet of paper.

"""

def fixtemp(t, n):
    r = 1.8
    s = 0
    for p in range(-n + 1, n - 1):
        s += comb(n - 2, (p + n - 1) // 2) * abs(r**p - 1)
    s = s * (1 + r) / 2**n
    return s * (t + 40)

def test(t, n, r):
    v = fixtemp(t, n)
    print("%.3f" % v)
    assert(abs(v - r) < 1e-3)

def main():
    test(41, 2, 25.2)
    test(41, 3, 54.88)
    test(41, 4, 77.236444)
    test(41, 10, 295.4268)
    test(20, 4, 57.21218)
    test(-1, 2, 12.133)
    test(-20, 2, 6.2222)
    test(-40, 4, 0)

main()
