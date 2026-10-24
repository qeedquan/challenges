#!/usr/bin/env python3

"""

I came upon this while investigating some pet-project about loading code to microcontroller via attached microphone rather than using wire or radio channel. Though task is pretty simple, idea seems amusing so decided to share.

Amateur radio operators initially communicated by morse codes. Later voice transmissions became popular. Even more later people started connecting computers to their radio-sets to be able to send texts and even graphics to each other.

Now radio channel, especially over large distances, may be unreliable and noicy. So situations when receiver loses part of the data stream are not uncommon. Receiver generally can understand 3 state - 0 or 1 being passed, and no signal at all.

This gives interesting problem - if we observe bit stream flowing from the skies to our antenna, we have no special mark to understand where one byte ends and the next starts. If we have lost part of stream and then continue collecting data, we need some way to figure out "heads" and "tails" of bytes, i.e to re-synchronize again. Supposedly if we lose few letters of a text it is not a big harm.

Fibonacci Numeral System
Every integer number could be represented as sum of fibonacci values, all different. This gives us binary system with "weights" of bits not related to powers of 2, but instead to fibonacci numbers! So the lowest bit stands for 1, next for 2, third for 3, fourth for 5 and so on. For example value 32 becomes:

32  =  3 + 8 + 21  =  1010100 (fib)
Curious property of such representation is that every value could be represented without consecutive 1s. Really two 1s together could be instead represented by single 1 in the next position!

Problem Statement
You get a bit-stream. It contains bytes as Fibonacci numerals, least significant bit first (i.e. contrary to how we write numbers in European style). End of every byte is marked by additional 1, so it is easy to distinguish (as most significant bit is necessarily 1 too) by two 1s.

Decode it to ASCII.

Input gives a "bit-stream" split to several strings of 0s and 1s. For convenience first line gives the total number of "chunks" following.

Answer should contain encoded text.

Example

input
2
10101000110100100011000010101101010010110010101101
0001001110001010110100001011010000101100000000011

answer
CATS FUNNY

"""

from sympy import fibonacci

def fibs2char(s):
    r = 0
    i = 2
    for c in s:
        if c == '1':
            r += fibonacci(i)
        i += 1
    return r

def decode(s):
    r = ""
    while len(s) > 0:
        try:
            i = s.index('11')
            t = s[:i+1]
            s = s[i+2:]
        except:
            t = s
            s = s[:0]
        r += chr(fibs2char(t))
    return r

def main():
    assert(decode("101010001101001000110000101011010100101100101011010001001110001010110100001011010000101100000000011") == "CATS FUNNY")

main()
