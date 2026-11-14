%{

Similar figures
Two rectangles are similar if the ratios of their sides are the same.

Consider these two rectangles; a rectangle 5 lines tall and 11 chars wide:

===========
===========
===========
===========
===========

and a rectangle 10 lines tall and 22 chars wide:

======================
======================
======================
======================
======================
======================
======================
======================
======================
======================

These shapes are similar because the ratios of their sides are the same. To put it formally (with h being the shortest side and w being the longest side):

h1/w1 = h2/w2

You can also do:

h1/h2 = w1/w2

The challenge
Write a program or function that takes a "main" rectangle and some "other" rectangles and prints which of "others" are similar to "main".

The input
A shape and a list of shapes. Each shape consists of 2 non-zero positive integers, which denote the width and height of the rectangle. For instance, this:

(4,2), (3,9)
denotes two rectangles, a 4x2 and a 3x9. The exact format of the input may be however you desire.

The output
The indices of the "other" shapes that are similar to "main". You may choose whether the indices are 0- or 1-based, as well as the exact format and order of the output.

Sample program
In Python:

main = eval(raw_input()) # The main rectangle.
rects = eval(raw_input()) # The list of rectangles.
similar = set()
for i, rect in enumerate(rects):
    if max(main)*min(rect) == min(main)*max(rect): # Cross-multiply
        # They are similar.
        similar.add(i)

print similar
Sample input and output
Input:

(1, 2)
[(1, 2), (2, 4)]
Output:

set([0, 1])
Input:

(1, 2)
[(1, 9), (2, 5), (16, 8)]
Output:

set([2])
Winning
This is code-golf, so the shortest submission wins.

Notes
This should go without saying, but standard loopholes are banned.
No builtins for locating similar figures may be used. (I don't even know if that exists, but I would't be surprised!)

%}

lookalikes = @(x, y) (max(x)) * min(y') == min(x) * max(y')

lookalikes([1 2], [1 2; 2 4])
lookalikes([1 2], [1 9; 2 5; 16 8])

