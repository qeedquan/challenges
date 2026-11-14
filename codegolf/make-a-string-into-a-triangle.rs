/*

Challenge
Given a string, make it into a triangle as shown below:

Input
Hello, world!
Output
H
He
Hel
Hell
Hello
Hello,
Hello, 
Hello, w
Hello, wo
Hello, wor
Hello, worl
Hello, world
Hello, world!
The first line contains the first character of the string. The following lines contain one more character on each line, until the full length of the original string is reached.

If you receive a one character string, just output it.

You will never receive an empty string.

Rules
Standard loopholes apply, as usual
This is code-golf, shortest solution wins.

*/

fn main() {
    triangularize("Hello, world!");
}

fn triangularize(s: &'static str) {
    for i in 0..s.len() {
        let mut j = 0;
        for c in s.chars() {
            if j > i {
                break;
            }
            print!("{}", c);
            j += 1;
        }
        println!();
    }
}
