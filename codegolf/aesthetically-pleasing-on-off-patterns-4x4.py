#!/usr/bin/env python3

"""

According to the numbersaplenty.com website, certain small numbers display some kind of symmetry when their binary digits are arranged in a 3×3 square grid.

For this challenge, we are using a 4×4 grid. Furthermore, to prevent large numbers from being disqualified, we are separating the binary digits into multiple chunks of 16 and place them in separate 4×4 grids.

Take the number 94220 for example.

Start from the number: 94220
Convert to binary: 10111000000001100
Pad leading zeros to 2×16 digits: 0000000000000001 0111000000001100
Place them in 4×4 grids:
0000
0000
0000
0001

0111
0000
0000
1100
Result: only the first grid has an axis of symmetry.
The second grid is not symmetric at all. It would have been symmetric about its center if the first 1 were turned to 0.

Task
Given a positive integer n (in decimal), determine whether every resulting 4×4 grid satisfies at least one of the conditions below:

has an orthogonal or diagonal axis of symmetry that passes its center;
is 180-degree rotationally symmetrical about its center.
This is code-golf, so the shortest code in bytes wins.

This is also a decision-problem so you may use your language's convention for truthy/falsy (swapping truthy and falsy is allowed), or use two distinct, fixed values to represent true or false.

More test cases
Input: 35
Grid:
0000
0000
0010
0011

The cluster of ones have a diagonal axis of symmetry, but the axis does not pass through the grid's center. In other words, if you considered the ones and the zeroes together, the grid does not have an axis of symmetry.

Result: falsy
Input: 66
Grid:
0000
0000
0100
0010

The cluster of ones is 180-degree rotationally symmetrical, but the center of symmetry is not the grid's center. In other words, if you considered the ones and the zeroes together, the grid does not have a center of symmetry.

Result: falsy
Input: 4080
Grid:
0000
1111
1111
0000

The grid has two axes of symmetry that passes its center, and is 180-degree rotationally symmetric about its center.

Result: truthy
Input: 399244
Grid:
0000
0000
0000
0110

0001
0111
1000
1100

The first grid is symmetric, while the second isn't.

Result: falsy
Note: Original title was "Esthetically Pleasing On/off Patterns" to match the initial letters of the Puzzling SE post.

"""

# Ported from @spears0fgungnir solution
def check_blocks(n):
    bits = bin(n)[2:]
    bits = bits.zfill((len(bits) + 15) // 16 * 16)
    for start in range(0, len(bits), 16):
        block = bits[start : start + 16]

        rows_reversed = block[::-1]
        rotated_rows = (
            block[12:16]
            + block[8:12]
            + block[4:8]
            + block[0:4]
        )
        columns = (
            block[::4]
            + block[1::4]
            + block[2::4]
            + block[3::4]
        )

        allowed_forms = (
            rows_reversed,
            rotated_rows,
            rotated_rows[::-1],
            columns,
            columns[::-1],
        )

        if block not in allowed_forms:
            return False

    return True

def main():
    assert(check_blocks(35) == False)
    assert(check_blocks(66) == False)
    assert(check_blocks(4080) == True)
    assert(check_blocks(399244) == False)

main()
