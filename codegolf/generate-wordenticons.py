#!/usr/bin/env python3

"""

Identicons are visual depictions of hash values, often made from symmetrical arrangements of geometric shapes. Your default Stack Exchange avatar is an identicon. This challenge is about creating "wordenticons", simple text-based versions of identicons that apply to strings of lowercase letters, i.e. words.

Challenge
Write a program or function that takes in a string S and outputs its wordenticon. S is guaranteed to be nonempty and only contain lowercase English letter characters a-z. You may optionally assume S has a trailing newline.

The wordenticon of S will be a square grid of text with side lengths 2*length(S) composed of spaces ( ), vertical bars, (|), and horizontal bars (―).

To generate the wordenticon of S, form a square grid where every column corresponds to a letter of S (in normal left-to-right reading order) and every row corresponds to a letter of S (in normal top-to-bottom reading order).

For example, if S is food our initial grid looks like

 food
f....
o....
o....
d....
where . is just a placeholder.

For every empty point (every .) in the grid:

If the column letter comes before the row letter alphabetically, replace the . with |.
If the column letter comes after the row letter alphabetically, replace the . with ―.
If the column and row letters are the same, replace the . with   (space).
Here is the food example after each of these steps:

Adding |'s:

 food
f...|
o|..|
o|..|
d....
Adding ―'s:

 food
f.――|
o|..|
o|..|
d―――.
Adding  's:

 food
f ――|
o|  |
o|  |
d―――
To complete the wordenticon, remove the superfluous row and column containing the words

 ――|
|  |
|  |
―――
then mirror the entire thing horizontally

 ――||――
|  ||  |
|  ||  |
―――  ―――
and finally mirror it again vertically

 ――||――
|  ||  |
|  ||  |
―――  ―――
―――  ―――
|  ||  |
|  ||  |
 ――||――
resulting in the 2*length(S) side length text grid that is the final wordenticon.

Examples
Here are some additional wordenticon examples. Note that different words can have identical wordenticons and some wordenticons can be completely made of spaces (unfortunately markdown does not want to render those).

food

 ――||――
|  ||  |
|  ||  |
―――  ―――
―――  ―――
|  ||  |
|  ||  |
 ――||――

mood

 ――||――
|  ||  |
|  ||  |
―――  ―――
―――  ―――
|  ||  |
|  ||  |
 ――||――

foof

 ――  ――
|  ||  |
|  ||  |
 ――  ――
 ――  ――
|  ||  |
|  ||  |
 ――  ――

fool

 ――――――
|  ||  |
|  ||  |
|――  ――|
|――  ――|
|  ||  |
|  ||  |
 ――――――

a [2*2 grid of spaces]




to

 ||
―  ―
―  ―
 ||

it

 ――
|  |
|  |
 ――

tt [4*4 grid of spaces]






abc

 ――――
| ―― |
||  ||
||  ||
| ―― |
 ――――

and

 ――――
| || |
|―  ―|
|―  ―|
| || |
 ――――

but

 ――――
| || |
|―  ―|
|―  ―|
| || |
 ――――

you

 ||||
― ―― ―
―|  |―
―|  |―
― ―― ―
 ||||

bob

 ―  ―
| || |
 ―  ―
 ―  ―
| || |
 ―  ―

cat

 |――|
― ―― ―
||  ||
||  ||
― ―― ―
 |――|

cart

 |――――|
― ―――― ―
|| ―― ||
|||  |||
|||  |||
|| ―― ||
― ―――― ―
 |――――|

todo

 ||||||
― |  | ―
―― ―― ――
― |  | ―
― |  | ―
―― ―― ――
― |  | ―
 ||||||

mice

 ||||||
― |||| ―
―― ―― ――
――|  |――
――|  |――
―― ―― ――
― |||| ―
 ||||||

zyxw

 ||||||
― |||| ―
―― || ――
―――  ―――
―――  ―――
―― || ――
― |||| ―
 ||||||

banana

 |―|―||―|―|
― ― ―  ― ― ―
|| | || | ||
― ― ―  ― ― ―
|| | || | ||
― ― ―  ― ― ―
― ― ―  ― ― ―
|| | || | ||
― ― ―  ― ― ―
|| | || | ||
― ― ―  ― ― ―
 |―|―||―|―|

codegolf

 ――――――――――――――
| ||| |||| ||| |
|― ―――――――――― ―|
|―| ―――――――― |―|
|―|| ――||―― ||―|
| ||| |||| ||| |
|―|||― || ―|||―|
|―||―――  ―――||―|
|―||―――  ―――||―|
|―|||― || ―|||―|
| ||| |||| ||| |
|―|| ――||―― ||―|
|―| ―――――――― |―|
|― ―――――――――― ―|
| ||| |||| ||| |
 ――――――――――――――

programming

 ―||―||||||||||||―||―
| || |||||||||||| || |
―― |―||||||||||||―| ――
――― ―|――――  ――――|― ―――
| || |||||||||||| || |
――――― ―――――――――― ―――――
―――|―|  |―||―|  |―|―――
―――|―|  |―||―|  |―|―――
―――|―|―― ―||― ――|―|―――
―――|―|||| || ||||―|―――
――― ―|――――  ――――|― ―――
――― ―|――――  ――――|― ―――
―――|―|||| || ||||―|―――
―――|―|―― ―||― ――|―|―――
―――|―|  |―||―|  |―|―――
―――|―|  |―||―|  |―|―――
――――― ―――――――――― ―――――
| || |||||||||||| || |
――― ―|――――  ――――|― ―――
―― |―||||||||||||―| ――
| || |||||||||||| || |
 ―||―||||||||||||―||―

abcdefghijklm

 ――――――――――――――――――――――――
| ―――――――――――――――――――――― |
|| ―――――――――――――――――――― ||
||| ―――――――――――――――――― |||
|||| ―――――――――――――――― ||||
||||| ―――――――――――――― |||||
|||||| ―――――――――――― ||||||
||||||| ―――――――――― |||||||
|||||||| ―――――――― ||||||||
||||||||| ―――――― |||||||||
|||||||||| ―――― ||||||||||
||||||||||| ―― |||||||||||
||||||||||||  ||||||||||||
||||||||||||  ||||||||||||
||||||||||| ―― |||||||||||
|||||||||| ―――― ||||||||||
||||||||| ―――――― |||||||||
|||||||| ―――――――― ||||||||
||||||| ―――――――――― |||||||
|||||| ―――――――――――― ||||||
||||| ―――――――――――――― |||||
|||| ―――――――――――――――― ||||
||| ―――――――――――――――――― |||
|| ―――――――――――――――――――― ||
| ―――――――――――――――――――――― |
 ――――――――――――――――――――――――
Scoring
This is code-golf, the shortest code in bytes wins. Tiebreaker goes to the earlier answer.

Notes
Any instance of horizontal bar (―) in your code may be counted as 1 byte instead of the 3 UTF-8 bytes it actually takes up. (Up to ten instances.)
If desired you may use regular dashes (-) in place of horizontal bars (―).
Removing or adding trailing spaces in the lines of a wordenticon is not allowed (even if the shape remains unchanged). It should be an exact 2*length(S) side length text square.
The output wordenticon may optionally have a single trailing newline.

"""

def wordenticons(s):
    print(s)
    s += s[::-1]
    for c0 in s:
        for c1 in s:
            if c0 == c1:
                print(" ", end="")
            elif c0 > c1:
                print("|", end="")
            else:
                print("―", end="")
        print()
    print()

def main():
    wordenticons("food")
    wordenticons("bob")
    wordenticons("cat")
    wordenticons("cart")
    wordenticons("todo")
    wordenticons("mice")
    wordenticons("zyxw")
    wordenticons("banana")
    wordenticons("codegolf")
    wordenticons("programming")
    wordenticons("abcdefghijklm")
    wordenticons("wavelet")

main()
