#!/usr/bin/env python3

"""

Mubashir needs your help to learn javaScript Programming. Help him by modifying a given string txt as follows:

Reverse the string given.
Replace each letter to its position in the alphabet for example (a = 1, b = 2, c = 3, ...).
Join the array and convert it to a number.
Convert the number to binary.
Convert the string back to a number.
See below example for more understanding :

modify("hello") ➞ 111001101011101101101010

 "hello" = "olleh"

 "olleh" = ['15', '12', '12', '5', '8']

 ['15', '12', '12', '5', '8'] = 15121258

 15121258 = "111001101011101101101010"

 "111001101011101101101010" = 111001101011101101101010
Examples
modify("hello") ➞ 111001101011101101101010

modify("mubashir") ➞ 10110000110010000110011111000111000001

modify("edabit") ➞ 111111110110001110001

Notes
There are no spaces and the string is lowercase.

"""

def modify(s):
    a = ord('a')
    z = ord('z')
    t = ""
    for i in range(len(s) - 1, -1, -1):
        c = ord(s[i])
        if a <= c and c <= z:
            c = c - a + 1
        t += str(c)
    
    b = bin(int(t))[2:]
    return int(b)

def main():
    assert(modify("mubashir") == 10110000110010000110011111000111000001)
    assert(modify("edabit") == 111111110110001110001)
    assert(modify("airforce") == 110001100001110111100011110000100011)
    assert(modify("pakistan") == 10100100011000010111100011111100111001100)
    assert(modify("hello") == 111001101011101101101010)

main()
