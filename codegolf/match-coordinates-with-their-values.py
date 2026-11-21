#!/usr/bin/env python3

"""

Given 3 input items, a list of coordinate pairs, a 2D string, and a single-character string, output whether the character at each coordinate of the 2D string is equal to the single character. You can take the input in any order and the coordinates may be 1-indexed.

You may take the 2D string as a 2D list, a list of lines, or a 2D string.

Example: (0,0), "#_\n__", "#" -> True

The string is

#_
__
The char at the coordinate (0,0) (from the top left) is #. This is equal to the third input item, #, so you output True (or any truthy value)

Example: [(0,0), (1,1)], "#_\n_#", "#" -> True

The string is

#_
_#
The characters at the coordinates of (0,0) and (1,1) are both #, so the output is true.

The output is only true iff every coordinate matches a hash. Not every hash has to have a matching coordinate though. If there are no occurrences of the single char (# in some of the test cases) in the 2D string, the output is still just falsy.

You can assume the coordinates will always be within the bounds of the 2D string.

More test cases: (I put the single char second for ease of readability)

[(0,0), (2,1), (3,0)], #

#_##
#_##

True


[(0,0), (1,1), (3,0)], #

#_##
#_##

False (1,1 is not a hash)



[(1,1)], a

#a##
#a##

True


[(4, 0), (3, 0), (2, 0), (1, 0), (0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (2, 2), (3, 2), (4, 2), (4, 3)], ' '


 ####
 #   
   # 

True
Note the last test case uses spaces as the single char string, and hashes around the spaces.

Related. (inverse of this challenge)

"""

def match(p, s, c):
    t = s.split('\n')
    for x, y in p:
        try:
            if t[y][x] != c:
                return False
        except:
            return False

    return True

def main():
    assert(match([(0, 0)], "#_\n__", '#') == True)
    assert(match([(0, 0), (1, 1)], "#_\n_#", '#') == True)
    assert(match([(0, 0), (2, 1), (3, 0)], "#_##\n#_##", '#') == True)
    assert(match([(0, 0), (1, 1), (3, 0)], "#_##\n#_##", '#') == False)
    assert(match([(4, 0), (3, 0), (2, 0), (1, 0), (0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (2, 2), (3, 2), (4, 2), (4, 3)], "     \n #### \n #   \n   # \n     \n", ' ') == True)

main()
