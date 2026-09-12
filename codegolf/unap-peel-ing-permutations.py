#!/usr/bin/env python3

"""

Given the height, h, and width, w, describing a rectangle of the first hw natural numbers in row-major order produce the numbers in the
order they are encountered by repeatedly removing a strip of the outermost numbers,
each time starting with the top-rightmost and ending with the bottom-leftmost,
but alternating between visiting each of the other two corners.

This is code-golf so try to write a program or function in your language of choice in the fewest possible bytes.

Your natural numbers may start from zero or one.
I will use one here, so 1,2,3,4,⋯row-major order is from top-left to bottom-right like English reading order.e.g. for the rectangle with h=2 and w=4:
1 2 3 4
5 6 7 8

Both h and w will be strictly positive integers.
You may choose whether the corner visited mid-strip on the first removal is:
the top-left corner ("Option 1"); or
the bottom-right corner ("Option 2")
...but this must be a consistent choice - your program or function should always use the same "Option".
You may print the result in any reasonable format or return an array-like construct with the numbers arranged in the desired order.

Example h=5,w=6
Remember, you should use either option 1 or option 2 consistently, regardless of the inputs...

Option 1 - visiting the top-left corner first:
 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30  -> Remove: 6 5 4 3 2 1 7 13 19 25

    8  9 10 11 12
   14 15 16 17 18
   20 21 22 23 24
   26 27 28 29 30  -> Remove: 12 18 24 30 29 28 27 26

    8  9 10 11
   14 15 16 17
   20 21 22 23     -> Remove: 11 10 9 8 14 20

      15 16 17
      21 22 23     -> Remove: 17 23 22 21

      15 16        -> Remove: 16 15
Expected result:

[6,5,4,3,2,1,7,13,19,25,12,18,24,30,29,28,27,26,11,10,9,8,14,20,17,23,22,21,16,15]
Option 2 - visiting the bottom-right corner first:
 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30  -> Remove: 6 12 18 24 30 29 28 27 26 25

 1  2  3  4  5
 7  8  9 10 11
13 14 15 16 17
19 20 21 22 23     -> Remove: 5 4 3 2 1 7 13 19

    8  9 10 11
   14 15 16 17
   20 21 22 23     -> Remove: 11 17 23 22 21 20

    8  9 10
   14 15 16        -> Remove: 10 9 8 14

      15 16        -> Remove: 16 15
Expected result:

[6,12,18,24,30,29,28,27,26,25,5,4,3,2,1,7,13,19,11,17,23,22,21,20,10,9,8,14,16,15]
Test cases
Note: All expected values may be one less if you choose to include zero in your natural numbers

If you are using option 1 - visiting the top-left corner first:
 h,  w    expected
 1,  1    1
 1,  3    3, 2, 1
 3,  1    1, 2, 3
 2,  2    2, 1, 3, 4
 2,  4    4, 3, 2, 1, 5, 8, 7, 6
 4,  2    2, 1, 3, 5, 7, 4, 6, 8
 7,  3    3, 2, 1, 4, 7, 10, 13, 16, 19, 6, 9, 12, 15, 18, 21, 20, 5, 8, 11, 14, 17
 3,  7    7, 6, 5, 4, 3, 2, 1, 8, 15, 14, 21, 20, 19, 18, 17, 16, 13, 12, 11, 10, 9
 5,  6    6, 5, 4, 3, 2, 1, 7, 13, 19, 25, 12, 18, 24, 30, 29, 28, 27, 26, 11, 10, 9, 8, 14, 20, 17, 23, 22, 21, 16, 15
 6,  5    5, 4, 3, 2, 1, 6, 11, 16, 21, 26, 10, 15, 20, 25, 30, 29, 28, 27, 9, 8, 7, 12, 17, 22, 14, 19, 24, 23, 13, 18

If you are using option 2 - visiting the bottom-right corner first:
 h,  w    expected
 1,  1    1
 1,  3    3, 2, 1
 3,  1    1, 2, 3
 2,  2    2, 4, 3, 1
 2,  4    4, 8, 7, 6, 5, 3, 2, 1
 4,  2    2, 4, 6, 8, 7, 1, 3, 5
 7,  3    3, 6, 9, 12, 15, 18, 21, 20, 19, 2, 1, 4, 7, 10, 13, 16, 5, 8, 11, 14, 17
 3,  7    7, 14, 21, 20, 19, 18, 17, 16, 15, 6, 5, 4, 3, 2, 1, 8, 13, 12, 11, 10, 9
 5,  6    6, 12, 18, 24, 30, 29, 28, 27, 26, 25, 5, 4, 3, 2, 1, 7, 13, 19, 11, 17, 23, 22, 21, 20, 10, 9, 8, 14, 16, 15
 6,  5    5, 10, 15, 20, 25, 30, 29, 28, 27, 26, 4, 3, 2, 1, 6, 11, 16, 21, 9, 14, 19, 24, 23, 22, 8, 7, 12, 17, 13, 18

"""

def unpeel(h, w):
    def compare(z):
        c = z % w
        d = z // w
        return [min(c, d, w - c - 0.5, h - d - 0.5), d - c]
    
    r = sorted(range(h * w), key=compare)
    for i in range(len(r)):
        r[i] += 1
    return r

def main():
    assert(unpeel(1, 1) == [1])
    assert(unpeel(1, 3) == [3, 2, 1])
    assert(unpeel(3, 1) == [1, 2, 3])
    assert(unpeel(2, 2) == [2, 1, 3, 4])
    assert(unpeel(2, 4) == [4, 3, 2, 1, 5, 8, 7, 6])
    assert(unpeel(4, 2) == [2, 1, 3, 5, 7, 4, 6, 8])
    assert(unpeel(7, 3) == [3, 2, 1, 4, 7, 10, 13, 16, 19, 6, 9, 12, 15, 18, 21, 20, 5, 8, 11, 14, 17])
    assert(unpeel(3, 7) == [7, 6, 5, 4, 3, 2, 1, 8, 15, 14, 21, 20, 19, 18, 17, 16, 13, 12, 11, 10, 9])
    assert(unpeel(5, 6) == [6, 5, 4, 3, 2, 1, 7, 13, 19, 25, 12, 18, 24, 30, 29, 28, 27, 26, 11, 10, 9, 8, 14, 20, 17, 23, 22, 21, 16, 15])
    assert(unpeel(6, 5) == [5, 4, 3, 2, 1, 6, 11, 16, 21, 26, 10, 15, 20, 25, 30, 29, 28, 27, 9, 8, 7, 12, 17, 22, 14, 19, 24, 23, 13, 18])

main()
