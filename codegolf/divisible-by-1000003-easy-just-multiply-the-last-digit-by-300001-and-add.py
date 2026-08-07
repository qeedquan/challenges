#!/usr/bin/env python3

"""

Given a prime P greater than 10, your program or function must figure out its divisibility rule x, defined as the integer with smallest absolute value which yields a multiple of the original prime when multiplied by the last digit of the prime and added to the rest of the original prime.

Example
Given an input 31, the last digit is 1 and the rest of the number is 3. Thus your program must find the integer x with minimum absolute value such that 1*x + 3 is a multiple of 31. In this case, x=-3 works, so the program or function would return -3.

Given an input 1000003, the last digit is 3 and the rest of the number is 100000. Thus your program would find x=300001 because 3*300001+100000 = 1000003 which is a multiple of 1000003.

Mathematical Background
The value of x can be used as a divisibility test. If a number N is divisible by P, then adding x times the last digit of N to the rest of N will yield a multiple of P if and only if N is divisible by P in the first place.

For P=11, we get x=-1, which is equivalent to the well-known divisibility rule for 11: a number is divisible by 11 alternating difference of its digits is divisible by 11.

Rules
The output may be in any form that clearly encodes both the sign and value of the output.
The input prime will be between 10 and 2^30.
You do not need to handle if the input is not a prime or is not in the range.
You do not need to handle if both x and -x are valid outputs (should not happen).
Brute force is permitted, but more creative solutions are appreciated.
This is code-golf, so shortest code in each language wins! Do not let answers in golfing languages discourage you from posting in other languages.
Test Cases
Input   Output
11  -1
13  4
17  -5
19  2
23  7
29  3
31  -3
37  -11
41  -4
43  13
47  -14
53  16
59  6
61  -6
67  -20
71  -7
73  22
79  8
83  25
89  9
97  -29
101 -10
103 31
107 -32
109 11
113 34
127 -38
131 -13
1000003 300001
2000003 600001
2999999 300000
9999991 -999999

"""

"""

@David Foerster
Can anybody provide a hint why (3 / (n % 5 * 2 - 5) * n + 1) / 10 and (n % 5 * 2 - 5^2) * n / 10 + 1 are able to find a minimal absolute value for something like this? My first intuition would have been to calculate the least common multiple using the greatest common divisor calculated with Euclid's algorithm. 

@Neil
Given a number, you can remove the last digit, multiply it by a number x, add it on, and still get a number divisible by n. If we then multiply the new number by 10 and subtract the original number it still remains divisible by n. xnor's comment then follows from some algebra. The next step is to rearrange the formula so that it gives x in terms of n: x = (k*n+1)/10. We want the smallest absolute x so therefore we want the smallest absolute k, and this must be whichever one of -3, -1, 1 or 3 (depending on n's last digit) that makes the division exact. 

"""

def value(n):
    return (3//((n%5)*2 - 5)*n + 1) // 10

def main():
    assert(value(11) == -1)
    assert(value(13) == 4)
    assert(value(17) == -5)
    assert(value(19) == 2)
    assert(value(23) == 7)
    assert(value(29) == 3)
    assert(value(31) == -3)
    assert(value(37) == -11)
    assert(value(41) == -4)
    assert(value(43) == 13)
    assert(value(47) == -14)
    assert(value(53) == 16)
    assert(value(59) == 6)
    assert(value(61) == -6)
    assert(value(67) == -20)
    assert(value(71) == -7)
    assert(value(73) == 22)
    assert(value(79) == 8)
    assert(value(83) == 25)
    assert(value(89) == 9)
    assert(value(97) == -29)
    assert(value(101) == -10)
    assert(value(103) == 31)
    assert(value(107) == -32)
    assert(value(109) == 11)
    assert(value(113) == 34)
    assert(value(127) == -38)
    assert(value(131) == -13)
    assert(value(1000003) == 300001)
    assert(value(2000003) == 600001)
    assert(value(2999999) == 300000)
    assert(value(9999991) == -999999)

main()
