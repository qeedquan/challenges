/*

UTF-8 is the most widely used character encoding on the internet. It encodes a Unicode code point into a byte sequence of 1 to 4 bytes long.

The UTF-8 encoding has many features that makes it popular, such as compatibility with ASCII and a self-synchronizing encoding.

UTF-8 introduction in Wikipedia

For this coding challenge, you (the challenger/coder) are to implement a UTF-8 decoder, that is, a function that transforms a UTF-8 byte sequence into a Unicode code point.

We are aiming for a decoder that can be practically used by or embedded into other applications, thus the decoder must be able to detect invalid byte sequence, and potentially be called multiple times to decode a UTF-8 string. (Your function should decode just one character. The wrapper code that turns a character decoder into a string decoder is not part of this challenge.)

UTF-8 brief overview
A UTF-8 sequence is a byte sequence that is 1 to 4 bytes long. The length of the sequence can be indicated by the value of the first byte (sometimes also known as "lead byte"). The other bytes of the sequence may be known (informally) as "continuation bytes". The bits of a Unicode code point will be contained in this one- to four-byte sequence.

Below is the table of the valid sequences and the ranges of the Unicode code points (taken from Table 3-7 of the Unicode standard core specification).

First byte	Second byte	Third byte	Fourth byte	Decoded code point
00 - 7F	not needed	not needed	not needed	0 - 7F
C2 - DF	80 - BF	not needed	not needed	80 - 7FF
E0	A0 - BF	80 - BF	not needed	800 - FFF
E1 - EC	80 - BF	80 - BF	not needed	1000 - CFFF
ED	80 - 9F	80 - BF	not needed	D000 - D7FF
EE - EF	80 - BF	80 - BF	not needed	E000 - FFFF
F0	90 - BF	80 - BF	80 - BF	10000 - 3FFFF
F1 - F3	80 - BF	80 - BF	80 - BF	40000 - FFFFF
F4	80 - 8F	80 - BF	80 - BF	100000 - 10FFFF
(all numbers are in hexadecimal in this table)

Byte sequences outside of this table are invalid. Note that the decoded code point can never be in the range [0xD800, 0xDFFF] as this range is invalid (these are "surrogate code units" and are invalid in UTF-8).

To decode the byte sequence to a Unicode code point, first format the byte values of the sequence into binary, then extract the specified bits from the sequence according to the table below (Table 3-6 of the Unicode standard core specification), and join the bits to form a code point value.

First byte	Second byte	Third byte	Fourth byte	Decoded code point
0xxxxxxx	n/a	n/a	n/a	0xxxxxxx
110yyyyy	10xxxxxx	n/a	n/a	00000yyy yyxxxxxx
1110zzzz	10yyyyyy	10xxxxxx	n/a	zzzzyyyy yyxxxxxx
11110uuu	10zzzzzz	10yyyyyy	10xxxxxx	uuuzz zzzzyyyy yyxxxxxx
(all numbers are in binary in this table)

For example the byte sequence F4 8A B3 87 is decoded to 0x10ACC7 (a private-use character):

           F4(hex)  8A(hex)  B3(hex)  87(hex)
Binary -> 11110100 10001010 10110011 10000111
               uuu   zzzzzz   yyyyyy   xxxxxx
               100   001010   110011   000111

Joined bits ->        uuuzz zzzzyyyy yyxxxxxx
                      10000 10101100 11000111
Decoded code point ->             10ACC7(hex)
Invalid sequence handling
Unicode allows a non-fatal conversion of a string or text. If an invalid UTF-8 sequence is encountered in the middle of a UTF-8 string, the decoder may replace the invalid sequence with the "replacement character" (U+FFFD) and then continue decoding the rest of the string. For decoding web content, WHATWG Encoding Standard requires a consistent behavior on how many U+FFFD characters should be decoded to, when a series of bytes that would decode to invalid UTF-8 are encountered. The requirement is: one U+FFFD for each "Maximal Subparts" of the invalid sequence. Though this challenge would not want your function to perform the U+FFFD substitution, your function is required not to read beyond the first byte of the input that makes the UTF-8 sequence invalid.

The official definition of the Maximal Subparts might be complicated to the readers (you can read it in the official specification if you like), thus I make an alternative wording that is equivalent to the official definition:

If the first byte (lead byte) of a UTF-8 sequence is in range [0x80, 0xC1] ∪ [0xF5, 0xFF], it's an invalid byte, and the length of the Maximal Subparts of the sequence is defined to be 1.
If an invalid byte is encountered not on the first byte position, but on the second, third, or fourth, the length of the Maximal Subparts is the number of bytes just processed subtracting that invalid byte. The length may be 1 to 3 in this case. Since that invalid byte may be the start of another valid UTF-8 sequence, the length of the Maximal Subparts is defined to exclude that byte.
C2 00       -> length 1 (second byte is invalid)
E0 A0 00    -> length 2 (third byte is invalid)
F0 90 00    -> length 2 (third byte is invalid)
F0 90 80 00 -> length 3 (fourth byte is invalid)
The lengths of Maximal Subparts are handled the same way for "overlong encodings", "surrogate code points" and "code points that would be greater than 0x10FFFF". These error cases can be detected on the second byte of each sequence, and thus the length of Maximal Subparts would always be 1:
C0          -> length 1 (overlong encoding)
E0 80       -> length 1 (overlong encoding)
F0 80       -> length 1 (overlong encoding)

ED A0       -> length 1 (surrogate code point)

F4 90       -> length 1 (decode to >0x10FFFF)
F5          -> length 1 (decode to >0x10FFFF)
Your function is required to output this length of Maximal Subparts in case of an invalid sequence. You do not need to identify the kinds of the encoding error in the output, however.

Input
An array of bytes (a byte contains 8 bits) containing a sequence of a UTF-8 coded character. You may use any data type that can conveniently represent a byte array for your programming language. (Replace "array" with "list" and "byte" with "integer" if the latter terms are more appropriate for your language.) The bytes of the input array may be padded with extra bits of 0 (such as {0x00F4, 0x008A, 0x00B3, 0x0087}) if you use any data type larger than 8 bits as the input array elements.
The input sequence is assumed to be terminated either by a byte value of zero or a value that can complete the sequence or make the sequence invalid. You don't need to implement a length check of the input array.
If your programming language can only process text (e.g. Bash script), then the input should be a sequence of integers formatted in hexadecimal, with a space separating each byte value (like the number formatting in the test data below). (Note: A UTF-8 byte sequence is almost always formatted in hexadecimal. The reason for this formatting requirement is to avoid trivializing the problem, by leveraging any Unicode decoding feature of the language when processing inputs. This doesn't forbid inputs in any other base if your language can process non-text inputs.) The input format of the text is assumed to be valid (for example, there would be no gibberish input like gh ij kl mnop), but you must handle invalid byte values when they appear in the input whose format is valid (such as FF FF FF FF). You may be strict or loose on the letter cases of the hexadecimal digits (that is, you may accept one case only or both).
Don't use any character or string data type provided by your programming language as input. (Let's assume the character data type of your language has a broken support of Unicode.)
Output
There must be at least two outputs: The decoded Unicode code point (if the UTF-8 sequence is valid), and the number of bytes in the sequence.
The main output of your function (the return value, if supported by your language) must be either the decoded Unicode code point or a flag value to indicate an error. If the input UTF-8 sequence is valid, the function must output the code point. Otherwise it must output a value outside the range [0x0, 0x10FFFF] to indicate an error. You may use -1 as an error value but it is not required.
The second output should represent the "length" of the UTF-8 sequence, so that the next potentially valid UTF-8 sequence in a string can be located in the &input[length] location (when expressed in C array notation). It is not required to output the length in an integer. You may use any data type in your programming language that can conveniently represent this length, directly or indirectly. (For example in C, a pointer pointing to the end of the just-decoded sequence is allowed as output.)
If the input byte sequence is invalid UTF-8, the "length" output must be the length of the Maximal Subparts of the invalid sequence (definition D93b in the Unicode standard core specification). The UTF-8 decoder as specified in WHATWG Encoding Standard conforms to this. This implies that your function must not read beyond the first byte that makes the UTF-8 sequence invalid in the byte array. (Please assume doing so can segfault).
If your programming language can only output text, format the two output values in signed hexadecimal. (The second output "length" can only be in the range [1, 4], thus whether it's formatted in decimal or hexadecimal doesn't matter.) (Note: A UTF-8 code point is usually formatted in hexadecimal as well, with a notable exception of HTML/XML numeric character reference, where decimal formating may be seen, e.g. &#1092807; for U+10ACC7.)
Additional requirements
Using any Unicode function from any programming language or library is not allowed. The goal of this challenge is to implement one decoder by yourself, not to call someone else's decoder. (Please assume the Unicode functions of your programming language or libraries are broken.)
String functions and array functions are allowed if they are not related to Unicode (such as querying an array's length).
Bit counting functions such as count leading zeros are allowed. However, if you use any compiler extension (such as __builtin_clz in GCC/Clang), you must label the compiler in your answer / submission entry. If you use standard functions of your language (such as std::countl_zero in C++) you do not need the labeling.
code-golf. Aim for code size as small as possible.
Test data
00          ->      0 1
01          ->      1 1
7F          ->     7F 1
C2 80       ->     80 2
DF BF       ->    7FF 2
E0 A0 80    ->    800 3
ED 9F BF    ->   D7FF 3
EE 80 80    ->   E000 3
EF BF BD    ->   FFFD 3
EF BF BF    ->   FFFF 3
F0 90 80 80 ->  10000 4
F4 8F BF BF -> 10FFFF 4

C2 00       ->     -1 1
DF 7F       ->     -1 1
E0 A0 00    ->     -1 2
ED 9F 7F    ->     -1 2
EE 80 C0    ->     -1 2
EF BF C2    ->     -1 2
F0 90 E0    ->     -1 2
F4 8F F0    ->     -1 2
F0 90 80 F5 ->     -1 3
F4 8F BF FF ->     -1 3

80          ->     -1 1
BF          ->     -1 1

C0          ->     -1 1
C1          ->     -1 1
E0 80       ->     -1 1
E0 9F       ->     -1 1
F0 80       ->     -1 1
F0 8F       ->     -1 1

ED A0       ->     -1 1
ED BF       ->     -1 1

F4 90       ->     -1 1
F4 BF       ->     -1 1
F5          ->     -1 1
F7          ->     -1 1
F8          ->     -1 1
FC          ->     -1 1
FE          ->     -1 1
FF          ->     -1 1
Sample (non-golf) implementation
https://gitlab.com/-/snippets/3718423 (the utf8_to_code_point_la1() function) This code is under MIT license.

The code can compile to 112-byte x86-64 machine code using gcc-15.1 with -Os option.

Before posting this challenge to Code Golf Stack Exchange, this was a challenge I was personally making of trying to implement a UTF-8 decoder that compiles to machine code as small as possible.

You may use my code as an inspiration for your submission, but please give me proper credit if you do.

*/

fn main() {
    decode(&vec![0x0]);
    decode(&vec![0x1]);
    decode(&vec![0x7f]);
    decode(&vec![0xc2, 0x80]);
    decode(&vec![0xdf, 0xbf]);
    decode(&vec![0xe0, 0xa0, 0x80]);
    decode(&vec![0xed, 0x9f, 0xbf]);
    decode(&vec![0xee, 0x80, 0x80]);
    decode(&vec![0xef, 0xbf, 0xbd]);
    decode(&vec![0xef, 0xbf, 0xbf]);
    decode(&vec![0xf0, 0x90, 0x80, 0x80]);
    decode(&vec![0xf4, 0x8f, 0xbf, 0xbf]);

    decode(&vec![0xc2, 0x00]);
    decode(&vec![0xdf, 0x7f]);
    decode(&vec![0xe0, 0xa0, 0x00]);
    decode(&vec![0xed, 0x9f, 0x7f]);
    decode(&vec![0xee, 0xb0, 0xc0]);
    decode(&vec![0xef, 0xbf, 0xc2]);
    decode(&vec![0xf0, 0x90, 0xe0]);
    decode(&vec![0xf4, 0xbf, 0xf0]);
    decode(&vec![0xf0, 0x90, 0x80, 0xf5]);
    decode(&vec![0xf4, 0x8f, 0xbf, 0xff]);

    decode(&vec![0xc0]);
    decode(&vec![0xc1]);
    decode(&vec![0xe0, 0x80]);
    decode(&vec![0xe0, 0x9f]);
    decode(&vec![0xf0, 0x80]);
    decode(&vec![0xf0, 0x8f]);

    decode(&vec![0xed, 0xa0]);
    decode(&vec![0xed, 0xbf]);

    decode(&vec![0xf4, 0x90]);
    decode(&vec![0xf4, 0xbf]);
    decode(&vec![0xf5]);
    decode(&vec![0xf7]);
    decode(&vec![0xf8]);
    decode(&vec![0xfc]);
    decode(&vec![0xfe]);
    decode(&vec![0xff]);
}

fn decode(data: &Vec<u8>) {
    let string = String::from_utf8(data.clone());
    if string.is_ok() {
        let string = string.unwrap();
        println!("{:x?} {}", string.as_bytes(), string.len());
    } else {
        println!("{:x?} -1", data);
    }
}
