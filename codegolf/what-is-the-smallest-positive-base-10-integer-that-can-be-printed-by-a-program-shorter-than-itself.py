#!/usr/bin/env python3

"""

I think the question as above is clear, but just in case:

Write a full program (not just a function) which prints a positive base 10 integer, optionally followed by a single newline.

Qualifying programs will be those whose output is longer (in bytes) than the source code of the program, measured in bytes (assuming ASCII or UTF-8 encoding for the program source code).

I.e. the code must be shorter than the number of digits in the resulting number.

Leading zeros are disallowed under all circumstances. Counting leading zeroes trivialises the problem; ignoring leading zeros unnecessarily complicates the question.

The winning program will be the qualifying program which prints the integer with the smallest magnitude.

"""

def main():
    print(str(100)*100)

main()
