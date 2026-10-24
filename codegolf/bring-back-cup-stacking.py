#!/usr/bin/env python3

"""

Do you remember cup stacking? Young competitors compete to see how quickly they can arrange 12 upside-down plastic cups into three consecutive arrangements of cup pyramids.

The number of each cups in each pyramid is as follows:

Step 1: 3, 6, 3

Step 2: 6, 6

Step 3: 1, 10, 1

Your program or function will be called 3 times, once for each step, in order. Each time, it needs to produce the output of the cups stacked correctly for that step. Each cup is represented by a '∩' character (U+2229, 'Intersection', but see Note). Space is used for padding. 1 space is required between each pair of cups next to each other in the same pyramid, to make the triangular alignment work. Pyramids are side by side, with the bases on the same line.

Sample output
Step 1:

      ∩
 ∩   ∩ ∩   ∩
∩ ∩ ∩ ∩ ∩ ∩ ∩
Step 2:

  ∩     ∩
 ∩ ∩   ∩ ∩
∩ ∩ ∩ ∩ ∩ ∩
Step 3:

     ∩
    ∩ ∩
   ∩ ∩ ∩
∩ ∩ ∩ ∩ ∩ ∩
Input
Your program/function can either take no input (and automatically advance to the next step when called again), or take the step (counting from 0 or 1) as input. It does not need to handle bad input or being called in an incorrect sequence.

Output
As described above, in any reasonable format (stdout, arrays of arrays of characters, etc). Additional spaces before, after or between pyramids is allowed. It's acceptable to have zero space between cups in adjacent pyramids. Additional newlines before/after (but not within) are fine.

If it is impossible within your language to output the character '∩', you may substitute another (eg, 'A'), but you must score each literal instance of it within your code used for this purpose as 3 bytes.

Scoring
This is code golf. Standard rules apply.

Note
The ∩ character is also present in ASCII at code point 239 / EF. It is acceptable to output ASCII using this character.

"""

import time

CUP1 = """

      ∩
 ∩   ∩ ∩   ∩
∩ ∩ ∩ ∩ ∩ ∩ ∩
"""

CUP2 = """

  ∩     ∩
 ∩ ∩   ∩ ∩
∩ ∩ ∩ ∩ ∩ ∩
"""

CUP3 = """
     ∩
    ∩ ∩
   ∩ ∩ ∩
∩ ∩ ∩ ∩ ∩ ∩
"""

def animate():
    cups = [CUP1, CUP2, CUP3]
    index = 0
    step = 1
    while True:
        print("\x1bc")
        print(cups[index])
        index += step
        if index >= len(cups) or index < 0:
            step = -step
            index += step
        time.sleep(0.4)

def main():
    animate()

main()
