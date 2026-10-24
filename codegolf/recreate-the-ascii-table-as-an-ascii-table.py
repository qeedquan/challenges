#!/usr/bin/env python3

"""

Frequently while I'm code-golfing, I'll want to know what the ASCII value of a certain character is. One of my favorite resources for quickly looking up all of the printable ASCII characters is ASCIItable.com. This has a really nice image that not only shows the printable ASCII characters and their values, but also the unprintable and extended characters, and the values in hexadecimal, octal, and HTML:

https://i.stack.imgur.com/iCOov.gif

Today's challenge is to recreate that ASCII table as an ASCII table instead of an image. To keep things simpler, we will not use control-characters (characters below 32) and we'll only show the decimal value and the character. In other words, your challenge is to write either a full-program or a function that prints or returns the following text:

Dec  Chr   | Dec  Chr   | Dec  Chr
----------------------------------
32   Space | 64   @     | 96   `
33   !     | 65   A     | 97   a
34   "     | 66   B     | 98   b
35   #     | 67   C     | 99   c
36   $     | 68   D     | 100  d
37   %     | 69   E     | 101  e
38   &     | 70   F     | 102  f
39   '     | 71   G     | 103  g
40   (     | 72   H     | 104  h
41   )     | 73   I     | 105  i
42   *     | 74   J     | 106  j
43   +     | 75   K     | 107  k
44   ,     | 76   L     | 108  l
45   -     | 77   M     | 109  m
46   .     | 78   N     | 110  n
47   /     | 79   O     | 111  o
48   0     | 80   P     | 112  p
49   1     | 81   Q     | 113  q
50   2     | 82   R     | 114  r
51   3     | 83   S     | 115  s
52   4     | 84   T     | 116  t
53   5     | 85   U     | 117  u
54   6     | 86   V     | 118  v
55   7     | 87   W     | 119  w
56   8     | 88   X     | 120  x
57   9     | 89   Y     | 121  y
58   :     | 90   Z     | 122  z
59   ;     | 91   [     | 123  {
60   <     | 92   \     | 124  |
61   =     | 93   ]     | 125  }
62   >     | 94   ^     | 126  ~
63   ?     | 95   _     | 127  DEL

Trailing spaces on each line, and a trailing newline are permitted. Since this is a kolmogorov-complexity challenge, your submission may not take any input, or access any external resources (such as a file or the web), and your goal is to compress the code to output this text as much as possible.

Standard loopholes apply, and the shortest answer in bytes wins. Happy golfing!

"""

def asciichar(c):
    s = chr(c)
    if c == 32:
        s = "Space"
    elif c == 127:
        s = "Del"
    return c, s

def asciitable():
    for i in range(3):
        print("%-4s %-6s" % ("Dec", "Chr"), end='')
        if i < 2:
            print("| ", end='')
    print()
    print("----------------------------------")
    for i in range(32):
        c0, s0 = asciichar(i + 32)
        c1, s1 = asciichar(i + 64)
        c2, s2 = asciichar(i + 96)
        print("%-4s %-6s | %-4s %-6s | %-4s %-6s" % (c0, s0, c1, s1, c2, s2))

def main():
    asciitable()

main()
