/*

Challenge
Write a program or function that given a string, returns a valid Brainfuck program that when compiled and executed as Brainfuck, returns that string..

Assume all inputs are encoded as ASCII.

Assume the outputted BF program will execute in an environment with an infinite tape.

Assume the pointer starts at cell 0 with every cell initialized to a value of zero.

Each example below represent one possible correct output for the given input. In particular, the examples include extra newlines and spaces to help human readability. Solutions are free to format the outputted BF code in any way.

The tape is doubly infinite.

All cells provided by the interpreter are exactly 8-bit cells. Overflow and underflow wrap around in a predictable and sane matter.

Examples
Space string
Given the input   , your program/function could return:

+++++ +++++
+++++ +++++
+++++ +++++
++ .

Exclamation point
Given the input ! , your program/function could return:

+++++ +++++
+++++ +++++
+++++ +++++
+++
.

Two letters
Given the input hi , your program/function could return:

+++++ +++++
+++++ +++++
+++++ +++++
+++++ +++++
+++++ +++++

+++++ +++++
+++++ +++++
+++++ +++++
+++++ +++++
+++++ +++++

++++
.
+
.

This is code-golf, so the code with the smallest number of bytes wins. Good luck.

*/

fn main() {
    test(" ");
    test("!");
    test("hi");
}

fn test(s: &'static str) {
    println!("{}", s);
    println!("{}", bfenc(s));
}

fn bfenc(s: &'static str) -> String {
    let mut r = String::new();
    let mut c0 = 0i32;
    for c in s.chars() {
        let (c1, mut cn, mut op) = (c as i32, 1, '+');
        if c0 > c1 {
            (cn, op) = (-1, '-');
        }

        let mut p = 1;
        while c0 != c1 {
            r.push(op);
            if p % 50 == 0 {
                r.push_str("\n\n");
            } else if p % 10 == 0 {
                r.push('\n');
            } else if p % 5 == 0 {
                r.push(' ');
            }
            c0 += cn;
            p += 1;
        }

        if p != 0 {
            r.push('\n');
        }
        r.push_str(".\n");
    }
    r
}
