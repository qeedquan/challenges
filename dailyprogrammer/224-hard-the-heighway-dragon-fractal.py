#!/usr/bin/env python3

"""

Description
Write a program to print out the (x, y) coordinates of each point in the nth iteration of the Heighway dragon fractal. Start at the origin (0, 0) and take steps of length 1, starting in the positive x direction (1, 0), then turning to the positive y direction (1, 1). Your program should generate 2n + 1 lines of output.

You can use any resources you want for help coming up with the algorithm, but if you want to start from the very beginning, use only the fact that the nth iteration can be made by folding a strip of paper in half n times, then unfolding it so that each crease is at a right angle.

Example
For n = 3, your output should be:

0 0
1 0
1 1
0 1
0 2
-1 2
-1 1
-2 1
-2 2
Plotted image of these points, made using LibreOffice.

The sum of the x's here is -4, and the sum of the y's is 10. For n = 12, the sums are -104896 and 52416. To verify that your program is correct, post the sum of x's and y's for n = 16 along with your code.

Optional challenges
Today's basic challenge is not too hard, relatively speaking, so if you want more, try some of these optional add-ons, or take it in your own direction.

Show us a plot of your output. There are many options for this. You can use a plotting library for your language of choice, or use a spreadsheet like I did. gnuplot is another free option. Feel free to get creative with colors, effects, animations, etc.

Optimize your code for memory usage. Aim for O(n) space.

Optimize your code for speed. What's the largest n you can generate all the data for in less than 1 minute? (You can skip printing output for this one, as long as you actually do all the calculations.)

Golf: minimize your code length. What's the shortest program you can write in your language that works?

There are other ways of generating the Heighway dragon than the paper folding one I suggested. Try implementing a different one than you used first.

There are many variations of the Heighway dragon (see Variations at the bottom). Try creating a terdragon, golden dragon, or anything else you can find.

Find a way to efficiently calculate s(n), the sum of the x's and y's for the nth iteration. For example, s(3) = (-4, 10) and s(12) = (-104896, 52416). Post s(100) along with your code. (This is possible without any advanced math, but it's tricky.)

Find a way to efficiently calculate p(k), the (x, y) position after k steps (i.e. the (k+1)th line of output when n is sufficiently large), starting from from p(0) = (0, 0), p(1) = (1, 0). For example, p(345) = (13, 6). Post p(345) along with your code. (This one is also quite tricky.)

"""

def heighway_sequence(degree):
    if degree == 1:
        return 'L'
    
    first = heighway_sequence(degree - 1)
    second = ''.join(['L' if turn == 'R' else 'R' for turn in first[::-1]])
    return first + 'L' + second

def heighway(degree):
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    direction = 0
    points = [(0, 0), (1, 0)]
    here = (1, 0)
    for turn in heighway_sequence(degree):
        if turn == 'L':
            direction += 1
        else:
            direction -= 1
        direction %= 4
        here = (here[0] + directions[direction][0], here[1] + directions[direction][1])
        points.append(here)

    x_sum = sum([point[0] for point in points])
    y_sum = sum([point[1] for point in points])
    return points, x_sum, y_sum

def main():
    points, x_sum, y_sum = heighway(3)
    assert(x_sum == -4 and y_sum == 10)

    points, x_sum, y_sum = heighway(12)
    assert(x_sum == -104896 and y_sum == 52416)

    points, x_sum, y_sum = heighway(16)
    assert(x_sum == 6711040 and y_sum == -3355392)

main()
