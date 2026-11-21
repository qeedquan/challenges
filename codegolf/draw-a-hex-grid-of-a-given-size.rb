#!/usr/bin/env ruby

=begin

Your task is to draw a requested number of cells in a flat-topped/pointy-sided hex pattern. Each cell is 5 characters high and 8 characters wide (4 characters wide at the top and bottom).

This is a valid layout for 6 cells:

          ____
         /    \
    ____/      \____
   /    \      /    \
  /      \____/      \
  \      /    \      /
   \____/      \____/
   /    \      /
  /      \____/ 
  \      /    \ 
   \____/      \
        \      /
         \____/
You can choose the exact layout, as long as you follow these rules:

All cells must be touching, and laid out within a regular hex grid pattern.
If there are >= 3 cells, every cell must have at least one vertex that is part of 3 cells.
The difference in length between the longest rows in each dimension (northeast and southeast) must be <= 2. (The above diagram has longest rows of 3 and 2).
That is, you can't simply make a long line of cells, they must expand out in 2 dimensions at roughly even pace. (If it turns out the formulated rules are insufficient to enforce this goal, they will be extended, no loopholes allowed).

Input
The number of cells to draw, an integer N >= 1. (You can take that integer as 0-based if you like.)

Output
The text output in the format above, made only of /\_ and space characters. Extra whitespace is fine.

(Formats such as a string of newline-separated text, arrays of arrays of characters etc, are fine).

Scoring
Code golf.

Sample data
N=1

  ____
 /    \
/      \
\      /
 \____/
N=2

  ____
 /    \
/      \
\      /
 \____/
 /    \
/      \
\      /
 \____/
N=3

  ____
 /    \
/      \____
\      /    \
 \____/      \
 /    \      /
/      \____/
\      /
 \____/

N=4 INVALID

  ____        ____
 /    \      /    \
/      \____/      \
\      /    \      /
 \____/      \____/
 /    \      /
/      \____/
\      /
 \____/
(Longest dimensions are 3 and 2, but there is a cell with no vertex touching 3 cells)

N=4 OK

  ____ 
 /    \
/      \____
\      /    \
 \____/      \
 /    \      /
/      \____/
\      /    \
 \____/      \
      \      /
       \____/
(Longest dimensions are 2 and 2)

N=5 INVALID

                    ____
                   /    \
  ____        ____/      \
 /    \      /    \      /
/      \____/      \____/
\      /    \      /
 \____/      \____/
 /    \      /
/      \____/
\      /
 \____/
(Longest dimensions are 4 and 2, but there are two cells with no vertex touching 3 cells)

N=5 OK

    ____        ____
   /    \      /    \
  /      \____/      \
  \      /    \      /
   \____/      \____/
   /    \      /    \
  /      \____/      \
  \      /    \      /
   \____/      \____/
(Longest dimensions are 3 and 3)

N=8

          ____
         /    \
    ____/      \____
   /    \      /    \
  /      \____/      \____
  \      /    \      /    \
   \____/      \____/      \
   /    \      /    \      /
  /      \____/      \____/
  \      /    \      /
   \____/      \____/
        \      /
         \____/

=end

# Ported from @Level River St solution
def hexagon(n)
  cell_height = Math.sqrt(n).round
  width = 9 * cell_height
  canvas = ("%#{width}s" % $/) * width
  drawing = '____ \____/ \      //      \ /    \ '
  n.times do |i|
    5.times do |j|
      row = i % cell_height
      column = i / cell_height
      offset = 2 * (j.zero? ? 1 : 0)
      length = 8 >> (j.zero? ? 1 : 0)
      position = row*6 + (j + (row%2)*2 + column*4)*width + offset
      canvas[position, length] = drawing[-j * 8, length]
    end
  end
  print "N=", n, "\n"
  print canvas
end

hexagon(1)
hexagon(2)
hexagon(3)
hexagon(4)
hexagon(5)
hexagon(6)
