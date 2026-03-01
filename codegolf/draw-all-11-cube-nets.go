/*

There are 11 ways of flattening a cube onto a flat surface, like a piece of paper, which can then be folded back up into a cube. Each of these is called a cube net.

Your task is to write a program or function to output all 11 cube nets, as ASCII art, in any order, and in any orientation.

https://i.sstatic.net/1ZMRp.png

Each cube net consists of six partially overlapping 3x3 squares. They are drawn using the characters |, -, + and   (space). Spaces are used for left padding. One of the 11 cube nets looks like this:

+-+-+-+
| | | |
+-+-+-+
  | |
  +-+
  | |
  +-+
  | |
  +-+
Cube nets can be output side-by-side, or one above the other. They don't need space between them, but must not share any characters.

Each cube net can appear in any of its 4 rotations, and can be flipped.

Output is any reasonable format: string with newlines, arrays of strings, arrays of arrays of characters, printing directly to the terminal, etc. Extra whitespace is fine.

This is code golf. Standard rules apply.

(Side note: each cube net you output should pass this challenge!)

Sample output
+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
| |
+-+


+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
  | |
  +-+


+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
    | |
    +-+


  +-+-+
  | | |
  +-+-+
  | |
  +-+
  | |
+-+-+
| | |
+-+-+


  +-+
  | |
+-+-+-+-+
| | | | |
+-+-+-+-+
    | |
    +-+


  +-+
  | |
+-+-+-+-+
| | | | |
+-+-+-+-+
  | |
  +-+


+-+-+
| | |
+-+-+-+-+
  | | | |
  +-+-+-+
  | |
  +-+


+-+-+
| | |
+-+-+-+-+
  | | | |
  +-+-+-+
    | |
    +-+


+-+
| |
+-+-+-+
| | | |
+-+-+-+-+
    | | |
    +-+-+


+-+-+
| | |
+-+-+-+
  | | |
  +-+-+-+
    | | |
    +-+-+


  +-+
  | |
  +-+
  | |
+-+-+
| | |
+-+-+
| |
+-+
| |
+-+

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `

+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
| |
+-+


+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
  | |
  +-+


+-+
| |
+-+-+-+-+
| | | | |
+-+-+-+-+
    | |
    +-+


  +-+-+
  | | |
  +-+-+
  | |
  +-+
  | |
+-+-+
| | |
+-+-+


  +-+
  | |
+-+-+-+-+
| | | | |
+-+-+-+-+
    | |
    +-+


  +-+
  | |
+-+-+-+-+
| | | | |
+-+-+-+-+
  | |
  +-+


+-+-+
| | |
+-+-+-+-+
  | | | |
  +-+-+-+
  | |
  +-+


+-+-+
| | |
+-+-+-+-+
  | | | |
  +-+-+-+
    | |
    +-+


+-+
| |
+-+-+-+
| | | |
+-+-+-+-+
    | | |
    +-+-+


+-+-+
| | |
+-+-+-+
  | | |
  +-+-+-+
    | | |
    +-+-+


  +-+
  | |
  +-+
  | |
+-+-+
| | |
+-+-+
| |
+-+
| |
+-+
`
