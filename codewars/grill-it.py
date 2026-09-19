#!/usr/bin/env python3

"""

Introduction

A grille cipher was a technique for encrypting a plaintext by writing it onto a sheet of paper through a pierced sheet (of paper or cardboard or similar). The earliest known description is due to the polymath Girolamo Cardano in 1550. His proposal was for a rectangular stencil allowing single letters, syllables, or words to be written, then later read, through its various apertures. The written fragments of the plaintext could be further disguised by filling the gaps between the fragments with anodyne words or letters. This variant is also an example of steganography, as are many of the grille ciphers. Wikipedia Link

https://upload.wikimedia.org/wikipedia/commons/8/8a/Tangiers1.png
https://upload.wikimedia.org/wikipedia/commons/b/b9/Tangiers2.png

Task

Write a function that accepts two inputs: message and code and returns hidden message decrypted from message using the code.
The code is a nonnegative integer and it decrypts in binary the message.

message : abcdef
code    : 000101
----------------
result  : df

"""

def grille(message, code):
    length = len(message)
    text = ""
    for i in range(length):
        if code & (1 << (length - i - 1)):
            text += message[i]
    return text

def main():
    assert(grille("", 5) == "")
    assert(grille("ab", 255) == "ab")
    assert(grille("ab", 256) == "")

    assert(grille("abcd", 1) == "d")
    assert(grille("0abc", 2) == "b")
    assert(grille("abcdef", 5) == "df")
    assert(grille("abcde", 32) == "")
    assert(grille("abcde", 223) == "abcde")
    assert(grille("tcddoadepwweasresd", 77098) == "codewars")

main()
