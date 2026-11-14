#!/usr/bin/env python3

"""

The beautiful pattern drawer
Good morning PPCG !

The other day, when I was trying to help someone on Stack Overflow, a part of his problem gave me an idea for this challenge.

First of all, check the following shape :

https://i.sstatic.net/dhlBh.png

Where all black numbers are the index of the points in the shape and all dark-blue numbers are the index of the links between the points.

Now, given an hexadecimal number for 0x00000 to 0xFFFFF, you need to draw a shape in the console using only character space and "■" (using the character "o" is okay too).

Here are some examples where hexadecimal number is input and shape is output :

0xE0C25 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■               ■
■               ■
■               ■
■ ■ ■ ■ ■       ■
        ■       ■
        ■       ■
        ■       ■
        ■ ■ ■ ■ ■
0xC1043 :
■ ■ ■ ■ ■ ■ ■ ■ ■
              ■
            ■
          ■
        ■
      ■
    ■
  ■
■ ■ ■ ■ ■ ■ ■ ■ ■
0xE4F27 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■       ■       ■
■       ■       ■
■       ■       ■
■ ■ ■ ■ ■ ■ ■ ■ ■
■       ■       ■
■       ■       ■
■       ■       ■
■ ■ ■ ■ ■ ■ ■ ■ ■
0xF1957 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■           ■ ■
■   ■       ■   ■
■     ■   ■     ■
■       ■       ■
■     ■   ■     ■
■   ■       ■   ■
■ ■           ■ ■
■ ■ ■ ■ ■ ■ ■ ■ ■
0xD0C67 :
■ ■ ■ ■ ■ ■ ■ ■ ■
  ■             ■
    ■           ■
      ■         ■
■ ■ ■ ■ ■       ■
      ■ ■       ■
    ■   ■       ■
  ■     ■       ■
■ ■ ■ ■ ■ ■ ■ ■ ■
0x95E30 :
■ ■ ■ ■ ■       ■
  ■     ■     ■ ■
    ■   ■   ■   ■
      ■ ■ ■     ■
■ ■ ■ ■ ■ ■ ■ ■ ■
        ■ ■
        ■   ■
        ■     ■
        ■       ■
0x95622 :
■ ■ ■ ■ ■       ■
  ■     ■     ■
    ■   ■   ■
      ■ ■ ■
■ ■ ■ ■ ■ ■ ■ ■ ■
        ■
        ■
        ■
■ ■ ■ ■ ■
0xC5463 :
■ ■ ■ ■ ■ ■ ■ ■ ■
        ■     ■
        ■   ■
        ■ ■
■ ■ ■ ■ ■
      ■ ■
    ■   ■
  ■     ■
■ ■ ■ ■ ■ ■ ■ ■ ■
0xE5975 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■       ■     ■ ■
■       ■   ■   ■
■       ■ ■     ■
■       ■       ■
■     ■ ■ ■     ■
■   ■   ■   ■   ■
■ ■     ■     ■ ■
■       ■ ■ ■ ■ ■
0xB5E75 :
■ ■ ■ ■ ■       ■
■ ■     ■     ■ ■
■   ■   ■   ■   ■
■     ■ ■ ■     ■
■ ■ ■ ■ ■ ■ ■ ■ ■
      ■ ■ ■     ■
    ■   ■   ■   ■
  ■     ■     ■ ■
■       ■ ■ ■ ■ ■
0xF4C75 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■     ■       ■
■   ■   ■       ■
■     ■ ■       ■
■ ■ ■ ■ ■       ■
      ■ ■ ■     ■
    ■   ■   ■   ■
  ■     ■     ■ ■
■       ■ ■ ■ ■ ■
0xF5D75 :
■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■     ■     ■ ■
■   ■   ■   ■   ■
■     ■ ■ ■     ■
■ ■ ■ ■ ■       ■
■     ■ ■ ■     ■
■   ■   ■   ■   ■
■ ■     ■     ■ ■
■       ■ ■ ■ ■ ■
Here are some explanation about how it works :

0xFFFFF(16) = 1111 1111 1111 1111 1111(2)
You here have 20 bits, each bit says whether a link exists or not.

Index of the Most Significant Bit (MSB) is 0 (picture reference) or the Less Significant Bit (LSB) is 19 (picture reference again).

Here's how it works for the first shape given as example :

0xE0C25(16) = 1110 0000 1100 0010 0101(2)
Meaning you'll have the following existing links : 0,1,2,8,9,14,17,19.

If you highlight the lines on the reference picture with those numbers, it will give you this shape :

■ ■ ■ ■ ■ ■ ■ ■ ■
■               ■
■               ■
■               ■
■ ■ ■ ■ ■       ■
        ■       ■
        ■       ■
        ■       ■
        ■ ■ ■ ■ ■
Here is a simple and ungolfed Python implementation if you need more help :

patterns = [
  0xE0C25, 0xC1043, 0xE4F27, 0xF1957,
  0xD0C67, 0x95E30, 0x95622, 0xC5463,
  0xE5975, 0xB5E75, 0xF4C75, 0xF5D75
]

def printIfTrue(condition, text = "■ "):
  if condition:
    print(text, end="")
  else:
    print(" "*len(text), end="")

def orOnList(cube, indexes):
  return (sum([cube[i] for i in indexes]) > 0)

def printPattern(pattern):
  cube = [True if n == "1" else False for n in str(bin(pattern))[2::]]
  for y in range(9):
    if y == 0: printIfTrue(orOnList(cube, [0, 2, 3]))
    if y == 4: printIfTrue(orOnList(cube, [2, 4, 9, 11, 12]))
    if y == 8: printIfTrue(orOnList(cube, [11, 13, 18]))
    if y in [0, 4, 8]:
      printIfTrue(cube[int((y / 4) + (y * 2))], "■ ■ ■ ")
      if y == 0: printIfTrue(orOnList(cube, [0, 1, 4, 5, 6]))
      if y == 4: printIfTrue(orOnList(cube, [3, 5, 7, 9, 10, 13, 14, 15]))
      if y == 8: printIfTrue(orOnList(cube, [12, 14, 16, 18, 19]))
      printIfTrue(cube[int((y / 4) + (y * 2)) + 1], "■ ■ ■ ")
    elif y in [1, 5]:
      for i in range(7):
        if i in [2, 5]:
          print(" ", end=" ")
        printIfTrue(cube[y * 2 + (1 - (y % 5)) + i])
    elif y in [2, 6]:
      for i in range(5):
        if i in [1, 2, 3, 4]:
          print(" ", end=" ")
        if i in [1, 3]:
          if i == 1 and y == 2:
            printIfTrue(orOnList(cube, [3, 4]))
          elif i == 3 and y == 2:
            printIfTrue(orOnList(cube, [6, 7]))
          if i == 1 and y == 6:
            printIfTrue(orOnList(cube, [12, 13]))
          elif i == 3 and y == 6:
            printIfTrue(orOnList(cube, [15, 16]))
        else:
          printIfTrue(cube[(y * 2 - (1 if y == 6 else 2)) + i + int(i / 4 * 2)])
    elif y in [3, 7]:
      for i in range(7):
        if i in [2, 5]:
          print("  ", end="")
        ri, swap = (y * 2 - 2) + (1 - (y % 5)) + i, [[3, 6, 12, 15], [4, 7, 13, 16]]
        if ri in swap[0]: ri = swap[1][swap[0].index(ri)]
        elif ri in swap[1]: ri = swap[0][swap[1].index(ri)]
        printIfTrue(cube[ri])
    if y == 0: printIfTrue(orOnList(cube, [1, 7, 8]))
    if y == 4: printIfTrue(orOnList(cube, [6, 8, 10, 16, 17]))
    if y == 8: printIfTrue(orOnList(cube, [15, 17, 19]))
    print()

for pattern in patterns:
  printPattern(pattern)
Of course it's not perfect and it's pretty long for what it should do, and that's the exact reason why you're here !

Making this program ridiculously short :)

This is code-golf, so shortest answer wins !

"""

def printIfTrue(condition, text="■ "):
    if condition:
        print(text, end="")
    else:
        print(" " * len(text), end="")


def orOnList(cube, indexes):
    return sum([cube[i] for i in indexes]) > 0


def printPattern(pattern):
    cube = [True if n == "1" else False for n in str(bin(pattern))[2::]]
    for y in range(9):
        if y == 0:
            printIfTrue(orOnList(cube, [0, 2, 3]))
        if y == 4:
            printIfTrue(orOnList(cube, [2, 4, 9, 11, 12]))
        if y == 8:
            printIfTrue(orOnList(cube, [11, 13, 18]))
        if y in [0, 4, 8]:
            printIfTrue(cube[int((y / 4) + (y * 2))], "■ ■ ■ ")
            if y == 0:
                printIfTrue(orOnList(cube, [0, 1, 4, 5, 6]))
            if y == 4:
                printIfTrue(orOnList(cube, [3, 5, 7, 9, 10, 13, 14, 15]))
            if y == 8:
                printIfTrue(orOnList(cube, [12, 14, 16, 18, 19]))
            printIfTrue(cube[int((y / 4) + (y * 2)) + 1], "■ ■ ■ ")
        elif y in [1, 5]:
            for i in range(7):
                if i in [2, 5]:
                    print(" ", end=" ")
                printIfTrue(cube[y * 2 + (1 - (y % 5)) + i])
        elif y in [2, 6]:
            for i in range(5):
                if i in [1, 2, 3, 4]:
                    print(" ", end=" ")
                if i in [1, 3]:
                    if i == 1 and y == 2:
                        printIfTrue(orOnList(cube, [3, 4]))
                    elif i == 3 and y == 2:
                        printIfTrue(orOnList(cube, [6, 7]))
                    if i == 1 and y == 6:
                        printIfTrue(orOnList(cube, [12, 13]))
                    elif i == 3 and y == 6:
                        printIfTrue(orOnList(cube, [15, 16]))
                else:
                    printIfTrue(
                        cube[(y * 2 - (1 if y == 6 else 2)) + i + int(i / 4 * 2)]
                    )
        elif y in [3, 7]:
            for i in range(7):
                if i in [2, 5]:
                    print("  ", end="")
                ri, swap = (y * 2 - 2) + (1 - (y % 5)) + i, [
                    [3, 6, 12, 15],
                    [4, 7, 13, 16],
                ]
                if ri in swap[0]:
                    ri = swap[1][swap[0].index(ri)]
                elif ri in swap[1]:
                    ri = swap[0][swap[1].index(ri)]
                printIfTrue(cube[ri])
        if y == 0:
            printIfTrue(orOnList(cube, [1, 7, 8]))
        if y == 4:
            printIfTrue(orOnList(cube, [6, 8, 10, 16, 17]))
        if y == 8:
            printIfTrue(orOnList(cube, [15, 17, 19]))
        print()

def main():
    patterns = [
        0xE0C25,
        0xC1043,
        0xE4F27,
        0xF1957,
        0xD0C67,
        0x95E30,
        0x95622,
        0xC5463,
        0xE5975,
        0xB5E75,
        0xF4C75,
        0xF5D75,
    ]
    for pattern in patterns:
        printPattern(pattern)

main()
