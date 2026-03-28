#!/usr/bin/env python3

"""

Your job is to take a string input and a number and align the string to the right, making the width of the text the number. When a line is too long, break it and put the rest on the next line, repeating until it's not necessary. If a line is shorter than the width, then pad it with spaces. Multiple newlines can occur, and should be treated like any other single character.

For example, the string

Programming
Puzzles
&
Code
Golf
and the number 5 would produce:

Progr
ammin
    g
Puzzl
   es
    &
 Code
 Golf
Whereas the same string and the number 10 would produce:

Programmin
         g
   Puzzles
         &
      Code
      Golf
The string

a

b
and the number 5 would produce:

    a
      <-- note the 5 spaces
    b
Shortest code wins!

"""

# ported from @xnor solution
def right_align(lines, align):
    for line in lines:
        string = line
        if line == "":
            string = " "

        while string != "":
            text = string[:align]
            text = text.rjust(align)
            print(text)
            string = string[align:]
    print()

def main():
    right_align(["Programming", "Puzzles", "&", "Code", "Golf"], 5)
    right_align(["Programming", "Puzzles", "&", "Code", "Golf"], 10)
    right_align(["a", "", "b"], 5)

main()
