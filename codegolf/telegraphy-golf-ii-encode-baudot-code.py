#!/usr/bin/env python3

"""

Almost exactly 10 years ago I posed the challenge Telegraphy Golf: Decode Baudot Code. For some background on Émile Baudot and his code, I encourage you to read that question.

Today’s challenge will be to encode a message using Baudot Code.

The gist of Baudot Code is this: Each letter, number, or symbol is encoded using 5 bits, least-significant-first, which I’ll call a quintet. A is 10000. B is 00110. Interestingly, the numeral 1 is also 10000, because Baudot Code is a modal code. The meaning of each quintet depends on the encoder’s current mode: Letter or figure. Letter mode includes the letters A–Z and a couple symbols; figure mode includes the numbers 0–9 and the rest of the symbols. Two special quintets switch the mode: 00010, or “figure shift” (“FS”), switches from letter mode to figure mode and 00001, or “letter shift” (“LS”), switches from figure mode to letter mode. Those two quintets pull double duty: If you’re already in letter mode, LS produces a space (“SP”), and if you’re already in figure mode, FS produces a space.

Here’s an example, encoding the message MAY 15TH, using figure shift, letter shift, and space.

  M     A     Y   LS/SP FS/SP   1     5   LS/SP   T     H
01011 10000 00100 00001 00010 10000 11100 00001 10101 11010
(You may have noticed that this is one of two possible correct encodings, depending on whether you put the LS before or after the space.)

For this challenge we’ll use the original UK variant of Baudot Code, and for simplicity we’ll omit characters that aren’t among the printable ASCII characters.

We’re also going to omit “ER”, or “erasure”, which exists for human encoders rather than infallible computer programs.

Here’s a table of the letters, figures, and their encodings (note that ER is included for completeness but won’t be used):

        Encoding             Encoding
Ltr Fig  12345       Ltr Fig  12345
--- --- --------     --- --- --------
 A   1   10000        P   +   11111
 B   8   00110        Q   /   10111
 C   9   10110        R   -   00111
 D   0   11110        S       00101
 E   2   01000        T       10101
 F       01110        U   4   10100
 G   7   01010        V   '   11101
 H       11010        W   ?   01101
 I       01100        X       01001
 J   6   10010        Y   3   00100
 K   (   10011        Z   :   11001
 L   =   11011        -   .   10001
 M   )   01011        ER  ER  00011
 N       01111        FS  SP  00010
 O   5   11100        SP  LS  00001
 /       11000
For your convenience (hopefully), here are the encodings in a more machine-parseable format and ordered by encoding (again, including ER):

A,1,10000|E,2,01000|/,,11000|Y,3,00100|U,4,10100|I,,01100|O,5,11100|FS,SP,00010|J,6,10010|G,7,01010|H,,11010|B,8,00110|C,9,10110|F,,01110|D,0,11110|SP,LS,00001|-,.,10001|X,,01001|Z,:,11001|S,,00101|T,,10101|W,?,01101|V,',11101|ER,ER,00011|K,(,10011|M,),01011|L,=,11011|R,-,00111|Q,/,10111|N,,01111|P,+,11111
Input
Input will be a string containing only valid characters of the encoding given above, in any convenient format.

Notes
Your encoder can be assumed to start in letter mode or, if you wish, you can start every transmission with a mode shift (LS or FS).
Output
The output must be a list of bits or a list of quintets in some obvious format. While we defined Baudot Code as a least-significant-bit-first encoding, you may use LSB- or MSB-first, whichever you prefer, e.g. A could be 10000 or 00001, as long as you’re consistent.

A quintet must be represented by 5 bits, i.e. 10000 10000 is a valid encoding for AA but 00010000 00010000 is not.

A list of numbers representing quintets is valid as well.

Notes
The characters - and / exist in both letter and figure mode. You may use either mode to encode them as is convenient.
There are infinitely many valid encodings for every input because you could, say, toggle back and forth between figure mode and letter mode a dozen times in a row. Any valid encoding is a valid output.
Rules
This is code-golf. Shortest answer in bytes wins.

Default I/O rules and standard rules apply, except as noted above. Standard loopholes are forbidden.

Test cases
Input: BAUDOT
Possible output: 00110 10000 10100 11110 11100 10101

Input: HELLO
Possible output: 11010 01000 11011 11011 11100

Input: MAY 15TH
Possible output: 01011 10000 00100 00001 00010 10000 11100 00001 10101 11010

Input: 32 FOOTSTEPS
Possible output: 00010 00100 01000 00010 00001 01110 11100 11100 10101 00101 10101 01000 11111 00101

Input: GOLF
Possible output: 01010 11100 11011 01110

Input: 8D =( :P
Possible output: 00010 00110 00001 11110 00001 00010 11011 10011 00010 11001 00001 11111

Input (4 leading spaces):     -/=/-
Possible output: 00001 00001 00001 00001 10001 11000 00010 11011 10111 00111

"""

# Ported from @lynn solution
def encode(source):
    code1 = "   YSBREXGMIWFNA-JKUTCQ/ZHLOVDP"
    code2 = "3 8-2 7) ?  1.6*4 9/ : =5'0+"

    result = []
    for char in source:
        position = code1.find(char) + 1
        if position:
            result.append(position)
        else:
            result.append((2, code2.find(char) + 4, 1))
    return result

def main():
    print(encode("BAUDOT"))
    print(encode("MAY 15TH"))
    print(encode("MAY 15TH"))
    print(encode("32 FOOTSTEPS"))
    print(encode("GOLF"))
    print(encode("8D =( :P"))
    print(encode("    -/=/-"))

main()
