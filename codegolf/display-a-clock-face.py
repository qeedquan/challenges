#!/usr/bin/env python3

"""

Display the 12 numbers on a clock face exactly like this:

           12
     11           1

 10                   2


9                       3


  8                   4

      7           5
            6
To better see the grid, here's one with dots:

...........12............
.....11...........1......
.........................
.10...................2..
.........................
.........................
9.......................3
.........................
.........................
..8...................4..
.........................
......7...........5......
............6............
Note that the grid is stretched in width by a factor of two to make it look more square.

Also note that two-digit numbers are aligned with their ones digit in place. The 9 digit should be flush against the left.

Return or print the result as a multiline string (not a list of lines). Any trailing spaces are optional. The final newline also optional.

"""

clock = """
...........12............
.....11...........1......
.........................
.10...................2..
.........................
.........................
9.......................3
.........................
.........................
..8...................4..
.........................
......7...........5......
............6............
"""

print(clock.replace(".", " "))