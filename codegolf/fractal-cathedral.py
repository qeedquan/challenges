#!/usr/bin/env python3

"""

Given a positive integer n >= 1, output the first n rows of the following structure:

   #
  # #
  ###
 #   #
 # # #
 ## ##
 #####
#     #
#  #  #
# # # #
# ### #
##   ##
## # ##
### ###
#######

The n-th 1-indexed row is the binary representation of n, mirrored without copying the last character, with # in place of 1 and <space> in place of 0. All rows are centered.

You must output as ASCII-art but you may use any non-whitespace character in place of where I use # in the example. Trailing whitespace is allowed, and a trailing newline is allowed. The output must look like the example, and no extra leading whitespace or leading newlines.

You can view the first 1023 rows of the fractal cathedral here.

To generate larger test cases, here's an ungolfed reference implementation in Python

"""

import math

def draw(rows):
    width = math.ceil(math.log(rows + 1, 2))
    for row in range(1, rows + 1):
        binary = bin(row)[2:]
        binary = binary.replace('0', ' ').rjust(width).replace('1', '#')
        print(binary[:-1] + binary[::-1])

def main():
    draw(1023)

main()
