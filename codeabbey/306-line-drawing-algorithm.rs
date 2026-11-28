/*

You read these words, most probably, looking at some kind of a pixel display - rectangular matrix of small dots which can be made light or dark independently. Such types of displays are very old, though they may be not the oldest devices which computers use to visualize information.

How do you draw a straight line on such a display? Of course if it is strictly vertical or horizontal, it is just a column or row of pixels. But what if it goes at some angle? In this case it is represented by a chain of vertical or horizontal segments, of course, but due to pixels being very small, it looks like single continous and straight line. Suppose for example we have screen 8 by 5 and want to draw line from corner to corner:

X - - - - - - -
- X X - - - - -
- - - X X - - -
- - - - - X X -
- - - - - - - X
Remember that historically computer displays have X=0, Y=0 at the top-left corner.

How do we draw such a line? We may represent it with a segment of line given by equation Y = K * X + B and calculate K and B from starting and ending points, and then iterating between start and ent set necessary points... But this involves floating point calculations (i.e. non-integer arithmetics).

Historically computers either had no direct support for floating point numbers or did it significantly slower than dealing with integers. Even nowadays billions of smaller processors (microcontrollers) found in various electronic devices (ranging from microwave oven to GPS-tracker) may lack support for non-integers.

How do we deal in this case? Well, it's up to you to figure out (or google it by the name of Bresenham).

Problem statement
You are to write the line-drawing program in a language limited to only integer operations - either Assembly for Intel-4004 or BASIC (which shall be switched to "integer" mode when checking your solution).

The input shall contain starting and ending point of a line. As an output the code should generate a sequence of pixel coordinates in hexadecimal form.

Input consists of 4 values - X0, Y0 describe the starting point and X1, Y1 the ending one.

assume that X1 - X0 >= Y1 - Y0 - the line is always in the same "octant" (for other "octants" some kind of coordinate transformations is generally used - but we don't care for this task);
our imaginary display is 256 by 192 pixels (as ZX-Spectrum had) in other words all values fit in 8-bits.
For assembly program it is going to be preloaded into first 8 registers: X0 = r0:r1 and Y0 = r2:r3 make starting point and ending point is X1 = r4:r5 and Y1 = r6:r7.

For basic program it is just 4 decimal values, space separated.

For test-run please copy one of the example inputs below into input field.

Answer is a string of printed hex digits (just like in Prn Hex Str problem), every 4 digits representing X and Y coordinate of the next pixel. Make sure to have them consecutive, from starting point to ending (and including these two).

Example: suppose we want to draw a line from X=60 Y=40 to X=220 Y=150:

input (registers for Asm-i4004):
3 C 2 8 D C 9 6 0 0 0 0 0 0 0 0

input (for BASIC):
60 40 220 150

output:
3C28...DC96
Output is going to be a long line so we omitted all pixels except starting and ending in the example :)

Important! Remember that the answer you submit doesn't matter - your code is checked instead by running it against some hidden test-cases.

*/

fn main() {
    line(60, 40, 220, 150);
}

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
fn line(mut x0: isize, mut y0: isize, x1: isize, y1: isize) {
    let dx = (x1 - x0).abs();
    let dy = -(y1 - y0).abs();
    let mut sx = -1;
    let mut sy = -1;
    if x0 < x1 {
        sx = 1;
    }
    if y0 < y1 {
        sy = 1;
    }
    let mut e = dx + dy;

    loop {
        print!("{:2X}{:2X} ", x0, y0);
        if x0 == x1 && y0 == y1 {
            break;
        }
        let e2 = 2 * e;
        if e2 >= dy {
            e += dy;
            x0 += sx;
        }
        if e2 <= dx {
            e += dx;
            y0 += sy;
        }
    }
    println!();
}
