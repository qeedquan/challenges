#!/usr/bin/env python3

"""

A number of programming languages construct large integers through 'concatenating' the digit to the end of the existing number.
For example, Labyrinth, or Adapt. By concatenating the digit to the end, I mean that, if the existing number is 45, and the digit is 7, the result number is 457(45×10+7).

A constructed number is a number that can be built this way through the use of the multiples of single digit numbers: 1,2,3,4,5,6,7,8,9 A.K.A an element in one of these 9 sequences:

1,12,123,1234,12345,…
2,24,246,2468,24690,…
3,36,369,3702,37035,…
4,48,492,4936,49380,…
5,60,615,6170,61725,…
6,72,738,7404,74070,…
7,84,861,8638,86415,…
8,96,984,9872,98760,…
9,108,1107,11106,111105,…

To provide an example of how the sequences are constructed, here's how the sequence for a=3 in constructed:

u1 = a = 3 = 3
u2 = 10*u1 + 2*a = 30 + 6 = 36
u3 = 10*u2 + 3*a = 360 + 9 = 369
u4 = 10*u3 + 4*a = 3690 + 12 = 3702
u5 = 10*u4 + 5*a = 37020 + 15 = 37035
u6 = 10*u5 + 6*a = 370350 + 18 = 370368

u33 = 10*u32 + 33*a = 37...260 + 99 = 37..359
u34 = 10*u33 + 34*a = 37...359 + 102 = 37..3692

u33 and u34 included to demonstrate when n×a≥100. A lot of digits dotted out for space.. A lot of digits dotted out for space.

It may still not be clear how these sequences are constructed, so here are two different ways to understand them:

Each sequence starts from the single digit. The next term is found by taking the next multiple of that digit, multiplying the previous term by 10 and adding the multiple. In sequence terms:

un=10*u[n-1] + n*a, u1=a

where a is a single digit (1 through 9)

Each of the 9 elements at any point in the sequence (take n=3 for instance) are the multiples of 123… from 1 to 9, where 123… is constructed by un+1=10×un+n (1,12,123,…,123456789,1234567900,12345679011,…)

So the first values are 1×1,2,3,…,8,9, the second are 12×1,2,3,…,8,9, the third 123×1,2,3,…,8,9, etc.

Your task is to take a constructed number as input and to output the initial digit used to construct it. You can assume the input will always be a constructed number, and will be greater than 0. It may be a single digit, which maps back to itself.

You may take input in any reasonable manner, including as a list of digits, as a string etc. It is acceptable (though not recommended) to take input in unary, or any other base of your choosing.

This is a code-golf so the shortest code wins!

Test cases
       u_n        => a
 37035            => 3
 6172839506165    => 5
 5                => 5
 246913580244     => 2
 987654312        => 8
 61728395061720   => 5
 1111104          => 9
 11111103         => 9
 111111102        => 9
 2469134          => 2
 98760            => 8
 8641975308641962 => 7
or as two lists:

[37035, 6172839506165, 5, 246913580244, 987654312, 61728395061720, 1111104, 11111103, 111111102, 2469134, 98760, 8641975308641962]
[3, 5, 5, 2, 8, 5, 9, 9, 9, 2, 8, 7]
When I posted this challenge, I didn't realise it could be simplified so much by the method used in Grimmy's answer, and so therefore would be very interested in answers that take a more mathematical approach to solving this, rather than a 'digit' trick (Obviously all valid answers are equally valid, just what I'd be interested in seeing).

"""

"""

@Grimmy
>            # input + 1
 9*          # * 9
   н         # take the first digit

The (n-1)th term of the sequence starting with a is Sum[i=1, n-1] a*i*10^(i-1) = a * (10^(n-1)/9 - n)/9. Multiply that by 9 and add a*n, and you get a * (10^n-1)/9, aka the digit a repeated n times.
Turns out adding 9 instead of a*n works for n=1, and for bigger n the linear difference is negligible next to the exponential growth.

"""
def deconstruct(n):
    s = str((n + 1)*9)
    return int(s[0])

def main():
    assert(deconstruct(37035) == 3)
    assert(deconstruct(6172839506165) == 5)
    assert(deconstruct(5) == 5)
    assert(deconstruct(246913580244) == 2)
    assert(deconstruct(987654312) == 8)
    assert(deconstruct(61728395061720) == 5)
    assert(deconstruct(1111104) == 9)
    assert(deconstruct(11111103) == 9)
    assert(deconstruct(111111102) == 9)
    assert(deconstruct(2469134) == 2)
    assert(deconstruct(98760) == 8)
    assert(deconstruct(8641975308641962) == 7)

main()
