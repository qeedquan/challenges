#!/usr/bin/env pthon3

"""

Task description:

Draw a cube in ASCII art in roughly a cabinet projection.

Monospaced fonts often have characters that are about twice as high as they are wide. Since the input is the length of the vertical lines (excluding the corners), horizontal lines are drawn with twice as many characters so that the resulting image is really roughly a cube. The receding lines are drawn at half the length as mandated by a cabinet projection.

Corners of the cube are represented by +, horizontal lines by -, vertical lines by | and diagonal ones use /.

Summarizing: Let the input be n, then

A horizontal edge of the cube are drawn with - and consists of 2 n characters.
A vertical edge of the cube are drawn with | and consists of n characters.
A diagonal edge of the cube are drawn with / and consists of n/2 characters.
Corners of the cube are drawn with +. Corners are not counted for the length of an edge as detailed above (see examples below as well).
Input:

The input, given on standard input, is a single positive, even number n (2 ≤ n ≤ 30) that gives the length of the vertical lines of the cube. It is followed by a single line break.

Output:

The output is a cube on standard output following above rules. Trailing whitespace on the lines is ignored.

Sample input 1:

2
Sample output 1:

  +----+
 /    /|
+----+ |
|    | +
|    |/
+----+
Sample input 2:

4
Sample output 2:

   +--------+
  /        /|
 /        / |
+--------+  |
|        |  |
|        |  +
|        | /
|        |/
+--------+
ETA: I now accepted the shortest solution. I will update the accepted answer when a shorter one comes along.

Since some people asked how long the entries of our contestants were:

227 – Python
240 – Perl
310 – C
315 – C
326 – VB.NET
459 – C

As well as our own solutions (not ranked with the others):

140 – Golfscript
172 – Ruby
183 – PowerShell

"""

# Ported from @JPvdMerwe solution
def cube(size):
    print(f"n={size}")
    if size < 2:
        return

    times = v = h = size//2
    space, plus, bar, slash, newline = " +|/\n"
    horizontal = plus + "-"*(times * 4) + plus
    middle = space * 4 * times
    edge = bar + middle + bar

    result = space*times + space + horizontal + newline
    while times:
        result += (
            space * times
            + slash
            + middle
            + slash
            + space * (h - times)
            + bar
            + newline
        )
        times -= 1

    result += horizontal + space * h + bar + newline
    result += (edge + space * h + bar + newline) * (v - 1)
    result += edge + space * h + plus + newline

    while v:
        v -= 1
        result += edge + space*v + slash + newline

    print(result + horizontal)

def main():
    for i in range(1, 11):
        cube(i)

main()