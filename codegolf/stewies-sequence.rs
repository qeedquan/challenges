/*

Let's use the four basic operations, addition +, multiplication *, subtraction - and division / (float, not integer).

Stewie's sequence is defined as follows:

x = [x(1), x(2)]    // Two initial numbers (one indexed)
x(3) = x(1) + x(2)
x(4) = x(2) * x(3)
x(5) = x(3) - x(4)
x(6) = x(4) / x(5)
x(7) = x(5) + x(6)
... and so on.

Challenge:

Take two non-negative integers (x(1), x(2)), and one positive integer N as input.

x(1) and x(2) will be the two first numbers of your sequence, and N will be the length of the sequence you must output. (You can choose to have the list 0-based, in which case N will be one less than the length).

You can not assume that x(2) >= x(1).
N will always be >2 if 1-based, (>1 if 0-based).
You do not have to handle division by zero errors.
Note the 2nd test case. You will not get 0, 1, and N=6 as input, since that will result in division by zero, but you must support 0, 1 and N=5.
Assume only valid input will be given.
The input and output can be on any convenient format, but you must support at least 3 digits after the decimal points if the output is non-integer.

Test cases:

1 3
8
1, 3, 4, 12, -8, -1.5, -9.5, 14.25

0 1
5
0, 1, 1, 1, 0     // N=6 would give division by zero error. You don't need to handle that case.

1 0
9
1, 0, 1, 0, 1, 0, 1, 0, 1

6 3
25
6, 3, 9, 27, -18, -1.5, -19.5, 29.25, -48.75, -0.6, -49.35, 29.61, -78.96, -0.375, -79.335, 29.7506, -109.086, -0.272727, -109.358, 29.825, -139.183, -0.214286, -139.398, 29.8709, -169.269

*/

fn main() {
    test(
        1.0,
        3.0,
        8,
        vec![1.0, 3.0, 4.0, 12.0, -8.0, -1.5, -9.5, 14.25],
    );

    test(0.0, 1.0, 5, vec![0.0, 1.0, 1.0, 1.0, 0.0]);

    test(
        1.0,
        0.0,
        9,
        vec![1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0],
    );

    test(
        6.0,
        3.0,
        25,
        vec![
            6.0, 3.0, 9.0, 27.0, -18.0, -1.5, -19.5, 29.25, -48.75, -0.6, -49.35, 29.61, -78.96,
            -0.375, -79.335, 29.7506, -109.086, -0.272727, -109.358, 29.825, -139.183, -0.214286,
            -139.398, 29.8709, -169.269,
        ],
    );
}

fn test(x: f64, y: f64, n: isize, r: Vec<f64>) {
    let eps = 1e-3;

    let p = stewies(x, y, n);
    assert_eq!(p.len() == r.len(), true);
    for i in 0..p.len() {
        assert_eq!((p[i] - r[i]).abs() < eps, true);
    }
}

fn stewies(mut x: f64, mut y: f64, n: isize) -> Vec<f64> {
    let mut r = vec![];

    if n >= 1 {
        r.push(x);
    }
    if n >= 2 {
        r.push(y);
    }

    for i in 2..n {
        let z = match (i - 2) & 3 {
            0 => x + y,
            1 => x * y,
            2 => x - y,
            3 => x / y,
            _ => panic!("unreachable"),
        };

        (x, y) = (y, z);
        r.push(z);
    }

    r
}
