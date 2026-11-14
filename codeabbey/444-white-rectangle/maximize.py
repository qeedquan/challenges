#!/usr/bin/env python3

"""

This seems to be very old puzzle - Jacques Arsac mentions it in his book "Programming of games and puzzles" saying he encountered it "few years ago" at some programming contest, and the book was published in 1985 itself...

Given a matrix consisting of empty (white) cells and blocked (black) ones - we want to find largest "white" or empty rectangle.

Input and output format:

First line of input contains rows and columns - dimensions of the grid. Next rows lines will contain each a string of columns characters, either X or - (the former meaning blocked cell, the latter an empty one).

Answer should be a single value - area of the largest rectangle fitting into this grid.

Example:

input data:
7 9
-----X--X
--------X
---------
-----X---
--X---X--
---------
-----X---

answer:
20

"""

import sys

def largest_rectangle_in_histogram(heights):
    stack = []
    max_area = 0
    
    # Dummy value to flush the stack at the end
    heights.append(0)
    
    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
        
    # Restore original heights list
    heights.pop()
    return max_area

def solve(lines):
    rows, cols = map(int, lines[0].split())
    
    # DP array to store the current histogram heights
    heights = [0] * cols
    max_rectangle_area = 0
    
    # Process each row
    for r in range(1, rows + 1):
        for c in range(cols):
            if lines[r][c] == '-':
                heights[c] += 1
            else:
                heights[c] = 0
        
        # Calculate maximum area for the current row's histogram
        current_max = largest_rectangle_in_histogram(heights)
        max_rectangle_area = max(max_rectangle_area, current_max)
    return max_rectangle_area

def main():
    lines = sys.stdin.read().splitlines()
    print(solve(lines))

main()
