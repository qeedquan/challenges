#!/usr/bin/env python3

"""

Let's build a basic paint program! Your task for today will be to create a basic paint program that can draw points, lines, and filled rectangles, then output an image file that many image viewers can read. But first, some background:

Netpbm Formats
PNG, GIF, JPEG, and even BMP are all image formats that are way too complex for an [Easy] challenge. Instead, we are going to be using Netpbm formats. More specifically, we will be using the PPM format, which supports 24-bit RGB color. Here's how a .ppm file looks (courtesy of Wikipedia):

P3
# The P3 means colors are in ASCII, then 3 columns and 2 rows,
# then 255 for max color, then RGB triplets
3 2
255
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
Each pixel in the image is represented with 3 integers (0-255) for its Red, Green, and Blue pixel values. The above .ppm file gets displayed as this (zoomed in).

Everything is separated by whitespace, but what the whitespace is (and how much of it there is) doesn't matter. Comments (anything after a #) are also ignored. In other words, the following PPM file renders exactly the same image:

P3 3 2 255 255 0 0 0 255 0 0 0 255 255 255 0 255 255 255 0 0 0
Lastly, note that in image processing, pixels are indexed using (row, column) coordinates, counting up from (0, 0). Thus, in the image above, the pixel at (0, 2) is on row 0, column 2, which has the RGB value of 0 0 255, or in other words, is blue.

Now that that's out of the way, let's get to painting!

Formal Input
Your input file will contain an X/Y size for an image to create, followed by a series of commands, each on its own line. The commands each start with point, line, or rect, followed by a RGB color, followed by whatever arguments the command needs. Here's a sample:

5 3
point 0 0 255 0 0
line 100 100 100 0 2 2 4
rect 77 0 0 1 3 2 2
Breaking the file down line by line:

5 3: The output image is 5 columns wide and 3 rows tall

point: we're drawing a single point... 0 0 255: with this RGB color (blue)... 0 0: at this coordinate (top left)

line: we're drawing a line... 100 100 100: with this RGB color (grey)... 0 2: from this coordinate... 2 4 to this coordinate (for oblique lines, make a "best effort" to approximate the line; no need to do any antialiasing or other fancy stuff)

rect: we're drawing a rectangle... 77 0 0: with this RGB color (dark red)... 1 3: with its top left coordinate here... 2 2 with its sides being 2 pixels tall and 2 pixels wide

The "unpainted" background can be assumed to be black (0 0 0).

Formal Output
The output PPM file for the above example should look like this (more or less, spacing notwithstanding):

P3
5 3
255
0   0   255    0   0   0      100 100 100    0   0   0      0   0   0
0   0   0      0   0   0      0   0   0      77  0   0      77  0   0
0   0   0      0   0   0      0   0   0      77  0   0      77  0   0
And it should render like this (zoomed in).

Challenge Input
400 300
rect 0 0 255 0 0 300 400
line 255 255 255 0 0 299 399
line 255 255 255 299 0 0 399
rect 200 200 0 100 150 100 100
point 0 0 0 150 200
Challenge Output
Actual output: https://raw.githubusercontent.com/fsufitch/dailyprogrammer/master/248_easy/sample2_tight.ppm

Converted to PNG and posted to Imgur: https://i.imgur.com/nRmSoUf.png

Big Challenge
Run these commands: https://raw.githubusercontent.com/fsufitch/dailyprogrammer/master/248_easy/sierpinsky.txt

You should get something like this: https://i.imgur.com/5F31DSE.png

Bonus Points
If you would like more of a challenge, implement the following commands:

bline <R> <G> <B> <row1> <col1> <row2> <col2> draw a line using Bresenham's line algorithm

circle <R> <G> <B> <centerRow> <centerCol> <radius>

ellipse <R> <G> <B> <centerRow> <centerCol> <radiusVertical> <radiusHorizontal>

fill <R> <G> <B> <row> <col> (flood fill one color starting at the given point)

smartfill <R> <G> <B> <row> <col> <tolerance> (flood fill similar colors starting at the given point, filling pixels as long as the gradient distance (sqrt( (r2-r1)^2 + (g2-g1)^2 + (b2-b1)^2)) is less than the tolerance.

Resources
Online PPM format converter: https://convertio.co/ppm-png/

For local command line conversion: https://www.imagemagick.org/

For local GUI editing/conversion: https://www.gimp.org/

Have any cool ideas for challenges? Come post them over in r/dailyprogrammer_ideas!

Got feedback? We (the mods) would like to know how we're doing! Are the problems too easy? Too hard? Just right? Boring/exciting? Varied/same? Anything you would like to see us do that we're not doing? Anything we're doing that we should just stop? Come by this feedback thread and let us know!

"""

from math import sqrt
from queue import Queue
import sys

# ported from @fibonacci__ solution

# bline, circle, ellipse function adapted from: http://members.chello.at/~easyfilter/bresenham.html
def print_drawing(drawing):
    print('P3\n%d %d\n255' % (len(drawing[0]), len(drawing)))
    print('\n'.join([' '.join(['%-4d %-4d %-4d' % l for l in line]) for line in drawing]))

def point(drawing, data):
    data = [int(d) for d in data]
    r, g, b, y, x = data[0:5]
    drawing[y][x] = (r, g, b)

def line(drawing, data):
    data = [int(d) for d in data]
    r, g, b = data[0:3]
    y1, x1, y2, x2 = data[3:7] if data[4] < data[6] else data[5:7] + data[3:5]
    for i in range(x1, x2 + 1):
        drawing[y1 + (y2 - y1) * (i - x1) // (x2 - x1)][i] = (r, g, b)

def rect(drawing, data):
    data = [int(d) for d in data]
    r, g, b, y, x, h, w = data[0:7]
    for i in range(h):
        drawing[y + i][x:x + w] = [(r, g, b) for p in range(w)]

def bline(drawing, data):
    data = [int(d) for d in data]
    r, g, b, y1, x1, y2, x2 = data[0:7]
    dx, sx = abs(x2 - x1), 1 if x1 < x2 else -1
    dy, sy = -abs(y2 - y1), 1 if y1 < y2 else -1
    err = dx + dy
    while True:
        drawing[y1][x1] = (r, g, b)
        if x1 == x2 and y1 == y2:
            break
        e2 = 2 * err
        if e2 >= dy:
            err += dy
            x1 += sx
        if e2 <= dx:
            err += dx
            y1 += sy

def circle(drawing, data):
    data = [int(d) for d in data]
    r, g, b, ym, xm, r_ = data[0:6]
    x, y, err = -r_, 0, 2 - 2 * r_
    while x < 0:
        drawing[ym + y][xm - x] = (r, g, b)
        drawing[ym - x][xm - y] = (r, g, b)
        drawing[ym - y][xm + x] = (r, g, b)
        drawing[ym + x][xm + y] = (r, g, b)
        r_ = err
        if r_ <= y:
            y += 1
            err += 2 * y + 1
        if r_ > x or err > y:
            x += 1
            err += 2 * x + 1

def ellipse(drawing, data):
    data = [int(d) for d in data]
    r, g, b, ym, xm, rv, rh = data[0:7]
    y1, x1, y2, x2 = ym + rv, xm - rh, ym - rv, xm + rh

    a_, b_= abs(x2 - x1), abs(y2 - y1)
    b1 = b_&1
    dx, dy = 4.0 * (1 - a_) * b_ * b_, 4.0 * (b1 + 1) * a_ * a_
    err = dx + dy + 1.0 * b1 * a_ * a_

    if x1 > x2:
        x1 = x2
        x2 += a_
    if y1 > y2:
        y1 = y2
    y1 += (b_ + 1) // 2
    y2 = y1 - b1
    a_ *= 8 * a_
    b1 = 8 * b_ * b_

    while x1 <= x2:
        drawing[y1][x2] = (r, g, b)
        drawing[y1][x1] = (r, g, b)
        drawing[y2][x1] = (r, g, b)
        drawing[y2][x2] = (r, g, b)
        e2 = 2 * err;
        if e2 <= dy:
            y1 += 1
            y2 -= 1
            dy += a_
            err += dy
        if e2 >= dx or 2 * err > dy:
            x1 += 1
            x2 -= 1
            dx += b1
            err += dx
   
    while y1 - y2 < b_:
        drawing[y1, x1 - 1] = (r, g, b)
        y1 += 1
        drawing[y1, x2 + 1] = (r, g, b)
        drawing[y2, x1 - 1] = (r, g, b)
        y2 -= 1
        drawing[y2, x2 + 1] = (r, g, b)


def fill(drawing, data):
    data = [int(d) for d in data]
    r, g, b, y, x = data[0:5]
    color = drawing[y][x]
    q = Queue()
    q.put([x, y])
    visited = set([])
    while not q.empty():
        curr = q.get()
        if tuple(curr) in visited:
            continue
        w = [curr[0], curr[1]]
        e = [w[0], w[1]]
        while w[0] > 0 and drawing[w[1]][w[0] - 1] == color:
            w[0] -= 1
        while e[0] < len(drawing[0]) - 1 and drawing[e[1]][e[0] + 1] == color:
            e[0] += 1
        for i in range(w[0], e[0] + 1):
            drawing[w[1]][i] = (r, g, b)
            if w[1] > 0 and drawing[w[1] - 1][i] == color:
                q.put([i, w[1] - 1])
            if w[1] < len(drawing) - 1 and drawing[w[1] + 1][i] == color:
                q.put([i, w[1] + 1])
        visited.add(tuple(curr))

def smartfill(drawing, data):
    data = [int(d) for d in data]
    r, g, b, y, x, tol = data[0:6]
    color = drawing[y][x]
    q = Queue()
    q.put([x, y])
    visited = set([])
    while not q.empty():
        curr = q.get()
        if tuple(curr) in visited:
            continue
        w = [curr[0], curr[1]]
        e = [w[0], w[1]]
        while w[0] > 0:
            curr_color = drawing[w[1]][w[0] - 1]
            dr, dg, db = curr_color[0] - color[0], curr_color[1] - color[1], curr_color[2] - color[2]
            if sqrt(dr * dr + dg * dg + db * db) < tol:
                w[0] -= 1
            else:
                break
        while e[0] < len(drawing[0]) - 1:
            curr_color = drawing[e[1]][e[0] + 1]
            dr, dg, db = curr_color[0] - color[0], curr_color[1] - color[1], curr_color[2] - color[2]
            if sqrt(dr * dr + dg * dg + db * db) < tol:
                e[0] += 1
            else:
                break
        for i in range(w[0], e[0] + 1):
            drawing[w[1]][i] = (r, g, b)
            if w[1] > 0:
                curr_color = drawing[w[1] - 1][i]
                dr, dg, db = curr_color[0] - color[0], curr_color[1] - color[1], curr_color[2] - color[2]
                if sqrt(dr * dr + dg * dg + db * db) < tol:
                    q.put([i, w[1] - 1])
            if w[1] < len(drawing) - 1:
                curr_color = drawing[w[1] + 1][i]
                dr, dg, db = curr_color[0] - color[0], curr_color[1] - color[1], curr_color[2] - color[2]
                if sqrt(dr * dr + dg * dg + db * db) < tol:
                    q.put([i, w[1] + 1])
        visited.add(tuple(curr))

def process(lines):
    x, y = int(lines[0][0]), int(lines[0][1])
    drawing = [[(0, 0, 0) for col in range(x)] for row in range(y)]
    for l in lines[1:]:
        if l[0] == 'point':
            point(drawing, l[1:])
        elif l[0] == 'line':
            line(drawing, l[1:])
        elif l[0] == 'rect':
            rect(drawing, l[1:])
        elif l[0] == 'bline':
            bline(drawing, l[1:])
        elif l[0] == 'circle':
            circle(drawing, l[1:])
        elif l[0] == 'ellipse':
            ellipse(drawing, l[1:])
        elif l[0] == 'fill':
            fill(drawing, l[1:])
        elif l[0] == 'smartfill':
            smartfill(drawing, l[1:])
    print_drawing(drawing)

def main():
    if len(sys.argv) < 2:
        print("usage: <file>")
        exit(2)

    with open(sys.argv[1]) as file:
        lines = [f.strip().split() for f in file]
        process(lines)

main()
