#!/usr/bin/env python3

"""

This is a 3x3 ASCII jigsaw puzzle:

 _____ _____ _____
|    _|     |_    |
|   (_   _   _)   |
|_   _|_( )_|_   _|
| (_) |_   _| (_) |
|  _   _) (_   _  |
|_( )_|_   _|_( )_|
|    _| (_) |_    |
|   (_       _)   |
|_____|_____|_____|
This is also a 3x3 ASCII jigsaw puzzle:

 _____ _____ _____
|     |_   _|     |
|  _   _) (_   _  |
|_( )_|_   _|_( )_|
|    _| (_) |_    |
|   (_   _   _)   |
|_   _|_( )_|_   _|
| (_) |_   _| (_) |
|      _) (_      |
|_____|_____|_____|
Each line in a ASCII jigsaw puzzle (excluding the edge cases i.e. the pieces literally on the edges) consists of the following pattern:

   _           _           _
 _( )_ _   _ _( )_ _   _ _( )_
|_   _| (_) |_   _| (_) |_   _|
 _) (_   _   _) (_   _   _) (_
|_   _|_( )_|_   _|_( )_|_   _| ...
  (_)         (_)         (_)
Given 2 integers H and W where H is the height (vertical amount) and W is the width (horizontal amount) and H and W are >1 output a possible HxW ASCII jigsaw puzzle.

Examples
Test Case 1
Input: 2, 4

Output:

 _____ _____ _____ _____
|     |_   _|     |_    |
|  _   _) (_   _   _)   |
|_( )_|_   _|_( )_|_   _|
|    _| (_) |_   _| (_) |
|   (_       _) (_      |
|_____|_____|_____|_____|
Test Case 2
Input: 4, 4

Output:

 _____ _____ _____ _____
|     |_   _|     |_    |
|  _   _) (_   _   _)   |
|_( )_|_   _|_( )_|_   _|
|    _| (_) |_   _| (_) |
|   (_   _   _) (_   _  |
|_   _|_( )_|_   _|_( )_|
| (_) |_   _| (_) |_    |
|  _   _) (_   _   _)   |
|_( )_|_   _|_( )_|_   _|
|    _| (_) |_   _| (_) |
|   (_       _) (_      |
|_____|_____|_____|_____|
Test Case 3
Input: 3, 5

Output:

 _____ _____ _____ _____ _____
|     |_   _|     |_   _|     |
|  _   _) (_   _   _) (_   _  |
|_( )_|_   _|_( )_|_   _|_( )_|
|    _| (_) |_   _| (_) |_    |
|   (_   _   _) (_   _   _)   |
|_   _|_( )_|_   _|_( )_|_   _|
| (_) |_   _| (_) |_   _| (_) |
|      _) (_       _) (_      |
|_____|_____|_____|_____|_____|
Test Case 4
Input: 2, 2

Output:

 _____ _____
|    _|     |
|   (_   _  |
|_   _|_( )_|
| (_) |_    |
|      _)   |
|_____|_____|

Clarifications
The height and width for each puzzle piece should not be scaled up or down.
With H and W being greater than one, the smallest dimensions possible are 2x2 (see IO 4).
You can have a full program or a function.
The input will be 2 lines with H on the 1st and W on the 2nd if you're using a function you can have them in the parameters.
Output to stdout (or something similar).
This is code-golf so shortest answer in bytes wins.

"""

"""

Ported from @walpen solution

The patterns themselves look like

we can see this as a lookup table from integers with columns taken mod 6 and rows mod 3

 012345
0     |
1
2_   _|

 0123
0_
1_
2
3  _
4  _
5

 0123456789AB
0       ( )
1 ) (
2       ( )
3 ( )
4       ) (
5 ( )

This strategy of combining different patterns has not really worked out for me here because expressing them is quite cumbersome (though I think I could have golfed more) and because the edge cases take up so many characters to fix. I'm putting this up regardless because it took me a minute and it might be of interest.

"""

def base(row, col):
    if col % 6 in [5] and row % 3 in [0, 2]:
        return 1
    if col % 6 in [0, 4] and row % 3 in [2]:
        return 2
    return 0

def underscores(row, col):
    if col % 4 in [0] and row % 6 in [0, 1] or col % 4 in [2] and row % 6 in [3, 4]:
        return 2
    return 0

def parentheses(row, col):
    if (row % 6, col % 12) in [(0, 9), (1, 1), (2, 9), (3, 3), (4, 7), (5, 3)]:
        return 4
    if (row % 6, col % 12) in [(0, 7), (1, 3), (2, 7), (3, 1), (4, 9), (5, 1)]:
        return 3
    return 0

def value(row, col):
    return base(row, col) + underscores(row, col) + parentheses(row, col)

def new_value(last_row, last_col, row, column):
    if row in [0, last_row]:
        return 2*(column % 6 > 0) or row > 0
    if column in [0, last_col]:
        return 1
    if column in [1, 2] and row % 6 in [1, 2]:
        return 0
    if column in [last_col - 1, last_col - 2] and row % 6 in [[4, 5], [1, 2]][last_col%12 > 0]:
        return 0
    if row in [1, 2] and column % 12 in [8,9,10]:
        return 0
    if row == last_row - 1 and column % 12 == 9:
        return 0
    return value(row - 1, column - 1)

def puzzle(rows, cols):
    codes = " |_()"
    last_row = rows * 3
    last_col = cols * 6
    print("rows=%d cols=%d" % (rows, cols))
    for row in range(last_row + 1):
        for col in range(last_col + 1):
            index = new_value(last_row, last_col, row, col)
            print(codes[index], end='')
        print()
    print()

def main():
    for x in range(1, 10):
        for y in range(1, 10):
            puzzle(x, y)

main()
