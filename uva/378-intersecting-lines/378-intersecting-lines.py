#!/usr/bin/env python3

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Segment:
    def __init__(self, start, end):
        self.start = start
        self.end = end

def solve(a, b):
    a1 = a.start.y - a.end.y
    b1 = -a.start.x + a.end.x
    a2 = b.start.y - b.end.y
    b2 = -b.start.x + b.end.x;
    c1 = a1*a.start.x + b1*a.start.y
    c2 = a2*b.start.x + b2*b.start.y
    
    D = a1*b2 - a2*b1
    Dx = c1*b2 - c2*b1
    Dy = a1*c2 - a2*c1

    if D == 0:
        if Dx != 0 or Dy != 0:
            return "NONE"
        if Dx == 0 and Dy == 0:
            return "LINE"
    return "POINT %.2f %.2f" % (Dx/D, Dy/D)

def main():
    print(solve(Segment(Point(0, 0), Point(4, 4)), Segment(Point(0, 4), Point(4, 0))))
    print(solve(Segment(Point(5, 0), Point(7, 6)), Segment(Point(1, 0), Point(2, 3))))
    print(solve(Segment(Point(5, 0), Point(7, 6)), Segment(Point(3, -6), Point(4, -3))))
    print(solve(Segment(Point(2, 0), Point(2, 27)), Segment(Point(1, 5), Point(18, 5))))
    print(solve(Segment(Point(0, 3), Point(4, 0)), Segment(Point(1, 2), Point(2, 5))))

main()

