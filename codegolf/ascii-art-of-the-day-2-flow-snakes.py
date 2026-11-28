#!/usr/bin/env python3

r"""

A Flow Snake, also known as a Gosper curve, is a fractal curve, growing exponentially in size with each order/iteration of a simple process. Below are the details about the construction and a few examples for various orders:

Order 1 Flow Snake:

____
\__ \
__/
Order 2 Flow Snake:

      ____
 ____ \__ \
 \__ \__/ / __
 __/ ____ \ \ \
/ __ \__ \ \/
\ \ \__/ / __
 \/ ____ \/ /
    \__ \__/
    __/
Order 3 Flow Snake:

                 ____
            ____ \__ \
            \__ \__/ / __
            __/ ____ \ \ \    ____
           / __ \__ \ \/ / __ \__ \
      ____ \ \ \__/ / __ \/ / __/ / __
 ____ \__ \ \/ ____ \/ / __/ / __ \ \ \
 \__ \__/ / __ \__ \__/ / __ \ \ \ \/
 __/ ____ \ \ \__/ ____ \ \ \ \/ / __
/ __ \__ \ \/ ____ \__ \ \/ / __ \/ /
\ \ \__/ / __ \__ \__/ / __ \ \ \__/
 \/ ____ \/ / __/ ____ \ \ \ \/ ____
    \__ \__/ / __ \__ \ \/ / __ \__ \
    __/ ____ \ \ \__/ / __ \/ / __/ / __
   / __ \__ \ \/ ____ \/ / __/ / __ \/ /
   \/ / __/ / __ \__ \__/ / __ \/ / __/
   __/ / __ \ \ \__/ ____ \ \ \__/ / __
  / __ \ \ \ \/ ____ \__ \ \/ ____ \/ /
  \ \ \ \/ / __ \__ \__/ / __ \__ \__/
   \/ / __ \/ / __/ ____ \ \ \__/
      \ \ \__/ / __ \__ \ \/
       \/      \ \ \__/ / __
                \/ ____ \/ /
                   \__ \__/
                   __/
Construction
Consider the order 1 Flow Snake to be built of a path containing 7 edges and 8 vertices (labelled below. Enlarged for feasibility):

4____5____6
 \         \
 3\____2   7\
       /
0____1/
Now for each next order, you simply replace the edges with a rotated version of this original order 1 pattern. Use the following 3 rules for replacing the edges:

1 For a horizontal edge, replace it with the original shape as is:

________
\       \
 \____   \
     /
____/
2 For a / edge (12 in the above construction), replace it with the following rotated version:

 /
/   ____
\  /   /
 \/   /
     /
____/
3 For a \ edge (34and 67 above), replace it with the following rotated version:

 /
/   ____ 
\   \   \
 \   \   \
  \  /
   \/
So for example, order 2 with vertices from order 1 labelled will look like

            ________
            \       \
  ________   \____   \6
  \       \      /   /
   \____   \5___/   /   ____
       /            \   \   \
  4___/   ________   \   \   \7
 /        \       \   \  /
/   ____   \____   \2  \/
\   \   \      /   /
 \   \   \3___/   /   ____
  \  /            \  /   /
   \/   ________   \/   /
        \       \      /
         \____   \1___/
             /
        0___/
Now for any higher order, you simply break up the current level into edges of lengths 1 /, 1 \ or 2 _ and repeat the process. Do note that even after replacing, the common vertices between any two consecutive edges are still coinciding.

Challenge
You have to write a function of a full program that receives a single integer N via STDIN/ARGV/function argument or the closest equivalent and prints the order N Flow Snake on STDOUT.
The input integer is always greater than 0.
There should not be any leading spaces which are not part of the pattern.
There should be either no trailing spaces or enough trailing spaces to pad the pattern to fill the minimum bounding rectangle completely.
Trailing newline is optional.
Fun Facts
Flow Snakes is a word play of Snow Flakes, which this pattern resembles for order 2 and above
The Flow and Snakes actually play a part in the pattern as the pattern is made up of a single path flowing throughout.
If you notice carefully, the order 2 (and higher as well) pattern comprises of rotations of order 1 pattern pivoted on the common vertex of the current and the previous edge.
There is a Non ASCII variant of Flow Snakes which can be found here and at several other locations.
This is code-golf so shortest code in bytes win!

"""

def draw(canvas, level, x, y, dir=0):
    if level == 0:
        syms = "_/\\ "
        offs = [-1, 2, 0, 1, 0, 1]

        if dir%2 == 0:
            x -= 1
        if dir%3 > 1:
            y += 1

        canvas[y][x] = syms[dir // 2]
        if dir < 2:
            canvas[y][x + 2*dir - 1] = "_"

        yo = 0
        if 2 < dir and dir < 5:
            yo = 1

        return offs[dir] + x, y - yo

    syms = "424050035512124224003"
    dirs = [(int(val)^dir % 2) for val in syms[dir//2::3]]
    step = (dir ^ 1) - dir
    for nextdir in dirs[::step]:
        x, y = draw(canvas, level - 1, x, y, nextdir)
    return x, y

"""

Ported from @KSab solution

This one was pretty tricky.
The patterns don't retain their ratios after each step meaning its very difficult to procedurally produce an image from its predecessor.
What this code does, though its pretty unreadable after some intense math golfing,
is actually draw the line from start to finish using the recursively defined D function.

The size was also an issue,
and I ended up just starting in the middle of a 5*3**n sided square and cropping things afterward,
though if I can think of better way to calculate the size I might change it.

"""

def flowsnake(n):
    size = 5 * 3**n
    canvas = [[" " for _ in range(size)] for _ in range(size)]
    draw(canvas, n, size//2, size//2)

    lines = []
    for row in canvas:
        line = "".join(row)
        line = line.rstrip()
        lines.append(line)

    left_margin = 0
    for line in lines:
        if line != "":
            index = line.find("\\") % size
            if left_margin == 0 or left_margin > index:
                left_margin = index

    for line in lines:
        if line:
            print(line[left_margin:])

def main():
    for i in range(1, 5):
        print("n=%d" % (i))
        flowsnake(i)

main()
