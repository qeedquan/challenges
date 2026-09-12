/*

Given the positive integer n. Print the image of size n∗n, formed by the asterisk and space characters as shown in the example.

*****
    *
*****
*
*****

Input
One positive integer n(n≤100).

Output
Print the image n∗n.

Examples
Input #1
5

Answer #1
*****
    *
*****
*
*****

Input #2
8

Answer #2
********
       *
********
*
********
       *
********
*

*/

fn main() {
    solve(5);
    solve(8);
}

fn solve(n: isize) {
    for y in 0..n {
        for x in 0..n {
            let mut c = ' ';
            if y & 1 == 0 {
                c = '*';
            } else if (x == 0) && (y & 0x2 != 0) {
                c = '*';
            } else if (x == n - 1) && (y & 0x2 == 0) {
                c = '*';
            }
            print!("{}", c);
        }
        println!();
    }
    println!();
}
