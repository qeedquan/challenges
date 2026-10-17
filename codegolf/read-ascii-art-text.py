#!/usr/bin/env python3

"""

Inspired by Golf me an ASCII Alphabet, of which this challenge is (almost) a direct inverse.
https://codegolf.stackexchange.com/questions/80940/golf-me-an-ascii-alphabet

Task:
Take a string of ASCII-art text and output the content of the text as regular ASCII text.

Input:
String of ASCII-art text.

Input will only contain instances of ASCII character #, spaces and 4 or 5 newlines (a trailing newline is optional). All lines have the same length. (That is, the last ASCII-art letter is padded with trailing spaces.) You can use some other printable ASCII character instead of # in the input if you wish.

The input will contain ASCII-art letters A-Z and ASCII-art spaces (a 5x5 block of whitespace). No punctuation. There is only one line of ASCII-art text (5 actual lines). There will be no trailing or leading ASCII-art spaces, nor will there be adjacent ASCII-art spaces.

Letter size is 5x5 characters. There is a 1x5 space between each letter. Space between words is a 5x5 block of whitespace (+ 1x5 space on each side, because it is just another letter). There will be no 1x5 space at the end or at the beginning, only between ASCII-art letters.

Output:
String containing the text as ASCII characters A-Z + spaces. The output can be in lowercase also, if that is somehow easier for your solution. Mixed case is also allowed.

The ASCII-art letters:
 ###  ####   ###  ####  ##### #####  ###  #   # ##### ##### #   # #     #   #
#   # #   # #   # #   # #     #     #     #   #   #     #   #  #  #     ## ##
##### ####  #     #   # ####  ####  #  ## #####   #     #   ###   #     # # #
#   # #   # #   # #   # #     #     #   # #   #   #   # #   #  #  #     #   #
#   # ####   ###  ####  ##### #      ###  #   # ##### ###   #   # ##### #   #

#   #  ###  ####   ###  ####   ###  ##### #   # #   # #   # #   # #   # #####
##  # #   # #   # #   # #   # #       #   #   # #   # #   #  # #   # #     #
# # # #   # ####  #   # ####   ###    #   #   #  # #  # # #   #     #     #
#  ## #   # #     #  #  #   #     #   #   #   #  # #  ## ##  # #    #    #
#   #  ###  #      ## # #   #  ###    #    ###    #   #   # #   #   #   #####
The space:

     |
     | A 5x5 square of spaces.
     | (Padded with |s to make it appear in this post.)
     |
     |
Examples:
Input:

#   # ##### #     #      ###        #   #  ###  ####  #     ####
#   # #     #     #     #   #       #   # #   # #   # #     #   #
##### ####  #     #     #   #       # # # #   # ####  #     #   #
#   # #     #     #     #   #       ## ## #   # #   # #     #   #
#   # ##### ##### #####  ###        #   #  ###  #   # ##### ####
Output: HELLO WORLD

Input:

 ###   ###   ###  ##### #####
#   # #     #   #   #     #
#####  ###  #       #     #
#   #     # #   #   #     #
#   #  ###   ###  ##### #####
Output: ASCII

Input:

####  ####   ###   ###
#   # #   # #   # #
####  ####  #     #  ##
#     #     #   # #   #
#     #      ###   ###
Output: PPCG

This is code-golf, so the shortest answer in bytes wins.

"""

# Ported from @ovs solution
def decode(text):
    alphabet = " QPVXU_O__FBLK_JMD_CSYZWIENH_AG___TR"
    lines = text.splitlines()
    result = []
    for column in range(0, len(text)//5, 6):
        bits = 0
        for row in range(5):
            group = lines[row][column:column + 5]
            values = "".join(group)
            for value in values:
                bits = (bits << 1) | (ord(value) & 1)

        index = (bits % 13836) % 37
        result.append(alphabet[index])

    return "".join(result)

print(decode("""
#   # ##### #     #      ###        #   #  ###  ####  #     #### 
#   # #     #     #     #   #       #   # #   # #   # #     #   #
##### ####  #     #     #   #       # # # #   # ####  #     #   #
#   # #     #     #     #   #       ## ## #   # #   # #     #   #
#   # ##### ##### #####  ###        #   #  ###  #   # ##### #### """[1:]))

print(decode("""
 ###   ###   ###  ##### #####
#   # #     #   #   #     #  
#####  ###  #       #     #  
#   #     # #   #   #     #  
#   #  ###   ###  ##### #####"""[1:]))

print(decode("""
####  ####   ###   ### 
#   # #   # #   # #    
####  ####  #     #  ##
#     #     #   # #   #
#     #      ###   ### """[1:]))
