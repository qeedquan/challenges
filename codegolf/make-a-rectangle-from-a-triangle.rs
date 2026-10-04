/*

You can depict a triangular number, T(N), by writing one 1 on a line, then two 2's on the line below, then three 3's on the line below that, and so on until N N's. You end up with a triangle of T(N) numbers, hence the name.

For example, T(1) through T(5):

1

1
22

1
22
333

1
22
333
4444

1
22
333
4444
55555
To keep things nicely formatted we'll use the last digit of the number for N > 9, so T(11) would be:

1
22
333
4444
55555
666666
7777777
88888888
999999999
0000000000
11111111111
Now pretend like each row of digits in one of these triangles is a 1-by-something polyomino tile that can be moved and rotated. Call that a row-tile.

For all triangles beyond T(2) it is possible to rearrange its row-tiles into a W×H rectangle where W > 1 and H > 1. This is because there are no prime Triangular numbers above N > 2. So, for N > 2, we can make a rectangle from a triangle!

(We're ignoring rectangles with a dimension of 1 on one side since those would be trivial by putting every row on one line.)

Here is a possible rectangle arrangement for each of T(3) through T(11). Notice how the pattern could be continued indefinitely since every odd N (except 3) reuses the layout of N - 1.

N = 3
333
221

N = 4
44441
33322

N = 5
55555
44441
33322

N = 6
6666661
5555522
4444333

N = 7
7777777
6666661
5555522
4444333

N = 8
888888881
777777722
666666333
555554444

N = 9
999999999
888888881
777777722
666666333
555554444

N = 10
00000000001
99999999922
88888888333
77777774444
66666655555

N = 11
11111111111
00000000001
99999999922
88888888333
77777774444
66666655555
However, there are plenty of other ways one could arrange the row-tiles into a rectangle, perhaps with different dimensions or by rotating some row-tiles vertically. For example, these are also perfectly valid:

N = 3
13
23
23

N = 4
33312
44442

N = 5
543
543
543
541
522

N = 7
77777776666661
55555444433322

N = 8
888888881223
666666555553
444477777773

N = 11
50000000000
52266666634
57777777134
58888888834
59999999994
11111111111

Challenge
Your task in this challenge is to take in a positive integer N > 2 and output a rectangle made from the row-tiles of the triangles of T(N), as demonstrated above.

As shown above, remember that:

The area of the rectangle will be T(N).

The width and height of the rectangle must both be greater than 1.

Row-tiles can be rotated horizontally or vertically.

Every row-tile must be depicted using the last digit of the number it represents.

Every row-tile must be fully intact and within the bounds of the rectangle.

The output can be a string, 2D array, or matrix, but the numbers must be just digits from 0 through 9.

The output does not need to be deterministic. It's ok if multiple runs produce multiple, valid rectangles.

The shortest code in bytes wins!

*/

fn main() {
    for i in 1..12 {
        rft(i);
    }
}

// ported from @Noodle9 solution
fn rft(mut n: isize) {
    println!("N={}", n);
    let mut i = 1 - (n & 1);
    while i < n {
        for j in 0..n + i {
            let mut x = i;
            if j < n {
                x = n;
            }
            print!("{}", x % 10);
        }
        println!();
        i += 1;
        n -= 1;
    }
    println!();
}
