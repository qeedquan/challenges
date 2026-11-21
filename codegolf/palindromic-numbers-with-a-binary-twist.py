#!/usr/bin/env python3

"""

Warning : this is NOT a "hey, let's draw a cake in ASCII-art" challenge! Please keep reading ;)

Some time ago it was my birthday, I'm 33 now.

So there is this awkward social tradition consisting in inviting family and friends, putting number-like candles on a cake, sing songs and open gifts.

   33
--------
Instead of numbers, I can use the binary system to put standard candles: I place 6 of them on the cake and light two of them.

 100001
--------
I can see that both decimal and binary numbers of my age are palindromic!

Challenge
I want to know if any other number can be put on a cake with candles and be palindromic, decimal and binary.

Write a program/function to test if a number is palindromic in both decimal and binary. But wait, there's more : in binary, leading zeros count for the test!

Input
A decimal number x that I want to test if it is birthday palindromic with 0 < x < 232-1 (yes, the people in my dimension live very long)

Output
Truthy if it meets exactly these two conditions, Falsey else:

The decimal representation of the number is a standard palindrome
The binary representation of the number is a standard palindrome, and adding leading zeros may help with this
Test cases
1 > 1 => Truthy
6 > 110 (0110) => Truthy
9 > 1001 => Truthy
10 > 1010 (01010) => Falsey, 10 is not palindromic
12 => 1100 (001100) => Falsey, 12 is not palindromic
13 => 1101 (...01101) => Falsey, neither 13 nor 1101 are palindromic
14 => 1110 (01110) => Falsey, 14 is not palindromic
33 > 100001 => Truthy
44 > 101100 (..0101100) => Falsey, 101100 is not palindromic
1342177280 > 1010000000000000000000000000000 (00000000000000000000000000001010000000000000000000000000000) => Falsey, 1342177280 is not palindromic (but the binary representation is)
297515792 > 10001101110111011101100010000 (000010001101110111011101100010000) => Truthy
##Rules##

Standard loopholes are disallowed
Built-in library conversions and tests are allowed
This is code-golf, the shortest code win!
Good luck, and eventually happy birthday!

"""

def palindromic(n):
    s = str(n)
    t = bin(n).strip('0b')
    return s == s[::-1] and t == t[::-1]

def main():
    assert(palindromic(1) == True)
    assert(palindromic(6) == True)
    assert(palindromic(9) == True)
    assert(palindromic(10) == False)
    assert(palindromic(12) == False)
    assert(palindromic(13) == False)
    assert(palindromic(14) == False)
    assert(palindromic(33) == True)
    assert(palindromic(44) == False)
    assert(palindromic(1342177280) == False)
    assert(palindromic(297515792) == True)

main()
