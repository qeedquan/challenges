#!/usr/bin/env python3

"""

--- Day 13: A Maze of Twisty Little Cubicles ---
You arrive at the first floor of this new building to discover a much less welcoming environment than the shiny atrium of the last one. Instead, you are in a maze of twisty little cubicles, all alike.

Every location in this area is addressed by a pair of non-negative integers (x,y). Each such coordinate is either a wall or an open space. You can't move diagonally. The cube maze starts at 0,0 and seems to extend infinitely toward positive x and y; negative values are invalid, as they represent a location outside the building. You are in a small waiting area at 1,1.

While it seems chaotic, a nearby morale-boosting poster explains, the layout is actually quite logical. You can determine whether a given x,y coordinate will be a wall or an open space using a simple system:

Find x*x + 3*x + 2*x*y + y + y*y.
Add the office designer's favorite number (your puzzle input).
Find the binary representation of that sum; count the number of bits that are 1.
If the number of bits that are 1 is even, it's an open space.
If the number of bits that are 1 is odd, it's a wall.
For example, if the office designer's favorite number were 10, drawing walls as # and open spaces as ., the corner of the building containing 0,0 would look like this:

  0123456789
0 .#.####.##
1 ..#..#...#
2 #....##...
3 ###.#.###.
4 .##..#..#.
5 ..##....#.
6 #...##.###
Now, suppose you wanted to reach 7,4. The shortest route you could take is marked as O:

  0123456789
0 .#.####.##
1 .O#..#...#
2 #OOO.##...
3 ###O#.###.
4 .##OO#OO#.
5 ..##OOO.#.
6 #...##.###
Thus, reaching 7,4 would take a minimum of 11 steps (starting from your current location, 1,1).

What is the fewest number of steps required for you to reach 31,39?

--- Part Two ---
How many locations (distinct x,y coordinates, including your starting location) can you reach in at most 50 steps?

"""

from collections import deque

def is_empty(x, y, number):
    r = (x*x + 3*x + 2*x*y + y + y*y) + number
    return r.bit_count()%2 == 0

def surrounding(x, y, number):
    for dx in (-1, 1):
        if x + dx >= 0 and is_empty(x + dx, y, number):
            yield (x + dx, y)
    for dy in (-1, 1):
        if y + dy >= 0 and is_empty(x, y + dy, number):
            yield (x, y + dy)

def solve(number, part):
    queue = deque()
    queue.append(((1, 1), 0))
    visited = {(1, 1)}
    length = 0
    while queue:
        point, length = queue.popleft()
        if part == 1 and point == (31, 39):
            return length
        if part == 2 and length == 51:
            return len(visited)
        
        visited.add(point)
        for new_point in surrounding(*point, number):
            if new_point not in visited:
                queue.append((new_point, length + 1))
    return -1

def main():
    number = 1352
    print(solve(number, 1))
    print(solve(number, 2))

main()

