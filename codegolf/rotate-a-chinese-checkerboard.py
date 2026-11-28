#!/usr/bin/env python3

"""

A Chinese checkerboard looks like this (based on this question, but this time it has a fixed size):

            G
           . G
          G G G
         G G . G
B B B B . . Y G . Y . Y Y
 B B B . . G . . . Y Y Y
  B . B . . . . . Y . Y
   B . . . . . . . . Y
    . . . . . . . . .
   . P . . . . . O O .
  P P . . . . . . . O O
 P P P . . . R . . O O .
P P P P . . R . . O O O O
         R . R R
          R R R
           R .
            R
Each non-space character in this example can be replaced by any non-space printable ASCII character in the input, while spaces are never changed. Note that it isn't guaranteed to be a valid arrangement in Chinese checker (such as it may not have exactly 7 different kind of characters).

Your task is to rotate it by a multiple of 60 degrees.

This is the above example rotated by 60 degrees clockwise:

            B
           B B
          B B B
         B . B B
P P P . . . B . . G G . G
 P P P P . . . . . G G G
  P P . . . . . G Y . G
   P . . . . . . . G G
    . . . . . . . . .
   R . . . . . . . . Y
  R . R R . . . . Y Y .
 R R R . . . O . . . Y Y
R . R R . . . O . Y Y Y Y
         O O O .
          O O O
           O .
            O
The input is a non-negative integer and a Chinese checkerboard. Your program (or function) should rotate it by the integer * 60 degrees. You decide whether to rotate clockwise or counterclockwise, as long as it is consistent. Both the input and output shouldn't have extra leading or trailing spaces.

This is code-golf. Shortest code wins.

"""


def trim(lines):
    result = []
    for line in lines:
        if line.rstrip() != "":
            result.append(line)
    return result

"""

Ported from @Sp3000 solution

Explanation
For each char in the input, we either:

Keep it if it's a space or newline, or
Replace it with the correct char otherwise
To figure out which char to replace with, we convert the grid to cube coordinates (x, y, z),
rotate n times by transforming (x, y, z) -> (-y, -z, -x), then convert back.

https://www.redblobgames.com/grids/hexagons/#coordinates

"""

def rotate(source, turns):
    output = ""
    lines = source.splitlines(keepends=True)
    lines = trim(lines)
    for row, line in enumerate(lines):
        for column, char in enumerate(line):
            z = row - 8
            y = 6 - (z + column) // 2
            x = -y - z

            for _ in range(turns):
                x, y, z = -y, -z, -x

            if char.isspace():
                output += char
            else:
                output += lines[z + 8][12 - y + x]
    return output

BOARD1 = """
            B
           B B
          B B B
         B . B B
P P P . . . B . . G G . G
 P P P P . . . . . G G G
  P P . . . . . G Y . G
   P . . . . . . . G G
    . . . . . . . . .
   R . . . . . . . . Y
  R . R R . . . . Y Y .
 R R R . . . O . . . Y Y
R . R R . . . O . Y Y Y Y
         O O O .
          O O O
           O .
            O
"""

def main():
    print(rotate(BOARD1, 6))

main()
