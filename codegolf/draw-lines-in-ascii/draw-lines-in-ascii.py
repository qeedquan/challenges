#!/usr/bin/env python3

r"""

Challenge
Draw lines in ASCII corresponding to given inputs:

in the first line there are given size of rows and columns of the view and number of separators between each point

in the second line is given list of lines separated by space

a line contains the position of head and tail coordinates (within the size of columns and rows) separated by space (x1 x2 y1 y2).

In the below examples we used character '#' for filled spot, '.' for free spots and ' ' for the separator but you are free to use any other printable ASCII characters.

Sample input 1:

33 15 1
5 0 31 0 31 0 31 10 31 10 27 14 27 14 27 4 27 4 0 4 0 4 0 14 0 14 27 14 31 10 5 10 5 10 5 0 5 0 0 4 31 0 27 4 5 10 0 14
Sample output 1:

. . . . . # # # # # # # # # # # # # # # # # # # # # # # # # # # .
. . . . # # . . . . . . . . . . . . . . . . . . . . . . . . # # .
. . # # . # . . . . . . . . . . . . . . . . . . . . . . . # . # .
. # . . . # . . . . . . . . . . . . . . . . . . . . . . # . . # .
# # # # # # # # # # # # # # # # # # # # # # # # # # # # . . . # .
# . . . . # . . . . . . . . . . . . . . . . . . . . . # . . . # .
# . . . . # . . . . . . . . . . . . . . . . . . . . . # . . . # .
# . . . . # . . . . . . . . . . . . . . . . . . . . . # . . . # .
# . . . . # . . . . . . . . . . . . . . . . . . . . . # . . . # .
# . . . . # . . . . . . . . . . . . . . . . . . . . . # . . . # .
# . . . . # # # # # # # # # # # # # # # # # # # # # # # # # # # .
# . . . # . . . . . . . . . . . . . . . . . . . . . . # . . # . .
# . # # . . . . . . . . . . . . . . . . . . . . . . . # . # . . .
# # . . . . . . . . . . . . . . . . . . . . . . . . . # # . . . .
# # # # # # # # # # # # # # # # # # # # # # # # # # # # . . . . .
Sample input 2:

31 15 0
0 0 30 14 0 14 30 0 15 0 15 14 0 7 30 7
Sample output 2:

##.............#.............##
..##...........#...........##..
....##.........#.........##....
.....###.......#......###......
........##.....#.....##........
..........###..#..###..........
.............#####.............
###############################
.............#####.............
..........###..#..###..........
.........##....#.....##........
......###......#......###......
....##.........#.........##....
..##...........#...........##..
##.............#.............##
Bonus Points

Use line position format like so (y1,x1)-(y2,x2).

e.g.

31 15 0
(0,0)-(14,30) (14,0)-(0,30) (0,15)-(14,15) (7,0)-(7,30)
Scoring

This is code-golf, so the shortest solution wins.

Just to finish this up, simple python(3) answer would be:

Try it online!

a()
or python(1789) *without escape characters:

Try it online!

Resault = ""


def bresenham(x0, y0, x1, y1):
    dx = x1 - x0
    dy = y1 - y0
    xsign = 1 if dx > 0 else -1
    ysign = 1 if dy > 0 else -1
    dx = abs(dx)
    dy = abs(dy)
    if dx > dy:
        xx, xy, yx, yy = xsign, 0, 0, ysign
    else:
        dx, dy = dy, dx
        xx, xy, yx, yy = 0, ysign, xsign, 0
    D = 2 * dy - dx
    y = 0
    for x in range(dx + 1):
        yield x0 + x * xx + y * yx, y0 + x * xy + y * yy
        if D >= 0:
            y += 1
            D -= 2 * dx
        D += 2 * dy


class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


class Line:
    def __init__(self, head: Point, tail: Point):
        self.head = head
        self.tail = tail


def drawline(size: tuple, lines: list, chrs=('.', '#', ' ')) -> Resault:
    global Resault
    co = []
    for line in lines:
        co.extend(list(bresenham(
            line.head.x, line.head.y, line.tail.x, line.tail.y)))
    for column in range(size[1]):
        for row in range(size[0]):
            if (row, column) in co:
                Resault += chrs[1]
            else:
                Resault += chrs[0]
            if row != size[0]-1:
                Resault += chrs[2]*size[2]
        if column != size[1]-1:
            Resault += "\n"
    return Resault


if __name__ == "__main__":
    size = tuple(map(int, input().split()))
    coordinates = [i[::-1] for i in [list(map(int, j.split(','))) for i in [
        i.split('-') for i in input().replace(')', '').replace(
            '(', '').split(' ')] for j in i]]
    coordinates = [coordinates[i-4:i] for i in range(4, len(coordinates)+4, 4)]
    lines = []
    for c in coordinates:
        lines.append(Line(Point(c[0][0], c[0][1]), Point(c[1][0], c[1][1])))
    print(drawline(size, lines))

"""

Resault = ""

def bresenham(x0, y0, x1, y1):
    dx = x1 - x0
    dy = y1 - y0
    xsign = 1 if dx > 0 else -1
    ysign = 1 if dy > 0 else -1
    dx = abs(dx)
    dy = abs(dy)
    if dx > dy:
        xx, xy, yx, yy = xsign, 0, 0, ysign
    else:
        dx, dy = dy, dx
        xx, xy, yx, yy = 0, ysign, xsign, 0
    D = 2 * dy - dx
    y = 0
    for x in range(dx + 1):
        yield x0 + x * xx + y * yx, y0 + x * xy + y * yy
        if D >= 0:
            y += 1
            D -= 2 * dx
        D += 2 * dy


class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


class Line:
    def __init__(self, head: Point, tail: Point):
        self.head = head
        self.tail = tail


def drawline(size: tuple, lines: list, chrs=('.', '#', ' ')) -> Resault:
    global Resault
    co = []
    for line in lines:
        co.extend(list(bresenham(
            line.head.x, line.head.y, line.tail.x, line.tail.y)))
    for column in range(size[1]):
        for row in range(size[0]):
            if (row, column) in co:
                Resault += chrs[1]
            else:
                Resault += chrs[0]
            if row != size[0]-1:
                Resault += chrs[2]*size[2]
        if column != size[1]-1:
            Resault += "\n"
    return Resault

def main():
    size = tuple(map(int, input().split()))
    coordinates = [i[::-1] for i in [list(map(int, j.split(','))) for i in [i.split('-') for i in input().replace(')', '').replace('(', '').split(' ')] for j in i]]
    coordinates = [coordinates[i-4:i] for i in range(4, len(coordinates)+4, 4)]
    lines = []
    for c in coordinates:
        lines.append(Line(Point(c[0][0], c[0][1]), Point(c[1][0], c[1][1])))
    print(drawline(size, lines))

main()
