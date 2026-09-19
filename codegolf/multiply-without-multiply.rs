/*

Write the fastest (best big-O) and smallest multiplication algorithm for positive integers, without using multiplication operators.
You are only allowed addition, subtraction, logical functions (AND, OR, XOR, NOT), bit shift, bit rotate, bit flip/set/clear and bit test.
Your program should be capable of multiplying 16-bit numbers to produce a 32-bit result.
Take input on stdin, separated by commas, spaces or new lines (your choice), but make it clear how to input the data.

Example input/output:

734 929
681886

*/

fn main() {
    let n = 10000;
    for a in -n..n {
        for b in -n..n {
            assert_eq!(mul(a, b), a * b);
        }
    }
}

/*

@fR0DDY

The algorithm is better known as the Ethiopian Multiplication or the Russian Peasant Multiplication.

Here’s the algorithm:
Let the two numbers to be multiplied be a and b.
If a is zero then break and print the result.
If a is odd then add b to the result.
Half a, Double b. Goto Step 2.

*/

fn mul(mut a: isize, mut b: isize) -> isize {
    let (mut r, s) = (0, sign(a) * sign(b));
    a = a.abs();
    b = b.abs();
    while a != 0 {
        if (a & 1) != 0 {
            r += b;
        }
        a >>= 1;
        b += b;
    }
    r * s
}

fn sign(x: isize) -> isize {
    if x < 0 {
        -1
    } else {
        1
    }
}
